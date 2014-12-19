/*
ID: andreic4
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <string> pre;
vector <string> pre2;
string word="";
bool v[2000001]={0};

void find(unsigned long int);
bool find2(int,int);

int main()
{
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
           
    string a;
    fin >> a;
    
    while( a!="." )
    {
        pre2.push_back(a);
        fin >> a;
    }
    for(int i=0; i<pre2.size(); i++)
    {
        word = pre2[i];
        if( find2(i,pre2[i].size()-1)==0 ) pre.push_back( pre2[i] );
    }
          
    /*for(int i=0; i<pre.size(); i++)
        cout << pre[i] << "\n";*/
    
    word = "";
    while( !fin.eof() )
    {
        char str[77];
        fin.getline( str, 77, '\n');
        word += str;
    }
    //cout << word.size() << "\n";
    //cout << v[13000] << v[13001] << v[13002] << v[13003] << v[13004] << v[13005] << v[13006] << v[13007] << v[13008] << "\n";
    //cout << word.substr( 15000,10) << "\n";
    //system("pause");
    v[0]=1;
    for(int i=0; i<word.size(); i++)
        find(i);
    //system("pause");
    int i=word.size();
    while( v[i]==0 ) i--;
    fout << i << "\n";
    
    //cout << word << "\n";
    //system("pause");
    return 0;
}

bool find2(int nr,int n)
{
    word = pre2[nr].substr(0,n+1);   
    for( int i=0; i<pre2.size(); i++)
    if( i!=nr )
    if( n+1>=pre2[i].size() )
    {
        int t=1;
        for(int j=pre2[i].size()-1, k=0; j>=0; j--,k++)
            if( pre2[i][j]!=word[n-k] ) t=0;
        //cout << word << " " << n << " " << pre2[i] << " " << t << "\n";
        if(t)
        {
            if( n+1==pre2[i].size() ) return 1;
            if( find2(nr,n-pre2[i].size())==1 ) return 1;
        }
    }
    return 0;
}

void find(unsigned long int start)
{
    /*if( start>12970 ) cout << "\t" << start << " " << v[start] << "\n";
    if( start>12970 ) 
    {
        cout << "passed first \n";
        system("pause");
    }*/
    if( start<word.size() )
    {
        /*if( start>12950 ) 
        {
            cout << "passed 2nd \n";
            system("pause");
        }*/
        if( v[start] )
        {
            /*if( start>12970 ) 
            {
                cout << "passed 3rd \n";
                system("pause");
            }*/
            for(int i=0; i<pre.size(); i++)
            {
                /*if( start>12970 ) 
                {
                    cout << "passed 4th at " << i << " \n";
                    system("pause");
                }*/
                if( word.substr( start, pre[i].size() ) == pre[i] )
                {
                    /*if( start>12970 ) 
                    {
                        cout << "passed 5th at " << i << " \n";
                        system("pause");
                    }*/
                    v[ start+pre[i].size() ]=1;
                }
            }
        }
        //if( start>12970 ) cout << "ended " << start << "\n";
    }
}
