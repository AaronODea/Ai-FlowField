#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Tile.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processClicks(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void generateGrid();
	void getTileClicked();


	int m_numTilesHigh = 50;
	int m_numTilesWide = 50;

	int m_totalTiles = (m_numTilesHigh * m_numTilesWide);

	std::vector<Tile*> m_tiles;

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

