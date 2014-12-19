#include <iostream>
#include <fstream>
using namespace std;

#define pb push_back
#define sz size()
#define LL long long
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "randuri.in" 
#define OUTFILE "randuri.out"
#define MAX 105
ofstream fout (OUTFILE);

char song[MAX][MAX];
char d[MAX][MAX];
int n=0;

int max(int x, int y)
{
  return (x > y ?  x : y);
}

bool getm(int x, int y)
{
  char sub[MAX][MAX] = {0};
  for(int i=1; i<strlen(song[x]); i++)
  for(int j=1; j<strlen(song[y]); j++)
  {
    if( song[x][i-1] == song[y][j-1] )
      sub[i][j] = max(1 + sub[i-1][j-1], max(sub[i-1][j], sub[i][j-1]));
    else
      sub[i][j] = max(sub[i-1][j], sub[i][j-1]);
    if( sub[i][j]>6 )
      return true;
  }

  /*REP(i, strlen(song[x]))
  {
    REP(j, strlen(song[y]))
      cout << sub[i][j] << " ";
    cout << endl;
  }system("pause");*/

  return false;
}

void comp()
{
  for(int j=2; j<n; j++)
  for(int i=0; i+j<n; i++)  
  {
    for(int k=i+1; k<i+j; k++)
    {
      d[i][i+j] = max(d[i][i+j], d[i][k] + d[k][i+j]);
    }
    if( d[i][i+j]==j-2 && getm(i,i+j) )
      d[i][i+j]++;
  }
}

int main()
{
  FILE* fin = fopen(INFILE, "r");
  n = 0;
  while( !feof(fin) )
  {
    fgets(song[n++], MAX, fin);
  }
  n--;

  memset(d, 0, sizeof(d));
  comp();  
  fout << (int)d[0][n-1] << "\n";
  
	return 0;
}
