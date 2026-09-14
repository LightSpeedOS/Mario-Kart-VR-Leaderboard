#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>

using namespace std;

const int sTier = 7000;
const int aTier = 5000;
const int bTier = 3000;
const int cTier = 1000;

struct Player
{
	string name;
	int VR;
	int position;

};

bool byPos(const Player& a, const Player& b)
{
	return a.position < b.position;
}

auto main() -> int
{
	SetConsoleTitleA("Mario Kart Versus Rating");
	srand(time(0));
	Player player{};

	vector<string>availableNames = 
	{ 
		"Mario",
		"Swoop",
		"Peach",
		"Yoshi",
		"Koopa",
		"Toadette",
		"Shy Guy",
		"Toad",
		"King Boo",
		"Peepa",
		"Birdo",
		"Spike",
	};
	
	vector<string>takenNames;
	vector<Player>Entities;

	while (true)
	{

		//int random = rand() % takenNames.size();
		int score = rand() % 10000 + 1000;
		int place = rand() % 12 + 1;

		while (!availableNames.empty())
		{
			int index = rand() % availableNames.size();
			takenNames.push_back(availableNames[index]);
			availableNames.erase(availableNames.begin() + index);
			player.name = takenNames.back();
			player.VR = score;
			player.position = place;
			Entities.push_back(player);
		}

		sort(Entities.begin(), Entities.end(), byPos);

		for (size_t i = 0; i < Entities.size(); i++)
		{
			cout << "#" << player.position << " " << player.name << " " << player.VR << endl;
		}
	}
}