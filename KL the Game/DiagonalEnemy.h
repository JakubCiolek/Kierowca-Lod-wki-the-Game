#pragma once
#include "Entity.h"
/// <summary>
///	Implementuje przeciwnika poruszaj�cego si� po skosie.
/// 
/// Jest roszerzeniem klasy Entity z dodatkow� metod� pozwalaj�c� na odbicie si� od �ciany i tym samym ruch po skosie bez wychodzenia poza ekran.
/// Dziedziczy po klasie Entity podstawowe elementy takie jak punkty �ycia, obra�enia czy szybko�� ruchu.
/// </summary>
class DiagonalEnemy :
    public Entity
{
public:

    DiagonalEnemy(Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed,int damage);
    virtual ~DiagonalEnemy();
    
    virtual void update();
    virtual void changedir(RenderWindow* window);
};

