#include <iostream>
using namespace std;

class Player {
public:
	int level = 1;
	string userName;
	int power = 10, health = 10;
};

class Enemy {
public:
	int level = 1;
	string enemyName = "Enemy";
	int power = 5, health = 5;
};

class Dragon {
public:
	int level = 15;
	string dragonName = "Great Dragon";
	int power = 15;
	int health = 15;

};

void chestFind(Player& player) {
	string openChest;
	cout << "You find chest do you wanna open? (yes,no)" << endl;
	cin >> openChest;
	if (openChest == "yes") {
		cout << "You find +1 power" << endl;
		cout << "Your adventure continue" << endl;
		player.power + 1;

	}
	else if (openChest == "no") {
		cout << "You continue your adventure " << endl;
	}
	else
		cout << "Please enter yes or no." << endl;
}

void dragonFight(Player& player, Dragon& dragon) {
	cout << "Dragon show up" << endl;
	cout << "Dragon want to fight with you" << endl;
	cout << endl << "Fight begin!" << endl;
	if (player.power > dragon.health) {
		dragon.health -= player.power;
		cout << player.userName << " defeated " << dragon.dragonName << endl;
		win(player);
	}
	else {
		player.health -= dragon.power;
		cout << dragon.dragonName << " defeated " << player.userName << endl;
	}
}

void choseDirection(Player& player, Dragon& dragon) {
	string direction;
	cout << endl << "Please chose direction: " << endl;
	cout << "up, right, left " << endl;
	cin >> direction;
	if (direction == "up") {
		cout << endl << "You reach the forest " << endl;
		chestFind(player);
	}
	else if (direction == "left") {
		string dragonWay;
		cout << endl << "You reach the mountain " << endl;
		cout << "You see the dragon flying over the mountain " << endl;
		cout << "Do you wanna fight with dragon? (yes,no) " << endl;
		cin >> dragonWay;
		if (dragonWay == "yes") {
			dragonFight(player,dragon);
		}
		else
			choseDirection(player);
	}
	else if (direction == "right") {
		cout << endl << "You reach the desert" << endl;
	}
	else
		cout << "Please chose up,left or right!" << choseDirection;
}

void win(Player& player) {
	player.power += 1;
	player.health += 1;

	if (player.power >= player.level * 5) {
		++player.level;
		cout << endl << player.userName << " Level up to " << player.level << endl;
	}
	choseDirection(player);
}

void fight(Player& player, Enemy& enemy) {
	cout << enemy.enemyName << " show up" << endl;
	cout << enemy.enemyName << " want to fight with you" << endl;
	cout << endl << "Fight begin!" << endl;
	if (player.power > enemy.health) {
		enemy.health -= player.power;
		cout << player.userName << " defeated " << enemy.enemyName << endl;
		win(player);
	}
	else {
		player.health -= enemy.power;
		cout << enemy.enemyName << " defeated " << player.userName << endl;
	}
}





int main() {
	Player player;
	Enemy enemy;
	cout << "Your goal is reach the lvl 20" << endl;
	cout << "You can chose where do you wanna go and fight with your enemy to lvl up" << endl;
	cout << "Please enter your username: " << endl;
	cin >> player.userName;
	cout << "Welcome the game " << player.userName << " where do you wanna go?" << endl;
	choseDirection(player);

	while (player.level < 20) {
		fight(player, enemy);
		if (player.level > player.level * 5) {
			cout << "Please chose a direction!" << endl;
			choseDirection(player);

		}
	}

	return 0;
}