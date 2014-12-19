#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("C.dat");

int main()
{
	while(!fin.eof())
	{
		char line[1024];
		fin.getline(line, 1024, '\n');
		cout << line << endl;
	}
	return 0;
}