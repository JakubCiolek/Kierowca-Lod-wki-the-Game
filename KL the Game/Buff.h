#pragma once
#include "GameObject.h"
/// <summary>
/// Implementuje elementy r�wnowa��ce rozgrywk�.
/// 
/// Implementuje elementy takie jak apteczki, ulepszenia, bronie, wzmocnienia dla gracza.
/// 
/// <param name="Vector2f buffdir;">kieruneki poruszania si� ulepszenia</param>
/// <param name=float buffmovspeed;">szybko�� poruszania si� ulepszenia</param>
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
