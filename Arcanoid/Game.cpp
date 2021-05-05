#include "Game.h"

//Initialization
void Game::initVariables()
{
	this->window = nullptr;
	
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 600;
	this->window = new sf::RenderWindow(this->videoMode, "Arcanoid", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{	
	for (float x = 40; x < this->window->getSize().x-40; x+=40)
	{
		for (float y = 0; y < 7; y++)
		{
			this->bricks.push_back(Brick(sf::Vector2f(x, 20+y*20),y));
		}
		
	}
	

}

// Constructor / Destructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	this->platform = new Platform(sf::Vector2f(250, 500));
	this->ball = new Ball(this->platform->getSprite().getPosition());
	this->ball->sprite.setPosition(this->platform->getSprite().getPosition().x,
		this->platform->getSprite().getPosition().y - this->platform->getHeight() / 2 -this->ball->radius);
}

Game::~Game()
{
	delete this->window;
	delete this->platform;
	delete this->ball;
}

//Functions
const bool Game::isRunning() const
{
	return this->window->isOpen();
}


void Game::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed)
			this->window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				this->window->close();
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
		{
			this->platform->velocity.x = this->platform->speed.x;
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) )
		{
			this->platform->velocity.x = -this->platform->speed.x;
		}
		else {
			this->platform->velocity.x = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& ! this->ball->started)
		{
			this->ball->started = true;
			this->ball->velocity = sf::Vector2f(this->platform->velocity.x, -1*this->ball->speed);
		}
	}
}

void Game::updateMousePosition()
{
	this->mousePos = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
}

void Game::update()
{
	if (this->checkCollision(this->ball->sprite,this->platform->getSprite()) && this->ball->started)
	{
		this->ball->velocity.y = -this->ball->speed;
		this->ball->velocity.x += this->platform->velocity.x/10;
	}
	else {
		std::vector<Brick>::iterator iterator = this->bricks.begin();
		while (iterator != this->bricks.end())
		{
			if (this->checkCollision(this->ball->sprite, (*iterator).getSprite())) {
				if (this->ball->sprite.getPosition().y > (*iterator).getSprite().getPosition().y -
					(*iterator).getSprite().getSize().y / 2 &&
					this->ball->sprite.getPosition().y < (*iterator).getSprite().getPosition().y +
					(*iterator).getSprite().getSize().y / 2
					)
				{
					this->ball->velocity.x *= -1;
				}
				else {
					this->ball->velocity.y *= -1;
				}
				this->bricks.erase(iterator);
				break;
			}
			else {
				iterator++;
			}

		}
	}
	if (this->ball->sprite.getPosition().y + this->ball->radius >= this->videoMode.height)
	{
		this->ball->velocity = sf::Vector2f(0, 0);
	}
	this->platform->move(&(this->videoMode));
	this->ball->move(&(this->videoMode), this->platform);
	this->pollEvents();
	this->updateMousePosition();
}
bool Game::checkCollision(sf::CircleShape ball, sf::RectangleShape item)
{
	if (ball.getPosition().x >item.getPosition().x-item.getSize().x/2 &&
		ball.getPosition().x< item.getPosition().x + item.getSize().x/2 &&
		ball.getPosition().y + ball.getRadius() > item.getPosition().y - item.getSize().y&&
		ball.getPosition().y - ball.getRadius() < item.getPosition().y + item.getSize().y
		)
	{
		return true;
	}
	return false;
}
void Game::renderBricks()
{
	for (int i = 0; i < this->bricks.size(); i++)
	{
		this->window->draw(bricks[i].getSprite());
	}
}
void Game::render()
{
	this->window->clear();

	this->renderBricks();
	this->window->draw(this->platform->getSprite());
	this->window->draw(this->ball->sprite);
	this->window->display();
}
