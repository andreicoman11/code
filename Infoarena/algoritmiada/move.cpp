#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define INFILE "move.in" 
#define OUTFILE "move.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int a[NMAX], t[NMAX], m[NMAX];
bool mov[NMAX];

int get_pos(int l, int r, int val)
{
	while( l<r )
	{
		int pos = (l+r) / 2;
		if( a[m[pos]]<val && val<=a[m[pos+1]] ) return pos;
		else if( val<=a[m[pos]] ) r = pos-1;
		else l = pos+1;
	}
	return l;
}

void set_move(int i)
{
	if( t[i]!=-1 ) set_move(t[i]);
	//fout << a[i] << " ";
   mov[a[i]-1] = 1;
}

int main()
{
	int n;
	fin >> n;
   map<int, int> pos;
	for(int i=0; i<n; i++) {
		fin >> a[i];
      pos[a[i]] = i;
   }

	t[0] = -1;
	m[0] = 0;
	int nr = 0;

	for(int i=1; i<n; i++)
	{
		if( a[i] <= a[m[0]] ) {
			m[0] = i;
			t[i] = -1;
		} else {
			int pos = get_pos(0, nr, a[i]);

			m[pos+1] = i;
			t[i] = m[pos];
			nr = max(nr, pos+1);
		}
	}
	
	fout << n - (nr+1) << '\n';
	set_move(m[nr]);

   for(int i=0; i<n; i++) 
      if( mov[i]==0 ) {
         if( i==0 ) {
            fout << "1 0\n";
         } else {
            fout << i+1 << " " << i << "\n";
         }

      }

	return 0;
}