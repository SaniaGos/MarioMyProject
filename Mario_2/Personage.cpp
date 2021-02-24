#include "Personage.h"

Personage::Personage(const string path, const int _frames, const float speed,
	Vector2f _pozition, Vector2i size) :
	numOfFrame(_frames),
	currentFrame(0),
	playerSpeed(speed),
	position(_pozition),
	proportions(size),
	onGround(false)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	dx = dy = 0.f;
}

Sprite Personage::getSprite() const { return sprite; }
Vector2f Personage::getPosition() const { return position; }


	   // *********** PLAYER ************//
//**********************************************//
PLAYER::PLAYER(const string jump, const string path, const int frames, const float inSpeed,
	Vector2f _pozition, Vector2i size) :
	Personage(path, frames, inSpeed, _pozition, size),
	playerUp(false),
	playerDown(false),
	playerRight(false),
	playerLeft(false)
{
	dx = 0.5;
	buffer.loadFromFile(jump);
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
void PLAYER::moveUp()
{
	playerUp = true;
}
void PLAYER::moveDown()
{
	playerDown = true;
}
void PLAYER::moveRight()
{
	playerRight = true;
}
void PLAYER::moveLeft()
{
	playerLeft = true;
}
void PLAYER::stopUp()
{
	playerUp = false;
}
void PLAYER::stopDown()
{
	playerDown = false;
}
void PLAYER::stopRight()
{
	playerRight = false;
}
void PLAYER::stopLeft()
{
	playerLeft = false;
}
void PLAYER::update(float time, Map& map)
{
	currentFrame += time * playerSpeed / 50;
	if (currentFrame >= numOfFrame) currentFrame = 0;
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
		sprite = frames[currentFrame + 1 + numOfFrame];

	else sprite = frames[0];
}
void PLAYER::updatePosition(float time, Map& map)
{
	if (playerLeft)	position.x -= playerSpeed * time * dx;
	if (playerRight) position.x += playerSpeed * time * dx;
	collision_x(map);

	if (playerUp) jump();
	if (!onGround)
	{
		dy += 0.0045 * time * playerSpeed;
		position.y += playerSpeed * time * dy;
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
Minor_Personage::Minor_Personage(const string _path, const int frames,
	const float inSpeed, int _lives,
	Vector2f _position, Vector2i size):
	Personage(_path, frames, inSpeed, _position, size)
{
	lives = _lives;
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
Mushrooms_And_Turtles::Mushrooms_And_Turtles(const string _path, const int frames,
	const float inSpeed, const int _progress, int _lives, Vector2f _position, Vector2i size) :
	Minor_Personage(_path, frames, inSpeed, _lives, _position, size),
	progress(_progress), back(false)
{
	start_position = _position.x;
	dx = 0.2;
}
void Mushrooms_And_Turtles::updatePosition(float time, const Map& map)
{
	if (!back)
	{
		position.x += playerSpeed * time * dx;
		if (position.x >= start_position + progress)
			back = true;
	}
	else
	{
		position.x -= playerSpeed * time * dx;
		if (position.x <= start_position)
			back = false;
	}
	sprite.setPosition(position.x - map.offset.x, position.y);
}
void Mushrooms_And_Turtles::update(float time, Map& map)
{
	currentFrame += time * playerSpeed / 80;
	if (currentFrame >= numOfFrame) currentFrame = 0;
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
		sprite.setTextureRect(e_frames[currentFrame + 1 + numOfFrame]);

	else sprite.setTextureRect(e_frames[0]);
}
//
//
	    //*********** Money ************//
//**********************************************//
Money::Money(const string _path, const int frames,
	const float inSpeed, int lives,
	Vector2f _position, Vector2i size) :
	Minor_Personage(_path, frames, inSpeed, lives, _position, size)
{}
void Money::update(float time, Map & map)
{
	currentFrame += time * playerSpeed / 180;
	if (currentFrame >= numOfFrame) currentFrame = 0;
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

}
