#pragma once
#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile(sf::RenderWindow& t_window);
	~Tile();

	void render();
	void setUp(sf::Vector2f t_size);
	void setPosition(sf::Vector2f t_position);
	void setID(int t_ID);


	sf::Vector2f getTilePosition();
	sf::Vector2f getTileSize();
	int getID();

private:
	sf::RenderWindow& m_window;

	sf::RectangleShape m_tile;
	
	int m_ID;
};

