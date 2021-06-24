#include "pch.h"
#include "CGame.h"

const char* kWindowTitle = "Tower Defence";

constexpr unsigned int kWindowWidth = 1024;
constexpr unsigned int kWindowHeight = 768;

constexpr unsigned int kFrameRateLimit = 60;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), kWindowTitle);
	window.setFramerateLimit(kFrameRateLimit);

	CGame* game = new CGame(&window);
	std::thread gameThread(&CGame::StartGame, game);

	//std::cout << "Threadid: " << gameThread.get_id() << std::endl;
	//
	//std::thread eventHandlerThread(&CGame::EventHandler, game);
	//std::cout << "Threadid: " << eventHandlerThread.get_id() << std::endl;

	//std::thread updateThread(&CGame::UpdateGame, game);
	//std::cout << "Threadid: " << updateThread.get_id() << std::endl;

	while (window.isOpen())
	{
		game->EventHandler();

		game->UpdateGame();
	}

	//updateThread.join();
	//eventHandlerThread.join();
	gameThread.join();
	delete game;

	return 0;
}
