#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

#define INFILE "perle.in" 
#define OUTFILE "perle.out"
#define NMAX 10010

char fin[NMAX];

bool get_rez()
{
  int n, aux;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> aux;
    fin[i] = char(aux + int('0'));
  }

  if( n==1 ) return 1;

  stack<char> sir;
  if( (fin[0]=='1' && n<5) || fin[0]=='3' )
    sir.push('C');
  else sir.push('B');

  int j = 0;
  for(;!sir.empty() && j<n; j++)
  {
    char cur = sir.top();
    sir.pop();

    if( isdigit(cur) )
    {
      if( cur!=fin[j] ) return 0;
    }
    else if( cur=='B' )
    {
      switch(fin[j]) {
        case '1':
          sir.push('C');
          sir.push('A');
          sir.push('3');
          sir.push('A');
          break;
        case '2':
          sir.push('B');
          break;
        default:
          return 0;
      }
    }
    else if( cur=='C' )
    {
      switch(fin[j]) {
        case '1':
          sir.push('A');
          sir.push('2');
          break;
        case '2':
          break;
        default:
          sir.push('C');
          sir.push('B');
      }
    }
  }

  if( sir.empty() && j==n ) return 1;
  return 0;
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  int N;
  cin >> N;
  while( N-- )
  {
    cout << get_rez() << "\n";
  }

	return 0;
}
