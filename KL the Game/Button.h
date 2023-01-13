#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
/// <summary>
///	Implementuje przyciski w menu gry.
/// 
/// <param name="sf::RectangleShape shape;">kszta³t przycisku</param>
/// <param name="sf::Text text;">tekst przycisku</param>
/// <param name="sf::Font* font;">czcionka tekstu przycisku</param>
/// </summary>
class Button
{
private:
	sf::RectangleShape shape;
	sf::Text text;
	sf::Font* font;

public:
	Button(sf::RenderWindow* window, std::string txt, float posY);
	~Button();
	const sf::FloatRect getGlobalBounds() const;
	void render(sf::RenderTarget* target);
};
