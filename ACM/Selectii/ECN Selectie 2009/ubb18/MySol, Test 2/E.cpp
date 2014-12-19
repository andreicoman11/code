#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("E.dat");

int main()
{
	int N;
	fin >> N;
	while(N--)
	{
		int k,w;
		fin >> k >> w;
		string t, s;
		fin >> t;
		int count = t.size();
		for(int i=1; i<w; i++)
		{
			fin >> s;
			int m = 0;
			int j;
			if( t.size()<=s.size() ) j=0;
			else j = t.size()-s.size();
			for(; j<t.size(); j++)
			{
				if( t.substr(j) == s.substr(0, t.size()-j) )
				{
					if( m < t.substr(j).size() )
						m = t.substr(j).size();
				}
			}
			
			count += s.size() - m;
			//cout << t << " " << s << " " << m << " " << count << endl;
			t = s;
			//cout << t << endl;
		}
		cout << count << endl;

	}
	return 0;
}
