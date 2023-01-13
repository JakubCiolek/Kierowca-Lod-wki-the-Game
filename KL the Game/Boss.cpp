#include "Boss.h"
/// <summary>
/// Aktualizuje pozycjê bossa na ekranie.
/// 
/// </summary>
void Boss::update()
{
	this->ObjShape->move(-1 * this->Entitymovspeed * this->EntitytDir);
}
/// <summary>
/// Konstruktor klasy Boss.
/// 
/// Konstruuje obiekt typu Boss i inicjalizuje jego zmienne,
/// 
/// <param name="Texture* texture">tekstura gracza</param>
/// <param name="float pos_x">pocz¹tkowa pozycja x</param>
/// <param name="float pos_y">pocz¹tkowa pozycja y</param>
/// <param name="float dir_x">pocz¹tkowy kierunek x</param>
/// <param name="float dir_y">kierunek y</param>
/// <param name="int damage">obra¿enia zadawane przez bossa</param>
/// <param name="long points">punkty w momencie zaczêcia walki z bossem (determinuj¹ iloœæ punktów ¿ycia bossa)</param>
/// </summary>
Boss::Boss(Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed, int damage,long points)
{
	this->ObjShape = new Sprite;
	this->ObjShape->setTexture(*texture);
	this->ObjShape->scale(0.3f, 0.3f);
	this->ObjShape->setPosition(pos_x, pos_y);
	this->Entitymovspeed = movement_speed;
	this->EntitytDir.x = dir_x;
	this->EntitytDir.y = dir_y;
	this->damage = damage;
	this->EntityhealthMax = points/10;
	this->Entityhealth = EntityhealthMax;
}
/// <summary>
/// Wirtualny destruktor klasy Boss.
/// 
/// </summary>
Boss::~Boss()
{
}
/// <summary>
/// Inicjuje Sprite Bossa.
/// 
/// </summary>
void Boss::InitSprite()
{
	this->ObjShape = new Sprite;
	this->ObjShape->scale(0.4f, 0.4f);
}
/// <summary>
/// Zmienia kierunek ruchu w przypadku uderzenia w koniec obszaru gry.
/// <param name="RenderWindow* window">wskaŸnik na okno gry jest potrzebny do pobrania rozmiaru okna</param>
/// </summary>
void Boss::changedir(RenderWindow* window)
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


