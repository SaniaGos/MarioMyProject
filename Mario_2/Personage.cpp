#include "Personage.h"


Personage::Personage(const string path, const int frames, const float speed, FloatRect inRect ) :
	numOfFrame(frames),
	currentFrame(0),
	rect(inRect),
	playerSpeed(speed)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(32, 96, 32, 32));
	sprite.setPosition(rect.left, rect.top);
	dx = dy = 0.f;
}

Sprite Personage::getSprite() const
{
	return sprite;
}

//void Personage::update(float time)
//{
//	currentFrame += time / playerSpeed;
//	if (currentFrame > numOfFrame) currentFrame = 0;
//}

PLAYER::PLAYER(const string path, const int frames, const float inSpeed, FloatRect inRect) :
	Personage(path, frames, inSpeed, inRect),
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
}

MinorPesonage::MinorPesonage(string path, int frames, float inSpeed, FloatRect inRect, float speed) :
	Personage(path, frames, speed, inRect)
{

}