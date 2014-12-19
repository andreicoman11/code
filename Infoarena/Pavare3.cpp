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
#define INFILE "pavare3.in" 
#define OUTFILE "pavare3.out"
#define MAX 151
ifstream fin (INFILE);
ofstream fout (OUTFILE);

int map[MAX][MAX];

int main()
{
  int n, m;
  fin >> n >> m;
  int area = n*m / 2;
  bool swapped = 0;
  if( m>n )
  {
    int aux = n; n = m; m = aux;
    swapped = 1;
  }
  memset(map, 0, sizeof(map));
  int cul = 1;
  for(int i=0; i<n && area; i++)
  for(int j=0; j<m && area; j++)
    if( map[i][j]==0 && j+2<m )
    {
      for(int k=0; k<4; k++)
      {
        map[i+k][j] = cul;
        map[i+k][j+2] = cul+1;
        map[i+k][j+1] = cul;
        if( k%2 ) map[i+k][j+1]++;
      }
      cul += 2;
      area -= 12;
    }

  for(int i=0; i<n; i++)
  for(int j=0; j<m; j++)
    if( map[i][j]==0 )
    {
      map[i][j] = cul;
      if( j+1<m && map[i][j+1]==0 )
        map[i][j+1] = cul;
      else
        map[i+1][j] = cul;
      cul++;
    }
  
  if( !swapped )
    for(int i=0; i<n; i++)
    {
      fout << map[i][0];
      for(int j=1; j<m; j++)
        fout << " " << map[i][j];
      fout << endl;
    }
  else
    for(int i=0; i<m; i++)
    {
      fout << map[0][i];
      for(int j=1; j<n; j++)
        fout << " " << map[j][i];
      fout << endl;
    }
	
	return 0;
}