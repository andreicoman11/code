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

ifstream fin ("B.in");
//ofstream fout ("B.out");

long double value(string);

int main()
{
	string e;
	getline(fin, e);
	while( e!="()" )
	{
		cout.setf(ios::fixed);
		cout << setprecision(2) << value(e) << "\n";
		getline(fin, e);
	}
	return 0;
}

long double value(string f)
{
	if( f[0]!='(' )
		return (long double)atoi(f.c_str());
	else
	{
		//cout << "f initial " << f << " ";
		f = f.substr(1, f.size()-2);
		//cout << "f fara paranteze " << f << "\n";

		istringstream in (f);
		double p;
		in >> p;

		f = f.substr( f.find(" ")+1 );
		//cout << "f fara p " << f << "\n";

		long double e1, e2;

		if( f[0]!='(' )
		{
			e1 = value( f.substr(0, f.find(" ") ) );
			e2 = value( f.substr( f.find(" ")+1 ) );
		}
		else
		{
			string f1;
			f1 += f[0];
			int p = 1, i;
			for(i=1; i<f.size() && p; i++)
			{
				f1 += f[i];
				if( f[i]=='(' ) p++;
				else if( f[i]==')' ) p--;
			}
			string f2 = f.substr(i+1);
			//cout << "f1 " << f1 << " --- f2 " << f2 << "\n";

			e1 = value(f1);
			e2 = value(f2);
		}

		//cout << e1 << " e1 --- e2 "  << e2 << "\n";
	
		long double rez;
		rez = p*(e1+e2) + (1-p)*(e1-e2);
		return rez;
	}
}