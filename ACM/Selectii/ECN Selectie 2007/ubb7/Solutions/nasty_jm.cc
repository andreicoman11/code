#include <iostream>

using namespace std;

int main()
{
	int n,x,y,z;
	cin >> n;
	while (n--) {
		cin >> x >> y >> z;
		if (x > y-z)
			cout << "do not advertise" << endl;
		else if (x == y-z)
			cout << "does not matter" << endl;
		else
			cout << "advertise" << endl;
	}
	return 0;
}
