#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class Brick
{
private:
	int hp;
	sf::RectangleShape sprite;
	sf::Vector2f position;
	float width = 40.f;
	float height = 20.f;
	int row;
	void initializeSprite();
	void initializeVariables();
public:
	Brick(sf::Vector2f position, int row);
	virtual ~Brick();

	sf::RectangleShape getSprite();
	void hit();
};

