#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

#define PB push_back
#define SZ size()
#define SORT(x) sort(ALL(x))
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "A-small-attempt0.in" 
#define OUTFILE "A-small.out"
#define INFILE2 "A-large.in" 
#define OUTFILE2 "A-large.out"

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

ifstream fin (INFILE2);
ofstream fout (OUTFILE2);

int main()
{
	int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
		int n;
		fin >> n;
		VI last(n,0);
		for(int i=0; i<n; i++)
		{
			string aux;
			fin >> aux;
			int m = 0;
			for(int j=aux.size()-1; j>=0; j--)
				if( aux[j]=='1' ) {m = j;break;}
			last[i] = m;
		}
		//for(int i =0; i<n; i++) cout << last[i] << " "; system("pause");
		int swaps = 0;
		for(int i=0; i<n-1; i++)
			if( last[i]>i )
			{
				int j = i+1;
				for(; last[j]>i; j++);
				
				for(int k = j; k>i; k--)
				{
					int aux = last[k];
					last[k] = last[k-1];
					last[k-1] = aux;
					swaps++;
				}
				//cout << i << "\t";for(int ii =0; ii<n; ii++) cout << last[ii] << " "; system("pause");
			}
	
		fout << "Case #" << r << ": " << swaps << endl;
	}
	
	return 0;
}