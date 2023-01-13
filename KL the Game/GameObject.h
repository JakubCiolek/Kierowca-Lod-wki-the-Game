
#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include<cstdlib>
#include<vector>
//#include <filesystem>
using namespace sf;

/// <summary>
///	Implementuje obiekty znajduj�ce si� na ekranie wymagaj�ce sprite.
/// 
/// Jest klas� og�lna dla prawie wszystkich element�w wy�wietlanych na ekranie.
/// Pozwala na pobranie aktualnych pozycji element�w, zmian� ich kierunku oraz akutalizacje.
///
/// <param name="Sprite* ObjShape;">Sprite wy�wietlanego elementu</param>
/// </summary>
class GameObject
{
protected:		
	Sprite* ObjShape;
	

public:

	virtual void InitSprite();

	GameObject();
	virtual ~GameObject();
	virtual void update();
	const sf::Vector2f& getPos() const;
	void render(RenderTarget& target);
	virtual void changedir(RenderWindow* window);
	const FloatRect getBounds() const;
	Sprite* getObjShape();
};

