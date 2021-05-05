#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Brick.h"
#include <vector>
#include "Platform.h"
#include "Ball.h"
class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	Ball* ball;
	sf::VideoMode videoMode;
	sf::RectangleShape enemy;
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;
	std::vector<Brick> bricks;
	Platform* platform;
	
	bool checkCollision(sf::CircleShape ball, sf::RectangleShape item);
	void renderBricks();
	void initVariables();
	void initWindow();
	void initEnemies();
public:
	Game();
	virtual ~Game();

	const bool isRunning() const;

	void pollEvents();
	void updateMousePosition();
	void update();
	void render();
};

