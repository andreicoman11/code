#include <iostream>
#include <vector>
using namespace std;

int n, K;
bool found;
vector<int> res;
int moves[8][2], mres[8][2];

void check(vector<int> v)
{
	for(int i=0; i<v.size(); i++)
		if( v[i]!=res[i] ) return;
	found = 1;
	for(int i=0; i<8; i++) {
		mres[i][0] = moves[i][0];
		mres[i][1] = moves[i][1];
	}
}

void go(vector<int> v, int d)
{
	if( d==0 ) {
		check(v);
	}
	else {
		int k[5] = {8, 8, 8, 8, 8};
		for(int i=v.size()-1; i>=0; i--)
			k[ v[i] ] = i;

		for(int i=0; i<K; i++)
		for(int j=0; j<K; j++)
			if( k[i]<k[j] ) {
				moves[d][0] = i;
				moves[d][1] = j;
				v[k[i]] = j;
				go(v, d-1);
				v[k[i]] = i;
			}
	}
}

int main()
{
	cin >> n >> K;
	vector<int> init;
	init.resize(n);
	res.resize(n);
	for(int i=0; i<n; i++) {
		cin >> init[i];
		init[i]--;
	}

	for(int i=0; i<n; i++) {
		cin >> res[i];
		res[i]--;
	}

	found = 0;
	// iterative deepening, of depth i
	int i = 1;
	for(; !found && i<7; i++)
		go(init, i);

	cout << i-1 << "\n";
	for(int j=i-1; j; j--)
		cout << mres[j][0]+1 << " " << mres[j][1]+1 << "\n";

	return 0;
}