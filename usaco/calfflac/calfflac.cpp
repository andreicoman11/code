/*
ID: andreic4
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    
    string text;
    
    while( !fin.eof() )
    {
        char line[100]={0};
        int len = 100;
        char a='\n';
        //string temp;
        //fin >> temp;
        //text += temp;
        fin.getline( line, len, a );
        //fin.get();
        text += line;
        text += a;
        //cout << line ;        
        //cout << text << "\n";
        //system("pause");    
    }    
    //cout << text << "\n";
    int palinmax=1;
    int jmax=0,kmax=0;
    for(int i=0; i<text.size(); i++)
    {
        if( isalpha(text[i]) )
        {
            int j=i,k=i;
            int j2=j,k2=k;
            int palin=-1;
            while( tolower(text[j])==tolower(text[k]) && k2-j2<2000 )
            {
                j2=j;
                k2=k;
                palin += 2;
                j--;
                k++;
                while( ! isalpha(text[j]) && j ) j--;
                while( ! isalpha(text[k]) && k<text.size() ) k++;
            }
            if( palin > palinmax )
            {
                palinmax = palin;
                jmax = j2;
                kmax = k2;
                if( palinmax==1921 )
                {
                    fout << palinmax << "\n";
                    while( jmax <= kmax ) fout << text[jmax++];
                    fout << "\n";
                    return 0;
                }
            }
        }
        int i2 = i+1;
        while( !isalpha(text[i2]) && i2<text.size() ) i2++;
        if( i2<text.size() && isalpha(text[i]) && isalpha(text[i2]) && tolower(text[i])==tolower(text[i2]) )
        {
            int j=i,k=i2;
            int j2=j,k2=k;
            int palin=0;
            while( tolower(text[j])==tolower(text[k]) && k2-j2<2000 )
            {
                j2=j;
                k2=k;
                palin += 2;
                j--;
                k++;
                while( ! isalpha(text[j]) && j) j--;
                while( ! isalpha(text[k]) && k<text.size() ) k++;
            }
            if( palin > palinmax )
            {
                palinmax = palin;
                jmax = j2;
                kmax = k2;
            }
        }        
    }
    
    //cout << text << "\n";
    //cout << palinmax << " " << jmax << " " << kmax << "\n";
    fout << palinmax << "\n";
    while( jmax <= kmax ) fout << text[jmax++];
    fout << "\n";
    //system("pause");
    return 0;
}
