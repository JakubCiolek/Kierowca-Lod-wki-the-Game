#pragma once
#include "GameObject.h"
/// <summary>
///	Implementuje wszelkiego rodzaju pociski w grze.
/// 
/// <param name="Vector2f bulletdir;">kierunek poruszania pocisku</param>
/// <param name="float bulletmovspeed;">prêdkoœæ poruszania pocisku</param>
/// <param name="bool from_boss;">Mówi o tym do kogo nale¿y pocisk(Boss(true)/Player(false))</param>
/// </summary>
class Bullet:
	public GameObject
{
	Vector2f bulletdir;
	float bulletmovspeed;
	bool from_boss;
public:
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed, bool from_boss);
	virtual ~Bullet();
	bool bulletowner();
	virtual void changedir(RenderWindow* window);
	virtual void update();
};

