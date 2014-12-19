/*
ID: andreic4
PROG: lgame
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
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "lgame.in" 
#define OUTFILE "lgame.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int val[32] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};

set<string> dic;
set<string> rez;
int n;
int max_sc = 0;
char word[8];
bool v[8] = {0};
char letters[16];
string let[2];

void read_dict()
{
  FILE* fi = fopen("lgame.dict", "r");
  char buf[8];
  fscanf(fi, "%s", buf);
  while( buf[0]!='.' )
  {
    dic.insert(buf);
    fscanf(fi, "%s", buf);
  }
}

void add(string c)
{
  string a = letters;
  if( a.find(c) == 0 )
  {
    rez.insert( letters );
  } 
  else 
  {
    a = a.substr(0, a.find(' '));
    if( a>c )
      rez.insert(c + " " + a);
    else
      rez.insert(a + " " + c);
  }
}

void back(int i, int score, string c)
{
  if( i<8 )
  {
    REP(j, 7)
      if( v[j]==0 )
      {
        v[j] = 1;
        letters[i] = word[j];
        score += val[ word[j]-int('a') ];
        if( c.sz >= 2 )
        {
          if( dic.find(c + word[j])!=dic.end() )
          {
            if( score>max_sc )
            {
              max_sc = score;
              rez.clear();
              add(c + word[j]);
            }
            else if( score==max_sc )
            {
              add(c + word[j]);
            }
            if( i<4 )
            {
              letters[i+1] = ' ';
              back(i+2, score, "");
            }
          }
        }
        back(i+1, score, c+word[j]);
        letters[i] = '\0';
        score -= val[ word[j]-int('a') ];
        v[j] = 0;
      }
  }
}

int main()
{
  read_dict();
  string w;
  fin >> w;
  //SORT(w);
  n = w.size();
  REP(i, n)
    word[i] = w[i];

  back(0, 0, "");

  fout << max_sc << endl;
  for(set<string>::iterator it=rez.begin(); it!=rez.end(); it++)
    fout << (*it) << endl;

	return 0;
}
