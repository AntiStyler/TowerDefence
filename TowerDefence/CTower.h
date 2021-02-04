#pragma once
#include "CEntity.h"

class CTower : public CEntity
{
public:
	CTower();
	CTower(sf::RenderWindow* pRender, sf::Vector2<float> size, sf::Color color = sf::Color(255, 255,255));
	~CTower();

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

	void					CreateProjectile();
	sf::CircleShape*		GetProjectile();
	void					DrawProjectile();

	sf::RectangleShape*		pTower;
private:
	CEntity*				pEntity;
	sf::RenderWindow*		pRender;

	sf::CircleShape*		pProjectile;

	sf::Vector2<float>		vecSize;
	sf::Color				color;
	sf::Vector2<float>		vecPosition;
};

