/*
ID: andreic4
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int m,n;

int main()
{
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    
    unsigned long int nr[100001];
    int primes[100]={0};
    int indices[100]={0};
    nr[0]=1;
    
    fin >> n >> m;
    
    for(int i=0; i<n; i++)
        fin >> primes[i];
        
    for(int i=1; i<=m; i++)
    {
        long long int min = 0;
        for(int j=0; j<n; j++)
        {
            while( nr[ indices[j] ] * primes[j] <= nr[i-1] ) indices[j]++;
            if( min==0 || min > nr[ indices[j] ] * primes[j] )         
                min = nr[ indices[j] ] * primes[j];
        }
        nr[i] = min;
        //cout << i << " " << nr[i] << "\n";
        //system("pause");
    }

    fout << nr[m] << "\n";    
    //system("pause");
    return 0;
}
