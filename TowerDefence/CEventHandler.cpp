#include "pch.h"
#include "CEventHandler.h"

bool CEventHandler::IsKeyPressed(sf::Keyboard::Key key)
{
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == key)
		{
			return true;
		}
	}

	return false;
}

sf::Keyboard::Key CEventHandler::GetPressedKey()
{
	return event.key.code;
}

bool CEventHandler::IsMouseButtonPressed(sf::Mouse::Button mouseButton)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == mouseButton)
		{
			return true;
		}
	}

	return false;
}

sf::Mouse::Button CEventHandler::GetPressedMouseButton()
{
	return event.mouseButton.button;
}

bool CEventHandler::IsWindowClosed()
{
	if (event.type == sf::Event::Closed)
	{
		return true;
	}

	return false;
}

bool CEventHandler::IsWindowResized()
{
	if (event.type == sf::Event::Resized)
	{
		return true;
	}

	return false;
}

bool CEventHandler::HasWindowLostFocus()
{
	if (event.type == sf::Event::LostFocus)
	{
		return true;
	}

	return false;
}

bool CEventHandler::HasWindowGainedFocus()
{
	if (event.type == sf::Event::GainedFocus)
	{
		return true;
	}

	return false;
}