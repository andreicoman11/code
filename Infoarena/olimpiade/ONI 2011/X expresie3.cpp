#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

#define LL long long
#define INFILE "expresie3.in" 
#define OUTFILE "expresie3.out"

char str[20010];
bool vis[256];
int v[256];

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);
   memset(vis, 0, sizeof(vis));
   memset(v, 0, sizeof(v));

   cin.getline(str, 20010, '\n');
   string s = str;
   int n = s.size();
   stack<int> st;
   int m = 1, mt = 1;
   for(int i=0; i<s.size(); i++)
   {
      if( isalpha(s[i]) )
      {
         vis[s[i]] = 1;
         v[s[i]] += m*mt;
      }
      else if( s[i]=='/' )
      {
         m = -1;
      }
      else if( s[i]=='*' )
      {
         m = 1;
      }
      else if( s[i]=='(' )
      {
         st.push(m);
         mt = mt*m;
         m = 1;
      }
      else if( s[i]==')' )
      {
         mt *= st.top();
         m = 1;
         st.pop();
      }
   }

   for(int i = int('a'); i<=int('z'); i++)
      if( vis[i] )
         cout << char(i) << " " << v[i] << '\n';


   return 0;
}
