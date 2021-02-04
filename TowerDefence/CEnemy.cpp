#include "pch.h"
#include "CEnemy.h"

void CEnemy::SetPosition(float x, float y)
{

}

void CEnemy::SetPosition(sf::Vector2<float> vec)
{

}

sf::Vector2<float> CEnemy::GetPosition()
{
	return sf::Vector2<float>(1.f, 1.f);
}

EEntityType CEnemy::GetEntityType()
{
	return EEntityType::kEntity_Type_Enemy;
}

EEntityStatus CEnemy::GetEntityStatus()
{
	return EEntityStatus::kStatus_Alive;
}

bool CEnemy::GetImmunity()
{
	return true;
}

void CEnemy::UpdateEntity()
{
	
}

void CEnemy::SetRenderWindow(sf::RenderWindow* pRender)
{
	this->pRender = pRender;
}

sf::RenderWindow* CEnemy::GetRenderWindow()
{
	return pRender;
}
