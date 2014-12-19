/*
ID: andreic4
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n;
char a[10][10], b[10][10];

void rotate();
void reflect();
int equals();

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    
    int t=1;
    int e=0;
    fin >> n;
    
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        fin >> a[i][j];
        
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        fin >> b[i][j];
    
    if( equals() ) { e=1; }
    rotate();
    if( equals() && t) { fout << "1\n"; t=0; }
    rotate();
    if( equals() && t) { fout << "2\n"; t=0; }
    rotate();
    if( equals() && t) { fout << "3\n"; t=0; }
    
    rotate();
    reflect();
    if( equals() && t) { fout << "4\n"; t=0; }
    rotate();
    if( equals() && t) { fout << "5\n"; t=0; }
    rotate();
    if( equals() && t) { fout << "5\n"; t=0; }
    rotate();
    if( equals() && t) { fout << "5\n"; t=0; }
    
    if( t && e ) fout << "6\n";
    if( t ) fout << "7\n";
    //system("pause");
    return 0;
}

void rotate()
{
    char x[10][10];
    
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        x[j][n-i-1] = a[i][j];
    
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j]=x[i][j];
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";      
}

void reflect()
{
    char x[10][10];
    
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        x[i][n-j-1] = a[i][j];
    
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j]=x[i][j];
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";      
}

int equals()
{
    for(int j=0; j<n; j++)
    for(int i=0; i<n; i++)
        if( a[i][j]!=b[i][j] ) return 0;
    return 1;
}
