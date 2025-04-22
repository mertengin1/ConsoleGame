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

void menu(Player& player){
	string menuChoise;
	cout << "1: Travel" << endl;
	cout << "2: Rest" << endl;
	cout << "3: Shop" << endl;
	cout << "4: Status" << endl;
	cout << "5: Quit Game" << endl;
	cin >> menuChoise;
	
}


void win(Player& player) {
	player.power += 1;
	player.health += 1;

	if (player.power >= player.level * 5) {
		++player.level;
		cout << endl << player.userName << " Level up to " << player.level << endl;
	}
}

void chestFind(Player& player) {
	string openChest;
	cout << "You find chest do you wanna open? (yes,no)" << endl;
	cin >> openChest;
	if (openChest == "yes") {
		cout << "You open the chest and find power item, your power increase +1" << endl;
		cout << "Your adventure continue" << endl;
		player.power += 1;
	}
	else if (openChest == "no") {
		cout << "You continue your adventure without opening the chest " << endl;
	}
	else {
		cout << "Please enter yes or no." << endl;
	}
}

void dragonFight(Player& player, Dragon& dragon) {
	cout << "Dragon shows up!" << endl;
	cout << "The dragon flies over you and wants to eat you!" << endl;
	cout << endl << "Fight begins!" << endl;
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
	cout << endl << "Please choose direction: " << endl;
	cout << "up, right, left" << endl;
	cin >> direction;
	if (direction == "up") {
		cout << endl << "You reach the forest " << endl;
		cout << "You see the temple in the depths of the forest" << endl;
		cout << "You see the graveyard on the hill" << endl;
		cout << "Which way do you wanna go?" << endl;
		chestFind(player);
	}
	else if (direction == "left") {
		string dragonWay;
		cout << endl << "You reach the mountain " << endl;
		cout << "You see the dragon flying over the mountain " << endl;
		cout << "Do you wanna fight with the dragon? (yes,no) " << endl;
		cin >> dragonWay;
		if (dragonWay == "yes") {
			dragonFight(player, dragon);
		}
	}
	else if (direction == "right") {
		cout << endl << "You reach the desert" << endl;
	}
	else {
		cout << "Please choose up, left or right!" << endl;
	}
}

void fight(Player& player, Enemy& enemy) {
	cout << enemy.enemyName << " shows up!" << endl;
	cout << enemy.enemyName << " wants to fight with you!" << endl;
	cout << endl << "Fight begins!" << endl;
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
	Dragon dragon;

	cout << "Your goal is to reach level 20" << endl;
	cout << "You can choose where you want to go and fight enemies to level up" << endl;
	cout << "Please enter your username: ";
	cin >> player.userName;
	cout << "Welcome to the game, " << player.userName << "! Where do you want to go first?" << endl;

	choseDirection(player, dragon);

	while (player.level < 20) {
		fight(player, enemy);
		choseDirection(player, dragon);
	}

	cout << "Congratulations " << player.userName << "! You reached level 20 and won the game!" << endl;
	return 0;
}
