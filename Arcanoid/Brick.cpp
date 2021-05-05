#include "Brick.h"
#include <iostream>
Brick::Brick(sf::Vector2f position, int row)
{
	this->position = position;
	this->row = row;
	this->initializeVariables();
	this->initializeSprite();
}

void Brick::initializeVariables()
{
	this->hp = 1;
}

Brick::~Brick()
{

}

void Brick::initializeSprite()
{
	
	this->sprite.setOrigin(this->width/2,this->height / 2);
	this->sprite.setPosition(sf::Vector2f(this->position.x + this->width / 2, this->position.y + this->height / 2));
	this->sprite.setSize(sf::Vector2f(this->width, this->height));
	if (this->row ==0) {
		this->sprite.setFillColor(sf::Color::White);
	}
	else if (this->row == 1)
	{
		this->sprite.setFillColor(sf::Color::Red);
	}
	else if (this->row == 2)
	{
		this->sprite.setFillColor(sf::Color::Yellow);
	}
	else if (this->row == 3)
	{
		this->sprite.setFillColor(sf::Color::Blue);
	}
	else if (this->row == 4)
	{
		this->sprite.setFillColor(sf::Color::Magenta);
	}
	else if (this->row == 5)
	{
		this->sprite.setFillColor(sf::Color::Green);
	}
	else if (this->row == 6)
	{
		this->sprite.setFillColor(sf::Color::Cyan);
	}
	this->sprite.setOutlineColor(sf::Color::Color(200, 200, 200));
	this->sprite.setOutlineThickness(1.f);
}

sf::RectangleShape Brick::getSprite()
{
	return this->sprite;
}



