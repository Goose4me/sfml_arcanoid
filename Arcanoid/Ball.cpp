#include "Ball.h"
#include "Platform.h"

void Ball::initializeSprite()
{
	this->sprite.setOrigin(sf::Vector2f(this->radius, this->radius ));
	this->sprite.setPosition(this->position);
	this->sprite.setRadius(this->radius);
	this->sprite.setFillColor(sf::Color::Red);
	this->sprite.setOutlineColor(sf::Color::Color(200, 200, 200));
	this->sprite.setOutlineThickness(0.5f);
}

void Ball::initializeVariables()
{
	this->velocity = sf::Vector2f(0,0);
	this->radius = 7.f;
}

Ball::Ball(sf::Vector2f position)
{
	this->position = position;
	this->initializeVariables();
	this->initializeSprite();
}

Ball::~Ball()
{
}
void Ball::checkBoundsCollsison(sf::VideoMode * vm)
{
	if (this->sprite.getPosition().y+ this->radius >=(*vm).height || this->sprite.getPosition().y - this->radius<=0)
	{
		this->velocity.y *= -1;
	}
	if (this->sprite.getPosition().x + this->radius >= (*vm).width || this->sprite.getPosition().x - this->radius <= 0) {
		this->velocity.x *= -1;
	}
}
float Ball::getRadius()
{
	return this->radius;
}

void Ball::move(sf::VideoMode *vm, Platform* platform)
{
	if (!this->started)
	{
		this->velocity.x = platform->velocity.x;

	}
	this->checkBoundsCollsison(vm);
	this->sprite.move(velocity);
}
