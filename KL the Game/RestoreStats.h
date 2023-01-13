#pragma once
#include "Buff.h"
/// <summary>
/// Implementuje apteczkê w grze.
/// 
/// <param name="int hp_up;">Iloœæ odnowionego hp przez apteczkê</param>
/// </summary>
class RestoreStats:
	public Buff
{
	int hp_up;

public:
	RestoreStats(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	int getHPUP();
	virtual ~RestoreStats();
};

