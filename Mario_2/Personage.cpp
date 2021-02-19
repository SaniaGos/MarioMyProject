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
}

void Personage::update(float time)
{
	currentFrame += time / M_SPEED;
	if (currentFrame > numOfFrame) currentFrame = 0;
}

PLAYER::PLAYER(string path, int frames, float inSpeed, FloatRect inRect, float speed) :
	Personage(path, frames, inRect, speed),
	onGround(false),
	playerUp(false),
	playerDown(false),
	playerRight(false),
	playerLeft(false)
{
	dx = dy = 0.f;
}

MinorPesonage::MinorPesonage(string path, int frames, float inSpeed, FloatRect inRect, float speed) :
	Personage(path, frames, inRect, speed)
{
	dx = dy = 0.f;
}