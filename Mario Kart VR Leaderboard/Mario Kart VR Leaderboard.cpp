#include "Includes.h"

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
	initConsole();
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

	vector<int>availableNums =
	{
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		10,
		11,
		12
	};
	
	vector<int>takenNums;
	vector<string>takenNames;
	vector<Player>Entities;

		while (!availableNames.empty())
		{
			int index = rand() % availableNames.size();
			int place = rand() % availableNums.size();
			int score = rand() % 9700 + 1000;

			takenNames.push_back(availableNames[index]);
			availableNames.erase(availableNames.begin() + index);

			takenNums.push_back(availableNums[place]);
			availableNums.erase(availableNums.begin() + place);

			player.name = takenNames.back();
			player.VR = score;
			player.position = takenNums.back();

			Entities.push_back(player);
		}

		sort(Entities.begin(), Entities.end(), byPos);

		for (size_t i = 0; i < Entities.size(); i++)
		{
			if (Entities[i].position == 1) cout << gold << "#" << Entities[i].position << reset << " " << Entities[i].name << " " << Entities[i].VR << endl;
			else if (Entities[i].position == 2) cout << silver << "#" << Entities[i].position << reset << " " << Entities[i].name << " " << Entities[i].VR << endl;
			else if (Entities[i].position == 3) cout << bronze << "#" << Entities[i].position << reset << " " << Entities[i].name << " " << Entities[i].VR << endl;

			if (Entities[i].position == 1 || Entities[i].position == 2 || Entities[i].position == 3) continue;

			cout << "#" << Entities[i].position << " " << Entities[i].name << " " << Entities[i].VR << endl;
		}
		getKey();
		return 0;
}