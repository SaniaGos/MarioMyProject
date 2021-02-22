#include "Personage.h"



Personage::Personage(const string path, const int _frames, const float speed,
	Vector2f _pozition, Vector2i size ) :
	numOfFrame(_frames),
	currentFrame(0),
	playerSpeed(speed),
	pozition(_pozition),
	proportions(size)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(pozition);
	dx = dy = 0.f;
}

Sprite Personage::getSprite() const
{
	return sprite;
}

void Personage::setFrames(const vector<IntRect> rectFrames)
{
	for (size_t i = 0; i < rectFrames.size(); i++)
	{
		sprite.setTextureRect(rectFrames[i]);
		frames.push_back(sprite);
	}
}

PLAYER::PLAYER(const string path, const int frames, const float inSpeed,
	Vector2f _pozition, Vector2i size) :
	Personage(path, frames, inSpeed, _pozition, size),
	onGround(false),
	playerUp(false),
	playerDown(false),
	playerRight(false),
	playerLeft(false)
{
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
void PLAYER::update(float time)
{
	currentFrame += time / playerSpeed;
	if (currentFrame > numOfFrame) currentFrame = 0;
	m_update();
}

void PLAYER::m_update()
{
	if (playerRight && !playerLeft)
		sprite = frames[currentFrame + 1];
	
	else if (playerLeft && !playerRight)
	{
		sprite = frames[currentFrame + 1 + numOfFrame];
	}
	
	else sprite = frames[0];
	sprite.setPosition(150, 250);
}




MinorPesonage::MinorPesonage(const string path, const int frames, const float inSpeed,
	Vector2f _pozition, Vector2i size) :
	Personage(path, frames, inSpeed, _pozition, size)
{

}