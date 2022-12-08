#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

/* [Player][Opponent]<outcome score + shape score> */
map<string, map<string, int>> g_outcome = {
	{
		"X", {
			{ "A", 3 + 1 },
			{ "B", 0 + 1 },
			{ "C", 6 + 1 }
		}
	},
	{
		"Y", {
			{ "A", 6 + 2 },
			{ "B", 3 + 2 },
			{ "C", 0 + 2 }
		}
	},
	{
		"Z", {
			{ "A", 0 + 3 },
			{ "B", 6 + 3 },
			{ "C", 3 + 3 }
		}
	}
};


void part1(ifstream &ifs)
{
	string in{};
	string opponent, player;

	int score{ 0 };
	while (getline(ifs, in))
	{
		stringstream ss(in);
		ss >> opponent >> player;
		score += g_outcome[player][opponent];
	}

	cout << "Part 1: " << score << endl;
}


int main()
{
	ifstream ifs{ "input.txt" };
	part1(ifs);

	ifs.clear();
	ifs.seekg(0);
}
