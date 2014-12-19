/*
ID: andreic4
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int get(int);

int main()
{
    ofstream fout ("fracdec.out");
    ifstream fin ("fracdec.in");
    
    int n,d;
    fin >> n >> d;
    char v[1000000]={0};
    char vec[1000000]={0};
    int i=2;
    int partint = n/d;
    int cifre = get( partint);

    v[n]=1;
    n = (n%d)*10;
    //cout << n << "\n";
    //system("pause");
    
    while( v[n]==0 && n!=0 )
    {
        v[n]=i;
        vec[i-2] = n/d;
        n = (n%d)*10;
        
        //cout << int(vec[i-2]) << " " << n << "\n";
        //system("pause");
        
        i++;
    }
    i -= 2;
    int afis=0;
    fout << partint << ".";
    afis += cifre;
        
    if( n==0 )
    {
        int j=0;
        if( i==0 ) fout <<"0";
        while( j<i )
        {
            afis++;
            fout << int(vec[j++]);
            if( afis>=76 && j<i )
            {
                afis=0;
                fout << "\n";
            }
        }
        fout << "\n";
    }
    else
    {
        int k = int(v[n])-2;
        //cout << k << "\n";
        int j=0;
        while( j<k )
        {
            fout << int(vec[j++]);
            afis++;
            if( afis>=76 )
            {
                afis=0;
                fout <<"\n";
            }
        }
        fout << "(";
        afis++;        
        while( j<i )
        {
            fout << int(vec[j++]);
            afis++;
            if( afis>=76 )
            {
                afis=0;
                fout <<"\n";
            }
        }
        fout << ")\n";
    }
    //system("pause");
    return 0;
}

int get(int x)
{
    int n=0;
    if( x==0 ) n=1;
    while( x )
    {
        n++;
        x /= 10;
    }   
    return n+1;
}
