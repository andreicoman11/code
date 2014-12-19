/*
ID: andreic4
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int eq( string, string );

int main()
{
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream f ("dict.txt");
    
    int t=0;
    string n;
    fin >> n;
    
    string temp;    
    
    while( temp!="ZYTA" )
    {
        f >> temp;
        //cout << temp << " " << eq( temp,n ) << "\n";
        if( eq( temp,n ) )
        {
            fout << temp << "\n";
            t=1;
        }        
    }
    
    if( t==0 ) fout << "NONE\n";
    //system("pause");
    return 0;
}

int eq( string tmp, string n )
{
    if( tmp.size()!=n.size() ) return 0;
    
    for(int i=0; i<n.size(); i++)
        if( n[i]=='2' ) 
        {
            if( tmp[i]!='A' && tmp[i]!='B' && tmp[i]!='C' ) return 0;
        }
        else if( n[i]=='3' ) 
        {
            if( tmp[i]!='D' && tmp[i]!='E' && tmp[i]!='F' ) return 0;
        }
        else if( n[i]=='4' ) 
        {
            if( tmp[i]!='G' && tmp[i]!='H' && tmp[i]!='I' ) return 0;
        }
        else if( n[i]=='5' ) 
        {
            if( tmp[i]!='J' && tmp[i]!='K' && tmp[i]!='L' ) return 0;
        }
        else if( n[i]=='6' ) 
        {
            if( tmp[i]!='M' && tmp[i]!='N' && tmp[i]!='O' ) return 0;
        }
        else if( n[i]=='7' ) 
        {
            if( tmp[i]!='P' && tmp[i]!='R' && tmp[i]!='S' ) return 0;
        }
        else if( n[i]=='8' ) 
        {
            if( tmp[i]!='T' && tmp[i]!='U' && tmp[i]!='V' ) return 0;
        }
        else if( n[i]=='9' ) 
        {
            if( tmp[i]!='X' && tmp[i]!='Y' && tmp[i]!='Z' ) return 0;
        }
    return 1;
}
