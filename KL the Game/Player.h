#pragma once
#include "Buff.h"
#include "GameObject.h"
/// <summary>
///	Implementuje gracza w grze
/// 
/// Implementuje podstawowe parametry gracza takie jak punkty ¿ycia, obra¿enia, prêdkoœæ poruszania, szybkoœæ ataku etc. 
/// 
/// <param name="Texture* Objtexture;">tekstura gracza</param>
/// <param name="int HP;">punkty ¿ycia gracza</param>
/// <param name="int HPMax;">Maksymalne punkty ¿ycia gracza</param>
/// <param name="int damage;">obra¿enia zadawane przez gracza</param>
/// <param name="int SpecialAttackCount;">iloœæ dostêpnych ataków specjalnych</param>
/// <param name="int SpecialAttackCountMax;">Maksymalna(pocz¹tkowa) iloœæ dostêpnych ataków specjalnych</param>
/// <param name="float movspeed;">prêdkoœæ poruszania gracza</param>
/// <param name="float attackCooldown;">Timer kontrolujacy czêstotliwoœæ strzelania</param>
/// <param name="float attackCooldownMax;">Maksymalna wartoœæ timera strzelania po jej osi¹gnieciu gracz mo¿e wystrzeliæ</param>
/// 
/// </summary>
class Player :
	public GameObject
{
	Texture* Objtexture;
	int HP;
	int HPMax;
	int damage;
	int SpecialAttackCount;
	int SpecialAttackCountMax;

	float movspeed;
	float attackCooldown;
	float attackCooldownMax;

	//std::vector<Buff> BuffsAplied;

	void initVariables();
	
public:
	
	virtual void InitSprite();
	virtual void InitTexture();
	Player();

	virtual ~Player();

	
	//const sf::FloatRect getBounds() const;
	const int& getPlayerHP() const;
	const int& getPlayerHPMax() const;
	void NextStage(Texture* texture,Vector2f pos);
	


	//Modifiers
	void setPosition(const float x, const float y);
	void loseHp(const int value);
	void gainHp(const int value);

	//Functions 
	void move(const float dirX, const float dirY);
	const bool canAttack();
	virtual void update();
	void updateAttack();
	int getDamage();
	int getSpecialAttack();
	void updateSpecialAttack(int a);
};
