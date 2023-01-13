#include "Buff.h"
/// <summary>
/// Wirtualny destruktor klasy Buff.
/// </summary>
Buff::~Buff()
{
}
/// <summary>
/// Aktualizuje pozycjê obiektu typu Buff.
/// </summary>
void Buff::update()
{
	this->ObjShape->move(this->buffmovspeed * this->buffdir);
}
/// <summary>
/// Funkcja polimorficzna do zwracania punktów ¿ycia odnawianych przez Buff.
/// </summary>
int Buff::getHPUP()
{
	return 0;
}
