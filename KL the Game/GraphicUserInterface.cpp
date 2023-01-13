#include "GraphicUserInterface.h"
#include <string>
#include <iostream>
#include <sstream>
#include <filesystem>
/// <summary>
/// Konstruktor klasy GraphicUserInterface.
/// 
/// Inicjalizuje zmmienne klasy. Wczytyuje czcionkê i inicjalizuje licznik punktów i specjalnych ataków. Ustawia pozycjê, rozmiar, kolor pasków zdrowia. Wczytuje tekstury,tworzy sprite paneli i ustawia ich pozycjê.
/// 
/// </summary>
GraphicUserInterface::GraphicUserInterface(RenderWindow* window)
{
	//Load font
	if (!this->font.loadFromFile("Fonts/Moon Light.otf"))
		std::cout << "failed to laod font" << "\n";
	//Init point text
	this->pointText.setPosition(window->getSize().x - 145.f, window->getSize().y - 560.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::White);

	//Init specialattack text
	this->attackText.setPosition(window->getSize().x - 145.f, window->getSize().y - 590.f);
	this->attackText.setFont(this->font);
	this->attackText.setCharacterSize(20);
	this->attackText.setFillColor(sf::Color::White);


	//Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(50.f, 400.f));
	this->playerHpBar.setFillColor(sf::Color(232, 108, 46, 255));
	this->playerHpBar.setPosition(sf::Vector2f(window->getSize().x - 50.f, window->getSize().y - 20.f));
	this->playerHpBar.setRotation(180.f);

	this->bossHpBar.setSize(sf::Vector2f(700.f, 20.f));
	this->bossHpBar.setFillColor(sf::Color(23, 226, 93, 255));
	this->bossHpBar.setPosition(sf::Vector2f(50.f, 20.f));

	//init panels
	std::string path = "Textures/GUI";
	int i = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		std::cout << entry.path() << "\n";
		this->panelsTex.push_back(new Texture);
		this->panelsTex[i]->loadFromFile(entry.path().string());
		Sprite* panel = new Sprite;
		this->panelsSpr.push_back(panel);
		i++;
	}
	for (int i = 0; i < panelsSpr.size(); i++)
	{
		this->panelsSpr[i]->setTexture(*this->panelsTex[i]);
	}
	this->panelsSpr[0]->setPosition(0.f, 0.f);
	this->panelsSpr[1]->setPosition(910.f, 0.f);

}

/// <summary>
/// Destruktor klasy GraphicUserInterface.
/// 
/// Zwalnia pamiêæ przy usuwaniu obiektu.
/// 
/// </summary>
GraphicUserInterface::~GraphicUserInterface()
{
	for (auto& i : this->panelsSpr)
	{
		delete i;
	}
	for (auto& i : this->panelsTex)
	{
		delete i;
	}
}

/// <summary>
/// Metoda wyœwietlaj¹ca pasek ¿ycia Bossa.
/// 
/// <param name="RenderWindow* window">wskaŸnik na okno gry</param> 
/// 
/// </summary>
void GraphicUserInterface::renderBossBar(RenderWindow* window)
{
	window->draw(this->bossHpBar);
}

/// <summary>
/// Metoda wyœwietlaj¹ca pasek ¿ycia Bossa.
/// 
/// <param name="int PlayerHP">aktualne punkty ¿ycia gracza</param> 
/// <param name="int PlayerHPMax">Maksymalne punkty ¿ycia gracza</param>
/// <param name="long points">aktualnia iloœæ punktów</param>
/// <param name="int specialattack">dostêpne ataki specjalne</param>
/// </summary>
void GraphicUserInterface::update(int PlayerHP, int PlayerHPMax,long points,int specialattack)
{
	std::stringstream ss;

	ss << "Points: " << points;

	this->pointText.setString(ss.str());

	ss.str("");
	ss.clear();

	ss << "NOSCOPE: " << specialattack;

	this->attackText.setString(ss.str());
	//Update player GUI
	float hpPercent = static_cast<float>(PlayerHP) / PlayerHPMax;
	this->playerHpBar.setSize(sf::Vector2f(this->playerHpBar.getSize().x, 400.f * hpPercent));
	
		

}

/// <summary>
/// Metoda aktualizuj¹ca pasek ¿ycia Bossa.
/// 
/// <param name="int BossHP">aktualne punkty ¿ycia bossa</param> 
/// <param name="int BossHPMax">Maksymalne punkty ¿ycia bossa</param> 
/// </summary>
void GraphicUserInterface::updateBossBar(int BossHP, int BossHPMax)
{
	float hpPercent = static_cast<float>(BossHP) / BossHPMax;
	this->bossHpBar.setSize(sf::Vector2f(700.f * hpPercent,this->bossHpBar.getSize().y));
}
/// <summary>
/// Metoda wyœwietlaj¹ca interfejs graficzny.
/// 
/// <param name="RenderWindow* window">wskaŸnik na okno gry</param> 
/// </summary>
void GraphicUserInterface::render(RenderWindow* window)
{
	for (auto& panel : panelsSpr)
	{
		window->draw(*panel);
	}
	window->draw(this->pointText);
	window->draw(this->attackText);
	window->draw(this->playerHpBar);
	
	
}
