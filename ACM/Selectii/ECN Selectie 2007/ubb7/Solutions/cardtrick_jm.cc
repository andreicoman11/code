#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,m;
	cin >> n;
	while (n--) {
		cin >> m;
		vector<int> deck(m);
		vector<int> current(m);
		for(int i=0;i<m;i++)
			current[i]=i;
		for(int i=0;i<m;i++) {
			for(int j=0;j<=i;j++) {
				int top=current[0];
				for(int k=0;k<current.size()-1;k++)
					current[k]=current[k+1];
				current[current.size()-1]=top;
			}
			deck[current[0]]=i+1;
			for(int k=0;k<current.size()-1;k++)
				current[k]=current[k+1];
			current.pop_back();
		}
		for(int i=0;i<m;i++) {
			if (i>0)
				cout << " ";
			cout << deck[i];
		}
		cout << endl;
	}
			
	return 0;
}
