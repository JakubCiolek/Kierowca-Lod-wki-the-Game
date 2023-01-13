#include "menu.h"
/// <summary>
/// Metoda inicjalizuj�ca okno gry.
/// </summary>
void menu::initWindow()
{
	this->window = new RenderWindow(VideoMode(1060,980), "Kierowca Lodowki:TheGame", Style::Titlebar | Style::Close | Style::Resize);
	//this->window = new RenderWindow(VideoMode((1060, 440), "Kierowca Lodowki:TheGame", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}
/// <summary>
/// Metoda inicjalizuj�ca tytu� gry.
/// </summary>
void menu::initTitle()
{
	this->title.setCharacterSize(60);
	this->title.setFillColor(sf::Color::White);
	this->title.setString("Kierowca Lodowki:THE GAME");
	this->title.setPosition(this->window->getSize().x / 2.f - this->title.getGlobalBounds().width / 2.f, 20.f);
}
/// <summary>
/// Metoda inicjalizuj�ca przyciski w menu.
/// </summary>
void menu::initButtons()
{
	std::string button1txt = "PLAY";
	this->buttons.push_back(new Button(this->window, button1txt, 350.f));
	std::string button3txt = "EXIT";
	this->buttons.push_back(new Button(this->window, button3txt, 850.f));
}
/// <summary>
/// Konstruktor klasy menu.
/// 
/// Tworzy obiekt klasy menu. Ustawia czcionk� tytu�u.
/// </summary>
menu::menu()
{
	this->font = std::unique_ptr<sf::Font>(new sf::Font);
	this->font->loadFromFile("Fonts/Moon Light.otf");

	this->title.setFont(*(this->font));
	this->initWindow();

	//this->game = new Game(this->window);

	this->initTitle();
	this->initButtons();
	this->menubackground = new Texture;
	this->menubackgroundsprite = new Sprite;
	this->menubackground->loadFromFile("Textures/menu.jpg");
	this->menubackgroundsprite->setTexture(*this->menubackground);
}

/// <summary>
/// Destruktor klasy menu.
/// 
/// Zwalnia pamie� zaalokowan� podczas tworzenia menu.
/// 
/// </summary>
menu::~menu()
{
	delete this->window;
	delete this->menubackground;
	delete this->menubackgroundsprite;
	for (size_t i = 0; i < buttons.size(); i++)
	{
		delete buttons[i];
		this->buttons.erase(this->buttons.begin() + i);
	}
}
/// <summary>
/// P�tla aktualizuj�ca menu.
/// </summary>
void menu::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
/// <summary>
/// Metoda wykrywaj�ca wci�niecie przycisk�w.
/// 
/// W zale�no�ci od tego jaki przycisk zostanie wci�ni�ty rozpoczyna gr� lub zamyka okno.
/// </summary>
void menu::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
		if (this->buttons[0]->getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			this->game = new Game(this->window);
			this->game->run();
			delete this->game;
		}
		if (this->buttons[1]->getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			this->window->close();
		}
	}

}
/// <summary>
/// Metoda aktualizuj�ca stan menu.
/// </summary>
void menu::update()
{
	this->updatePollEvents();
}
/// <summary>
/// Metoda wy�wietlaj�ca elementy menu.
/// </summary>
void menu::render()
{
	this->window->clear();
	this->window->draw(*this->menubackgroundsprite);
	this->window->draw(this->title);
	for (auto button : this->buttons)
	{
		button->render(this->window);
	}
	
	this->window->display();	
}