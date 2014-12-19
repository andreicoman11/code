#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "shuffle.in" 
#define OUTFILE "shuffle.out"
#define NMAX 2000010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

LL k;
int n, v[NMAX], last[NMAX];
bool used[NMAX];

void encode() {	
	int ret = 0;
	//cout << "final ";
	for(int i=0; i<n; i++) {
		ret = (ret * 13 + last[i] + 1);
      while( ret>=1299827 )
         ret -= 1299827;
		//cout << last[i]+1 << " ";
	}
	fout << ret; 
}

void shuffle()
{
	int b = n-1, idx = 0;
	while( b )
	{
		int m = (b+1) >> 1;
		for(int i=m; i<=b; i++) {
			v[idx] = i;
			idx++;
		}
		b = m-1;
	}
	v[idx] = 0;
}

void get_period() {
	memset(used, 0, sizeof(used));
	k--;
	for(int i=0; i<n; i++)
	if( !used[i] ) {
		vector<int> x;

		x.pb(i);
		int nr = 1;
		used[i] = 1;
		int j = v[i];

		while( !used[j] ) {
			x.pb(j);
			nr++;
			used[j] = 1;
			j = v[j];
		}

		int k2 = int(k % (LL)nr);
		for(int j=0; j<nr; j++) {
			last[x[j]] = v[x[k2]];
			k2++;
			if( k2==nr ) k2=0;
		}
	}
}

int main()
{
	fin >> n >> k;

   if( k ) {
	   // get first shuffle, get first perm
	   shuffle();
	   /*for(int i=0; i<n; i++)
		   cout << v[i] << " ";
	   cout << endl;*/
	   get_period();
   } else
      for(int i=0; i<n; i++)
         last[i] = i;
	encode();
	return 0;
}