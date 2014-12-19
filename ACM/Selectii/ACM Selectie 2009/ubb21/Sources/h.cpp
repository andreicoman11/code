//Code of Tavo92

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

#define forn(a, b) for(int a = 0; a<(b); ++a)

int count(vector <int> xs, vector <int> ys)
{
	int ans = 0;

	for(int x = -100; x<=100; ++x) for(int y = -100; y<=100; ++y)
	{
		bool izq, der, arr, baj;

		izq = der = arr = baj = false;

		forn(i, xs.size())
		{
			if(xs[i] == x)
			{
				if(ys[i] < y)
					baj = true;
				else if(ys[i] > y)
					arr = true;
			}
			else if(ys[i] == y)
			{
				if(xs[i] < x)
					izq = true;
				else if(xs[i] > x)
					der = true;
			}
		}

		if(izq && der && arr && baj) ++ans;
	}

	return ans;
}

void main()
{
	int test;
	freopen("h.dat", "r", stdin);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		forn(i, n) cin >> a[i];
		cin >> n;
		forn(i, n) cin >> b[i];
		cout << count(a, b) << endl;
	}
}