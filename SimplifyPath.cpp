#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	for (int i=1; i<=10; ++i) {
		v.push_back(i);
	}

	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); ++iter) {
		cout << *iter << " " ;
	}
	cout << "===" << v.size() << v[v.size()-1] << endl;
	
	while (v.size() > 1) {
		v.pop_back();
	}

	cout << "after pop" << endl;
	for (iter = v.begin(); iter != v.end(); ++iter) {
		cout << *iter << " " ;
	}
	cout << endl;

	return 0;
}
