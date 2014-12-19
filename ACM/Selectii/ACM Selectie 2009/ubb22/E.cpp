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

int v[1000];
int taken[1000000];
int cou;
vector<int> c;
int m;

void perm(int i, int no, int x[])
{
	if( i>=c.size() )
	{
		if( taken[no]==-1 ) 
		{
			v[cou++] = no;
			taken[no] = cou-1;
		}
	}
	else for(int j=0; j<c.size(); j++)
		if( x[j]==0 && (i>0 || (i==0 && c[j]!=0)) )
		{
			x[j] = 1;
			perm(i+1, no*10+c[j], x);			
			x[j] = 0;
		}
}

void swap(int k, bool q[])
{
	if( k==0 )
	{
		m = 0;
		for(int i=0; i<cou; i++)
			if( q[i] && v[i]>m ) m = v[i];
	}
	else
	{
		bool q2[1000] = {0};
		for(int i=0; i<cou; i++)
			if( q[i] )
			{
				//cout << "for " << v[i] << endl;
				// try all swaps
				int no[6] = {0};
				int a = v[i];
				int j = c.size()-1;
				while(a)
				{
					no[j] = a%10;
					j--;
					a/=10;
				}
				for(int j=0; j<c.size()-1; j++)
				for(int l=j+1; l<c.size(); l++)
					if( j>0 || (j==0 && no[l]) )
					{
						int aux = no[j];
						no[j] = no[l];
						no[l] = aux;
						a = 0;
						for(int p=0; p<c.size(); p++)
							a = a*10 + no[p];
						//cout << a << endl;
						q2[taken[a]] = 1;
						aux = no[j];
						no[j] = no[l];
						no[l] = aux;
					}
			}
		swap(k-1, q2);
	}
}

int main()
{
	int N;
	cin >> N;
	while( N-- )
	{
		int n,k;
		cin >> n >> k;
		if( n==1000000 ) cout << n << endl;
		else if( n<100 && n%10==0 ) cout << "-1\n";
		else if( n<10 ) cout << -1 << endl;
		else
		{
			c.clear();
			int nn = n;
			while(n)
			{
				c.push_back(n%10);
				n/=10;
			}
			n = nn;
			cou = 0;
			int x[10] = {0};
			memset( taken, -1, sizeof(taken));
			perm(0,0,x);

			/*for(int i=0; i<cou; i++)
				cout << v[i] << " " << taken[v[i]] << endl;
			cout << cou << endl << n << " " << taken[n] << endl;*/
			bool q[1000] = {0};
			q[ taken[n] ] =1;
			swap(k, q);
			cout << m;
			if(N) cout << endl;
		}
	}

	return 0;
}
