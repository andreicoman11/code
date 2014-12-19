/*
ID: andreic4
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool verif(unsigned long int);
unsigned long int recalc( unsigned long int);

int main()
{
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    
    int m;
    fin >> m;
    m++;
    
    m = recalc(m);
    while( verif(m)==0 ) 
    {
        m = recalc(m+1);
        //cout << m << " ";
    }
    
    fout << m << "\n";
    //system("pause");
    return 0;
}


bool verif(unsigned long int m)
{
    int v[9];
    int a[9];
    int i=0,j=0;
    int digits[10]={0};
    while( m )
    {
        v[i++] = m%10;
        m = m/10;
        digits[ v[i-1] ]++;
        if( digits[ v[i-1] ]>1 ) return 0;
    }
    i--;
    /*
    for(int k=1; k<=9; k++)
        cout << digits[k] << " ";
    cout << "\n";
    /*
    for(int k=0; k<=i; k++)
        cout << v[k] << " ";
    cout << "\n";*/
    
    while( i>=0 )   a[j++] = v[i--];
    
    /*
    for(int k=0; k<j; k++)
        cout << a[k] << " ";
    cout << "\n";*/
    
    int d[9]={0};
    int cur=0;
    while( d[cur]==0 )
    {
        d[cur]=1;
        cur = ( cur + a[cur] )%j;
        //cout << cur << " ";     
    }
    if( cur ) return 0;
    for(int i=0; i<j; i++)
        if( d[i]==0 ) return 0;
        //else cout << d[i] << " ";
    return 1;
}

unsigned long int recalc( unsigned long int m)
{
    //cout << "recalc " << m << " ";
    int v[9];
    int i=0;
    while( m )
    {
        v[i++] = m%10;
        m = m/10;
    }
    i--;
    unsigned long int ans=0;
    while( i>=0 )
    {
        if( v[i]==0 ) v[i]++;
        ans = ans*10 + v[i];
        i--;
    }
    //cout << ans << "\n";
    //system("pause");
    return ans;
}

