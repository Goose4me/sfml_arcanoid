#include "Platform.h"

void Platform::initializeSprite()
{
	this->sprite.setOrigin(sf::Vector2f(this->width / 2, this->height / 2));
	this->sprite.setPosition(this->position);
	this->sprite.setSize(sf::Vector2f(this->width, this->height));
	this->sprite.setFillColor(sf::Color::White);
	this->sprite.setOutlineColor(sf::Color::Color(200, 200, 200));
	this->sprite.setOutlineThickness(1.f);
}

void Platform::initializeVariables()
{
	this->velocity = sf::Vector2f(0,0);
}

Platform::Platform(sf::Vector2f position)
{
	this->position = position;
	this->initializeVariables();
	this->initializeSprite();
}

Platform::~Platform()
{
}
sf::RectangleShape Platform::getSprite()
{
	return this->sprite;
}

void Platform::move(sf::VideoMode* vm)
{
	
	this->sprite.move(this->velocity);
	if (this->sprite.getPosition().x + this->width / 2 >= (*vm).width) {

		this->sprite.setPosition(sf::Vector2f((*vm).width - this->width / 2, this->sprite.getPosition().y));
	}
	else if (this->sprite.getPosition().x - this->width / 2 <= 0)
	{

		this->sprite.setPosition(sf::Vector2f(this->width / 2, this->sprite.getPosition().y));
	}
}

float Platform::getHeight()
{
	return this->height;
}






