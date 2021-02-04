#pragma once
#include "CEntity.h"

class CEnemy : public CEntity
{
public:
	void					CreateEntity();
	void					DestroyEntity(CEntity* pEntity);
	void					SetPosition(float x, float y);
	void					SetPosition(sf::Vector2<float> vec);
	sf::Vector2<float>		GetPosition();
	void					Move(sf::Vector2<float> offset);
	void					Move(float x, float y);
	EEntityType				GetEntityType();
	EEntityStatus			GetEntityStatus();
	bool					GetImmunity();
	void					UpdateEntity();

	void					SetRenderWindow(sf::RenderWindow* pRender);
	sf::RenderWindow*		GetRenderWindow();

private:
	CEntity* pEntity;
	sf::RenderWindow* pRender;
};
