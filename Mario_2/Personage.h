#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Define.h"
#include "Map.h"

using namespace sf;
using namespace std;

class Personage
{
protected:
	int      numOfFrame;
	float    currentFrame;
	Vector2f position;             // ������� ���������
	Vector2i proportions;          // ����� ������� ���������
	Texture  texture;
	float    playerSpeed;
	float    dx, dy;
	bool     onGround;
	Sprite   sprite;
	vector<Sprite> frames;

	void collision_y(Map& map);
public:
	Personage() = delete;
	Personage(const string path, const int _frames, const float speed, Vector2f _pozition, Vector2i size);
	Sprite getSprite() const;
	void setFrames(const vector<IntRect> frames);
	virtual void update(float time, Map& map) = 0;
};


class PLAYER : public Personage
{
private:
	SoundBuffer buffer;
	Sound       sound;


	bool        playerUp;
	bool        playerDown;
	bool        playerRight;
	bool        playerLeft;

	void jump();
	void collision_x(Map& map);
	void updateSprite();
	void updatePosition(float time, Map& map);


public:
	PLAYER() = delete;
	PLAYER(const string jump, const string path, const int frames, const float inSpeed,
		Vector2f _pozition, Vector2i size);
	Vector2f getPosition() const;

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	void stopUp();
	void stopDown();
	void stopRight();
	void stopLeft();
	void update(float time, Map& map);

};

class MinorPesonage : public Personage
{
private:

public:
	MinorPesonage(const string path, const int frames, const float inSpeed,
		Vector2f _pozition, Vector2i size);

};