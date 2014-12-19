/*
ID: andreic4
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX 1000000

using namespace std;

int main()
{
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
    
    vector <string> map,map2;
    
    for(int i=0; i<10; i++)
    {
        string temp;
        fin >> temp;
        map.push_back(temp);
    }
    map2 = map;
    int f1,f2,c1,c2;
    
    for(int i=0; i<10; i++)
    for(int j=0; j<10; j++)
        if( map[i][j]=='F' )
        {
            map[i][j]='N';
            map2[i][j]='.';
            f1=i;
            f2=j;
        }
        else if( map[i][j]=='C' )
        {
            map2[i][j]='N';
            map[i][j]='.';
            c1=i;
            c2=j;
        }
    
    long long int t=0;
    
    while( t<MAX && (f1!=c1 || f2!=c2) )
    {
        if( map[f1][f2]=='N')
        {        
            if( f1>0 && map[f1-1][f2]!='*' ) { f1--; map[f1][f2] = map[f1+1][f2]; map[f1+1][f2]='.'; }
            else map[f1][f2]='E';
        }
        else if( map[f1][f2]=='E')
        {         
            if( f2<9 && map[f1][f2+1]!='*' ) { f2++; map[f1][f2] = map[f1][f2-1]; map[f1][f2-1]='.'; }
            else map[f1][f2]='S';
        }
        else if( map[f1][f2]=='S')
        {         
            if( f1<9 && map[f1+1][f2]!='*' ) { f1++; map[f1][f2] = map[f1-1][f2]; map[f1-1][f2]='.'; }
            else map[f1][f2]='W';
        }
        else if( map[f1][f2]=='W')
        {         
            if( f2>0 && map[f1][f2-1]!='*' ) { f2--; map[f1][f2] = map[f1][f2+1]; map[f1][f2+1]='.'; }
            else map[f1][f2]='N';
        }
        
        if( map2[c1][c2]=='N')
        {         
            if( c1>0 && map2[c1-1][c2]!='*' ) { c1--; map2[c1][c2] = map2[c1+1][c2]; map2[c1+1][c2]='.'; }
            else map2[c1][c2]='E';
        }
        else if( map2[c1][c2]=='E')
        {         
            if( c2<9 && map2[c1][c2+1]!='*' ) { c2++; map2[c1][c2] = map2[c1][c2-1]; map2[c1][c2-1]='.'; }
            else map2[c1][c2]='S';
        }
        else if( map2[c1][c2]=='S')
        {         
            if( c1<9 && map2[c1+1][c2]!='*' ) { c1++; map2[c1][c2] = map2[c1-1][c2]; map2[c1-1][c2]='.'; }
            else map2[c1][c2]='W';
        }
        else if( map2[c1][c2]=='W')
        {         
            if( c2>0 && map2[c1][c2-1]!='*' ) { c2--; map2[c1][c2] = map2[c1][c2+1]; map2[c1][c2+1]='.'; }
            else map2[c1][c2]='N';
        }
        
        t++;
        
        /*cout << t << "\n";
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
                cout << map[i][j];
            cout << "\n";
        }
        system("pause");*/
    }
    
    if( t==MAX ) fout << "0\n";
    else fout << t << "\n";
    
    //system("pause");
    return 0;
}
