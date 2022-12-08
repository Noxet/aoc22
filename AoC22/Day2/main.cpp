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
			// ROCK
			{ "A", 3 + 1 },
			{ "B", 0 + 1 },
			{ "C", 6 + 1 }
		}
	},
	{
		"Y", {
			// PAPER
			{ "A", 6 + 2 },
			{ "B", 3 + 2 },
			{ "C", 0 + 2 }
		}
	},
	{
		"Z", {
			// SCISSORS
			{ "A", 0 + 3 },
			{ "B", 6 + 3 },
			{ "C", 3 + 3 }
		}
	}
};

/* [Opponent][Strategy]<Player choice>
 *	X = Loose
 *	Y = Draw
 *	Z = Win
 */
map<string, map<string, string>> g_strategy = {
	{
		"A", {
			{ "X", "Z" },
			{ "Y", "X" },
			{ "Z", "Y" }
		}
	},
	{
		"B", {
			{ "X", "X" },
			{ "Y", "Y" },
			{ "Z", "Z" }
		}
	},
	{
		"C", {
			{ "X", "Y" },
			{ "Y", "Z" },
			{ "Z", "X" }
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


void part2(ifstream &ifs)
{
	string in{};
	string opponent, player;

	int score{ 0 };
	while (getline(ifs, in))
	{
		stringstream ss(in);
		ss >> opponent >> player;
		// choose what to play based on the forced strategy
		score += g_outcome[g_strategy[opponent][player]][opponent];
	}

	cout << "Part 2: " << score << endl;
}


int main()
{
	ifstream ifs{ "input.txt" };
	part1(ifs);

	ifs.clear();
	ifs.seekg(0);

	part2(ifs);
}
