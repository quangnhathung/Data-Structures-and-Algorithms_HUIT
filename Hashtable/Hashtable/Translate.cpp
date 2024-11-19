#include"Dictionary.h"
using namespace std;
int main() {
	Input(Bucket, "Dictionary.txt");
	system("pause");
	system("cls");
	while (1) {
		cout << "***************************************" << endl;
		cout << "*     QUANG NHAT HUNG TRANSLATE       *" << endl;
		cout << "***************************************" << endl;
		cout << "Word: ";
		string s;
		getline(cin, s);
		DictNode* p = SearchMeaning(Bucket, s);
		if (p == NULL) cout << "Khong co trong du lieu" << endl;
		else cout << "Meaning: " << p->key.Meaning << endl;
		system("pause");
		system("cls");
	}
	return 0;
}