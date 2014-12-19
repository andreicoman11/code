#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("F.dat");

typedef struct list{
	list* next;
	list* prev;
	int val;
	int no;
} nod;

int main()
{
	while(!fin.eof())
	{
		int N, r[1000], pol=1, rem=0;
		nod* first=0;
		nod* last=0;
		fin >> N;
		fin >> r[0];
		for(int i=0; i<r[0]; i++)
			fin >> r[i+1];
		char c;
		fin >> c;
		while( c!='e' )
		{
			//cout << c << endl;
			if( c=='a' ) {
				int id;
				fin >> id;
				//cout << id;
				int f = 0;
				nod* parse = first;
				while( parse!=0 )
				{
					if( parse->val == id )
					{
						parse->no++;
						f = 1;
						break;
					}
					parse = parse->next;
				}
				if( !f ) {
					nod* n = new nod;
					n->val = id;
					n->no = 1;
					if( first==0 )
					{
						//cout << "first";
						first = n;
						last = n;
						n->prev = 0;
						n->next = 0;
					} else {
						parse = first;
						while( parse!=0 && id > parse->val )
							parse = parse->next;
						if( parse==first )
						{
							//cout << "add to begin";
							n->next = first;
							n->prev = 0;
							first->prev = n;
							first = n;
						} else if( parse == 0 ) {
							//cout << "add to end";
							last->next = n;
							n->prev = last;
							n->next = 0;
							last = n;
						} else {
							//cout << "add to middle";
							n->next = parse;
							n->prev = parse->prev;
							(parse->prev)->next = n;
							parse->prev = n;
						}
					}
				}				

			} else if( c=='p' ) {
				fin >> pol;

			} else if( c=='r' ) {
				if( first==0 ) {
					cout << "-1\n";
				} else {
					rem++;
					int f = 0;
					for(int i=0; i<r[0]; i++)
						if( r[i+1]==rem ){
							f=1;
							break;
						}
					if( pol==1 ) {
						if( f )
							cout << first->val << endl;
						first->no--;
						if( first->no==0 ) {
							if( first->next!=0 ) {
								nod* aux = first;
								first = first->next;
								first->prev = 0;
								delete aux;
							} else
							{
								delete first;
								first = 0;
								last = 0;
							}
						} 
							
					} else {
						if( f )
							cout << last->val << endl;
						last->no--;
						if( last->no==0 ) {
							if( last->prev!=0 ) {
								nod* aux = last;
								last = last->prev;
								last->next = 0;
								delete aux;
							} else
							{
								delete last;
								first = 0;
								last = 0;
							}
						}
					}
				}
			}
			fin >> c;
		}
		cout << endl;
	}
	return 0;
}