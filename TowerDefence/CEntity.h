#pragma once

enum class EEntityType
{
	kEntity_Type_Nothing,
	kEntity_Type_Player,
	kEntity_Type_Enemy,
	kEntity_Type_Tower
};

enum class EEntityStatus
{
	kStatus_Unkown,
	kStatus_Alive,
	kStatus_Dead,
};

class CEntity
{
public:
	//virtual							~CEntity() = 0;
	virtual void					CreateEntity() = 0;
	virtual void					DestroyEntity(CEntity* pEntity) = 0;
	virtual void					SetPosition(float x, float y) = 0;
	virtual void					SetPosition(sf::Vector2<float> vec) = 0;
	virtual sf::Vector2<float>		GetPosition() = 0;
	virtual void					Move(sf::Vector2<float> offset) = 0;
	virtual void					Move(float x, float y) = 0;
	virtual EEntityType				GetEntityType() = 0;
	virtual EEntityStatus			GetEntityStatus() = 0;
	virtual bool					GetImmunity() = 0;
	virtual void					UpdateEntity() = 0;

	uint8_t* GetRandomizedRGB()
	{
		uint8_t rgb[3]{};
		rgb[0] = rand() % 255 + 20;
		rgb[1] = rand() % 255 + 20;
		rgb[2] = rand() % 255 + 20;

		return rgb;
	}
};

