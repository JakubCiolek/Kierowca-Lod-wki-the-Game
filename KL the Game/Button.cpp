#include "Button.h"
/// <summary>
/// Konstruktor klasy Button
/// 
/// Konstruuje obiekt typu Button i inicjalizuje jego zmienne,
/// <param name="RenderWindow* window">wskaŸnik na okno gry jest potrzebny do pobrania rozmiaru okna</param>
/// <param name=" std::string txt">tekst wyœwietlany w przycisku</param>
/// <param name="float posY">pozycja y przycisku</param>
/// </summary>
Button::Button(sf::RenderWindow* window, std::string txt, float posY)
{

	this->shape.setSize(sf::Vector2f(200.f, 100.f));
	this->shape.setPosition(window->getSize().x / 2.f - this->shape.getGlobalBounds().width / 2.f, posY);
	this->shape.setFillColor(sf::Color(255,255,255,0));
	this->font = new sf::Font;
	this->font->loadFromFile("Fonts/Moon Light.otf");

	this->text.setFont(*(this->font));
	this->text.setCharacterSize(40);
	this->text.setFillColor(sf::Color::White);
	this->text.setString(txt);
	this->text.setPosition(this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width / 2 - this->text.getGlobalBounds().width / 2,
		this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height / 2 - this->text.getGlobalBounds().height);
}
/// <summary>
/// Destruktor klasy Button
/// 
/// </summary>
Button::~Button()
{
	delete this->font;
}
/// <summary>
/// Metoda zwracaj¹ca pozycjê obiektu typu Button.
/// 
/// </summary>
const sf::FloatRect Button::getGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}
/// <summary>
/// Metoda wyœwietlaj¹ca obiekty typu Button na ekranie.
/// </summary>
void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}