//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "Fraction.h"
//toi gian phan so
int UCLN(int a, int b) {//tim ucln
	/*a = abs(a);
	b = abs(b);
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;*/
	int ucln = 1;
	for (int i = 1; i <= a || i <= b; i++) {
		if (a % i == 0 && b % i == 0) ucln = i;
	}
	return ucln;
}
void SimplifyFraction(int& a, int& b) {
	while (UCLN(a, b) != 1) {
		int x = UCLN(a, b);
		a /= x;
		b /= x;
	}
}
//dinh dang phan so (tu +,mau- thi doi dau/tu, mau - thi doi thanh +
void format(int& a, int& b) {
	if (b == 0) return;
	if (a > 0 && b < 0) {
		a *= -1;
		b *= -1;
	}
	if (a < 0 && b < 0) {
		a *= -1;
		b *= -1;
	}
	SimplifyFraction(a, b);
	return;
}