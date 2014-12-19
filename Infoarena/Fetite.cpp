#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

ifstream fin ("fetite.in");
ofstream fout ("fetite.out");

unsigned long long int n;

unsigned long long rez(unsigned long long int n)
{
	if( n==1 ) return n;
	else if( n%2==0 ) return rez(n/2)*2-1;
	else return rez((n-1)/2)*2+1;
}

int main()
{
	fin >> n;
	fout << rez(n) << endl;

return 0;
}


