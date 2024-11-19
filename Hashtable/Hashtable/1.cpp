#include"HashTble(interger).h"
using namespace std;

int main() {
	cout << "Nhap gia tri: ";
	int x;
	cin >> x;
	while (x!=-1) {
		cin >> x;
		Insert(bucket, x);
	}
	cout << endl;
	Show(bucket);
	return 0;
}