#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

//ifstream fin ("C-small.in");
//ofstream fout ("C-small.out");
ifstream fin ("C-large.in");
ofstream fout ("C-large.out");

int N, N2 = 1, a, b;
bool used[10000010];

int verif(int x)
{
   int rec = 0;
   used[x] = 1;
   string s = "";
   while(x)
   {
      s += char((x%10) + int('0'));
      x /= 10;
   }
   reverse(s.begin(), s.end());
   s += s;

   for(int i=1; i<s.size()/2; i++)
      if( s[i]!='0' )
      {
         int nr = 0;
         for(int j=i; j<i+s.size()/2; j++)
            nr = nr*10 + int(s[j]) - int('0');
         if( !used[nr] && nr<=b && a<=nr ) rec++, used[nr] = 1;
      }

   return (rec * (rec+1) / 2);
}

int main()
{
	fin >> N;
	while( N2<=N )
	{
      fin >> a >> b;
      int res = 0;
      memset(used, 0, sizeof(used));
      for(int a2=a;a2<=b; a2++)
         if( !used[a2] )
            res += verif(a2);

		fout << "Case #" << N2++ << ": " << res << endl;
	}

	return 0;
}