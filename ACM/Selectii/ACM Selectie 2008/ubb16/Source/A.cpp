#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define FORI(i,s) for (int i=0;i<s.size();i++)
#define BEND(x) (x).begin(),(x).end()
#define FORALL(it,st) for(typeof(st.begin())it=st.begin();it!=st.end();it++)

void docase() {
 char proj[32768], foo[32768];
 vector<string> prj;
 vector<set<string> > dudes;
 map<string,int> occurs;
 while (1) {
  gets(proj);
  hax:
  if (proj[0] == '0') exit(0);
  if (proj[0] == '1') break;
  set<string> me;
  prj.push_back(string(proj));
  while (1) {
   gets(foo);
   if (!islower(foo[0])) {
    strcpy(proj,foo);
    dudes.push_back(me);
    FORALL(it,me) occurs[*it]++;
    goto hax;
   }
   me.insert(string(foo));
  }
 }
 set<pair<int,string> > ans;
 FORI(i,prj) {
  int j=0;
  FORALL(it,dudes[i]) j += occurs[*it] == 1;
  ans.insert(make_pair(-j,prj[i]));
 }
 FORALL(it,ans) printf("%s %i\n", it->second.c_str(), -it->first);
}

int main() {
 while (1) docase();
}
