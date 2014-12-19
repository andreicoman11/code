#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    ofstream fout ("A.out");
    ifstream fin  ("A.dat");
    
    int l[26];
    for(int i=0; i<26; i++)
        l[i] = i;
    string cifru = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    while( !fin.eof() )
    {
        char tmp[10001];
        fin.getline( tmp, 10001, '\n');
        string temp = tmp, word;
        istringstream get( temp );
        get >> word;
        for(int j=0; j<word.size(); j++)
            word[j] = tolower( word[j] );
        
        if( word=="cipher" )
        {
            int j=0;
            while( temp[j]!='c' && temp[j]!='C' ) j++;
            int v[26]={0};
            for(int i=j+7,k=0; i<temp.size(); i++)
                if( isalpha( temp[i]) )
                {
                    temp[i] = toupper( temp[i] );
                    v[ int(temp[i])-int('A') ] = k++;
                }
            int t=0;
            for(int i=0; i<26; i++)
                t += v[i];
            
            if( t!=325 ) 
            {
                fout << "Bad cipher. Using default\n";
                for(int i=0; i<26; i++)
                    l[i] = i;
                cifru = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            }
            else
            {
                cifru = "";
                fout << "Good cipher. Using ";
                for(int i=j+7; i<temp.size(); i++)
                    if( isalpha(temp[i]) )
                    {
                        temp[i] = toupper( temp[i] );
                        cifru += temp[i];
                        fout << temp[i];
                    }
                fout << "\n";
                
                for(int i=0; i<26; i++)
                    l[i] = v[i];
            }
            
        }
        else if( word=="encrypt" )
        {
            int i=0;
            while( temp[i]!='e' && temp[i]!='E' ) i++;
            i+=7;
            fout << "RESULT: ";
            for( ; i<temp.size(); i++)
                if( !isalpha( temp[i]) ) fout << temp[i];
                else
                {
                    int v1,v2;
                    
                    if( isupper(temp[i]) ) v2 = l[ int(temp[i]) - int('A') ];
                    else v2 = l[ int(temp[i]) - int('a')];
                    
                    if( isalpha(temp[i-1]) )
                    {
                        if( isupper(temp[i-1]) ) v1 = l[ int(temp[i-1]) - int('A') ];
                        else v1 = l[ int(temp[i-1]) - int('a') ];
                    }
                    else v1 = l[0];
                    
                    int val = v2-v1;
                    if( val<0 ) val += 26;
                    
                    if( isupper(temp[i]) ) fout << cifru[ val ];
                    else { char tt = tolower( cifru[ val ] ); fout << tt; }
                    
                    //cout << temp[i-1] <<  " " << temp[i] << " " << v1 << " " << v2 << " " << val << "\n"; system("pause");
                }
            
            fout << "\n";
            
        }
        else if( word=="decrypt" )
        {
            int i=0;
            while( temp[i]!='d' && temp[i]!='D' ) i++;
            i+=7;
            fout << "RESULT: ";
            char last;
            for( ; i<temp.size(); i++)
                if( !isalpha( temp[i]) ) fout << temp[i];
                else
                {
                    int v1,v2,val=0;
                    
                    if( isalpha(temp[i-1]) )
                    {
                        if( isupper(last) ) v1 = l[ int(last) - int('A') ];
                        else v1 = l[ int(last) - int('a') ];
                    }
                    else v1 = l[0];
                    
                    for(int k=0; k<26; k++)
                        if( cifru[k]==temp[i] ) val=k;
                        else if( int(cifru[k]) == int(temp[i])+int('A')-int('a') ) val=k;
                        
                    
                    v2 = val + v1;
                    if( v2>=26 ) v2-=26;
                    
                    if( isupper(temp[i]) ) { fout << cifru[v2]; last = cifru[v2]; }
                    else { char tt = tolower( cifru[ v2 ] ); fout << tt;  last = tt;}
                    
                    //cout << temp[i-1] << " " << temp[i] << " " << v1 << " " << v2 << " " << val << "\n"; system("pause");
                }
            
            fout << "\n";
        }
        else fout << "Command not understood.\n";
    }





 return 0;
}
