//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "Dictionary.h"
#include"ASCIInode.h"
//Do thoi gian hoc ly thuyet ngan,nen thay chi day thuaatj toan
// vi vay em khong hieu code trong sach(phan BalFactor) nen em danh hoc tu been ngoai
// em xin loi vi dieu nay a!

void menu() {
	cout << "*******************************" << endl;
	cout << "*  Quang Nhat Hung Dictionary *" << endl;
	cout << "***************************** *" << endl;
	cout << "*0. Thoat.                    *" << endl;
	cout << "*1. Khoi tao tu dien.         *" << endl;
	cout << "*2. Tra Anh-Viet.             *" << endl;
	cout << "*3. Dong gop vao bo du lieu.  *" << endl;
	cout << "*4. Xoa Tu.                   *" << endl;
	cout << "*5. Xoa toa bo tu dien.       *" << endl;
	cout << "*******************************" << endl;
	cout << "\tOPTION: ";
}
void End() {
	system("pause");
	system("cls");
}
int main() {
	AVLTreeDictionary tr;
	Init_Dictionary(tr);
	int z;
	cout << "Ps: Bo tu dien nay co 2 bo du lieu." << endl << endl;
	do {
		menu();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			cout << "1. Bo du lieu chinh.(khong the in cay)" << endl;
			cout << "2. Bo du lieu demo.(co the in cay)" << endl;
			cout << "\tOPTION: "; int x; cin >> x;
			switch (x) {
			case 1: {
				InputDictionary(tr.Root);
				End();
				break;
			}
			case 2: {
				InputDictionaryDemo(tr.Root);
				cout << endl;
				print_ascii_treeDct(tr.Root);
				End();
				break;
			}
			}
			break;
		}
		case 2: {
			cin.ignore();
			string s;
			cout << "Tra tu o day: "; getline(cin, s);
			AVLDictNode* p = Translate(tr.Root, s);
			if (p == NULL) {
				cout << "Co le tu nay chua co trong bo duw lieu! :<" << endl << endl;
				break;
			}
			cout << p->Data.Vocabulary << ": " << p->Data.Meaning << endl;
			End();
			break;
		}
		case 3: {
			cin.ignore();
			string s;
			cout << "Nhap tu can xoa: "; getline(cin, s);
			Dlt_Vocabulary(tr.Root, s);
			cout << "Done!" << endl;
			End();
			break;
		}
		case 4: {
			cin.ignore();
			Dictionary x;
			cout << "Nhap vocabulary: "; cin >> x.Vocabulary;
			cout << "Nhap nghia: "; cin >> x.Meaning;
			Add_Dictionary(tr.Root, CreateDictnode(x));
			UpdateData(tr.Root, "Dictionaty.txt");
			cout << "Cam on ban da dong gop du lieu!" << endl;
			cout << "Done!" << endl;
			End();
			break;
		}
		case 5: {
			Dlt_Dct(tr.Root);
			cout << "Done!" << endl;
			End();
			break;

		}
		}
	} while (z != 0);
	return 0;
}