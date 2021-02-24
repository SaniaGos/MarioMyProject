#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Define.h"
#include "Map.h"

using namespace sf;
using namespace std;
class Minor_Personage;

class Personage
{
protected:
	SoundBuffer		buffer;
	Sound			sound;
	float			currentFrame;
	Vector2f		position;             // позиція персонажа
	Vector2i		proportions;          // розмір спрайту персонажа
	Texture			texture;
	float			dx, dy;
	Sprite			sprite;
	vector<Sprite>	frames;
	int             lives;

public:
	Personage() = delete;
	Personage(Vector2f _pozition, Vector2i size);
	Sprite getSprite() const;
	Vector2f getPosition() const;
	virtual void setFrames(const vector<IntRect>& frames) = 0;
	virtual void update(float time, Map& map) = 0;
	virtual void die() = 0;
};

class PLAYER : public Personage
{
private:


	bool        playerUp;
	bool        playerDown;
	bool        playerRight;
	bool        playerLeft;
	bool	    onGround;

	void jump();
	void collision_y(Map& map);
	void collision_x(Map& map);
	void updateSprite();
	void updatePosition(float time, Map& map);


public:
	PLAYER() = delete;
	PLAYER(Vector2f _pozition, Vector2i size);

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	void stopUp();
	void stopDown();
	void stopRight();
	void stopLeft();
	void setFrames(const vector<IntRect>& rectFrames);
	void update(float time, Map& map);
	void die();
	friend void clashPersonage(PLAYER& Mario, Minor_Personage& personage);
};

class Minor_Personage : public Personage
{
protected:
		
	vector<IntRect> e_frames;

	virtual void updateSprite() = 0;
public:
	Minor_Personage() = delete;
	Minor_Personage(Vector2f _position, Vector2i size);
	void setFrames(const vector<IntRect>& frames);
	bool getLives() const;
	friend void clashPersonage(PLAYER& Mario, Minor_Personage& personage);
};

class Mushrooms_And_Turtles : public Minor_Personage
{
private:
	bool            back;
	float			start_position;
	void updatePosition(float time, const Map& map);
	void updateSprite();
public:
	Mushrooms_And_Turtles(Vector2f _position, Vector2i size);

	void update(float time, Map& map);
	void die();
};


class Money : public Minor_Personage
{
private:

	void updateSprite();
public:
	Money() = delete;
	Money(Vector2f _position, Vector2i size);
	void update(float time, Map& map);
	void die();
};


