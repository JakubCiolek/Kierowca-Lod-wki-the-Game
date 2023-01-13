#pragma once

#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "DiagonalEnemy.h"
#include "Bullet.h"
#include "Buff.h"
#include "Boss.h"
#include "RestoreStats.h"
#include "GraphicUserInterface.h"
#include <map>
#include <string>
#include <iostream>
#include <filesystem>
#include <thread>
#include <regex>
#include <semaphore>
using namespace sf;
enum class phase { one, two, three };
enum class bossfight { off, phaseone, phasetwo };
/// <summary>
/// Klasa wykorzystywana jako silnik gry.
///
/// Klasa zajmuje siê aktualizowaniem(stanu zdrowia, pozycji) obiektów wyœwietlanych na ekranie(gracza, wrogów). 
/// Zajmuje siê prze³¹czaniem faz gry i ulepszen gracza. Jest odpowiedzialna za wyœwietlanie obiektów na ekranie.
///
/// <param name="RenderWindow* window;">okno gry.</param>
/// <param name="bool ContinueGame;">bool mówi¹cy o tym czy nast¹pi³ koniec gry.</param>																								
/// <param name="std::map<std::string, Texture*>textures;">przechowuje tekstury potrzebne w grze.</param>
/// <param name="std::vector<Texture* > noscope;">przechowuje klatki animacji ataku specjalnego.</param>
/// <param name="std::vector<Bullet*> bullets;">przechowuje obiekty typu Bullet, aktualnie wyœwietlane na ekranie.</param> 
/// <param name="float BuffspawnTimer;">timer umo¿liwiajacy generowanie obiektu Buff na ekranie.</param>
/// <param name="float BuffspawnTimerMax;">maksymalna wartosc timera(wartoœæ BuffSpawnTimer roœnie a¿ uzyska wartoœæ maksymaln¹).</param>
/// <param name="std::vector<Buff*> buffs;">przechowuje obiekty typu Buff, aktualnie wyœwietlane na ekranie.</param>
/// <param name="phase phase;">faza(ulepszeñ lodówki) w jakiej znajduje siê gracz.</param>
/// <param name="bossfight bossfight;">faza gry,  off - walka z normalnymi przeciwnikami phaseone/phasetwo - walka z bossem.</param>
/// <param name="GameObject* noscopeattack;">obiekt klasy GameObject ataku specjalnego wyœwietlany na ekranie podczas jego trwania. Jego tekstura jest stale podmieniana aby uzyskaæ efekt ruchu.</param>
/// <param name="Texture* background;">tekstura t³a.</param>
/// <param name="Sprite* backgroundsprite;">sprite t³a.</param>
/// <param name="GraphicUserInterface* gui;">Obiekt klasy GraphicUserInterface - obs³uguje interfejs graficzny w czasie gry.</param>
/// <param name="long points;">punkty zdobyte przez gracza.</param>
/// <param name="long bosstrigger;">iloœæ punktów, przy której rozpocznie siê walka z bossem.</param>
/// <param name="Player* player;">przechowuje obiekt typu Player.</param>
/// <param name="Entity* boss;">przechowuje obiekt typu Boss.</param>
/// <param name="float spawnTimer;">timer umo¿liwiajacy generowanie obiektu Buff na ekranie.</param>
/// <param name="float spawnTimerMax;">maksymalna wartosc timera(wartoœæ spawnTimer roœnie a¿ uzyska wartoœæ maksymaln¹).</param>
/// <param name="std::vector<Entity*> entities;">przechowuje obiekty typu enitity (enemy, diagonalenemy)</param>
/// </summary>
class Game
{

private:
	//Window
	RenderWindow* window;
	bool ContinueGame;
	////Resources
	std::map<std::string, Texture*> textures;
	std::vector<Texture* > noscope;
	std::vector<Bullet*> bullets;
	float BuffspawnTimer;
	float BuffspawnTimerMax;
	std::vector<Buff*> buffs;
	phase phase;
	bossfight bossfight;
	GameObject* noscopeattack;
	Texture* background;
	Sprite* backgroundsprite;
	////GUI
	GraphicUserInterface* gui;

	////Systems
	long points;
	long bosstrigger;

	////Player
	Player* player;
	Entity* boss;


	//Enemies
	float spawnTimer;
	float spawnTimerMax;

	std::vector<Entity*> entities;

	////Private functions
	void initWindow(RenderWindow* window);
	void initTextures();
	void initAnimation();
	void initGUI();
	void initWorld();
	//void initSystems();

	void initPlayer();
	void initEntities();
	void initBoss();

public:
	Game(RenderWindow* window);
	virtual ~Game();
	void run();
	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateBullets();
	void updateEntities();
	void updateBuffs();
	void updateCombat();
	void updateBoss();
	void update();
	void animatenoscope();
	void render();
};




