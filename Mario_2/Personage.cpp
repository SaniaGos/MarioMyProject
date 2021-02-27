#include "Personage.h"

void clashPersonage(PLAYER& Mario, Minor_Personage& personage)
{
	if (personage.lives && Mario.getRect().intersects(personage.getRect()))
		personage.collision(Mario);
}

Personage::Personage(Vector2f _pozition, Vector2i size) :
	currentFrame(0),
	position(_pozition),
	proportions(size),
	texture(),
	sprite(),
	buffer(),
	sound(),
	lives(0),
	inGame(true)
{
	dx = dy = 0.f;
}
Sprite Personage::getSprite() const { return sprite; }
Vector2f Personage::getPosition() const { return position; }
Vector2f Personage::getSpeed() const { return Vector2f(dx, dy); }
void Personage::setSpeed_y(float speed_y)
{
	dy = speed_y;
}
FloatRect Personage::getRect() const
{
	return FloatRect(position, Vector2f(proportions));
}


//************** PLAYER ************//
//**********************************//
PLAYER::PLAYER(Vector2f _pozition, Vector2i size) :
	Personage(_pozition, size),
	playerUp(false),
	playerDown(false),
	playerRight(false),
	playerLeft(false),
	onGround(false),
	coin(0)
{
	dx = 0.5;
	texture.loadFromFile(GlobalConfig::GetConfig().mario_atlas);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	buffer.loadFromFile(GlobalConfig::GetConfig().mario.music);
	sound.setBuffer(buffer);
}
void PLAYER::collision_x(Map& map)
{
	for (int i = position.y / GlobalConfig::GetConfig().map.atlas_height; i < (position.y + proportions.y) / GlobalConfig::GetConfig().map.atlas_height; i++)
		for (int j = position.x / GlobalConfig::GetConfig().map.atlas_width; j < (position.x + proportions.x) / GlobalConfig::GetConfig().map.atlas_width; j++)
		{
			if (map.getMap()[i][j] == 'B' ||
				map.getMap()[i][j] == '0')
			{
				if (playerRight) { position.x = j * GlobalConfig::GetConfig().map.atlas_width - proportions.x; }
				if (playerLeft) { position.x = j * GlobalConfig::GetConfig().map.atlas_width + GlobalConfig::GetConfig().map.atlas_width; }
			}
		}
}
void PLAYER::collision_y(Map& map)
{
	onGround = false;
	for (int j = position.x / GlobalConfig::GetConfig().map.atlas_width; j < (position.x + proportions.x) / GlobalConfig::GetConfig().map.atlas_width; j++)
		for (int i = position.y / GlobalConfig::GetConfig().map.atlas_height; i < (position.y + proportions.y) / GlobalConfig::GetConfig().map.atlas_height; i++)
		{
			if (map.getMap()[i][j] == 'B' ||
				map.getMap()[i][j] == '0')
			{
				if (dy > 0) { position.y = i * GlobalConfig::GetConfig().map.atlas_height - proportions.y, dy = 0, onGround = true; }
				if (dy < 0) { position.y = i * GlobalConfig::GetConfig().map.atlas_height + GlobalConfig::GetConfig().map.atlas_height, dy = 0; }
			}
		}
}
void PLAYER::moveUp() { playerUp = true; }
void PLAYER::moveDown() { playerDown = true; }
void PLAYER::moveRight() { playerRight = true; }
void PLAYER::moveLeft() { playerLeft = true; }
void PLAYER::stopUp() { playerUp = false; }
void PLAYER::stopDown() { playerDown = false; }
void PLAYER::stopRight() { playerRight = false; }
void PLAYER::stopLeft() { playerLeft = false; }
void PLAYER::update(float time, Map& map)
{
	currentFrame += time * GlobalConfig::GetConfig().mario.speed / 50;
	if ((int)currentFrame >= 3) currentFrame = 0;
	updateSprite();
	updatePosition(time, map);
}
void PLAYER::die()
{

}
void PLAYER::addCoin() { coin++; }
size_t PLAYER::getCoin() const { return coin; }
void PLAYER::jump()
{
	if (onGround)
	{
		dy = -1;
		onGround = false;
		sound.play();
	}
}
void PLAYER::updateSprite()
{
	if (playerRight && !playerLeft)
		sprite = frames[currentFrame + 1];

	else if (playerLeft && !playerRight)
		sprite = frames[currentFrame + 1 + 3];

	else sprite = frames[0];
}
void PLAYER::updatePosition(float time, Map& map)
{
	if (playerLeft)	position.x -= GlobalConfig::GetConfig().mario.speed * time * dx;
	if (playerRight) position.x += GlobalConfig::GetConfig().mario.speed * time * dx;
	collision_x(map);

	if (playerUp) jump();
	if (!onGround)
	{
		dy += 0.0045 * time * GlobalConfig::GetConfig().mario.speed;
		position.y += GlobalConfig::GetConfig().mario.speed * time * dy;
	}
	collision_y(map);

	if (position.x > GlobalConfig::GetConfig().map.horizontal_resolution / 2 &&
		position.x < (map.getMap()[0].size() * GlobalConfig::GetConfig().map.atlas_height) - GlobalConfig::GetConfig().map.horizontal_resolution / 2)
		map.offset.x = position.x - GlobalConfig::GetConfig().map.horizontal_resolution / 2;

	sprite.setPosition(position.x - map.offset.x, position.y);
}
void PLAYER::setFrames(const vector<IntRect>& rectFrames)
{
	for (size_t i = 0; i < rectFrames.size(); i++)
	{
		sprite.setTextureRect(rectFrames[i]);
		frames.push_back(sprite);
	}
}

//*********** MinorPesonage ************//
//**********************************************//
Minor_Personage::Minor_Personage(Vector2f _position, Vector2i size) :
	Personage(_position, size), life(true)
{
	proportions.y > GlobalConfig::GetConfig().map.atlas_height ? position.y -= (proportions.y - GlobalConfig::GetConfig().map.atlas_height) : position.y;
}
void Minor_Personage::setFrames(const vector<IntRect>& frames)
{
	e_frames = frames;
}
bool Minor_Personage::getLives() const { return life; }
//
//
//*********** Mushrooms_And_Turtles ************//
//**********************************************//
Mushrooms::Mushrooms(Vector2f _position, Vector2i size) :
	Minor_Personage(_position, size),
	back(false)
{
	texture.loadFromFile(GlobalConfig::GetConfig().enemie_atlas);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	start_position = _position.x;
	lives = GlobalConfig::GetConfig().mushroom.life;
	dx = 0.2;
	setFrames(
		{
					IntRect(64, 0, 32, 32),          // кадр мертвого

					IntRect(0, 0, 32, 32),           // два кадри руху вправо
					IntRect(32, 0, 32, 32),

					IntRect(0, 0, 32, 32),           // два кадри руху вліво
					IntRect(32, 0, 32, 32)
		});
}
void Mushrooms::updatePosition(float time, Map& map)
{
	if (lives != 0)
	{
		if (!back)
		{
			position.x += GlobalConfig::GetConfig().enemieSpeed * time * dx;
			if (position.x >= start_position + GlobalConfig::GetConfig().maxDistance)
				back = true;
		}
		else
		{
			position.x -= GlobalConfig::GetConfig().enemieSpeed * time * dx;
			if (position.x <= start_position)
				back = false;
		}
	}
	sprite.setPosition(position.x - map.offset.x, position.y);
}
void Mushrooms::update(float time, Map& map)
{
	currentFrame += time * GlobalConfig::GetConfig().enemieSpeed / 80;
	if ((int)currentFrame >= 2) currentFrame = 0;
	updateSprite();
	updatePosition(time, map);
}
void Mushrooms::die() { lives = 0; }
void Mushrooms::collision(PLAYER& mario)
{
	if (mario.getSpeed().y > 0)
	{
		mario.setSpeed_y(-0.8);
		die();
	}
}
void Mushrooms::updateSprite()
{
	sprite.setTexture(texture);
	if (lives > 0 && !back)
		sprite.setTextureRect(e_frames[currentFrame + 1]);

	else if (lives > 0 && back)
		sprite.setTextureRect(e_frames[currentFrame + 1 + 2]);

	else sprite.setTextureRect(e_frames[0]);
}
//
//
//*********** Money ************//
//******************************//
Money::Money(Vector2f _position, Vector2i size) :
	Minor_Personage(_position, size)
{
	texture.loadFromFile(GlobalConfig::GetConfig().item_atlas);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	buffer.loadFromFile(GlobalConfig::GetConfig().money.music);
	sound.setBuffer(buffer);
	lives = GlobalConfig::GetConfig().money.life;
	setFrames(
		{
					IntRect(0, 84, 32, 32),				// кадр 1
					IntRect(32, 84, 32, 32),			// кадр 2
					IntRect(64, 84, 32, 32),			// кадр 3
					IntRect(96, 84, 32, 32)				// кадр 4
		});
}
void Money::update(float time, Map& map)
{
	currentFrame += time * GlobalConfig::GetConfig().enemieSpeed / 180;
	if ((int)currentFrame >= 4) currentFrame = 0;
	updateSprite();
	sprite.setPosition(position.x - map.offset.x, position.y);
}
void Money::collision(PLAYER& mario)
{
	sound.play();
	mario.addCoin();
	die();
}
void Money::die() { lives = 0, life = false; }
void Money::updateSprite()
{
	sprite.setTexture(texture);
	if (lives > 0)
		sprite.setTextureRect(e_frames[currentFrame]);
}


//*********** Turtle ************//
//******************************//
Turtle::Turtle(Vector2f _position, Vector2i size) :
	Minor_Personage(_position, size),
	back(false)
{
	texture.loadFromFile(GlobalConfig::GetConfig().enemie_atlas);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	start_position = _position.x;
	lives = GlobalConfig::GetConfig().turtle.life;
	dx = 0.2;
	setFrames(
		{
					IntRect(64, 32, 32, 48),          // кадр мертвого

					IntRect(32, 32, -32, 48),         // два кадри руху вправо
					IntRect(64, 32, -32, 48),

					IntRect(0, 32, 32, 48),           // два кадри руху вліво
					IntRect(32, 32, 32, 48)
		});
}
void Turtle::updatePosition(float time, Map& map)
{
	if (lives > 1)
	if (!back)
	{
		position.x += GlobalConfig::GetConfig().enemieSpeed * time * dx;
		if (position.x >= start_position + GlobalConfig::GetConfig().maxDistance)
			back = true;
	}
	else
	{
		position.x -= GlobalConfig::GetConfig().enemieSpeed * time * dx;
		if (position.x <= start_position)
			back = false;
	}
	collision_x(map);
	sprite.setPosition(position.x - map.offset.x, position.y);
}
void Turtle::collision_x(Map& map)
{
	if(!back && position.x > start_position)
	for (int i = position.y / GlobalConfig::GetConfig().map.atlas_height; i < (position.y + proportions.y) / GlobalConfig::GetConfig().map.atlas_height; i++)
		for (int j = position.x / GlobalConfig::GetConfig().map.atlas_width; j < (position.x + proportions.x) / GlobalConfig::GetConfig().map.atlas_width; j++)
		{
			if (map.getMap()[i][j] == 'B' ||
				map.getMap()[i][j] == '0' ||
				map.getMap()[i][j] == 'V')
			{
				back = true;
			}
		}
}
void Turtle::updateSprite()
{
	sprite.setTexture(texture);
	if (lives > 1 && !back)
		sprite.setTextureRect(e_frames[currentFrame + 1]);

	else if (lives > 1 && back)
		sprite.setTextureRect(e_frames[currentFrame + 1 + 2]);

	else sprite.setTextureRect(e_frames[0]);
}
void Turtle::die()
{
	lives -= 1; 
	if (!lives) life = false;
}
void Turtle::update(float time, Map& map)
{
	currentFrame += time * GlobalConfig::GetConfig().enemieSpeed / 80;
	if ((int)currentFrame >= 2) currentFrame = 0;
	updateSprite();
	updatePosition(time, map);
}
void Turtle::collision(PLAYER& mario)
{
	if (mario.getSpeed().y > 0)
	{
		mario.setSpeed_y(-0.8);
		die();
	}
}
