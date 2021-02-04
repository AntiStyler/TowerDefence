#pragma once

namespace Math
{
	template<typename T>
	float GetMagnitude(sf::Vector2<T> vec)
	{
		return sqrt(vec.x * vec.x + vec.y * vec.y);
	}

	template<typename T>
	sf::Vector2<T> GetUnitVector(sf::Vector2<T> vec, float magnitude)
	{
		return sf::Vector2<T>(vec.x / magnitude, vec.y / magnitude);
	}
}