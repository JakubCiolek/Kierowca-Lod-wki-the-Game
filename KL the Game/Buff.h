#pragma once
#include "GameObject.h"
/// <summary>
/// Implementuje elementy równowa¿¹ce rozgrywkê.
/// 
/// Implementuje elementy takie jak apteczki, ulepszenia, bronie, wzmocnienia dla gracza.
/// 
/// <param name="Vector2f buffdir;">kieruneki poruszania siê ulepszenia</param>
/// <param name=float buffmovspeed;">szybkoœæ poruszania siê ulepszenia</param>
/// </summary>
class Buff:
	public GameObject
{
protected:
	Vector2f buffdir;
	float buffmovspeed;
public:
	virtual ~Buff();
	virtual void update();
	virtual int getHPUP();
};
