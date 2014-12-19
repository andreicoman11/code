#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

ifstream fin ("A-large-practice.in");
//ifstream fin ("A-large.in");
//ofstream fout ("A-large.out");

struct node
{
	double val;
	string feature;
	node* left;
	node* right;
};

int N, N2 = 1;
set<string> features;

node* read_node(string t)
{
	node* n = new node();
	int i = 0, j=0;
	while( !isdigit(t[i]) ) i++;
	while( t[i+j]!=')' && t[i+j]!='(' ) j++;
	if( t[i+j]==')' )
	{
		t = t.substr(i, j);
		//cout << "case )\t" << t << endl;
		istringstream in(t);
		in >> n->val;
		n->feature = "";
		//cout << "node solo, val " << n->val << endl;system("pause");
	}
	else
	{
		//cout << "case (\t" << t << endl;
		istringstream in( t.substr(i, j) );
		in >> n->val >> n->feature;
		//cout << n->val << " and " << n->feature << endl;

		i = i+j;
		j = i+1;
		int par = 1;
		while( par )
		{
			if( t[j]=='(' ) par++;
			else if( t[j]==')') par--;
			j++;
		}
		string l = t.substr(i,j-i);
		i = j+1;
		j = t.size()-1;
		while( t[j]!=')') j--;
		string r = t.substr(i, j-i);
		//cout << l << endl << r << endl; system("pause");
		n->left = read_node( l );
		n->right = read_node( r );
	}

	return n;
}

double comp_val(node* n)
{
	if( n->feature=="" ) return n->val;
	else if( features.find(n->feature)!=features.end() ) return n->val * comp_val(n->left);
	else return n->val * comp_val(n->right);
}

int main()
{
	FILE* fout;
	fout = fopen ("A-large.out", "w");
	fin >> N;
	while(N2<=N)
	{
		string t = "";
		int l;
		fin >> l;
		char str[512];
		fin.getline(str, 512);
		for(int i=0; i<l; i++)
		{
			fin.getline(str, 512);
			t += str;
		}
		node* root = read_node(t);

		int a = 0;
		fin >> a;
		cout << a << endl;
		fprintf(fout ,"Case #%d:\n", N2);
		for(int i=0; i<a; i++)
		{
			fin >> t;
			int fs = 0;
			fin >> fs;
			cout << fs << endl;
			features.clear();
			while(fs)
			{
				fin >> t;
				features.insert(t);
				fs--;
			}
			fprintf(fout ,"%.7f\n", comp_val(root));
		}

		N2++;
	}
return 0;
}


