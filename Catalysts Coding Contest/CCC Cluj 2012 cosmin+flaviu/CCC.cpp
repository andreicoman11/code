#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream fin("7.txt");
ofstream fout("soccer.out");

struct jucator
{
   int t,n,x,y,d,poss;
   double rd;
};
jucator j[1<<6];
 int pase[3];

struct poz
{
   int x,y;
};
poz last[64];
 poz ball;

int main()
{
   int x;
   int k=1;
   int frame=1;
   char c='a';
   for(int i=1;i<=30;i++)
   {
      j[i].poss=0;
      j[i].rd=0;
   }
   int stplayer,player,team,stteam;
  
   bool pas_start=false,nivel2=false;
   
   while(fin>>x)
   {
     ball.x=x;
      fin>>ball.y;
     
      c='a';
      if(frame!=1)
            for(int i=1;i<=k;i++)
            {
               last[i].x=j[i].x;
               last[i].y=j[i].y;
            } k = 1;
      while( c!='\n')
      {
      fin>>x;   
      j[k].t=x;
      fin>>x;
      j[k].n=x;
      fin>>x;
      j[k].x=x;
      fin>>x;
      j[k].y=x;
      fin.get(c);
      k++;
     
      }
      
      k--;
     
       int in_pos=0;
       for(int i=1;i<=k;i++)
      {
         
         if((j[i].x-ball.x)*(j[i].x-ball.x) + (j[i].y-ball.y)*(j[i].y-ball.y)*1.0<2.25)
          {
             in_pos++;
             team=j[i].t;
             player=i;
         }
      }
       if(in_pos==1 && pas_start && nivel2 && team==stteam && player!=stplayer)
      {
         pase[team]++;
         nivel2=false;
      }
       if(in_pos==1)
      {
         pas_start=true;
         stteam=team;
         stplayer=player;
      }
      else
         if(in_pos==0 && pas_start)
            nivel2=true;
         else if(in_pos>1)
            pas_start=false;

     
      if(in_pos!=0)
         nivel2=0;
    //  cout<<frame;

   }
   
   fout<<"1 "<<pase[1]<<" 2 "<<pase[2];           

   fin.close();
   fout.close();
   return 0;
}