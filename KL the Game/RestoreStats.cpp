#include "RestoreStats.h"


/// <summary>
/// Konstruktor klasy RestoreStats.
/// 
/// Konstruuje obiekt typu RestoreStats i inicjalizuje jego zmienne,
/// 
/// <param name="Texture* texture">tekstura gracza</param>
/// <param name="float pos_x">pocz�tkowa pozycja x</param>
/// <param name="float pos_y">pocz�tkowa pozycja y</param>
/// <param name="float dir_x">pocz�tkowy kierunek x</param>
/// <param name="float dir_y">kierunek y</param>
/// <param name="float movement_speed">pr�dko�� poruszania</param>
/// 
/// </summary>
RestoreStats::RestoreStats(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->ObjShape = new Sprite;
	this->ObjShape->setTexture(*texture);
	this->ObjShape->scale(0.1f, 0.1f);
	this->ObjShape->setPosition(pos_x, pos_y);
	this->buffdir.x = dir_x;
	this->buffdir.y = dir_y;
	this->buffmovspeed = movement_speed;
	this->hp_up = 10;
}
/// <summary>
/// Metoda zwracaj�ca ilo�� punkt�w �ycia do odnowienia
/// 
/// </summary>
int RestoreStats::getHPUP()
{
	return this->hp_up;
}

RestoreStats::~RestoreStats()
{
}
