#include <iostream>
#include<ctime>
#include<cstdlib>
#include "class.h"

using namespace std;

#define W 30
#define H 15

char map[W][H];


//Funzione per mantenere i bordi
void clamp2(int& value, int minValue, int maxValue) {
	if (value <= minValue) {
		value = minValue;
		return;
	}
	if (value >= maxValue) {
		value = maxValue;
		return;
	}
}

char CommandPrompt() {
	char cmd;
	cout << endl << "Insert Command> ";
	cin >> cmd;
	return cmd;
}

void drawMap(Entity hero, Enemy orc, Enemy orc1, Bonus bonus) {
	int life = hero.GetLife();
	int points = hero.GetPoints();
	int power;
	bool be = bonus.GetBe();

	for (int y = -1; y <= H; y++) {
		for (int x = -1; x <= W; x++) {
			if (y == -1 or y == H) {
				cout << '-';
			}
			else if (x == -1 or x == W) {
				cout << '|';
			}
			else if (hero.isAtPos(x, y) && orc.isAtPos(x, y)) {
				cout << hero.GetGlyph();
				life--;
			}
			else if (hero.isAtPos(x, y) && orc1.isAtPos(x, y)) {
				cout << hero.GetGlyph();
				life--;
			}
			else if (hero.isAtPos(x, y) && bonus.isAtPos(x, y)) {
				be = false;
				cout << hero.GetGlyph();
				points += 100;
				power = bonus.GetPower();
			}
			else if (hero.isAtPos(x, y)) {
				cout << hero.GetGlyph();
			}
			else if (orc.isAtPos(x, y)) {
				cout << orc.GetGlyph();
			}
			else if (orc1.isAtPos(x, y)) {
				cout << orc1.GetGlyph();
			}
			else if (bonus.isAtPos(x, y) && be == true) {
				cout << bonus.GetGlyph();
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}

void moving(char cmd, bool running, Entity hero, Enemy orc, Enemy orc1) {
	cmd = CommandPrompt();
	switch (cmd) {
	case 'q':
		running = false;
		break;
	case 'd':
		hero.right();
		orc.move();
		orc1.move();
		break;
	case 'a':
		hero.left();
		orc.move();
		orc1.move();
		break;
	case 'w':
		hero.up();
		orc.move();
		orc1.move();
		break;
	case 's':
		hero.down();
		orc.move();
		orc1.move();
		break;
	}
}
