#include "Picture.h"


Personage::Personage(string path, int frames): numOfFrame(frames), currentFrame(0)
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