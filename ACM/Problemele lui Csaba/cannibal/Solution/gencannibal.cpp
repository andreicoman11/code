#include <fstream>
#include <map>
#include <queue>
#include <time.h>
#include <iostream>

using namespace std;

struct Tstate 
{
	bool side;
	int can,mis;
};

bool operator< (const Tstate &a, const Tstate &b)
{
	return a.side<b.side || a.side==b.side && a.can<b.can ||
		a.side==b.side && a.can==b.can && a.mis<b.mis;
}

int n,m,k;
map <Tstate,int> levels;
queue <Tstate> qStates;


int bf() //Breadth first search
{
	if (n>m) return -1;
	if (k>=n+m) return 1;
	while (!qStates.empty()) qStates.pop();
	levels.clear();
	Tstate aux, final;
	//Starting state
	aux.side=false; 
	aux.can=n;
	aux.mis=m;
	//Final state
	final.can=0; 
	final.mis=0;
	final.side=true;
	qStates.push(aux);
	levels[aux]=0;
	while (!qStates.empty() && !levels.count(final))
	{
		Tstate head=qStates.front();
		int aCan, aMis; //The number of cannibals and missionaries on the current side
		if (!head.side)
		{
			aCan=head.can;
			aMis=head.mis;
		}
		else
		{
			aCan=n-head.can;
			aMis=m-head.mis;
		}
		for (int q=0;q<=min(k,aMis);++q) 
			//The number of missionaries to travel with the boat
			//It must be less or equal with:
			// -the number of missionaries on the current side of the river
			// -the size of the boat
		{
			for (int w=0;w<=min(k-q,aCan);++w) 
				//The number of cannibals to travel with the boat
				//It must be less or equal with:
				// -the number of missionaries to travel with the boat (if it's >0)
				// -the remaining places in the boat
				// -the number of cannibals on the current side of the river
			{
				if (q+w==0) continue; //Somebody must be in the boat
				if (q && w>q) break;
				aux.side=!head.side;
				if (!head.side)
				{
					aux.can=head.can-w;
					aux.mis=head.mis-q;
				}
				else
				{
					aux.can=head.can+w;
					aux.mis=head.mis+q;
				}
				if ((aux.can<=aux.mis || aux.mis==0) &&
					((n-aux.can)<=(m-aux.mis) || aux.mis==m) &&
					//The property must be maintained on both sides
					//otherwise the cannibals will eat the missionaries
					//If there are 0 missionaries, there's nothing to eat
					!levels.count(aux)) //State not visited yet
				{
					levels[aux]=levels[head]+1;
					qStates.push(aux);
				}
			}
		}
		qStates.pop();
	}
	if (levels.count(final)) return levels[final];
	else return -1;
}

void main()
{
	clock_t start=clock();
	ofstream fout("cannibal.txt");
	fout<<"{";
	for (n=0;n<=50;++n)
	{
		fout<<"{";
		for (m=0;m<=50;++m)
		{
			cout<<n<<" "<<m<<endl;
			fout<<"{";
			for (k=1;k<=99;++k)
			{
				fout<<bf()<<",";
			}
			fout<<"1},"<<endl;
		}
		fout<<"},"<<endl;
	}
	fout<<"}"<<endl;
	fout<<(clock()-start)/double (CLOCKS_PER_SEC);
	fout.close();
}