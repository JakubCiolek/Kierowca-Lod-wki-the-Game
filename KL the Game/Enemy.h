#pragma once
#include "Entity.h"
/// <summary>
///	Implementuje przeciwnika poruszaj¹cego siê pionowo.
/// 
/// Jest roszerzeniem klasy Entity oznaczaj¹cym przeciwnika poruszajcego siê pionowo w dó³.
/// Dziedziczy po klasie Entity podstawowe elementy takie jak punkty ¿ycia, obra¿enia czy szybkoœæ ruchu.
/// </summary>
class Enemy :
    public Entity
{
    
public:
    Enemy(Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed, int damage);
    virtual ~Enemy();
    virtual void update();
    virtual void changedir(RenderWindow* window);

};

