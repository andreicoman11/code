#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define LL long long
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "reactii.in" 
#define OUTFILE "reactii.out"
#define MAX 15000
ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, m, scur;
int s[MAX][2];

void verif()
{
  /*for(int i=0; i<=scur; i++)
  {
    cout << s[i][0] << "-" << s[i][1] << " ";
  }cout << endl;*/
  if( scur>0 )
  {
    if( s[scur][0]-1 == s[scur-1][1] )
    {
      s[scur-1][1] = s[scur][1];
      scur--;
      verif();
    }
    else if( s[scur][1]+1 == s[scur-1][0] )
    {
      s[scur-1][0] = s[scur][0];
      scur--;
      verif();
    }
  }
}

int main()
{
  fin >> n >> m;
  while(m--)
  {
    int aux;
    scur = -1;
    for(int i=0; i<n; i++)
    {
      fin >> aux;
      scur++;
      s[scur][0] = s[scur][1] = aux;
      verif();
    }//system("pause");
    if( scur>0 ) fout << "0\n";
    else          fout << "1\n";
  }
	
	return 0;
}