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

set<string> s;
int main()
{
	int k, c;
	cin >> k;
	while(k)
	{
		string aux;
		cin >> c;
		s.clear();
		for(int i=0; i<k; i++)
		{
			cin >> aux;
			s.insert(aux);
		}
			
		bool ok = true;
		for(int i=0; i<c; i++)
		{
			int cc, rr, r=0;
			cin >> cc >> rr;
			string aux;
			for(int j=0; j<cc; j++)
			{
				cin >> aux;
				if( s.find(aux)!=s.end() ) r++;
			}
			if( r<rr ) ok=0;
		}
		
		if( ok ) cout << "yes\n";
		else cout << "no\n";
		
		
		cin >> k;
	}

	return 0;
}
