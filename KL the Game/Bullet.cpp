#include "Bullet.h"
/// <summary>
/// Konstruktor klasy Bullet.
/// 
/// Konstruuje obiekt typu Bullet i inicjalizuje jego zmienne,
/// 
/// <param name="Texture* texture">tekstura gracza</param>
/// <param name="float pos_x">pocz¹tkowa pozycja x</param>
/// <param name="float pos_y">pocz¹tkowa pozycja y</param>
/// <param name="float dir_x">pocz¹tkowy kierunek x</param>
/// <param name="float dir_y">kierunek y</param>
/// <param name="float movement_speed">prêdkoœæ poruszania pocisku</param>
/// <param name="bool from_boss">Informuje o tym kto wystrzeli³ pocisk(Boss(true)/player(false))</param>
/// </summary>
Bullet::Bullet(Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed, bool from_boss)
{
	this->ObjShape = new Sprite;
	this->ObjShape->setTexture(*texture);
	
	this->ObjShape->setPosition(pos_x, pos_y);
	this->bulletdir.x = dir_x;
	this->bulletdir.y = dir_y;
	this->bulletmovspeed = movement_speed;
	this->from_boss = from_boss;
}

/// <summary>
/// Destruktor klasy Bullet.
/// </summary>
Bullet::~Bullet()
{
}
bool Bullet::bulletowner()
{
	return this->from_boss;
}
/// <summary>
/// Zmienia kierunek ruchu w przypadku uderzenia w koniec obszaru gry.
/// <param name="RenderWindow* window">wskaŸnik na okno gry jest potrzebny do pobrania rozmiaru okna</param>
/// </summary>
void Bullet::changedir(RenderWindow* window)
{

	//right window collision
	if (this->getBounds().left + this->getBounds().width >= window->getSize().x-150.f)
	{
		this->bulletdir.x = this->bulletdir.x * -1;
	}
	//left window collision
	else if (this->getBounds().left < 0.f)
	{
		this->bulletdir.x = this->bulletdir.x * -1;
	}
}
/// <summary>
/// Aktualizuje pozycjê obiektu typu Bullet.
/// </summary>
void Bullet::update()
{
	this->ObjShape->move(this->bulletmovspeed * this->bulletdir);
	
}
