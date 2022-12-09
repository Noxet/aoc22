#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <set>

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


void part2(ifstream &ifs)
{
	constexpr int GROUP_SIZE = 3;
	int sum{ 0 };

	while (!ifs.eof())
	{
		// assume all characters have been seen before
		vector<bool> seen(52, true);


		for (int i = 0; i < GROUP_SIZE; ++i)
		{
			vector<bool> mark(52, false);
			string in{};
			getline(ifs, in);
			for (const auto &c : in)
			{
				// if seen before, mark it
				if (seen.at(priority(c) - 1)) mark.at(priority(c) - 1) = true;
			}

			// update seen with the latest, basically performing a set intersection
			seen = mark;
			//copy(mark.begin(), mark.end(), seen.begin());
		}

		for (size_t i = 0; i < seen.size(); ++i)
		{
			if (seen.at(i))
			{
				sum += i + 1;
			}
		}
	}

	cout << "Part 2: " << sum << endl;
}


int main()
{
	ifstream ifs{ "input.txt" };
	part1(ifs);

	ifs.clear();
	ifs.seekg(0);

	part2(ifs);
}
