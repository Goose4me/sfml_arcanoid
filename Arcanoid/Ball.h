#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Platform.h"
class Ball
{
private:
	
	sf::Vector2f position;
	float radius = 20.f;
	float speed = 5.f;
	
	void checkBoundsCollsison(sf::VideoMode *vm);

	void initializeSprite();
	void initializeVariables();
	sf::CircleShape sprite;
	friend class Game;
public:
	Ball(sf::Vector2f position);
	virtual ~Ball();

	sf::Vector2f velocity;
	bool started = false;
	
	float getRadius();
	
	void move(sf::VideoMode *vm, Platform* platform);
	
};

