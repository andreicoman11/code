//Sursa: 2003 ACM Southeastern Europe Problema E
//Metoda de rezolvare: Backtracking
//Timp: O(2^n) - de remarcat ca din cauza naturii problemei stackul nu ajunge la adancime mare 
//numai cand algoritmul construieste solutia corecta, solutiile gresite se detecteaza destul de repede
//Memorie: O(distanta maxima) Cel mai rau caz este cand avem doi copaci, 
//caci in acest caz P=distanta. Deci avem nevoie de memorie O(P)


#include <stdio.h>
#include <string.h>
#include <cmath>
#include <stdlib.h>

#define MAX 1000000 //Valoarea maxima lui P

long nr_dist /*Numarul distantelor*/,n/*numarul copacilor*/;
int was[MAX]/*was_i - cate valori egale cu i avem*/,length/*distanta maxima*/,ss[1500]/*stackul backtrackingului*/;
bool ans[MAX];//Solutia gasita
bool found;/*True cand am gasit solutie, pentru a putea sari afara din backtracking si pentru afisare*/

void write_data()
{
	found=true;
	int p=1, prev=0;
	for (int q=1;q<=length;++q)
	{
		if (ans[q])
		{
			p*=q-prev;
			prev=q;
		}
	}
	printf("%d%\n",p);
}

bool valid_station(int sp, int next_station) 
//Un copac este valid daca avem toate distantele de la cele adaugate anterior
{
	for (int q=1;q<sp;++q)
	{
		if (!was[abs(next_station-ss[q])]) return false;
	}
	return true;
}

void add_station(int sp, int next_station)
{
	ss[sp]=next_station;
	ans[next_station]=true;
	for (int q=1;q<sp;++q)
	{
		--was[abs(next_station-ss[q])];
	}
}

void remove_station(int sp, int next_station)
{
	ans[next_station]=false;
	for (int q=1;q<sp;++q)
	{
		++was[abs(next_station-ss[q])];
	}
}

void back(int sp, int next_station)
{
	if (sp>n) write_data();
	while (!was[next_station]) --next_station;
	if (valid_station(sp, next_station))
	{
		add_station(sp, next_station);
		back(sp+1,next_station);
		if (found) return; //Daca am gasit solutie, putem sari afara
		remove_station(sp, next_station);
	}
	if (valid_station(sp, length-next_station))
	{
		add_station(sp, length-next_station);
		back(sp+1,next_station);
		if (found) return;
		remove_station(sp, length-next_station);
	}
}

void main()
{
	memset(was,0,sizeof(was));
	while (scanf("%d",&nr_dist) == 1)
	{
		n=(sqrt(double(8*nr_dist+1))+1)/2; //Formula primita prin rezolvarea ecuatiei n*(n-1)/2 = nr_dist
		for (int q=0;q<nr_dist;++q)
		{
			int aux;
			scanf("%d",&aux);
			++was[aux];
		}
		length=MAX;
		while (!was[length]) --length;
	  
		memset(ans,false,sizeof(ans));
		ans[0]=true; //Sigur avem un copac in 0 
		ans[length]=true; //si in distanta maxima
		ss[1]=0; //Deci acestea le si putem adauga solutiei
		ss[2]=length;
		--was[length];
		found=false;
		back(3/*Backul incepem de la nivelul 3*/,length/*Ca optimizare, adaugam distantele incepand cu cele mai mari*/);
		if (!found) printf("No solution\n");
	}
}