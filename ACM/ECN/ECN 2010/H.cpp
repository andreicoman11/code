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
#define INFILE "h.in" 
#define OUTFILE "h.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int divs[512];
int rests[512];

int main()
{
	int b, k;
	int go = 0;
	while( fin >> b )
	{
		if( go ) fout << endl;
		else go = 1;
		int c = 0;
		memset( rests, 0, sizeof(rests));
		memset( divs, 0, sizeof(divs));
		FOR(i, 2, b)
			if( (b-1) % i ==0 ) 
			{
				divs[c++] = i;
				//cout << divs[c-1] << " ";
			}
		//cout << endl; //system("pause");

		fin >> k;
		for(int i=0, a=0; i<k;i++)
		{
			fin >> a;
			//cout << i << " " << a << endl;
			for(int j=0; j<c; j++)
			{
				rests[j] = (rests[j] + a) % divs[j];
				//cout << j << " " << rests[j] << endl;
			}
			//system("pause");
		}

		bool ok = 0;
		REP(i, c)
			if( rests[i]==0 )
			{
				fout << divs[i] << " ";
				ok = 1;
			}
		if( !ok ) fout << "-1";
	}

	
	return 0;
}