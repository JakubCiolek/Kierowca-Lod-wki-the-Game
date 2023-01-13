#include "Entity.h"
/// <summary>
/// Konstruktor klasy Entity.
/// </summary>
Entity::Entity()
{
}
/// <summary>
/// Wirtualny destruktor klasy Entity.
/// </summary>
Entity::~Entity()
{
}
void Entity::update()
{
}

void Entity::changedir(RenderWindow* window)
{
}
/// <summary>
/// Metoda zwraca obra�enia obiektu typu Entity.
/// </summary>
int Entity::getDamage()
{
	return damage;
}
/// <summary>
/// Metoda zmniejsza warto�� punkt�w �ycia obiektu typu Entity.
/// <param name="int dmg">ilo�� otrzymanych obra�e�</param>
/// </summary>
void Entity::loseHP(int dmg)
{
	Entityhealth = Entityhealth - dmg;
}
/// <summary>
/// Metoda zwraca punkty �ycia obiektu typu Entity.
/// </summary>
int Entity::getEntityHP()
{
	return this->Entityhealth;
}
/// <summary>
/// Metoda zwraca maksymalne punkty �ycia obiektu typu Entity.
/// </summary>
int Entity::getEntityHPMax()
{
	return this->EntityhealthMax;
}
