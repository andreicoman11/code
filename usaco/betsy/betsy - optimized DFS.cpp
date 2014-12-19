/*
ID: andreic4
PROG: betsy
LANG: C++
*/
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
#include <queue>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define INFILE "betsy.in" 
#define OUTFILE "betsy.out"
ifstream fin (INFILE);
ofstream fout (OUTFILE);

int b[10][10];
int s[10][10];
int N;
int dx[] = {-1, 1,  0, 0};
int dy[] = { 0, 0, -1, 1};
int total = 0;

void subs(int x, int y)
{
  for(int m=0; m<4; m++)
    s[x+dx[m]][y+dy[m]]--;
}

void adds(int x, int y)
{
  for(int m=0; m<4; m++)
    s[x+dx[m]][y+dy[m]]++;
}

void verifs(int i, int j, int &x, int &y, int &s1)
{
  s1 = 0;
  for(int m=0; m<4; m++)
    if( s[i+dx[m]][j+dy[m]]==1 && b[i+dx[m]][j+dy[m]]==0 && (i+dx[m]!=N || j+dy[m]!=1))
    {
      s1++;
      x = i+dx[m];
      y = j+dy[m];
    }
}

void prints()
{
  FOR(i, 1, N+1)
  {
    FOR(j, 1, N+1)
      cout << b[i][j] << " ";
    cout << "\t\t\t";
    FOR(j, 1, N+1)
      cout << s[i][j] << " ";
    cout << endl;
  }
  system("pause");
}

void back(int i, int j, int nr)
{
  // verify if we just hit a wall
  // and did not color one of the sides
  if( i==N && b[i][j-1]==0 && b[i][j+1]==0 )
    return;
  if( j==N && b[i-1][j]==0 && b[i+1][j]==0 )
    return;
  //prints();
  if( i==N && j==1 )
  {
    if( nr==N*N+1 )
    {
      total++;
      /*FOR(ii, 1, n+1)
      {
        FOR(jj, 1, n+1)
          fout << b[ii][jj] << " ";
        fout << endl;
      }
      fout << endl;*/
    }
  }
  else
  {
    // verif if we have left s=1
    int x, y, s1;
    verifs(i, j, x, y, s1);
    if( s1==1 )
    {
      // put(xn, yn) next
      b[x][y] = nr;
      subs(x, y);
      back(x, y, nr+1);
      b[x][y] = 0;
      adds(x, y);
    }
    else if( s1==0 )
    {
      for(int k=0; k<4; k++)
      {
        x = i+dx[k];
        y = j+dy[k];
        if( b[x][y]==0 )
        {
          b[x][y] = nr;
          subs(x, y);
          back(x, y, nr+1);
          b[x][y] = 0;
          adds(x, y);
        }
      }
    }
  }
}

int main()
{
  fin >> N;
  //N = 5;
  memset(b, -1, sizeof(b));
  FOR(i, 1, N+1)
  FOR(j, 1, N+1)
    b[i][j] = 0;

  // set sums: corners=2, edges=3, middle=4, else=0
  memset(s, 0, sizeof(s));
  FOR(i, 1, N+1)
  FOR(j, 1, N+1)
    s[i][j] = ( (i==N)||(i==1)||(j==1)||(j==N) ? 3 : 4);
  s[1][1] = s[1][N] = s[N][1] = s[N][N] = 2;

  // start with 1,1 update sums, b
  s[1][2] = s[2][1] = 2;
  b[1][1] = 1;
  back(1,1,2);
  fout << total << endl;

	return 0;
}
