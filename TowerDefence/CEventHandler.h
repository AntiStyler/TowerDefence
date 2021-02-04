#pragma once

class CEventHandler
{
public:
	bool IsKeyPressed(sf::Keyboard::Key key);
	sf::Keyboard::Key GetPressedKey();
	bool IsMouseButtonPressed(sf::Mouse::Button mouseButton);
	sf::Mouse::Button GetPressedMouseButton();
	bool IsWindowClosed();
	bool IsWindowResized();
	bool HasWindowLostFocus();
	bool HasWindowGainedFocus();

	sf::Event event;
};

