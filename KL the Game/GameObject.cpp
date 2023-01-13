#include "GameObject.h"
/// <summary>
/// Inicjalizacja Sprite.
/// </summary>
void GameObject::InitSprite()
{
    this->ObjShape = new Sprite;
}
/// <summary>
/// Konstruktor klasy GameObject.
/// </summary>
GameObject::GameObject()
{
    
}
/// <summary>
/// Wirtualny Destruktor klasy GameObject.
/// </summary>
GameObject::~GameObject()
{
    delete this->ObjShape;
}

void GameObject::update()
{

}
/// <summary>
/// Metoda zwracaj¹ca pozycjê.
/// </summary>
const sf::Vector2f& GameObject::getPos() const
{
    return this->ObjShape->getPosition();
}
/// <summary>
/// Metoda wyœwietlaj¹ca GameObject na ekranie.
/// </summary>
void GameObject::render(RenderTarget& target)
{
    target.draw(*this->ObjShape);
}
void GameObject::changedir(RenderWindow* window)
{
}
/// <summary>
/// Metoda zwracaj¹ca pozycjê.
/// </summary>
const FloatRect GameObject::getBounds() const
{
    return this->ObjShape->getGlobalBounds();
}
/// <summary>
/// Metoda zwracaj¹ca Sprite obiektu.
/// </summary>
Sprite* GameObject::getObjShape()
{
    return this->ObjShape;
}
