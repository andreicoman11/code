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
#define INFILE "f.in" 
#define OUTFILE "f.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

void back(int i, string st, string l)
{
	if( i>=l.sz ) fout << st << endl;
	else for(int j=0; j<=st.sz; j++)
	{
		string n = st.substr(0, j) + l[i] + st.substr(j);
		//cout << st << "\t" << st.substr(0, j) << " " << l[i] << " " << st.substr(j) << endl;
		//cout << n << endl;system("pause");
		back(i+1, n, l);
	}
}

int main()
{
	string line;
	bool f = 0;
	while( fin >> line )
	{
		if(f) fout << endl;
		else f = 1;
		cout << line << endl;
		back(1, line.substr(0,1), line);
	}
	
	return 0;
}