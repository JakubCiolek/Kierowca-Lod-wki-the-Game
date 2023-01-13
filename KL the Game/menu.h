#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Button.h"
#include "Game.h"
/// <summary>
///	Implementuje menu gry.
/// 
/// Odpowiada za wyœwietlanie tytu³u i przycisków w menu gry oraz za wykrycie inputu u¿ytkownika, a nastêpnie rozpoczêcie gry(inicalizacjê obiektu typu Game).
/// 
/// <param name="sf::RenderWindow* window;">okno gry</param>
/// <param name="std::unique_ptr<sf::Font> font;">czcionka u¿ywana w menu</param>
/// <param name="sf::Text title;">tekst tytu³u gry</param>
/// <param name="std::vector<Button*> buttons;">przechowuje obiekty typu button</param>
/// <param name="Game* game;">wskaŸnik na obiekt typu game</param>
/// <param name="Texture* menubackground;">tekstura t³a</param>
/// <param name="Sprite* menubackgroundsprite;">sprite t³a</param>
/// </summary>
class menu
{
private:

	sf::RenderWindow* window;
	std::unique_ptr<sf::Font> font;
	sf::Text title;
	std::vector<Button*> buttons;
	Game* game;
	Texture* menubackground;
	Sprite* menubackgroundsprite;

	void initWindow();
	void initTitle();
	void initButtons();

public:
	menu();
	~menu();
	void run();
	void updatePollEvents();
	void update();
	void render();
};

