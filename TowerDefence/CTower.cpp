#include "pch.h"
#include "CTower.h"

CTower::CTower(sf::RenderWindow* pRender, sf::Vector2<float> size, sf::Color color)
{
	this->pRender = pRender;
	this->vecSize = size;
	this->color = color;

	CreateEntity();
}

CTower::~CTower()
{
	DestroyEntity(pEntity);
}

void CTower::CreateEntity()
{
	pTower = new sf::RectangleShape(this->vecSize);
}

void CTower::DestroyEntity(CEntity* pEntity)
{
	delete pProjectile;
	delete pTower;
	delete pEntity;
}

void CTower::SetPosition(float x, float y)
{
	if (pTower)
	{
		pTower->setPosition(x, y);
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

void CTower::SetPosition(sf::Vector2<float> vec)
{
	if (pTower)
	{
		pTower->setPosition(vec);
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

sf::Vector2<float> CTower::GetPosition()
{
	if (pTower)
	{
		return pTower->getPosition();
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

void CTower::Move(sf::Vector2<float> offset)
{
	if (pTower)
	{
		pTower->move(offset);
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

void CTower::Move(float x, float y)
{
	if (pTower)
	{
		pTower->move(x, y);
	}
	else
	{
		std::cout << "ERROR: player was nullptr." << std::endl;;
	}
}

EEntityType CTower::GetEntityType()
{
	return EEntityType::kEntity_Type_Tower;
}

EEntityStatus CTower::GetEntityStatus()
{
	return EEntityStatus::kStatus_Alive;
}

bool CTower::GetImmunity()
{
	return true;
}

void CTower::UpdateEntity()
{
	if (pTower)
	{
		pRender->draw(*pTower);
	}
	else
	{
		std::cout << "ERROR: tower was nullptr." << std::endl;;
	}
}

void CTower::SetRenderWindow(sf::RenderWindow* pRender)
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

sf::RenderWindow* CTower::GetRenderWindow()
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

void CTower::CreateProjectile()
{
	if (pTower)
	{
		pProjectile = new sf::CircleShape(10.f);
		pProjectile->setFillColor(sf::Color(255, 255, 255, 0));
		pProjectile->setPosition(pTower->getPosition());
	}
}

sf::CircleShape* CTower::GetProjectile()
{
	if (pProjectile)
	{
		return pProjectile;
	}
	else
	{
		std::cout << "ERROR: Projectile was nullptr." << std::endl;
	}
}

void CTower::DrawProjectile()
{
	if (pProjectile)
	{
		pRender->draw(*pProjectile);
	}
	else
	{
		std::cout << "ERROR: Projectile was nullptr." << std::endl;;
	}
}