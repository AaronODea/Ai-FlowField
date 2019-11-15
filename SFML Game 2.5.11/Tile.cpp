#include "Tile.h"

Tile::Tile(sf::RenderWindow& t_window) :
m_window(t_window)
{
}

Tile::~Tile()
{
}

void Tile::render()
{
	m_window.draw(m_tile);
}

void Tile::setUp(sf::Vector2f t_size)
{
	m_tile.setFillColor(sf::Color(0, 0, 0, 0));
	m_tile.setOutlineColor(sf::Color::White);
	m_tile.setOutlineThickness(1);
	m_tile.setSize(t_size);
}

void Tile::setPosition(sf::Vector2f t_position)
{
	m_tile.setPosition(t_position);
}

void Tile::setID(int t_ID)
{
	m_ID = t_ID;
}

sf::Vector2f Tile::getTilePosition()
{
	return m_tile.getPosition();
}

sf::Vector2f Tile::getTileSize()
{
	return m_tile.getSize();
}

int Tile::getID()
{
	return m_ID;
}
