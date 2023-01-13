#pragma once
#include "GameObject.h"
/// <summary>
///	Implementuje wszelkiego rodzaju przeciwnik�w w grze.
/// 
/// Dziedziczy po GameObject. Jest klas� og�ln� dla Boss,DiagonalEnemy i Enemy. Posiada ich wsp�lne elemnty, kt�re p�niej s� dziedziczone.
/// 
/// <param name="int Entityhealth;">punkty �ycia przeciwnika</param>
/// <param name="int EntityhealthMax;">maksymalne(pocz�tkowe) punkty �ycia przeciwnika</param>
/// <param name="Vector2f EntitytDir;">kierunek poruszania przeciwnika</param>
/// <param name="float Entitymovspeed;">pr�dko�� poruszania przeciwnika</param>
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
