#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

ifstream fin("Bingo.in");
ofstream fout ("B.out");

int gcd(long long int, long long int);

int main()
{
    long long int games = 0, totalwords = 0;
    string line;
    vector<string> words;
    
    while( !fin.eof() )
    {
        getline(fin,line);
        
        for(int i=0; i<line.size(); i++)
            if( !isalpha(line[i]) ) line[i] = ' ';
            else if( int(line[i])<int('a')) line[i] = tolower(line[i]);
        
        istringstream in(line);
        string a;
        while( in >> a )
        {
            if( a=="bullshit" )
            {
                games++;
                totalwords += words.size();
                words.clear();
            }
            else
            {
                int ok=1;
                for(int i=0; i<words.size() && ok; i++)
                    if( words[i]==a ) ok=0;
                if( ok ) words.push_back(a);
            }
        }
    }
    
    long long int res = gcd(totalwords,games);
    fout << (totalwords/res) << " / " << (games/res) << "\n";
    
    return 0;
}

int gcd(long long int a, long long int b)
{
    while( b!=0 )
    {
        long long int c = a;
        a = b;
        b = c%b;
    }
    return a;
}
