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

int t=0;

void search(string);

int main()
{
    ofstream fout ("cryptcow.out");
    ifstream fin ("cryptcow.in");
    
    string line;
    char temp[100];
    fin.getline( temp, 100, '\n' );
    line = temp;    
    if( (line.size()-47)%3==0 )  search(line);
    
    if(t)
    {
        fout << "1 ";
        int k=0;
        for(int i=0; i<line.size(); i++)
            if( line[i]=='C' ) k++;
        fout << k << "\n";
    }
    else fout << "0 0\n";
    
    //system("pause");
    return 0;
}

void search(string l)
{
    cout << l << "\n";
    system("pause");
    if( l=="Begin the Escape execution at the Break of Dawn" ) t=1;
    if( !t )
    {
        for(int i=0; i<l.size()-2 && !t; i++)
            if( l[i]=='C' )
        for(int j=i+1; j<l.size()-1 && !t; j++)
            if( l[j]=='O' )
        for(int k=j+1; k<l.size() && !t; k++)
            if( l[k]=='W' )
            {
                string temp="";
                for(int ii=0; ii<i; ii++)
                    temp += l[ii];
                for(int ii=j+1; ii<k; ii++)
                    temp += l[ii];
                for(int ii=i+1; ii<j; ii++)
                    temp += l[ii];
                for(int ii=k+1; ii<l.size(); ii++)
                    temp += l[ii];
                search( temp );
            }
    }
}
