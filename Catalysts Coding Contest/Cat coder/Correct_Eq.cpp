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
#define INFILE ".in" 
#define OUTFILE ".out"

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

ifstream fin (INFILE);
ofstream fout (OUTFILE);

bool eval(string s)
{
	int r = 0;
	int op = 1;
	int eq = 1;
	REP(i, s.SZ)
	{
		if( isdigit(s[i]) )
		{
			int n = 0;
			while( isdigit(s[i]) )
			{
				n = n*10 + (int)s[i] - int('0');
				i++;
			}
			i--;
			r += op * n;
		}
		else if( s[i]=='-' ) op = -1 * eq;
		else if( s[i]=='+' ) op = 1 * eq;
		else if( s[i]=='=' ) {eq = -1;op=-1;}
	}
	cout << s << " " << r << endl;//system("pause");
	if( r && eq==-1 ) return 0;
	return 1;
}

int main()
{
	VVI m(10);
	VVI p(10);
	
	m[6].PB(5);
	m[7].PB(1);
	m[8].PB(0);
	m[8].PB(6);
	m[8].PB(9);
	m[9].PB(3);
	m[9].PB(5);
	
	p[0].PB(8);
	p[1].PB(7);
	p[3].PB(9);
	p[5].PB(6);
	p[5].PB(9);
	p[6].PB(8);
	p[9].PB(8);

	string eq;
	while( fin >> eq )
	{
		bool found = 0;
		REP(i, eq.SZ)
		{
			if( isdigit( eq[i]) && m[int(eq[i]) - int('0')].SZ>0 )
			{
				int nr = int(eq[i]) - int('0');
				char last = eq[i];
				REP(j, m[nr].SZ)
				{
					eq[i] = char(int('0') + m[nr][j]);
					REP(k, eq.SZ)
						if( isdigit(eq[k]) && p[int(eq[k]) - int('0')].SZ>0 )
						{
							int nr2 = int(eq[k]) - int('0');
							char last2 = eq[k];
							REP(l, p[nr2].SZ)
							{
								eq[k] = char( int('0') + p[nr2][l]);
								if( eval(eq) )
								{
									fout << eq << endl;
									found = 1;
									break;
								}
							}
							eq[k] = last2;
							if( found ) break;
						}
						else if( eq[k]=='-' )
						{
							eq[k] = '+';
							if( eval(eq) )
								{
									fout << eq << endl;
									found = 1;
									break;
								}
							eq[k] = '-';
						}
					if( found ) break;
				}
				eq[i] = last;
			}
			if( eq[i]=='+'  )
			{
				char last = eq[i];
				eq[i] = '-';
				REP(k, eq.SZ)
					if( isdigit(eq[k]) && p[int(eq[k]) - int('0')].SZ>0 )
					{
						int nr2 = int(eq[k]) - int('0');
						char last2 = eq[k];
						REP(l, p[nr2].SZ)
						{
							eq[k] = char( int('0') + p[nr2][l]);
							if( eval(eq) )
							{
								fout << eq << endl;
								found = 1;
								break;
							}
						}
						eq[k] = last2;
						if( found ) break;
					}
					else if( eq[k]=='-' )
						{
							eq[k] = '+';
							if( eval(eq) )
								{
									fout << eq << endl;
									found = 1;
									break;
								}
							eq[k] = '-';
						}
				eq[i] = last;
			}
			if( found ) break;
		}
		if( !found )
		REP(i, eq.SZ)
		FOR(j, i+1, eq.SZ)
			if( eq[i]=='-' && eq[j]=='=' )
			{
				eq[i] = '=';
				eq[j] = '-';
				if( eval(eq) )
				{
					fout << eq << endl;
					found = 1;
					break;
				}
				eq[i] = '-';
				eq[j] = '=';
			} else if( eq[i]=='=' && eq[j]=='-' )
			{
				eq[i] = '-';
				eq[j] = '=';
				if( eval(eq) )
				{
					fout << eq << endl;
					found = 1;
					break;
				}
				eq[i] = '=';
				eq[j] = '-';
			}
		
		if( !found ) fout << "not found for " << eq << endl;
	}
	
	return 0;
}