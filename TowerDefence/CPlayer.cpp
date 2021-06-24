#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer(sf::RenderWindow* pRender, sf::Vector2<float> size, sf::Color color)
{
	this->pRender = pRender;
	this->vecSize = size;
	this->color = color;

	CreateEntity();
}

CPlayer::~CPlayer()
{
	DestroyEntity(pEntity);
	//delete pRender;
}

void CPlayer::CreateEntity()
{
	pPlayer = new sf::RectangleShape(this->vecSize);
	pPlayer->setPosition(900.f, 600.f);
	pPlayer->setFillColor(this->color);
}

void CPlayer::DestroyEntity(CEntity* pEntity)
{
	try
	{
		delete pPlayer;
		delete pEntity;
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}

void CPlayer::SetPosition(float x, float y)
{
	if (pPlayer)
	{
		pPlayer->setPosition(x, y);
		return;
	}

	std::cout << "ERROR: player was nullptr." << std::endl;
}

void CPlayer::SetPosition(sf::Vector2<float> vec)
{
	if (pPlayer)
	{
		pPlayer->setPosition(vec);
		return;
	}

	std::cout << "ERROR: player was nullptr." << std::endl;
}

sf::Vector2<float> CPlayer::GetPosition()
{
	if (pPlayer)
	{
		return pPlayer->getPosition();
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;
		return sf::Vector2<float>(0.f, 0.f);
	}
}

void CPlayer::Move(sf::Vector2<float> offset)
{
	if (pPlayer)
	{
		pPlayer->move(offset);
		return;
	}

	std::cout << "ERROR: player was nullptr." << std::endl;
}

void CPlayer::Move(float x, float y)
{
	if (pPlayer)
	{
		pPlayer->move(x, y);
		return;
	}
	
	std::cout << "ERROR: player was nullptr." << std::endl;
}

EEntityType CPlayer::GetEntityType()
{
	// TODO: Add EntityType Handling
	return EEntityType::kEntity_Type_Player;
}

EEntityStatus CPlayer::GetEntityStatus()
{
	// TODO: Add EntityType Handling
	return EEntityStatus::kStatus_Alive;
}

bool CPlayer::GetImmunity()
{
	return true;
}

void CPlayer::UpdateEntity()
{
	if (pPlayer)
	{
		pRender->draw(*pPlayer);
		return;
	}

	std::cout << "ERROR: player was nullptr." << std::endl;
}

void CPlayer::SetRenderWindow(sf::RenderWindow* pRender)
{
	if (pRender)
	{
		this->pRender = pRender;
		return;
	}

	std::cout << "ERROR: RenderWindow was nullptr." << std::endl;
}

sf::RenderWindow* CPlayer::GetRenderWindow()
{
	if (pRender)
	{
		return pRender;
	}

	std::cout << "ERROR: RenderWindow was nullptr." << std::endl;
	return nullptr;
}

sf::RectangleShape* CPlayer::GetPlayer()
{
	if (pPlayer)
	{
		return pPlayer;
	}

	std::cerr << "ERROR: RenderWindow was nullptr." << std::endl;
	return nullptr;
}