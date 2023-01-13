#include "Player.h"


/// <summary>
/// Inicjalizuje tekstur� gracza.
/// </summary>
void Player::InitTexture()
{
	this->Objtexture = new Texture;
	if (!this->Objtexture->loadFromFile("Textures/fridge.png"))
	{
		std::cout << "Player tekstura nie wczytana \n";
	}
	
}

/// <summary>
/// Inicjalizuje zmienne klasy Player.
/// </summary>
void Player::initVariables()
{
	this->HPMax = 100;
	this->movspeed = 7.f;
	this->attackCooldownMax = 5.f;
	this->attackCooldown = this->attackCooldown;
	this->HP = HPMax;
	this->damage = 1;
	this->SpecialAttackCountMax = 5;
	this->SpecialAttackCount = SpecialAttackCountMax;
}

/// <summary>
/// Inicjalizuje sprite gracza.
/// </summary>
void Player::InitSprite()
{
	this->ObjShape = new Sprite;
	this->ObjShape->setTexture(*this->Objtexture);
	this->ObjShape->scale(0.3f, 0.3f);

}
/// <summary>
/// Konstrutor klasy Player.
/// 
/// Wywo�uje metody inicjuj�ce zmienne.
/// 
/// </summary>
Player::Player()
{
	this->initVariables();
	this->InitTexture();
	this->InitSprite();
}

/// <summary>
/// Destruktor klasy Player.
/// 
/// Zwalnia poprzednio zalokowan� pamie�.
/// 
/// </summary>
Player::~Player()
{
	delete this->Objtexture;
}


/// <summary>
/// Metoda zwraca punkty �ycia gracza.
/// </summary>
const int& Player::getPlayerHP() const
{
	return this->HP;
}

/// <summary>
/// Metoda zwraca maksymalne punkty �ycia gracza.
/// </summary>
const int& Player::getPlayerHPMax() const
{
	return this->HPMax;
}

/// <summary>
/// Metoda ulepszaj�ca gracza.
/// 
/// Metoda wczytuje now� tekstur� gracza. Upewnia si� aby zosta� na tej samej pozycji.
/// 
/// <param name="Texture* texture">tekstura do wczytania</param>
/// <param name="Vector2f pos">pozycja gracza w chwili ulepszenia</param>
/// 
/// </summary>
void Player::NextStage(Texture* texture, Vector2f pos)
{
	delete this->ObjShape;
	this->ObjShape = new Sprite;
	this->ObjShape->setTexture(*texture);
	this->ObjShape->scale(0.3f, 0.3f);
	this->ObjShape->setPosition(pos);
}
/// <summary>
/// Metoda ustawia pozycj� gracza
/// 
/// <param name="const float x">pozycja x</param>
/// <param name="const float y">pozycja y</param>
/// 
/// </summary>
void Player::setPosition(const float x, const float y)
{
	this->ObjShape->setPosition(x, y);
}
void Player::loseHp(const int value)
{
	this->HP = this->HP - value;
}
/// <summary>
/// Metoda dodaj�ca punkty �ycia.
/// 
/// <param name="const int value">ilo�� punkt�w �ycia do odnowienia</param>
/// 
/// </summary>
void Player::gainHp(const int value)
{
	if (this->HP < this->HPMax)
	{
		this->HP = this->HP + value;
	}
	
}
/// <summary>
/// Metoda poruszaj�ca graczem.
/// 
/// <param name="const float dirX">warto�� przesuni�cia w kierunku X</param>
/// <param name="const float dirY">warto�� przesuni�cia w kierunku Y</param>
/// 
/// </summary>
void Player::move(const float dirX, const float dirY)
{
	this->ObjShape->move(this->movspeed*dirX,this->movspeed*dirY);
}
/// <summary>
/// Obs�uguje cooldown ataku gracza.
/// 
/// Zwraca true je�eli  gracz mo�e wystrzeli�. False je�eli attackCooldown nie osi�gn�� warto�ci maksymalnej.
///
/// </summary>
const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}
/// <summary>
/// Metoda aktualizuj�ca gracza.
/// </summary>
void Player::update()
{
	this->updateAttack();
	
}
/// <summary>
/// Metoda timer strzelania gracza.
/// </summary>
void Player::updateAttack()
{
	
	if (this->attackCooldown< this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}

}
/// <summary>
/// Metoda zwracaj�ca obra�enia zadawane przez gracza.
/// </summary>
int Player::getDamage()
{
	return this->damage;
}
/// <summary>
/// Metoda zwracaj�ca ilo�� dost�pnych atak�w specjalnych.
/// </summary>
int Player::getSpecialAttack()
{
	return this->SpecialAttackCount;
}
/// <summary>
/// Metoda akutualizuje ilo�� dost�pnych atak�w specjalnych.
/// </summary>
void Player::updateSpecialAttack(int a)
{
	this->SpecialAttackCount = SpecialAttackCount + a;
	if (this->SpecialAttackCount > this->SpecialAttackCountMax)
	{
		this->SpecialAttackCount = this->SpecialAttackCount;
	}
}
