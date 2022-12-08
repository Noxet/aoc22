#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;


int priority(const char c)
{
	if (islower(c))
	{
		return c - 'a' + 1;
	}

	return c - 'A' + 27;
}


void part1(ifstream &ifs)
{
	string in{};
	int sum{ 0 };
	while (getline(ifs, in))
	{
		string comp1 = in.substr(0, in.size() / 2);
		string comp2 = in.substr(in.size() / 2, in.size());

		for (const auto &c : comp2)
		{
			if (comp1.find(c) != string::npos)
			{
				sum += priority(c);
				break;
			}
		}
	}

	cout << "Part 1: " << sum << endl;
}


void part2(ifstream &ifs) { }


int main()
{
	ifstream ifs{ "input.txt" };
	part1(ifs);

	ifs.clear();
	ifs.seekg(0);

	part2(ifs);
}
