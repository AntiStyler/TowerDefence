#pragma once
#include "CEventHandler.h"
#include "CPlayer.h"
#include "CTower.h"

#include "util.h"

class CGame
{
public:
	CGame(sf::RenderWindow* pRender);

	void StartGame();
	void CloseGame();
	void UpdateGame();
	void EventHandler();

	void CreateGameBoundaries();
	void UpdateGameBoundaries();
	void DeleteGameBoundaries();
private:
	sf::RenderWindow* pRender;
	CEventHandler* pEventHandler;

	CPlayer* pPlayer;
	std::vector<CTower*> pTowers;

	sf::Vector2f direction;
	float magnitude = 0.f;

	bool bGamePaused = false;

	std::vector<sf::RectangleShape*> boundaries;
};
