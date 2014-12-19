#include <iostream>
#include <fstream>
using namespace std;

#define INFILE "lacusta.in" 
#define OUTFILE "lacusta.out"
#define NMAX 256
#define INF 1000000

int n, m;
long long val[NMAX], from[NMAX], to[NMAX];

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  cin >> n >> m;

  for(int j=0; j<m; j++)
  {
    cin >> val[j];
    if( j==0 )  from[j] = INF;
    else        from[j] = val[j] + val[0];
    to[j] = 0;
  }

  for(int i=1; i<n; i++)
  {
    long long minto1 = INF, minto2 = INF;
    for(int j=0; j<m; j++)
    {
      cin >> val[j];
      to[j] = from[j] + val[j];
      if( minto1 > to[j] )
      {
        minto2 = minto1;
        minto1 = to[j];
      }
      else if( minto2 > to[j] )
      {
        minto2 = to[j];
      }
    }

    for(int j=0; j<m; j++)
    {
      if( to[j]==minto1 )
        from[j] = minto2 + val[j];
      else
        from[j] = minto1 + val[j];
    }
  }

  long long ans = INF;
  for(int j=0; j<m-1; j++)
    ans = min( ans, to[j] );

  cout << ans+val[m-1] << "\n";

	return 0;
}
