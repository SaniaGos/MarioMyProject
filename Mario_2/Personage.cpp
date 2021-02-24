#include "Personage.h"

Personage::Personage(Vector2f _pozition, Vector2i size) :
	currentFrame(0),
	position(_pozition),
	proportions(size),
	texture(),
	sprite(),
	buffer(),
	sound(),
	lives(0)
{
	dx = dy = 0.f;
}
Sprite Personage::getSprite() const { return sprite; }
Vector2f Personage::getPosition() const { return position; }


// ************* PLAYER ************//
//**********************************//
PLAYER::PLAYER(Vector2f _pozition, Vector2i size) :
	Personage(_pozition, size),
	playerUp(false),
	playerDown(false),
	playerRight(false),
	playerLeft(false),
	onGround(false)
{
	dx = 0.5;
	texture.loadFromFile(MARIO_SPRITE);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	buffer.loadFromFile(MARIO_JUMP);
	sound.setBuffer(buffer);
}
void PLAYER::collision_x(Map& map)
{
	for (int i = position.y / ATLAS_HEIGHT; i < (position.y + proportions.y) / ATLAS_HEIGHT; i++)
		for (int j = position.x / ATLAS_WIDTH; j < (position.x + proportions.x) / ATLAS_WIDTH; j++)
		{
			if (map.getMap()[i][j] == 'B' ||
				map.getMap()[i][j] == '0')
			{
				if (playerRight) { position.x = j * ATLAS_WIDTH - proportions.x; }
				if (playerLeft) { position.x = j * ATLAS_WIDTH + ATLAS_WIDTH; }
			}
		}
}
void PLAYER::collision_y(Map& map)
{
	onGround = false;
	for (int j = position.x / ATLAS_WIDTH; j < (position.x + proportions.x) / ATLAS_WIDTH; j++)
		for (int i = position.y / ATLAS_HEIGHT; i < (position.y + proportions.y) / ATLAS_HEIGHT; i++)
		{
			if (map.getMap()[i][j] == 'B' ||
				map.getMap()[i][j] == '0')
			{
				if (dy > 0) { position.y = i * ATLAS_HEIGHT - proportions.y, dy = 0, onGround = true; }
				if (dy < 0) { position.y = i * ATLAS_HEIGHT + ATLAS_HEIGHT, dy = 0; }
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
	currentFrame += time * MARIO_SPEED / 50;
	if ((int)currentFrame >= MARIO_FRAMES) currentFrame = 0;
	updateSprite();
	updatePosition(time, map);
}
void PLAYER::die()
{

}
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
		sprite = frames[currentFrame + 1 + MARIO_FRAMES];

	else sprite = frames[0];
}
void PLAYER::updatePosition(float time, Map& map)
{
	if (playerLeft)	position.x -= MARIO_SPEED * time * dx;
	if (playerRight) position.x += MARIO_SPEED * time * dx;
	collision_x(map);

	if (playerUp) jump();
	if (!onGround)
	{
		dy += 0.0045 * time * MARIO_SPEED;
		position.y += MARIO_SPEED * time * dy;
	}
	collision_y(map);

	if (position.x > HORIZONTAL_RESOLUTION / 2 &&
		position.x < (map.getMap()[0].size() * ATLAS_HEIGHT) - HORIZONTAL_RESOLUTION / 2)
		map.offset.x = position.x - HORIZONTAL_RESOLUTION / 2;

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
	Personage(_position, size)
{
	proportions.y > ATLAS_HEIGHT ? position.y -= (proportions.y - ATLAS_HEIGHT) : position.y;
}
void Minor_Personage::setFrames(const vector<IntRect>& frames)
{
	e_frames = frames;
}
bool Minor_Personage::getLives() const
{
	return lives > 0 ? true : false;
}
//
//
//*********** Mushrooms_And_Turtles ************//
//**********************************************//
Mushrooms_And_Turtles::Mushrooms_And_Turtles(Vector2f _position, Vector2i size) :
	Minor_Personage(_position, size),
	back(false)
{
	texture.loadFromFile(ENEMIES);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	start_position = _position.x;
	lives = MUSHR_LIVES;
	dx = 0.2;
}
void Mushrooms_And_Turtles::updatePosition(float time, const Map& map)
{
	if (!back)
	{
		position.x += SPEED_ENEMIES * time * dx;
		if (position.x >= start_position + MAX_DISTANCE)
			back = true;
	}
	else
	{
		position.x -= SPEED_ENEMIES * time * dx;
		if (position.x <= start_position)
			back = false;
	}
	sprite.setPosition(position.x - map.offset.x, position.y);
}
void Mushrooms_And_Turtles::update(float time, Map& map)
{
	currentFrame += time * SPEED_ENEMIES / 80;
	if ((int)currentFrame >= MUSHR_FRAMES) currentFrame = 0;
	updateSprite();
	updatePosition(time, map);
}
void Mushrooms_And_Turtles::die()
{

}
void Mushrooms_And_Turtles::updateSprite()
{
	sprite.setTexture(texture);
	if (lives > 0 && !back)
		sprite.setTextureRect(e_frames[currentFrame + 1]);

	else if (lives > 0 && back)
		sprite.setTextureRect(e_frames[currentFrame + 1 + MUSHR_FRAMES]);

	else sprite.setTextureRect(e_frames[0]);
}
//
//
		//*********** Money ************//
//**********************************************//
Money::Money(Vector2f _position, Vector2i size) :
	Minor_Personage(_position, size)
{
	texture.loadFromFile(ITEMS);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	buffer.loadFromFile(MONEY_SOUND);
	sound.setBuffer(buffer);
	lives = MONEY_LIVES;
}
void Money::update(float time, Map& map)
{
	currentFrame += time * SPEED_ENEMIES / 180;
	if (currentFrame >= MONEY_FRAMES) currentFrame = 0;
	updateSprite();
	sprite.setPosition(position.x - map.offset.x, position.y);
}
void Money::die()
{
	lives -= 1;
}
void Money::updateSprite()
{
	sprite.setTexture(texture);
	if (lives > 0)
		sprite.setTextureRect(e_frames[currentFrame]);
}




void clashPersonage(PLAYER& Mario, Minor_Personage& personage)
{
	if (FloatRect(Mario.position, Vector2f(Mario.proportions)).intersects(FloatRect(personage.position, Vector2f(personage.proportions))))
	{
		if (personage.getLives())
		{
			if (Mario.dy > 0)
			{
				Mario.dy = -0.8;
				personage.die();
			}
			else
				Mario.die();
		}
	}
}
