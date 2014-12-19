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
#define REP(x, hi) for (size_t x=0; x<(hi); x++)
#define REPD(x, hi) for (size_t x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (size_t x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (size_t x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "jku.in" 
#define OUTFILE "jku.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

bool fost[512][512];

void printV(VI v)
{
  REP(i, v.sz)
      cout << v[i] << " ";
  cout << endl;
}

VI getNr(int n, int m, int x, int y, char d, char modus, int b)
{
  VVI mat(n);
  memset(fost, 0, sizeof(fost));
  int c = 1;
  REP(i,n)
  {
    mat[i].resize(m);
    REP(j, m)
      mat[i][j] = c++;      
  }
  VI ans;
  while( ans.sz < n*m)
  {
    cout << x << " " << y << " " << d << "\t";
    if( d=='N' )
    {
      for(;x>=1; x--)
      REP(i, b)
        {
          if( 0<=y-1+i && y-1+i < m && fost[x-1][y-1+i]==0 )
          {
            ans.pb( mat[x-1][y-1+i] );
            fost[x-1][y-1+i] = 1;
          }
          else ans.pb(0);
        }
      x = 1;
      d = 'S';
      if( modus=='S' )
      {
        if( y>1 && fost[x-1][y-2]==0 ) y--;
        else if( y<m && fost[x-1][y-1+b]==0 ) y = y + 2*(b-1) + 1;
      }
      else
      {
        if( y>b && fost[x-1][y-2]==0 )
        {
          int oldy = y;
          y = 1;
          while( fost[x-1][y-1]==1 ) y++;
          y = min(y+b-1,oldy-1);
        }
        else if( y<m && fost[x-1][y-1+b]==0 )
        {
          int oldy = y;
          y = m;
          while( fost[x-1][y-1]==1 ) y--;
          if( y-oldy<=2*(b-1) && (oldy + 2*(b-1) +1)<=m ) y = oldy + 2*(b-1) +1;
        }

      }
    }
    else if( d=='S' )
    {
      for(;x<=n; x++)
      REP(i, b)
        {
          if( y-1-i>=0 && y-1-i<m && fost[x-1][y-1-i]==0 )
          {
            ans.pb( mat[x-1][y-1-i] );
            fost[x-1][y-1-i] = 1;
          }
          else ans.pb(0);
        }
      x = n;
      d = 'N';
      if( modus=='S' )
      {
        if( y>1 && fost[x-1][y-1-b]==0 ) y = y - 2*(b-1) - 1;
        else if( y<m && fost[x-1][y]==0 ) y++;
      }
      else
      {
        if( y>b && fost[x-1][y-1-b]==0 )
        {
          int oldy = y;
          y = 1;
          while( fost[x-1][y-1]==1 ) y++;
          if( oldy-y<=2*(b-1) && (oldy - 2*(b-1)-1)>0 ) y = oldy - 2*(b-1)-1;
        }
        else if( y<m && fost[x-1][y]==0 )
        {
          int oldy = y;
          y = m;
          while( fost[x-1][y-1]==1 ) y--;
          y = max(y-b+1, oldy+1);
        }
      }
    }
    else if( d=='W' )
    {
        for(;y>=1; y--)
        REP(i, b)
          {
            if( x-1-i>=0 && x-1-i<n && fost[x-1-i][y-1]==0 )
            {
              ans.pb( mat[x-1-i][y-1] );
              fost[x-1-i][y-1] = 1;
            }
            else ans.pb(0);
          }
        y = 1;
        d = 'O';
        if( modus=='S' )
        {
          if( x>1 && fost[x-1-b][y-1]==0 ) x = x - 2*(b-1) - 1;
          else if( x<n && fost[x][y-1]==0 ) x++;
        }
        else
        {
          if( x>b && fost[x-1-b][y-1]==0 )
          {
            int oldx = x;
            x = 1;
            while( fost[x-1][y-1]==1 ) x++;
            if( oldx-x<=2*(b-1) && (oldx - 2*(b-1) - 1)>0 ) x = oldx - 2*(b-1) - 1;
          }
          else if( x<n && fost[x][y-1]==0 )
          {
            int oldx = x;
            x = n;
            while( fost[x-1][y-1]==1 ) x--;
            x = max(x-b+1, oldx+1);
          }
        }
    }
    else if( d=='O' )
    {
        for(;y<=m; y++)
        REP(i, b)
          {
            if( x-1+i<n && x-1+i>=0 && fost[x-1+i][y-1]==0 )
            {
              ans.pb( mat[x-1+i][y-1] );
              fost[x-1+i][y-1] = 1;
            } else ans.pb(0);
          }
        y = m;
        d = 'W';
        if( modus=='S' )
        {
          if( x>1 && fost[x-2][y-1]==0 ) x--;
          else if( x<n && fost[x-1+b][y-1]==0 ) x = x + 2*(b-1) + 1;
        }
        else
        {
          if( x>b && fost[x-2][y-1]==0 )
          {
            int oldx = x;
            x = 1;
            while( fost[x-1][y-1]==1 ) x++;
            x = min(x+b-1, oldx-1);
          }
          else if( x<n && fost[x-1+b][y-1]==0 )
          {
            int oldx = x;
            x = n;
            while( fost[x-1][y-1]==1 ) x--;
            if( x-oldx<=2*(b-1) && (oldx + 2*(b-1) + 1)<=n) x = oldx + 2*(b-1) + 1;
          }
        }
    }
    cout << "tooo " << x << " " << y << " " << d << endl;
    //printV(ans);
    /*REP(i, n)
    {
      REP(j, m)
        cout << fost[i][j] << " ";
      cout << endl;
    }*/
    //system("pause");
  }

  return ans;
}


int main()
{
  int n, m, x, y, b;
  char d, modus;
  while( fin >> n >> m >> x >> y >> d >> modus >> b)
  {
    cout << n << " " << m << "  " << x << " "<< y << " " << d << " " << modus << " " << b << "\n\n\n";
    VI ans = getNr(n, m,x , y, d, modus, b);
    REP(i, ans.sz)
      fout << ans[i] << " ";
    fout << endl;
    cout << "\n\n\n";
  }  
	
	return 0;
}