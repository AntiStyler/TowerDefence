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
	delete pPlayer;
	delete pEntity;
}

void CPlayer::SetPosition(float x, float y)
{
	if (pPlayer)
	{
		pPlayer->setPosition(x, y);
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

void CPlayer::SetPosition(sf::Vector2<float> vec)
{
	if (pPlayer)
	{
		pPlayer->setPosition(vec);
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

sf::Vector2<float> CPlayer::GetPosition()
{
	if (pPlayer)
	{
		return pPlayer->getPosition();
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

void CPlayer::Move(sf::Vector2<float> offset)
{
	if (pPlayer)
	{
		pPlayer->move(offset);
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

void CPlayer::Move(float x, float y)
{
	if (pPlayer)
	{
		pPlayer->move(x, y);
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

EEntityType CPlayer::GetEntityType()
{
	return EEntityType::kEntity_Type_Player;
}

EEntityStatus CPlayer::GetEntityStatus()
{
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
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

void CPlayer::SetRenderWindow(sf::RenderWindow* pRender)
{
	if (pRender)
	{
		this->pRender = pRender;
	}
	else
	{
		std::cout << "ERROR: RenderWindow was nullptr." << std::endl;
	}
}

sf::RenderWindow* CPlayer::GetRenderWindow()
{
	if (pRender)
	{
		return pRender;
	}
	else
	{
		std::cout << "ERROR: RenderWindow was nullptr." << std::endl;
	}
}

sf::RectangleShape* CPlayer::GetPlayer()
{
	if (pPlayer)
	{
		return pPlayer;
	}
}