#include "Game.h"

std::counting_semaphore TexLoaded(0);
/// <summary>
/// Inicjalizuje gracza (obiekt typu Player).
/// 
/// Tworzy nowy obiekt typu Player i ustawia jego pozycjê na ekranie.
/// 
/// </summary>
void Game::initPlayer()
{
	TexLoaded.acquire();
	this->player = new Player();
	this->player->setPosition(this->window->getSize().x / 2 -(this->player->getBounds().width/2) , this->window->getSize().y - 100.f - this->player->getBounds().height);

}

/// <summary>
/// Inicjalizuje wartoœci timerów odnawiania wrogów i ulepszeñ.
/// 
/// </summary>
void Game::initEntities()
{
	TexLoaded.acquire();
	this->spawnTimerMax = 30.0f;
	this->spawnTimer = this->spawnTimerMax;
	this->BuffspawnTimerMax = 60.0f;
	this->BuffspawnTimer = this->BuffspawnTimerMax;
}

/// <summary>
/// Inicjalizuje Bossa (obiekt typu Boss).
/// 
/// Wywo³uje konstruktor klasy Boss i przekazuje niezbêdne wartoœci.
/// 
/// </summary>
void Game::initBoss()
{
	this->boss = new Boss(this->textures["BOSS"],
		this->window->getSize().x / 2,
		70.f,
		-1.f,
		0.f,
		3.f,
		20,
		this->bosstrigger);
}

/// <summary>
/// Konstruktor klasy Game.
/// 
/// Konstruuje obiekt typu Game, inicjalizuje jego zmienne i wywo³uje metody inicjalizuj¹ce zasoy niezbêdne do uruchmienia gry.
/// 
/// </summary>
Game::Game(RenderWindow* window)
{
	std::thread t2([this]() {this->initTextures(); });
	std::thread t1([this]() {this->initAnimation(); });
	std::thread t3([this]() {this->initPlayer(); });
	std::thread t4([this]() {this->initEntities(); });
	std::thread t5([this]() {this->initGUI(); });
	std::thread t6([this]() {this->initWorld(); });
	this->initWindow(window);
	this->phase = phase::one;
	this->ContinueGame = true;
	this->noscopeattack = new GameObject();
	this->noscopeattack->InitSprite();
	this->bossfight = bossfight::off;
	this->bosstrigger = 1000;
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
}

/// <summary>
/// Destruktor klasy Game.
/// 
/// Usuwa wszystkie wskaŸniki i dynamicznie przydzielon¹ pamieæ.
/// 
/// </summary>
Game::~Game()
{
	
	delete this->player;
	delete this->background;
	delete this->backgroundsprite;
	delete this->noscopeattack;
	delete this->gui;
	
	//Delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	for (auto& i : this->noscope)
	{
		delete i;
	}

	//Delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}

	//Delete enemies
	for (auto* i : this->entities)
	{
		delete i;
	}
}

//Private functions

/// <summary>
/// Inicjalizuje okno gry.
/// 
/// <param name="RenderWindow* window">wskaŸnik na okno gry</param>
/// </summary>
void Game::initWindow(RenderWindow* window)
{
	this->window = window;
}

/// <summary>
/// Inicjalizuje i wczytuje tekstury do std::<map>textures.
/// 
/// </summary>
void Game::initTextures()
{
	this->textures["BULLET"] = new Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
	this->textures["ENEMY"] = new Texture();
	this->textures["ENEMY"]->loadFromFile("Textures/enemy.png");
	this->textures["DIAGONALENEMY"] = new Texture();
	this->textures["DIAGONALENEMY"]->loadFromFile("Textures/diagonalenemy.png");
	this->textures["RESTORESTATS"] = new Texture();
	this->textures["RESTORESTATS"]->loadFromFile("Textures/harnas1.png");
	this->textures["FRIDGE2"] = new Texture();
	this->textures["FRIDGE2"]->loadFromFile("Textures/fridge2.png");
	this->textures["FRIDGE3"] = new Texture();
	this->textures["FRIDGE3"]->loadFromFile("Textures/fridge3.png");
	this->textures["BOSS"] = new Texture();
	this->textures["BOSS"]->loadFromFile("Textures/boss.png");
	this->textures["BOSSBULLET"] = new Texture();
	this->textures["BOSSBULLET"]->loadFromFile("Textures/bossbullet.png");
	this->textures["BACKGROUND"] = new Texture();
	this->textures["BACKGROUND"]->loadFromFile("Textures/space.jpg");
	TexLoaded.release();
	TexLoaded.release();
	TexLoaded.release();
	TexLoaded.release();
	TexLoaded.release();

}

/// <summary>
/// Inicjalizuje i wczytuje klatki animacjii do std::vector<Texture> noscope.
/// 
/// U¿ywa directory_iterator aby wczytaæ wszystkie klatki animacji z katalogu.Sprawdza poprawnoœæ nazw plików u¿ywaj¹c regexa.
/// 
/// </summary>
void Game::initAnimation()
{
	TexLoaded.acquire();
	std::regex filename("frame_[0-9][0-9]_delay-0\.04s\.png");
	
	std::string path = "Textures/noscopeframes";
	int framenum = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		
		if (std::regex_search(entry.path().string() ,filename))
		{
			std::cout << entry.path() << "\n";
			this->noscope.push_back(new Texture);
			this->noscope[framenum]->loadFromFile(entry.path().string());
			framenum++;
		}
		
	}
	std::cout << noscope.size() << std::endl;
}
/// <summary>
/// Inicjalizuje graficzny interfejs gry.
/// 
/// Tworzy obiekt klasy GraphicalUserInterface i zapisuje go do zmiennej.
/// 
/// </summary>
void Game::initGUI()
{
	TexLoaded.acquire();
	gui = new GraphicUserInterface(this->window);

}

/// <summary>
/// Inicjalizuje t³o gry.
/// 
/// Tworzy teksturê t³a i j¹ wczytujê nastêpnie tworzy Sprite t³a i go inicjuje.
/// 
/// </summary>
void Game::initWorld()
{
	TexLoaded.acquire();
	this->background = new Texture;
	this->background->loadFromFile("Textures/space.jpg");
	this->backgroundsprite = new Sprite;
	this->backgroundsprite->setTexture(*background);
	
}

//Functions

/// <summary>
/// G³ówna pêtla gry.
/// 
/// Wywo³uje metody update() oraz render() dopóki okno gry jest otwarte i gracz ma dodatnie punkty ¿ycia.
/// 
/// </summary>
void Game::run()
{
	while (this->window->isOpen() && this->ContinueGame)
	{
		this->update();
		this->render();
	}
}

/// <summary>
/// Obs³uguje zamkniêcie okna przez u¿ytkownika.
/// 
/// </summary>
void Game::updatePollEvents()
{
	Event ev;
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == Event::Closed)
		{
			this->window->close();
		}

	}
}

/// <summary>
/// Sprawdza input u¿ytkownika.
/// 
/// Jest odpowiedzialna za poruszanie gracza i strzelanie po wykryciu wciœniêcia odpowiednich klawiszy.
/// Je¿eli gracz strzela tworzy obiekty klasy Bullet.
/// 
/// </summary>
void Game::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (this->player->getBounds().left + this->player->getBounds().width < this->window->getSize().x-150.f)
		{
			this->player->move(1.f, 0.f);
		}
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (this->player->getBounds().left > 0.f)
		{
			this->player->move(-1.f, 0.f);
		}
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (this->player->getBounds().top > 50.f)
		{
			this->player->move(0.f, -1.f);
		}
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		if (this->player->getBounds().top + this->player->getBounds().height < this->window->getSize().y)
		{
			this->player->move(0.f, 1.f);
		}
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Space)&& this->player->canAttack())
	{
		if (this->phase == phase::one)
		{
			this->bullets.push_back(
				new Bullet(
					this->textures["BULLET"],
					this->player->getPos().x,
					this->player->getPos().y,
					0.f,
					-1.f,
					7.f,
					false
				)
			);
		}
		else if (this->phase == phase::two)
		{
			this->bullets.push_back(
				new Bullet(
					this->textures["BULLET"],
					this->player->getPos().x,
					this->player->getPos().y,
					0.f,
					-1.f,
					7.f,
					false
				)
			);
			this->bullets.push_back(
				new Bullet(
					this->textures["BULLET"],
					this->player->getPos().x+51.f,
					this->player->getPos().y,
					0.f,
					-1.f,
					7.f,
					false
				)
			);
		}
		else if (this->phase == phase::three)
		{
			this->bullets.push_back(
				new Bullet(
					this->textures["BULLET"],
					this->player->getPos().x,
					this->player->getPos().y,
					0.f,
					-1.f,
					7.f,
					false
				)
			);
			this->bullets.push_back(
				new Bullet(
					this->textures["BULLET"],
					this->player->getPos().x + 72.f,
					this->player->getPos().y,
					0.f,
					-1.f,
					7.f,
					false
				)
			);
			this->bullets.push_back(
				new Bullet(
					this->textures["BULLET"],
					this->player->getPos().x + 123.f,
					this->player->getPos().y,
					0.f,
					-1.f,
					7.f,
					false
				)
			);
			this->bullets.push_back(
				new Bullet(
					this->textures["BULLET"],
					this->player->getPos().x + 195.f,
					this->player->getPos().y,
					0.f,
					-1.f,
					7.f,
					false
				)
			);
		}
			
	}
}

/// <summary>
/// Aktualizuje rozmiar pasków bossa i gracza.
/// 
/// Wywo³uje metody updateBossBar oraz update dla obiektu klasy GraphicalUserInterface co powoduje aktualizacje ich rozmiaru w zale¿noœci od ¿ycia.
/// 
/// </summary>
void Game::updateGUI()
{
	this->gui->update(this->player->getPlayerHP(), this->player->getPlayerHPMax(),this->points,this->player->getSpecialAttack());
	if (this->bossfight != bossfight::off)
	{
		this->gui->updateBossBar(this->boss->getEntityHP(), this->boss->getEntityHPMax());
	}
}

/// <summary>
/// Aktualizuje obiekty klasy Bullet.
/// 
/// Sprawdza kolizjê pocisków z brzegami obszaru gry - je¿eli taka nast¹pi usuwa te pociski.Wywo³uje metodê changedir() dla pocisków bossa w trakcie walki z nim.
/// 
/// </summary>
void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
		if (this->bossfight != bossfight::off)
		{
			bullet->changedir(this->window);
		}
		// bullet calling top of screen
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin()+counter);
			counter--;
			
		}
		// bullet calling bottom of screen
		else if (bullet->getBounds().top > this->window->getSize().y)
		{
			//delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			counter--;

		}
		counter++;
		
		
		//std::cout << bullets.size() << std::endl;
	}
}
/// <summary>
/// Obs³ugujê walkê w grze.
/// 
/// Wykrywa kolizjê obiektów Bullet z obiektami Entity i usuwa je w przypadku jej nast¹pienia. Podczas walki z bossem wykrywa równie¿ kolizjê pocisków bossa z graczem.
/// W przypadku kolizji pocisku z obiektem w grze wywo³uje metodê loseHP() zadaj¹c¹ obra¿enia trafionemu obiektowi.
/// 
/// </summary>
void Game::updateCombat() 
{
	for (int i = 0; i < this->entities.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->entities[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				//this->points += this->entities[i]->getPoints();
				this->entities[i]->loseHP(player->getDamage());
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

			}
			
		}
		if (entities[i]->getEntityHP() < 1)
		{
			delete this->entities[i];
			this->entities.erase(this->entities.begin() + i);
			enemy_deleted = true;
			points += 100;
		}
	}
	if (this->bossfight != bossfight::off)
	{
		for (size_t k = 0; k < this->bullets.size(); k++)
		{
			if (this->boss->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->boss->loseHP(player->getDamage());
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
			}
			else if (this->player->getBounds().intersects(this->bullets[k]->getBounds())&& bullets[k]->bulletowner())
			{
				this->player->loseHp(10);
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
			}
		}
	}
	
}

/// <summary>
/// Aktualizuje pozycjê i strzelanie bossa.
/// 
/// Wywo³uje metode update() i changedir() klasy Boss (poruszanie siê bossa).
/// Tworzy obiekty Bullet wystrzeliwane z bossa w monencie kiedy timer na to pozwoli. Sprawdza kolizjê gracza z bossem i w przypadku jej wykrycia zadaje obra¿enia graczowi.
/// Je¿eli Boss przejdzie do drugiej fazy zmienia sposób jego strzelania.
/// 
/// </summary>
void Game::updateBoss()
{
	this->boss->update();
	this->boss->changedir(this->window);
	//std::cout << this->boss->getEntityHP() << std::endl;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->bullets.push_back(
				new Bullet(
					this->textures["BOSSBULLET"],
					this->boss->getPos().x,
					this->boss->getPos().y + this->boss->getBounds().height + 10.f,
					0.f,
					1.f,
					7.f,
					true
				)
			);
			this->bullets.push_back(
				new Bullet(
					this->textures["BOSSBULLET"],
					this->boss->getPos().x + this->boss->getBounds().width,
					this->boss->getPos().y + this->boss->getBounds().height + 10.f,
					0.f,
					1.f,
					7.f,
					true
				)
			);
			if (this->bossfight == bossfight::phasetwo)
			{
				this->bullets.push_back(
					new Bullet(
						this->textures["BOSSBULLET"],
						this->boss->getPos().x,
						this->boss->getPos().y + this->boss->getBounds().height + 10.f,
						-1.f,
						1.f,
						5.f,
						true
					)
				);
				this->bullets.push_back(
					new Bullet(
						this->textures["BOSSBULLET"],
						this->boss->getPos().x + this->boss->getBounds().width,
						this->boss->getPos().y + this->boss->getBounds().height + 10.f,
						1.f,
						1.f,
						5.f,
						true
					)
				);
			}
			this->spawnTimer = 0;
		}

		if (player->getBounds().intersects(this->boss->getBounds()))
		{
			this->player->loseHp(100);
		}
	
	if (this->boss->getEntityHP() < this->boss->getEntityHPMax() / 2)
	{
		this->bossfight= bossfight::phasetwo;
	}
}

/// <summary>
/// Tworzy i aktualizuje pozycjê wrogów.
/// 
/// Kiedy spawnTimer na to pozwoli tworzy obiekty Enemy i DiagonalEnemy. Wykrywa kolizjê z doln¹ krawêdzi¹ obszaru gry i usuwa wrogów. 
/// Wywo³uje tez metody update() i changedir() dla obiektów Entity co obs³uguje ich poruszanie siê. 
/// 
/// </summary>
void Game::updateEntities()
{
	if (this->bossfight == bossfight::off)
	{
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			float random = rand() % (this->window->getSize().x - 400);
			this->entities.push_back(new Enemy(this->textures["ENEMY"],
				random,
				20.f,
				0.f,
				-1.f,
				5.f,
				10
			)
			);
			this->entities.push_back(new Enemy(this->textures["ENEMY"],
				random + 100.f,
				20.f,
				0.f,
				-1.f,
				5.f,
				10
			)
			);
			this->entities.push_back(new DiagonalEnemy(this->textures["DIAGONALENEMY"],
				random +200.f,
				20.f,
				-3.f,
				-0.3f,
				4.f,
				10
			)
			);
			this->entities.push_back(new DiagonalEnemy(this->textures["DIAGONALENEMY"],
				random+300.f,
				20.f,
				-3.f,
				-0.3f,
				4.f,
				10
			)
			);
			this->spawnTimer = 0.f;
		}
	}
		unsigned counter = 0;
		for (auto* entity : this->entities)
		{
			entity->update();
			entity->changedir(this->window);
			// bullet calling top of screen
			if (entity->getBounds().top > this->window->getSize().y)
			{

				delete this->entities.at(counter);
				this->entities.erase(this->entities.begin() + counter);
				counter--;

			}
			else if (entity->getBounds().intersects(this->player->getBounds()))
			{
				this->player->loseHp(this->entities.at(counter)->getDamage());
				delete this->entities.at(counter);
				this->entities.erase(this->entities.begin() + counter);
				counter--;
			}
			/*if (entities[counter]->getEntityHP() < 1)
			{
				delete this->entities.at(counter);
				this->entities.erase(this->entities.begin() + counter);
				counter--;
				points += 100;
			}*/
			counter++;
			//std::cout << entities.size() << std::endl;
		}
		this->spawnTimer += 0.5f;
	
	
}

/// <summary>
/// Tworzy i aktualizuje pozycjê apteczek.
/// 
/// Wykrywa kolizjê obiektów Buff z krawêdzi¹ okna i je usuwa. Wykrywa kolizjê z graczem i wywo³uje metodê gainHP() na graczu przywracaj¹c¹ zdrowie.
/// Tworzy obiekty Buff kiedy BuffspawnTimer na to pozwoli.
/// 
/// </summary>
void Game::updateBuffs()
{
	if (this->BuffspawnTimer == this->BuffspawnTimerMax)
	{
		this->buffs.push_back(new RestoreStats(this->textures["RESTORESTATS"],
			rand()%this->window->getSize().x,
			20.f,
			0.f,
			-1.f,
			-3.f
			)
		);
		this->BuffspawnTimer = 0.f;
	}
	unsigned counter = 0;
	for (auto* buff : this->buffs)
	{
		buff->update();
		
		if (buff->getBounds().top > this->window->getSize().y)
		{
			
			delete this->buffs.at(counter);
			this->buffs.erase(this->buffs.begin() + counter);
			counter--;

		}
		else if (buff->getBounds().intersects(this->player->getBounds()))
		{
			this->player->gainHp(this->buffs.at(counter)->getHPUP());
			delete this->buffs.at(counter);
			this->buffs.erase(this->buffs.begin() + counter);
			counter--;
		}
		
		counter++;
		//std::cout << buffs.size() << std::endl;
	}
	this->BuffspawnTimer += 0.5f;
}

/// <summary>
/// G³ówna metoda update()
/// 
/// Metoda wywo³uj¹ca wszystkie metody aktualizuj¹ce stan gry oprócz tego obs³uguje równie¿ fazê gry i ulepszeñ gracza. Liczy punkty.
/// Sprawdza warunek kontynuacji gry (¿ycie gracza wiêksze ni¿ 0).
/// </summary>
void Game::update()
{
	//game loop
	this->updatePollEvents();
	this->updateInput();
	this->player->update();
	this->updateBullets();
	this->updateEntities();
	this->updateBuffs();
	this->updateCombat();
	this->animatenoscope();
	this->updateGUI();
	
		
	
	//std::cout << this->player->getPlayerHP() << std::endl;
	if ((player->getPlayerHP()) < 1)
	{
		this->ContinueGame = false;
	}
	if (this->points >= 1000 && this->phase == phase::one)
	{
		this->player->NextStage(this->textures["FRIDGE2"],player->getPos());
		this->phase = phase::two;
	}
	else if (this->points >= 2000 && this->phase == phase::two)
	{
		this->player->NextStage(this->textures["FRIDGE3"], player->getPos());
		this->phase = phase::three;
	}
	if (this->points >= this->bosstrigger)
	{
		this->bossfight = bossfight::phaseone;
		this->initBoss();
		this->bosstrigger += 10000;
	}
	if (this->bossfight != bossfight::off)
	{
		this->updateBoss();
		if (this->boss->getEntityHP() < 1)
		{
			this->bossfight = bossfight::off;
			this->points += 1000;
			delete this->boss;
		}
	}
	else
	{
		this->points++;
	}
	
	//move player
}
/// <summary>
/// Pozwala na u¿ycie specjalnego ataku.
/// 
/// Wykrywa wciœniecie klawisza specjalnego ataku, a nastêpnie wyœwietla na ekranie animacjê, z której siê on sk³ada.
/// 
/// </summary>
void Game::animatenoscope()
{

	if (Keyboard::isKeyPressed(Keyboard::V))
	{
		if (player->getSpecialAttack() > 0)
		{
			int x = (-1 * ((1280 - this->window->getSize().x) / 2)) - 100;
			int y = (this->window->getSize().y - 720) / 2;
			for (auto* frame : this->noscope)
			{

				this->noscopeattack->getObjShape()->setTexture(*frame);
				this->noscopeattack->getObjShape()->setPosition(x, y);
				//this->noscopeattack->getObjShape()->setPosition(-110,180);
				this->window->clear();
				this->noscopeattack->render(*this->window);
				this->window->display();
			}
			for (auto* entity : this->entities)
			{
				entity->loseHP(5);
			}
			player->updateSpecialAttack(-1);
		}
		
	}
}
/// <summary>
/// G³ówna metoda wyœwietlaj¹ca elementy gry na ekranie,
/// 
/// Wywo³uje wszystkie metody renderuj¹ce obiekty, a nastêpnie wyœwietla je w oknie gry.
/// 
/// </summary>
void Game::render()
{
	this->window->clear();
	//draw stuff
	this->window->draw(*backgroundsprite);
	this->player->render(*this->window);
	
	for (auto* bullet : this->bullets)
	{
		bullet->render(*this->window);
	}
	for (auto* entity : this->entities)
	{
		entity->render(*this->window);
	}
	for (auto* buff : this->buffs)
	{
		buff->render(*this->window);
	}
	this->gui->render(this->window);
	if (this->bossfight != bossfight::off)
	{

		this->boss->render(*this->window);
		this->gui->renderBossBar(this->window);
	}
	
	this->window->display();
}
