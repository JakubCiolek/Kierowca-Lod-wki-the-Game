#pragma once
#include "Entity.h"
/// <summary>
///	Implementuje przeciwnika poruszaj�cego si� pionowo.
/// 
/// Jest roszerzeniem klasy Entity oznaczaj�cym przeciwnika poruszajcego si� pionowo w d�.
/// Dziedziczy po klasie Entity podstawowe elementy takie jak punkty �ycia, obra�enia czy szybko�� ruchu.
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

