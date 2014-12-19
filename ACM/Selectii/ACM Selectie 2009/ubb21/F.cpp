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


int main()
{
	int N;
	cin >> N;
	while( N-- )
	{
		string t;
		cin >> t;
		int v[30];
		memset( v, -1, sizeof(v));
		string ans = "";
		int c = -1;
		for(int i=0; i<t.size(); i++)
		{
			int j = int(t[i]) - int('a');
			//cout << j << " " << v[j] << endl;
			if( v[j]==-1 )
			{
				v[j] = ++c;
				ans += char(v[j] + int('a'));
			}
			else
				ans += char(v[j]+int('a'));
		}
		
		cout << ans << endl;
	}

	return 0;
}
