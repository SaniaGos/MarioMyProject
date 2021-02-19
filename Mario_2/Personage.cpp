#include "Personage.h"


Personage::Personage(string path, int frames, FloatRect inRect, float speed) : 
	numOfFrame(frames),
	currentFrame(0),
	rect(inRect),
	playerSpeed(speed)
{
	Texture m_Texture;
	m_Texture.loadFromFile(path);
	m_Sprite.setTexture(m_Texture);
	dx = dy = 0.f;
}

//void Personage::update(float time)
//{
//	currentFrame += time / playerSpeed;
//	if (currentFrame > numOfFrame) currentFrame = 0;
//}

PLAYER::PLAYER(string path, int frames, float inSpeed, FloatRect inRect, float speed) :
	Personage(path, frames, inRect, speed),
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

MinorPesonage::MinorPesonage(string path, int frames, float inSpeed, FloatRect inRect, float speed) :
	Personage(path, frames, inRect, speed)
{
}