#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class Platform
{
private:
	sf::RectangleShape sprite;
	sf::Vector2f position;
	float width = 100;
	float height = 15;
	void initializeSprite();
	void initializeVariables();
	void checkBounds(sf::VideoMode *vm);
public:
	Platform(sf::Vector2f position);
	virtual ~Platform();

	sf::Vector2f velocity;
	const sf::Vector2f speed = sf::Vector2f(8.f, 0);
	float getHeight();


	sf::RectangleShape getSprite();
	void move(sf::VideoMode* vm);
	
};

