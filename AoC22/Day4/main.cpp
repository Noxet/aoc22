#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <sstream>

using namespace std;


struct Section
{
	unsigned int from;
	unsigned int to;
};


using func = function<bool(const Section &, const Section &)>;


ostream& operator<<(ostream &out, const Section &s)
{
	out << s.from << "-" << s.to;
	return out;
}


inline bool fullyContained(const Section &a, const Section &b)
{
	return (a.from >= b.from && a.to <= b.to) || (b.from >= a.from && b.to <= a.to);
}


inline bool partiallyContained(const Section &a, const Section &b)
{
	return !((a.from < b.from && a.to < b.from) || (b.from < a.from && b.to < a.from));
}


void solution(ifstream &ifs, const func &f)
{
	string in{};
	int sum{ 0 };
	while (getline(ifs, in))
	{
		stringstream ss{ in };
		unsigned int a, b;
		char ignore;

		ss >> a >> ignore >> b;
		Section s1{ a, b };

		// skip the comma, read a, skip the "-", read b
		ss >> ignore >> a >> ignore >> b;
		Section s2{ a, b };

		if (f(s1, s2)) ++sum;
	}

	cout << sum << endl;
}


int main()
{
	ifstream ifs{ "input.txt" };
	cout << "Part 1:" << endl;
	solution(ifs, fullyContained);

	ifs.clear();
	ifs.seekg(0);

	cout << "Part 2:" << endl;
	solution(ifs, partiallyContained);
}
