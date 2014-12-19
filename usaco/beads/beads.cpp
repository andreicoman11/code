/*
ID: andreic4
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    
    int n;
    fin >> n;
    string a;
    fin >> a;
    
    a += a;
    int max=1;
    
    for( int i=0; i<a.size(); i++)
    {
        int cur=0;
        if( a[i]=='r' )
        {
            //cout << i << " " << "r " ;
            while( a[i+cur]!='b' && i+cur<a.size() ) { cur++; }
            //cout << cur << "\t";
            while( a[i+cur]!='r' && i+cur<a.size() ) { cur++; }
            if( cur>max ) {max=cur; }
            //cout << cur << " " << max << "\n";
        }
        else if( a[i]=='b' )
        {
            //cout << i << " " << "b " ;
            while( a[i+cur]!='r' && i+cur<a.size() ) { cur++; }
            //cout << cur << "\t";
            while( a[i+cur]!='b' && i+cur<a.size() ) { cur++; }
            if( cur>max ) {max=cur; }
            //cout << cur << " " << max << "\n";
        }
        else
        {
            while( a[i+cur]=='w' && i+cur<a.size() ) cur++;
            if( a[i+cur]=='r' )
            {
                //cout << i+cur << " " << "r " ;
                while( a[i+cur]!='b' && i+cur<a.size() ) { cur++; }
                //cout << cur << "\t";
                while( a[i+cur]!='r' && i+cur<a.size() ) { cur++; }                
                //cout << cur << " " << max << "\n";
            }
            else if( a[i+cur]=='b' )
            {
                //cout << i+cur << " " << "b " ;
                while( a[i+cur]!='r' && i+cur<a.size() ) { cur++; }
                //cout << cur << "\t";
                while( a[i+cur]!='b' && i+cur<a.size() ) { cur++; }                
                //cout << cur << " " << max << "\n";
            }
            if( cur>max ) {max=cur; }
        }
    }
    
    fout << ( max > n ? n : max ) << "\n";
    //system("pause");
    return 0;
}
