#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

int n, //The number of words
	sDict; //The sum of the word lengths
char dict[20][10001]; //The words of the dictionary
int a[20][20]; //The overlapping of two consecutive words
int c[20][1<<15];  //C_{i,j} = The maximum overlapping we can get, when we are in node i and 
						   //we have visited the nodes represented by the bits of j. -1 means not yet calculated

int overlap(char* word1, char* word2) 
//The basic idea is the partial match table construction algorithm from the Knuth-Morris-Pratt algorithm
{
	int l1=strlen(word1), l2=strlen(word2), l3=l1+l2;
	if (l1==1 || l2==1) return 0; //A single character doesn't have a real suffix or prefix
	char aux=word2[l2-1];
	word2[l2-1]='#'; //To avoid cases where word2 is a suffix of word1
	char s[20001];
	strcpy(s,word2);
	strcat(s,word1);
	vector <int> jump(l3);
	int i=1, j=1; 
	while (i<l2) //Calculate the beginning of the vector for later use
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
	i=l2+1; //We start from the second character of word1, to avoid cases where word1 is a prefix of word2
	j=1;
	while (i<l3)
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
	word2[l2-1]=aux;
	return jump[l3-1];
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
		sDict=0;
		for (int q=0;q<n;++q) 
		{
			fin>>dict[q];
			dict[q][strlen(dict[q])]='\0';
			sDict+=strlen(dict[q]);
		}
		for (int q=0;q<n;++q)
		{
			for (int w=0;w<n;++w) 
				if (q!=w) a[q][w]=overlap(dict[q],dict[w]);
		}
		memset(c,-1,sizeof(c));
		for (int q=0;q<n;++q)
		{
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