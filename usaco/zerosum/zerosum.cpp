/*
ID: andreic4
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("zerosum.out");

int n;
int v[10]={0};

void rec(int);
void verif();

int main()
{
    ifstream fin ("zerosum.in");
    
    fin >> n;
    
    rec(1);
    
    //system("pause");
    return 0;
}

void rec(int i)
{
    if( i>=n ) verif();
    else
    {        
        if( i && v[i-1]!=3 ){ v[i]=3; rec(i+1); }
        v[i]=1;
        rec(i+1);
        v[i]=2;
        rec(i+1);
        v[i]=0;
    }    
}

void verif()
{
    int sum=1;
    int i=1;    
        
    //cout << "1";
    
    while( i<n )
    {
        //if( v[i]==1 ) cout << " + ";
        //else if( v[i]==2 ) cout << " - ";        
        //cout << i+1;
        
        if( v[i]==1 ) sum += i+1;
        else if( v[i]==2 ) sum -= i+1;
        else if( v[i]==3 ) 
        {
            if( i==1 || v[i-1]==1 ) sum += 9*i + i + 1;
            else sum -= 9*i + i + 1;
        }
        i++;
    }
    
    if( sum==0 )
    {
        for(int i=1; i<n; i++)
        {
            fout << i;
            if( v[i]==1 ) fout << "+";
            else if( v[i]==2 ) fout << "-";
            else if( v[i]==3 ) fout << " ";
        
        }
        fout << n << "\n";
    }
    
    //cout << " = " << sum << "\n";
    
}
