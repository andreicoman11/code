#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define LL long long
#define sortAll(x) sort(x.begin(), x.end())
#define INFILE "subset2.in" 
#define OUTFILE "subset2.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

LL n, k, res = 1;

int main()
{
	fin >> n >> k;

	res += (n/k) * ((k-1) / 2);

	res += (n%k > ((k-1)/2) ? ((k-1)/2) : (n%k));

	if( k%2==0 && k>2 ) res++;

	fout << res;

	return 0;
}