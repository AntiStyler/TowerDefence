#pragma once
#include "CEntity.h"
#include "CTower.h"

class CPlayer : public CEntity
{
public:
	CPlayer();
	CPlayer(sf::RenderWindow* pRender, sf::Vector2<float> size, sf::Color color = sf::Color(255, 255, 255));
	~CPlayer();

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

	sf::RectangleShape*		GetPlayer();

private:
	CEntity*				pEntity;
	sf::RectangleShape*		pPlayer;
	sf::RenderWindow*		pRender;

	sf::Vector2<float>		vecSize;
	sf::Color				color;
	sf::Vector2<float>		vecPosition;

	float					health;
	sf::Vector2<float>		velocity;
};
