#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

int n, //The number of words
	sDict; //The sum of the word lengths
vector <string> dict; //The words of the dictionary
vector <vector <int> > a; //The overlapping of two consecutive words
vector <vector <int> > c;  //C_{i,j} = The maximum overlapping we can get, when we are in node i and 
						   //we have visited the nodes represented by the bits of j. -1 means not yet calculated

int overlap(string word1, string word2) 
//The basic idea is the partial match table construction algorithm from the Knuth-Morris-Pratt algorithm
{
	if (word1.size()==1 || word2.size()==1) return 0; //A single character doesn't have a real suffix or prefix
	word2[word2.size()-1]='#'; //To avoid cases where word2 is a suffix of word1
	string s=word2+word1; 
	vector <int> jump(s.size());
	int i=1, j=1; 
	while (i<word2.size()) //Calculate the beginning of the vector for later use
	{
		if (s[i]==s[j-1])
		{
			jump[i]=j;
			++i;
			++j;
		}
		else
			if (j>1) j=jump[j-2]+1;
			else
			{
				jump[i]=0;
				++i;
			}
	}
	i=word2.size()+1; //We start from the second character of word1, to avoid cases where word1 is a prefix of word2
	j=1;
	while (i<s.size())
	{
		if (s[i]==s[j-1])
		{
			jump[i]=j;
			++i;
			++j;
		}
		else
			if (j>1) j=jump[j-2]+1;
			else
			{
				jump[i]=0;
				++i;
			}
	}
	return jump[s.size()-1];
}

int calculate(int node, int bits) //Using memoization technique
{
	if (c[node][bits]!=-1) return c[node][bits]; //We already calculated this value
	else
	{
		int ans=0;
		for (int q=0;q<n;++q)
		{
			if (q!=node && bits&(1<<q)) //Where can we come from?
			{
				int aux=calculate(q,bits-(1<<node));
				ans=max(ans,aux+a[q][node]);
			}
		}
		c[node][bits]=ans; //Don't forget to store the value to avoid multiple calculation
		return ans;
	}
}

void main()
{
	clock_t start=clock();
	ifstream fin("sirrom.in");
	fin>>n;
	while (n!=-1)
	{
		dict.clear();
		dict.resize(n);
		a.clear();
		a.resize(n);
		sDict=0;
		for (int q=0;q<n;++q) 
		{
			fin>>dict[q];
			sDict+=dict[q].size();
		}
		for (int q=0;q<n;++q)
		{
			a[q].resize(n);
			for (int w=0;w<n;++w) 
				if (q!=w) a[q][w]=overlap(dict[q],dict[w]);
		}
		c.clear();
		c.resize(n);
		for (int q=0;q<n;++q)
		{
			c[q].resize(1<<n,-1);
			c[q][1<<q]=0; //Adding single words
		}
		int mCommon=0;
		for (int q=0;q<n;++q)
		{
			mCommon=max(mCommon,calculate(q,(1<<n)-1)); //The optimal solution can end in any node (word)
		}
		cout<<sDict-mCommon<<endl;
		fin>>n;
	}
	cout<<double (clock()-start)/CLOCKS_PER_SEC<<'s'<<endl;
}