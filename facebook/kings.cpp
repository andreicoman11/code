#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MOD 1000000007
#define NMAX 16

int n, k;
int d[NMAX][NMAX][66000];
bool v[NMAX][NMAX][66000];
vector<vector<int> > b;

int comp(int i, int j, int bs)
{
	if( i==n-1 ) return 1;
	if( v[i][j][bs] ) return d[i][j][bs];
	v[i][j][bs] = 1;

	int res = 0;
	for(int jj=0; jj<n; jj++) 
		if( (bs & (1<<jj))==0 && (jj<j-1 || jj>j+1 ) )
			res = (res + comp(i+1, jj, bs ^ (1<<jj))) % MOD;
	d[i][j][bs] = res;
	return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		
		memset(d, 0, sizeof(d));
		memset(v, 0, sizeof(v));
		b.clear();
		b.resize(n);
		int bitset = 0;
		int lastk = -1;
		for(int i=0; i<n; i++) {
			b[i].resize(n);
			if( i<k ) {
				int pos;
				cin >> pos;
				lastk = pos;
				b[i][pos] = 1;
				bitset ^= (1<<pos);
			}
		}

		int res = (n==k);
		for(int i=0; i<n; i++)
			if( (bitset & (1<<i))==0 && (lastk==-1 || i<lastk-1 || i>lastk+1) )
				res = (res + comp(k, i, bitset ^ (1<<i))) % MOD;
		cout << res << endl;
	}
	return 0;
}