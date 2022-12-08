#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using std::cout;
using std::endl;
using std::string;


void part1(std::ifstream &ifs)
{
	string in{};

	int sum{ 0 };
	int max{ 0 };

	while (std::getline(ifs, in))
	{
		if (in.empty())
		{
			if (sum > max) max = sum;
			sum = 0;
			continue;
		}

		sum += std::stoi(in);
	}

	cout << "Part 1: " << max << endl;
}


void part2(std::ifstream &ifs)
{
	std::vector<int> vec{};
	string in{};
	int sum{ 0 };

	while (std::getline(ifs, in))
	{
		if (in.empty())
		{
			vec.push_back(sum);
			sum = 0;
			continue;
		}

		sum += std::stoi(in);
	}

	std::sort(vec.begin(), vec.end(), [](const int i, const int j) { return i > j; });
	const auto result = std::reduce(vec.begin(), vec.begin() + 3);
	cout << "Part 2: " << result << endl;
}


int main()
{
	std::ifstream ifs{ "input.txt" };
	part1(ifs);

	// clear state and rewind
	ifs.clear();
	ifs.seekg(0);

	part2(ifs);
}
