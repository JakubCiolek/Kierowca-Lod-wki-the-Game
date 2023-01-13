#include "Enemy.h"


/// <summary>
/// Konstruktor klasy Enemy.
/// 
/// Konstruuje obiekt typu Enemy i inicjalizuje jego zmienne,
/// 
/// <param name="Texture* texture">tekstura wroga</param>
/// <param name="float pos_x">pocz¹tkowa pozycja x</param>
/// <param name="float pos_y">pocz¹tkowa pozycja y</param>
/// <param name="float dir_x">pocz¹tkowy kierunek x</param>
/// <param name="float dir_y">kierunek y</param>
/// <param name="float movement_speed">prêdkoœæ poruszania</param>
/// <param name="int damage">zadawane obra¿enia</param>
/// </summary>
Enemy::Enemy(Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed,int damage)
{
	this->ObjShape = new Sprite;
	this->ObjShape->setTexture(*texture);
	this->ObjShape->scale(0.1f, 0.1f);
	this->ObjShape->setPosition(pos_x, pos_y);
	this->Entitymovspeed = movement_speed;
	this->EntitytDir.x = dir_x;
	this->EntitytDir.y = dir_y;
	
	this->damage = damage;
	this->EntityhealthMax = 3;
	this->Entityhealth = EntityhealthMax;
}
/// <summary>
///	Wirtualny destruktor klasy DiagonalEnemy.
/// </summary>
Enemy::~Enemy()
{
}


/// <summary>
/// Aktualizuje pozycjê obiektów typu DiagonalEnemy.
/// </summary>
void Enemy::update()
{
	this->ObjShape->move( -1*this->Entitymovspeed  * this->EntitytDir);
}

void Enemy::changedir(RenderWindow* window)
{
}


