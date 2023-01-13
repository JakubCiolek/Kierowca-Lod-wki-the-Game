#include "DiagonalEnemy.h"


/// <summary>
/// Konstruktor klasy DiagonalEnemy.
/// 
/// Konstruuje obiekt typu DiagonalEnemy i inicjalizuje jego zmienne,
/// 
/// <param name="Texture* texture">tekstura wroga</param>
/// <param name="float pos_x">pocz¹tkowa pozycja x</param>
/// <param name="float pos_y">pocz¹tkowa pozycja y</param>
/// <param name="float dir_x">pocz¹tkowy kierunek x</param>
/// <param name="float dir_y">kierunek y</param>
/// <param name="float movement_speed">prêdkoœæ poruszania</param>
/// <param name="int damage">zadawane obra¿enia</param>
/// </summary>
DiagonalEnemy::DiagonalEnemy(Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed,int damage)
{
	this->ObjShape = new Sprite;
	this->ObjShape->setTexture(*texture);
	this->ObjShape->scale(0.1f, 0.1f);
	this->Entitymovspeed = movement_speed;
	this->ObjShape->setPosition(pos_x, pos_y);
	this->EntitytDir.x = dir_x;
	this->EntitytDir.y = dir_y;
	this->damage = damage;
	this->EntityhealthMax = 3;
	this->Entityhealth = EntityhealthMax;
}
/// <summary>
///	Wirtualny destruktor klasy DiagonalEnemy.
/// </summary>
DiagonalEnemy::~DiagonalEnemy()
{
}
/// <summary>
/// Aktualizuje pozycjê obiektów typu DiagonalEnemy.
/// </summary>
void DiagonalEnemy::update()
{
	
	this->ObjShape->move(-1 * this->Entitymovspeed * this->EntitytDir);
}
/// <summary>
/// Zmienia kierunek ruchu w przypadku uderzenia w koniec obszaru gry.
/// 
/// <param name="RenderWindow* window">wskaŸnik na okno gry jest potrzebny do pobrania rozmiaru okna</param>
/// </summary>
void DiagonalEnemy::changedir(RenderWindow* window)
{
	//right window collision
	if (this->getBounds().left + this->getBounds().width >= window->getSize().x-150.f)
	{
		this->EntitytDir.x = this->EntitytDir.x * -1;
	}
	//left window collision
	else if (this->getBounds().left < 0.f)
	{
		this->EntitytDir.x = this->EntitytDir.x * -1;
	}
}

