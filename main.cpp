#include <iostream>
#include<ctime>
#include<cstdlib>
#include "class.h"
#include "function.h"
using namespace std;

int main() {

	Position h{ 5, 7 };
	Position o1{ 10, 10 };
	Position o2{ 8, 4 };
	Position b{ 11, 13 };

	Entity hero{ h,'@' };
	Enemy orc{ o1,'z', 1 };
	Enemy orc1{ o2,'x', 2 };
	Bonus bonus{ b, '*', 1 };

	bool running = true;

	while (running) {
		system("cls");

		//stampo la mappa
		drawMap(hero, orc, orc1, bonus);

		if (life == 0) {
			running = false;
			system("cls");
			cout << "GAME OVER!" << endl;
			break;
		}

		if (points > 0 && points % 500 == 0) {
			points = 0;
			life++;
		}

		char cmd = CommandPrompt();

		moving(cmd, running, hero, orc, orc1);

		cout << "POINTS: " << points << endl;
		cout << "LIFE: " << life << endl;
		cout << endl;
	}
	cout << "Legend:" << endl;
	cout << "- q for quit command" << endl;
	cout << "- d for right command" << endl;
	cout << "- a for left command" << endl;
	cout << "- w for up command" << endl;
	cout << "- s for down command" << endl;
	cout << endl;
	cout << "When life goes 0 the game is over" << endl;
	cout << endl;

	return 0;
}