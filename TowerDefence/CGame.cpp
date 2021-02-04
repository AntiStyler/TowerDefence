#include "pch.h"
#include "CGame.h"

CGame::CGame(sf::RenderWindow* pRender)
{
	this->pRender = pRender;
	this->pEventHandler = new CEventHandler();
}

void CGame::StartGame()
{
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
		for (int i = 0; i < pTowers.size(); i++)
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

		pPlayer->Move(-0.5f, 0.f);
		pPlayer->UpdateEntity();
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
