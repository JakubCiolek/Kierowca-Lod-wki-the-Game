#pragma once
#include "GameObject.h"
/// <summary>
///	Implementuje wszelkiego rodzaju przeciwników w grze.
/// 
/// Dziedziczy po GameObject. Jest klas¹ ogóln¹ dla Boss,DiagonalEnemy i Enemy. Posiada ich wspólne elemnty, które póŸniej s¹ dziedziczone.
/// 
/// <param name="int Entityhealth;">punkty ¿ycia przeciwnika</param>
/// <param name="int EntityhealthMax;">maksymalne(pocz¹tkowe) punkty ¿ycia przeciwnika</param>
/// <param name="Vector2f EntitytDir;">kierunek poruszania przeciwnika</param>
/// <param name="float Entitymovspeed;">prêdkoœæ poruszania przeciwnika</param>
/// </summary>
class Entity:
	public GameObject
{

protected:
	int Entityhealth;
	int EntityhealthMax;
	int damage;
	Vector2f EntitytDir;

	float Entitymovspeed;
	
public:
	

	Entity();
	virtual ~Entity();
	virtual void update();
	virtual void changedir(RenderWindow* window);
	int getDamage();
	void loseHP(int dmg);
	int getEntityHP();
	int getEntityHPMax();

};
