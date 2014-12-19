/*
ID: andreic4
PROG: heritage
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ofstream fout ("heritage.out");
char v[30][3];
    
int val(char a)
{
    return int(a)-int('A');
}

char root(string,string);
int cauta(char a, string s1)
{
    for(int i=0; i<s1.size(); i++)
        if( s1[i]==a ) return i;
    return -1;
}
void afis(int);

int main()
{
    
    ifstream fin ("heritage.in");
    string s1,s2;
    fin >> s1 >> s2;
    
    if( s1.size()<2 ) { fout << s1 << "\n"; return 0; }
    int rot = val(s2[0]);
    int zid = cauta(s2[0],s1);
    string s11 = s1.substr(0,zid);
    string s12 = s1.substr(zid+1,s1.size()-zid-1);
    string s21 = s2.substr(1,zid);
    string s22 = s2.substr(zid+1,s2.size()-zid-1);
    //cout << s11 << " " << s12 << " " << s21 << " " << s22 << "\n";
    //system("pause");
    v[rot][0] = s2[0];
    if( s11.size() ) v[rot][1] = root(s11,s21);
    else v[rot][1] = '0';
    if( s12.size() ) v[rot][2] = root(s12,s22);
    else v[rot][2] = '0';
    
    /*for(int i=0; i<26; i++)
        cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << "\n";
    system("pause");*/
    
    afis(rot);
    fout << "\n";
    //system("pause");
    return 0;
}

char root(string s1,string s2)
{
    //cout << s1 << " " << s2 << "\n";
    //system("pause");
    int rot = val(s2[0]);
    int zid = cauta(s2[0],s1);
    string s11 = s1.substr(0,zid);
    string s12 = s1.substr(zid+1,s1.size()-zid-1);
    string s21 = s2.substr(1,zid);
    string s22 = s2.substr(zid+1,s2.size()-zid-1);
    v[rot][0] = s2[0];
    if( s11.size() ) v[rot][1] = root(s11,s21);
    else v[rot][1] = '0';
    if( s12.size() ) v[rot][2] = root(s12,s22);
    else v[rot][2] = '0';
    return s2[0];
}

void afis(int k)
{
    //cout << char(k+int('A')) << "\n";
    //system("pause");
    if( v[k][1]!='0' ) afis( val(v[k][1]) );
    if( v[k][2]!='0' ) afis( val(v[k][2]) );
    fout << v[k][0];
}
