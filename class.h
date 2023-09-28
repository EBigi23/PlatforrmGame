struct Position {
	int x;
	int y;
};

class Entity {

private:
	Position position_;
	char glyph_;
	int life = 3;
	int points = 0;
	int power = 0;

public:
	Entity(Position& pos, char glyph) {
		position_ = pos;
		glyph_ = glyph;
	}

	void move(int dx, int dy) {
		position_.x += dx;
		position_.y += dy;
		clamp2(position_.x, 0, W - 1);
		clamp2(position_.y, 0, H - 1);
	}

	void up(int amount = 1) { //lo metto già uguale a 1 così sa già di quanto si deve muovere senza che glielo passi ogni volta
		move(0, -amount);
	}
	void down(int amount = 1) {
		move(0, +amount);
	}
	void right(int amount = 1) {
		move(+amount, 0);
	}
	void left(int amount = 1) {
		move(-amount, 0);
	}

	bool isAtPos(int x, int y) {
		return position_.x == x && position_.y == y;
	}

	char GetGlyph() {
		return glyph_;
	}

	int GetLife() {
		return life;
	}

	int GetPoints() {
		return points;
	}

	int GetPower() {
		return power;
	}

	void attacca(); // attacca un nemico
	void raccogliArtefatto(Entity hero, Bonus bonus, bool be) { // raccoglie un artefatto e aumenta la vita del personaggio
		be = bonus.GetBe();
		if (hero.isAtPos(x, y) && bonus.isAtPos(x, y)) {
			be = false;
			cout << hero.GetGlyph();
			hero.GetPoints() += 100;
			hero.GetPower() = bonus.GetPower();
		}
	}
	void subisciDanno(int danno);// diminuisce la vita del personaggio a causa di un nemico
};

class Enemy : public Entity {
private:
	int level;
public:
	Enemy(Position& pos, char glyph, int lvl) : Entity(pos, glyph) {
		this->level = lvl;
	}

	void move() {
		srand(time(NULL));
		char ch = 'a' + rand() % 4;

		switch (ch) {
		case 'a':
			if (level == 1) {
				Entity::up();
			}
			else if (level == 2) {
				Entity::up();
				Entity::up();
			}
			break;
		case 'b':
			if (level == 1) {
				Entity::down();
			}
			else if (level == 2) {
				Entity::down();
				Entity::down();
			}
			break;
		case 'c':
			if (level == 1) {
				Entity::right();
			}
			else if (level == 2) {
				Entity::right();
				Entity::right();
			}
			break;
		case 'd':
			if (level == 1) {
				Entity::left();
			}
			else if (level == 2) {
				Entity::left();
				Entity::left();
			}
			break;
		}
	}

	void attacca(Personaggio& p); // attacca il personaggio
	int getVita(); // restituisce la vita attuale del nemico
	int getDanno(); // restituisce il danno inflitto dal nemico
};

class Bonus : public Entity {
private:
	int level;
	int power;
	bool be;
public:
	Bonus(Position& pos, char glyph, int pwr, bool b = true) : Entity(pos, glyph) {
		this->power = pwr;
		this->be = b;
	}

	int GetPower() {
		if (level == 1) {
			
		}
		
	}

	bool GetBe() {
		return be;
	}
};
