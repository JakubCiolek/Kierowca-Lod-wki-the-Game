#pragma once
#include "Entity.h"
/// <summary>
/// Implementuje Bossa w grze.
/// 
/// Obs³uguje bossa w grze. Dziedziczy po klasie Entity podstawowe elementy takie jak punkty ¿ycia, obra¿enia czy szybkoœæ ruchu.
/// 
/// <param name="std::vector<Entity*> entities;">przechowuje obiekty typu enitity (enemy, diagonalenemy)</param>
/// </summary>
class Boss :
    public Entity
{
public:
    virtual void update();
    Boss(Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed, int damage, long points);
    virtual ~Boss();
    virtual void InitSprite();
    virtual void changedir(RenderWindow* window);
   
};

