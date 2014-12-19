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
//ofstream fout("C.out");

int main()
{
	int N;
	fin >> N;
	while(N--)
	{
		int n;
		fin >> n;
		int a  = n/2;
		int b = n-a;
		long long total = 0;
		total += a*(a-1)/2;
		//cout << a*(a-1)/2 << " ";
		total += b*(b-1)/2;
		//cout << b*(b-1)/2 << " ";
		cout << total << endl;
	}
	return 0;
}