/*
ID: andreic4
PROG: cryptcow
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ofstream fout ("cryptcow.out");

int t=0,k=0;
int nr=0;

void search(char* l,int);

int main()
{
    
    ifstream fin ("cryptcow.in");
    
    string line;
    char temp[100];
    fin.getline( temp, 100, '\n' );
    line = temp;
    int n = line.size();
    for(int i=0; i<n; i++)
            if( line[i]=='C' ) k++;
    if( (n-47)%3==0 )  search(temp,n);
    
    if(t)
    {
        fout << "1 ";
        int k=0;
        fout << k << "\n";
    }
    else fout << "0 0\n";
    
    //system("pause");
    return 0;
}

void search(char* l,int n)
{
    nr++;
    if( nr%10000==0 ) cout << nr << "\n";
    //cout << l << "\n";
    //system("pause");
    if( strcmp(l,"Begin the Escape execution at the Break of Dawn")==0 ) 
    {
        fout << "1 " << k << "\n";
        exit(0);
    }
    else
    {
        for(int i=0; i<n-2; i++)
            if( l[i]=='C' )
        for(int j=i+1; j<n-1; j++)
            if( l[j]=='O' )
        for(int k=j+1; k<n; k++)
            if( l[k]=='W' )
            {
                char temp[100];
                int p=0;
                for(int ii=0; ii<i; ii++)
                    temp[p++] = l[ii];
                for(int ii=j+1; ii<k; ii++)
                    temp[p++] = l[ii];
                for(int ii=i+1; ii<j; ii++)
                    temp[p++] = l[ii];
                for(int ii=k+1; ii<n; ii++)
                    temp[p++] = l[ii];
                temp[p] = '\0';
                search( temp, n-3 );
            }
    }
}
