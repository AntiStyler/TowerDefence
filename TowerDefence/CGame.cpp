#include "pch.h"
#include "CGame.h"

CGame::CGame(sf::RenderWindow* pRender)
{
	this->pRender = pRender;
	this->pEventHandler = new CEventHandler();
	this->pPlayer = nullptr;
}

void CGame::StartGame()
{
	CreateGameBoundaries();

	this->pPlayer = new CPlayer(pRender, sf::Vector2<float>(50.f, 50.f));

	//for (auto i = 0; i < 21; i++)
	//{
	//	pTowers.push_back(new CTower(pRender, sf::Vector2<float>(20.f, 20.f)));
	//
	//	if (i == 0)
	//	{
	//		pTowers[i]->SetPosition(250.f, 100.f);
	//	}
	//	else if (i > 0 && i <= 10)
	//	{
	//		pTowers[i]->Move(pTowers[i - 1]->GetPosition().x + 20.f, pTowers[i - 1]->GetPosition().y + 25.f);
	//	}
	//	else if (i > 0 && i > 10)
	//	{
	//		pTowers[i]->Move(pTowers[i - 1]->GetPosition().x + 20.f, pTowers[i - 1]->GetPosition().y - 25.f);
	//	}
	//
	//	if (pTowers[i])
	//	{
	//		pTowers[i]->CreateProjectile();
	//	}
	//}
}

void CGame::CloseGame()
{
	delete pEventHandler;
	delete pPlayer;

	for (auto tower : pTowers)
	{
		delete tower;
	}
}

void CGame::UpdateGame()
{
	//sf::Font font;
	//font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");
	//sf::Text text("Game Over", font);
	//text.setCharacterSize(30);
	//text.setStyle(sf::Text::Bold);
	//text.setFillColor(sf::Color::Red);
	//text.setPosition(60.f, 60.f);

	pRender->clear();

	if (!bGamePaused)
	{
		// draw tower projectiles
		for (auto i = 0; i < pTowers.size(); i++)
		{
			if (pTowers[i] != nullptr)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
				{
					pTowers[i]->GetProjectile()->setFillColor(sf::Color(255, 0, 0, 255));
					direction = pPlayer->GetPosition() - pTowers[i]->GetProjectile()->getPosition();
					pTowers[i]->GetProjectile()->move(Math::GetUnitVector(direction, Math::GetMagnitude(direction)) * 2.f);
					pTowers[i]->DrawProjectile();
					
					if (pPlayer->GetPlayer()->getGlobalBounds().contains(pTowers[i]->GetProjectile()->getPosition()))
					{
						std::cout << "Player dead" << std::endl;
						bGamePaused = true;
					}
				}

				pTowers[i]->UpdateEntity();
			}
		}

		// movement
		if (pPlayer)
		{
			auto playerPos = pPlayer->GetPosition();
			auto windowSize = pRender->getSize();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && playerPos.x > 0.f)
			{
				pPlayer->Move(-2.f, 0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && playerPos.x < windowSize.x - pPlayer->GetPlayer()->getSize().x)
			{
				pPlayer->Move(2.f, 0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && playerPos.y > 0.f)
			{
				pPlayer->Move(0.f, -2.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && playerPos.y < windowSize.y - pPlayer->GetPlayer()->getSize().y)
			{
				pPlayer->Move(0.f, 2.f);
			}
		}

		pPlayer->UpdateEntity();
		UpdateGameBoundaries();
	}
	else
	{

	}

	pRender->display();
}

void CGame::EventHandler()
{
	if (pRender == nullptr)
	{
		return;
	}

	while (pRender->pollEvent(pEventHandler->event))
	{
		if (pEventHandler->IsWindowClosed())
		{
			pRender->close();
		}
		if (pEventHandler->IsWindowResized())
		{
			sf::FloatRect visibleArea(0, 0, pEventHandler->event.size.width, pEventHandler->event.size.height);
			pRender->setView(sf::View(visibleArea));
		}
		if (pEventHandler->HasWindowLostFocus())
		{
			bGamePaused = true;
		}
		if (pEventHandler->HasWindowGainedFocus())
		{
			bGamePaused = false;
		}
		if (pEventHandler->IsKeyPressed(sf::Keyboard::Escape))
		{
			bGamePaused = !bGamePaused;
		}
		if (!bGamePaused && pEventHandler->IsMouseButtonPressed(sf::Mouse::Button::Left))
		{
			CTower* pTowerNew = new CTower(pRender, sf::Vector2f(20.f, 20.f));
			pTowers.push_back(pTowerNew);

			for (CTower* tower : pTowers)
			{
				if (tower->pTower->getGlobalBounds().contains((sf::Vector2<float>)sf::Mouse::getPosition(*pRender)))// || 
					//tower->pTower->getGlobalBounds().contains(pTowerNew->GetPosition()))
				{
					std::cout << "exists already" << std::endl;
					pTowers.pop_back();
					delete pTowerNew;
					return;
				}
			}
						
			pTowerNew->SetPosition(sf::Mouse::getPosition(*pRender).x, sf::Mouse::getPosition(*pRender).y);
			pTowerNew->CreateProjectile();
		}
	}
}

void CGame::CreateGameBoundaries()
{
	if (pRender == nullptr)
	{
		return;
	}

	std::cout << "Creating boundaries..." << std::endl;

	auto windowSize = pRender->getSize();
	auto colorWhite = sf::Color(255, 255, 255, 255);

	sf::RectangleShape* boundaryTop = new sf::RectangleShape(sf::Vector2<float>(pRender->getSize().x, 1.f));
	sf::RectangleShape* boundaryRight = new sf::RectangleShape(sf::Vector2<float>(1.f, pRender->getSize().y));
	sf::RectangleShape* boundaryBottom = new sf::RectangleShape(sf::Vector2<float>(pRender->getSize().x, 1.f));
	sf::RectangleShape* boundaryLeft = new sf::RectangleShape(sf::Vector2<float>(1.f, pRender->getSize().y));

	boundaryTop->setPosition(0.f, 0.f);
	boundaryTop->setFillColor(colorWhite);

	boundaryRight->setPosition(windowSize.x - 1.f, 0.f);
	boundaryRight->setFillColor(colorWhite);

	boundaryBottom->setPosition(0.0f, windowSize.y - 1.f);
	boundaryBottom->setFillColor(colorWhite);

	boundaryLeft->setPosition(0.f, 0.f);
	boundaryLeft->setFillColor(colorWhite);

	boundaries.push_back(boundaryTop);
	boundaries.push_back(boundaryRight);
	boundaries.push_back(boundaryBottom);
	boundaries.push_back(boundaryLeft);
}

void CGame::UpdateGameBoundaries()
{
	for (auto boundary : boundaries)
	{
		if (boundary)
		{
			pRender->draw(*boundary);
		}
	}
}

void CGame::DeleteGameBoundaries()
{
	for (auto boundary : boundaries)
	{
		if (boundary)
		{
			delete boundary;
		}
	}
}