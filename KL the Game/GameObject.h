
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
///	Implementuje obiekty znajduj¹ce siê na ekranie wymagaj¹ce sprite.
/// 
/// Jest klas¹ ogólna dla prawie wszystkich elementów wyœwietlanych na ekranie.
/// Pozwala na pobranie aktualnych pozycji elementów, zmianê ich kierunku oraz akutalizacje.
///
/// <param name="Sprite* ObjShape;">Sprite wyœwietlanego elementu</param>
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

