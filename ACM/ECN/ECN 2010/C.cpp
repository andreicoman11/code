#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "c.in" 
#define OUTFILE "c.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

LL pos = 0;
int a[128] = {0};
int s;

void back(int i, double sum)
{
	if(i>=s)
	{
		if(sum<=1.0) pos++;
	} 
	else
	{
		back(i+1, sum);
		for(int j = 1 ; j<=a[i]; j++)
			if( (double)(j*j)/(double)(a[i]*a[i])+sum<=1.0 )
			{
				back(i+1, (double)(j*j)/(double)(a[i]*a[i])+sum);
				back(i+1, (double)(j*j)/(double)(a[i]*a[i])+sum);
			}

	}
}

int main()
{
	int N;
	fin >> N;
	cout << N << endl;
	while(N--)
	{
		fin >> s;
		memset(a, 0, sizeof(a));
		char c;
		fin >> a[0];
		FOR(i, 1, s)
			fin >> c >> a[i];
		pos = 0;
		back(0, 0);
		fout << pos << endl;
	}

	
	return 0;
}