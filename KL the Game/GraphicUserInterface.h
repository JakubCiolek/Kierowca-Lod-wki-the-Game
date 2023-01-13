#pragma once
#include "gameobject.h"
/// <summary>
///	Implementuje graficzny interfejs u�ytkownika w trakcie rozgrywki.
/// 
/// Pozwala na wy�wietlanie takich element�w jak pasek �ycia gracza/bossa, licznika punkt�w, licznika atak�w specjalnych oraz graficznych paneli na g�rze i z boku okna gry.
///
/// <param name="Font font;">Czcionka u�ywana podczas rozgrywki</param>
/// <param name="Text pointText;">tekst wy�wietl�cy licznik punkt�w</param>
/// <param name="Text attackText;">tekst wy�wietl�cy licznik atak�w specjalnych</param>
/// <param name="std::vector<Texture* > panelsTex;">przechowuje tekstury paneli interfejsu</param>
/// <param name="std::vector<Sprite*> panelsSpr;">przechowuje sprite paneli interfejsu</param>
/// <param name="RectangleShape playerHpBar;">kszta�t pasku zdrowia gracza</param>
/// <param name="RectangleShape bossHpBar;">kszta�t pasku zdrowia bossa</param>
/// 
/// </summary>
class GraphicUserInterface
{
private:
	Font font;
	Text pointText;
	Text attackText;
	std::vector<Texture* > panelsTex;
	std::vector<Sprite*> panelsSpr;

	////PlayerGUI
	RectangleShape playerHpBar;
	RectangleShape bossHpBar;
public:
	GraphicUserInterface(RenderWindow* window);
	~GraphicUserInterface();
	void update(int PlayerHP, int PlayerHPMax, long points, int specialattack );
	void updateBossBar(int BossHP, int BossHPMax);
	void render(RenderWindow* window);
	void renderBossBar(RenderWindow* window);
};

