
#include "Game.h"
#include <iostream>


Game::Game() :
	m_window{ sf::VideoMode{ 1500U, 1500U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	generateGrid();
}

Game::~Game()
{
}

void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{


	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (sf::Event::MouseButtonPressed == newEvent.type)
		{
			processClicks(newEvent);
		}
	}
}

void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

void Game::processClicks(sf::Event t_event)
{
	if (sf::Mouse::Left == t_event.key.code)
	{
		getTileClicked();
	}
	
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

void Game::render()
{
	m_window.clear(sf::Color::Black);
	for (int i = 0; i < ((m_numTilesHigh * m_numTilesWide)-1); i++)
	{
		m_tiles[i]->render();
	}
	m_window.display();
}

void Game::generateGrid()
{

	for (int i = 0; i < (m_totalTiles -1); i++)
	{
		m_tiles.push_back(new Tile(m_window));
		m_tiles[i]->setUp(sf::Vector2f(m_window.getSize().x / m_numTilesHigh, m_window.getSize().y / m_numTilesWide));	
		m_tiles[i]->setID(i);
	}

	float x = 0;
	float y = 0;
	float xcount = 0;
	float ycount = 0;
	for (int i = 0; i < (m_totalTiles -1); i++)
	{
		m_tiles[i]->setPosition(sf::Vector2f(x, y));

		if (x <= (m_window.getSize().x)- m_tiles[i]->getTileSize().x)
		{
			x += m_tiles[i]->getTileSize().x;
		}
		else
		{
			xcount++;
			ycount++;
			x = 0;
			y = (m_tiles[i]->getTileSize().y * ycount);
		}
	}
}

void Game::getTileClicked()
{
	sf::Vector2f m_click = sf::Vector2f(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y);

	for (int i = 0; i < (m_totalTiles)-1; i++)
	{
		if(m_tiles[i]->getTilePosition().x >= m_click.x && ((m_tiles[i]->getTilePosition().x) + (m_tiles[i]->getTileSize().x)) <= m_click.x)
		{
			std::cout << "click" << std::endl;
		}
	}

}



