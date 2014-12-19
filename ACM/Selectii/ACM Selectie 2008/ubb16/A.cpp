#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;

ifstream fin ("A.in");
//ofstream fout ("A.out");

int N;

bool isproject(string);

int main()
{
	string project;
	getline(fin, project);
	while( project[0]!='0' )
	{
		vector<string> projects;
		map<string,int> ids;
		map<string,bool> students;
		projects.push_back(project);
		int cur = 0;
		string tmp;
		getline(fin, tmp);
		int v[100] = {0};
		while( tmp[0]!='1' )
		{
			//cout << tmp << " ";
			if( isproject(tmp) )
			{
				projects.push_back( tmp );
				cur++;
			}
			else
			{
				if( students[tmp] )
				{
					//cout << "student exists ";
					if( ids[tmp]!=cur && ids[tmp]!=-1 )
					{
						//cout << "will be removed ";
						v[ ids[tmp] ]--;
						ids[tmp]=-1;
					}
				}
				else
				{
					v[ cur ]++;
					ids[tmp] = cur;
					students[tmp] = true;
				}
			}
			//cout << cur << "\n";
			getline(fin, tmp);
		}

		/*cout << cur << "   ";
		for(int i=0; i<=cur; i++)
			cout << v[i] << " " << projects[i];*/

		bool ok = true;
		while(ok)
		{
			ok = false;
			for(int i=0; i<cur; i++)
				if( v[i]<v[i+1] || 
					(v[i]==v[i+1] && projects[i]>projects[i+1] ) )
				{
					ok = true;
					int aux = v[i];
					v[i] = v[i+1];
					v[i+1] = aux;
					tmp = projects[i];
					projects[i] = projects[i+1];
					projects[i+1] = tmp;
				}
		}

		for(int i=0; i<=cur; i++)
			cout << projects[i] << " " << v[i] << "\n";

		getline(fin, project);
	}
	return 0;
}

bool isproject(string t)
{
	for(int i=0; i<t.size(); i++)
		if( isalpha(t[i]) && islower(t[i]) ) return false;
	return true;
}