#include "Personage.h"


Personage::Personage(string path, int frames, FloatRect inRect): numOfFrame(frames), currentFrame(0), rect(inRect)
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

PLAYER::PLAYER(string path, int frames, float inSpeed, FloatRect inRect) : Personage(path, frames, inRect),
	onGround(false),
	playerUp(false),
	playerDown(false),
	playerRight(false),
	playerLeft(false),
	playerSpeed(inSpeed)
{
	dx = dy = 0.f;
}