#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <functional>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int n, //The number of words
	sDict; //The sum of the word lengths
char dict[20][10001]; //The words of the dictionary
int a[20][20]; //The overlapping of two consecutive words
vector <int> overlaps; //Used in optimizing the backtracking

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

int randomize(int tries)
{
	int ss[15];
	bool was[15];
	int sofar,best=0,nIter;
	while (tries--)
	{
		sofar=0;
		memset(was,false,sizeof(was));
		for (int sp=0;sp<n;++sp)
		{
			nIter=0;
			do
			{
				++nIter;
				if (nIter>2*n) break;
				ss[sp]=rand()%n;
			} while (was[ss[sp]] || sp>0 && sofar+a[ss[sp-1]][ss[sp]]+overlaps[n-1-sp]<=best);
			if (nIter>2*n) break;
			was[ss[sp]]=true;
			if (sp>0) sofar+=a[ss[sp-1]][ss[sp]];
		}
		best=max(best,sofar);
	}
	return best;
}

void main()
{
	clock_t start=clock();
	srand(start);
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
		overlaps.push_back(0);
		for (int q=0;q<n;++q)
		{
			for (int w=0;w<n;++w) 
				if (q!=w) 
				{
					a[q][w]=overlap(dict[q],dict[w]);
					overlaps.push_back(a[q][w]);
				}
		}
		sort(overlaps.begin()+1,overlaps.end(),greater <int>());
		for (int q=2;q<overlaps.size();++q)
		{
			overlaps[q]+=overlaps[q-1];
		}
		int mCommon=randomize(500000); 
		cout<<sDict-mCommon<<endl;
		fin>>n;
	}
	cout<<double (clock()-start)/CLOCKS_PER_SEC<<'s'<<endl;
}