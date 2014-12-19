#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "a.in" 
#define OUTFILE "a.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

struct nod{
	char val;
	nod* l;
	nod* r;
};

bool inv;

void tree(string pre, string in, nod* root)
{
	//cout << pre << "   " << in << endl;
	if( inv || (pre.sz==0 && in.sz==0) ) return;
	if( pre.sz==1 && in.sz==1 && pre!=in ) 
	{
		inv = true;
		return;
	}
	root->val = pre[0];
	int i = in.find(pre[0]);
	string li = in.substr(0, i);
	string ri = in.substr(i+1);
	string lp = pre.substr(1, li.sz);
	string rp = pre.substr(li.sz+1);
	//cout << lp << " " << rp << "\t" << li << " " << ri << endl;

	if( lp.sz && li.sz )
	{
		nod* ll = new nod();
		ll->l = NULL;
		ll->r = NULL;
		root->l = ll;
		tree( lp, li, ll);
	}

	if( rp.sz && ri.sz )
	{
		nod* rr = new nod();
		rr->l = NULL;
		rr->r = NULL;
		root->r = rr;
		tree( rp, ri, rr);
	}

}

void printt(nod* root)
{
	if( root->l != NULL )
		printt( root->l );
	if( root->r != NULL )
		printt( root->r );
	fout << root->val;
}

int main()
{
	string line;
	char buf[512];
	fin.getline(buf, 512);
	line = buf;
	cout << buf << endl;
	do 
	{
		nod* root = new nod();
		root->l = root->r = NULL;

		int i = line.find(" ");
		string left = line.substr(0, i);
		string right = line.substr(i+1);

		inv = 0;
		tree( left, right, root);
		if( !inv )
		{
			printt(root);
			fout << endl;
		}
		else fout << "Invalid tree\n";
		
		fin.getline(buf, 512);
		line = buf;
		cout << buf << endl;
	} while( line!="#" );
	return 0;
}