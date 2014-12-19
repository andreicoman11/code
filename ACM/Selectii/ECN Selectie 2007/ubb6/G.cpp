#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

ofstream fout ("G.out");
ifstream fin  ("game.in");
int n;

int main()
{
	fin >> n;
	std::map<string,int> names;
	vector<string> teamnames;

	while(n)
	{
		names.clear();
		teamnames.clear();
		vector< vector<int> > games;
		vector<int> a;
		games.push_back(a);
		games.push_back(a);
		int t[1000] = {0};
		int isgameplayed[1000] = {0};
		
		for(int i=0; i<n; i++)
		{
			string aux;
			fin >> aux;
			names[aux] = i;
			teamnames.push_back( aux );
		}

		for(int i=0; i<n-1; i++)
		{
			string q,w;
			fin >> q >> w;
			games[0].push_back( names[q] );
			games[1].push_back( names[w] );
			t[ names[q] ]++;
			t[ names[w] ]++;
		}

		int p = n-1;
		int round = 1;
		while(p)
		{
			fout << "Round #" << round << "\n";			
			if( p==1 )
			{
				string w1, w2;
				for(int i=0, tt=1; i<n; i++)
					if( t[i]>0 && tt) 
					{
						w1 = teamnames[i];
						tt = 0;
					}
					else w2 = teamnames[i];
				fout << w1 << " defeats " << w2 << "\n";
				fout << "Winner: " << w1 << "\n";
				p--;
			}
			else
			{
				bool x[1000] = {0};
				for(int i=0; i<n && p>1 ; i++)
					if( t[i]==1 && x[i]==0 )
					{
						int cucine = n;
						int gameno = n;
						for(int j=0; j<n-1; j++)
							if( isgameplayed[j]==0 )
						{
							int player1 = games[0][j];
							int player2 = games[1][j];

							if( player1==i && x[player2]==0 && t[player2]>1 && (t[player2]<t[cucine] || cucine==n) )	{ cucine = player2; gameno = j; }
							else if( player2==i && x[player1]==0 && t[player1]>1 && (t[player1]<t[cucine] || cucine==n) )	{ cucine = player1; gameno = j; }
						}
						if( cucine<n )
						{
							isgameplayed[ gameno ] = 1;
							t[cucine]--;
							t[i]-=2;
							fout << teamnames[cucine] << " defeats " << teamnames[i] << "\n";
							p--;
							x[cucine] = x[i] = 1;
						}
					}
				for(int i=0; i<n; i++)
					if( x[i]==0 && t[i]>0 )
						fout << teamnames[i] << " advances with wildcard\n";
				round++;
			}
		}
		fout << "\n";
		fin >> n;
	}

	return 0;
}
