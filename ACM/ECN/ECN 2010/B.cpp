#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
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
#define INFILE "b.in" 
#define OUTFILE "b.out"

FILE* fin = fopen(INFILE, "r");
FILE* fout = fopen(OUTFILE, "w");

char l1[512], station[64];
map<int, int> m;
char st[12500][64];
int dist[12500][12500] = {0};
int s1, s2, d1, d2, i, j;
int cnt = 0;

int main()
{
	while( !feof(fin) && fgets(l1, 512, fin) )
	{
		//cout << "l= " << l1 << endl;
		if( isalpha(l1[0]) )
		{
			fscanf(fin, "%d %d ", &d1, &s1);
			fgets(station, 64, fin);
			station[ strlen(station)-2 ] = '\0';
			//cout << "new train " << d1 << " " << s1 << " " << station << endl;
			if( m.find(s1)==m.end() )
			{
				memcpy(st[cnt], station, sizeof(station)+1);
				i = cnt;
				m[s1] = cnt;
				cnt++;
			}
			else
			{
				i = m[s1];
			}
			//cout << "first" << s1 << " " << station << " " << i << endl;
			fgets(l1, 512, fin);
		}
		else if( strchr(l1, ':')==NULL )
		{
			//cout << "next " << l1 << endl;
			sscanf(l1, "%d %d", &d2, &s2);

			int c = 0;
			for(; c<strlen(l1); c++)
				if( isalpha(l1[c]) ) break;
			memcpy(station, l1+c, strlen(l1)-c+1);
			station[strlen(station)-1] = '\0';

			if( m.find(s2)==m.end() )
			{
				memcpy(st[cnt], station, sizeof(station)+1);
				j = cnt;
				m[s2] = cnt;
				cnt++;
			}
			else
			{
				j = m[s2];
			}
			//cout << "i=" << i << " j=" << j << " " << dist[i][j] << endl;
			//cout << s2 << " " << st[j] << " " << j << "\t";
			if( dist[i][j]+dist[j][i]==0 ) dist[i][j] = dist[j][i] = abs(d2 - d1);
			else if( dist[i][j]>0 && dist[i][j]!= abs(d1-d2) )
			{
				dist[i][j] = dist[j][i] = -1;
				if( strcmp( st[i], st[j])>0 ) fprintf(fout, "%d %s - %d %s\n", s2, st[j], s1, st[i]);
				else fprintf(fout, "%d %s - %d %s\n", s1, st[i], s2, st[j]);
			}
			//cout << "dist=" << dist[i][j] << endl;
			d1 = d2;
			s1 = s2;
			i = j;
		}
		//cout << "...done\n";
		//if( cnt>=12499 ) {cout<<cnt;exit(0);}
		//system("pause");
	}
	//REP(i, cnt)
	//	cout << "." << st[i] << ".\n";

	return 0;
}