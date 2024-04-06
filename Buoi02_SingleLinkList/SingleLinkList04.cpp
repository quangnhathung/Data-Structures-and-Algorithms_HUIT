//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

struct Lophocphan {
	string MaHocPhan;
	string TenHocPhan;
	int Sotinchi;
	float DTL;
	float DCK;
	float TongHocphan;
};
struct SinhVien {
	string Maso;
	string Hodem;
	string ten;
	int Namsinh;
	float DiemKq;
	vector<Lophocphan> Hocphan;
};
struct SNode {
	SinhVien Data;
	SNode* Next;
};
struct SList {
	SNode* Head;
	SNode* Tail;
};
//ham
void Init_Slist(SList& sl) {
	sl.Head = sl.Tail = NULL;
}
bool IsEmpty(SList sl) {
	if (sl.Head == NULL) return true;
	return false;
}
void Add_Head(SList& sl, SNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	p->Next = sl.Head;
	sl.Head = p;
	return;
}
void Add_Tail(SList& sl, SNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	sl.Tail->Next = p;
	sl.Tail = p;
}
SNode* CreateSNode(SinhVien x) {
	SNode* p = new SNode;
	p->Data = x;
	p->Next = NULL;
	return p;
}
void InputFromFile(SList& sl) {
	ifstream file1("sinhvien.txt");
	//ifstream file2("lophocphan.txt");
	if (!file1.is_open()) {
		cerr << "Mo file sinh vien that bai!!" << endl;
		return;
	}
	string s1;
	while (getline(file1, s1)) {
		SinhVien x;
		stringstream ss1(s1);
		getline(ss1, x.Maso, ',');
		getline(ss1, x.Hodem, ',');
		getline(ss1, x.ten, ',');
		ss1 >> x.Namsinh;
		ss1.ignore();
		ifstream file2("lophocphan.txt");
		if (!file2.is_open()) {
			cerr << "Mo file hoc phan that bai!!" << endl;
			return;
		}
		string s2;
		while (getline(file2, s2)) {
			stringstream ss2(s2);
			Lophocphan z;
			getline(ss2, z.MaHocPhan, ',');
			getline(ss2, z.TenHocPhan, ',');
			ss2 >> z.Sotinchi;
			ss2.ignore();
			x.Hocphan.push_back(z);

		}
		file2.close();
		Add_Tail(sl, CreateSNode(x));
	}
	file1.close();
}
void InputDieuAuto(SList& sl) {
	SNode* p = sl.Head;
	ifstream file("diem.txt");
	if (!file.is_open()) {
		cerr << "Mo file diem that bai!!" << endl;
		return;
	}
	while (p != NULL) {
		for (size_t i = 0; i < p->Data.Hocphan.size(); i++) {
			float x; file >> x;
			float y; file >> y;
			p->Data.Hocphan[i].DTL = x;
			p->Data.Hocphan[i].DCK = y;
			p->Data.Hocphan[i].TongHocphan = p->Data.Hocphan[i].DTL * 0.3 + p->Data.Hocphan[i].DCK * 0.7;
		}
		p = p->Next;
	}
	file.close();
	//diem.clear();//xoa vector
}
void InputDiem(SinhVien& x) {
	for (size_t i = 0; i < x.Hocphan.size(); i++) {
		cout << x.Hocphan[i].TenHocPhan << ": " << endl;
		cout << "\tNhap diem giua ki: "; cin >> x.Hocphan[i].DTL;
		cout << "\tNhap diem cuoi ki: "; cin >> x.Hocphan[i].DCK;
		x.Hocphan[i].TongHocphan = x.Hocphan[i].DTL * 0.3 + x.Hocphan[i].DCK * 0.7;
	}
}
float Tinhdiemkqht(SinhVien x) {
	int tong = 0;
	for (size_t i = 0; i < x.Hocphan.size(); i++) {
		tong += x.Hocphan[i].Sotinchi;
	}
	float diem = 0;
	for (size_t i = 0; i < x.Hocphan.size(); i++) {
		diem += (x.Hocphan[i].TongHocphan * x.Hocphan[i].Sotinchi) / tong;
	}
	return diem;
}
//tinh diem trung binh
void Inputdiemtb(SList& sl) {
	SNode* p = sl.Head;
	while (p != NULL) {
		p->Data.DiemKq = Tinhdiemkqht(p->Data);
		p = p->Next;
	}
}
void PrintMark(SList sl) {
	SNode* p = sl.Head;
	cout << "*********************************************************************" << endl;
	cout << setw(16) << left << "Ma Sinh vien" << setw(19) << left << "Ho Dem" << setw(7) << left << "Ten" << setw(10) << left << "Nam sinh" << setw(10) << left << "Diem ket qua" << endl;
	cout << "*********************************************************************" << endl;
	while (p != NULL) {
		cout << setw(16) << left << p->Data.Maso << setw(19) << left << p->Data.Hodem << setw(9) << left << p->Data.ten << setw(12) << left << p->Data.Namsinh << setw(13) << left << fixed << setprecision(2) << p->Data.DiemKq << endl;
		p = p->Next;

	}
}
SNode* GetStd(SList sl, string s) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.Maso == s) {
			return p;
		}
		p = p->Next;
	}
	return NULL;
}
void PrintStudent(SNode* p) {
	cout << setw(33) << left << "\t    " + p->Data.Hodem + " " + p->Data.ten << "* " << setw(15) << left << "Diem giua ki" << setw(15) << "Diem cuoi ki" << "Trung binh hoc phan" << endl;
	cout << "********************************************************************************************" << endl;
	for (size_t i = 0; i < p->Data.Hocphan.size(); i++) {
		cout << setw(41) << p->Data.Hocphan[i].TenHocPhan << setw(7) << left << "* " << setw(17) << left << p->Data.Hocphan[i].DTL << setw(17) << p->Data.Hocphan[i].DCK << p->Data.Hocphan[i].TongHocphan << endl;
	}
	cout << "*********************************************************************************************" << endl;
	cout << "Diem ket qua hoc tap: " << p->Data.DiemKq << endl;
	cout << "*********************************************************************************************" << endl;
}
//Ham
void Student(SList sl, string s) {
	SNode* p = sl.Head;
	int x = 0;
	while (p != NULL) {
		if (p->Data.Maso == s) {
			cout << "Ma so: " << p->Data.Maso << endl;
			cout << "Ho va ten: " << p->Data.Hodem + " " + p->Data.ten << endl;
			cout << "Nam sinh: " << p->Data.Namsinh << endl;
			cout << "Diem trung binh hoc ky: " << p->Data.DiemKq << endl;
			x++;
		}
		p = p->Next;
	}
	if (x == 0) cerr << "Khong tim thay sinh vien !" << endl;
}
//sap xep
void Swap(SNode* p, SNode* q) {
	SinhVien temp = p->Data;
	p->Data = q->Data;
	q->Data = temp;
}
void Sort1(SList& sl) {//xep theo ma
	SNode* p = sl.Head;
	while (p != NULL) {
		SNode* q = p;
		while (q != NULL) {
			if (p->Data.Maso > q->Data.Maso) {
				Swap(p, q);
			}
			q = q->Next;
		}
		p = p->Next;
	}
}
void Sort2(SList& sl) {//xep theo ten
	SNode* p = sl.Head;
	while (p != NULL) {
		SNode* q = p;
		while (q != NULL) {
			if (p->Data.ten > q->Data.ten) {
				Swap(p, q);
			}
			q = q->Next;
		}
		p = p->Next;
	}
}
bool Check(SList sl, string s) {
	//kiem ra co trung khoa hay khong tra
	if (IsEmpty(sl)) return false;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.Maso == s) return true;//trung
		p = p->Next;
	}
	return false;//khong trung
}
void Add_Std(SList& sl) {
	SinhVien x;
	ifstream file("lophocphan.txt");
	if (!file.is_open()) {
		cerr << "Mo file that bai!!";
		return;
	}
	do {
		cout << "Nhap ma sinh vien: "; getline(cin, x.Maso);
	} while (Check(sl, x.Maso));
	cout << "Nhap ho dem sinh vien: "; getline(cin, x.Hodem);
	cout << "Nhap ten sinh vien: "; getline(cin, x.ten);
	cout << "Nam sinh: ", cin >> x.Namsinh;
	cin.ignore();
	string s2;
	while (getline(file, s2)) {
		stringstream ss2(s2);
		Lophocphan z;
		getline(ss2, z.MaHocPhan, ',');
		getline(ss2, z.TenHocPhan, ',');
		ss2 >> z.Sotinchi;
		ss2.ignore();
		x.Hocphan.push_back(z);
	}
	InputDiem(x);
	Add_Tail(sl, CreateSNode(x));
	Inputdiemtb(sl);
	Sort1(sl);
	file.close();
}
//xoa
//find 
int check(SList sl, string x) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.Maso == x) return 1;
		p = p->Next;
	}
	return 0;
}

SNode* Get_NodePrv(SList sl, SNode* p) {
	SNode* q = sl.Head;
	if (p == NULL) {
		cerr << "Loi!";
		return NULL;
	}
	if (p == sl.Head) {
		return NULL;
	}
	while (q->Next != p) {
		q = q->Next;
	}
	return q;
}
void Dlt_Tail(SList& sl) {
	if (sl.Head == NULL) return;
	if (sl.Head == sl.Tail) {
		SNode* p = sl.Head;
		Init_Slist(sl);
		delete p;
		return;
	}
	SNode* p = sl.Tail;
	SNode* q = Get_NodePrv(sl, sl.Tail);
	sl.Tail = q;
	sl.Tail->Next = NULL;
	delete p;
}
void Dlt_Head(SList& sl) {
	if (sl.Head == NULL) return;
	if (sl.Head == sl.Tail) {
		SNode* p = sl.Head;
		Init_Slist(sl);
		delete p;
		return;
	}
	SNode* p = sl.Head;
	sl.Head = p->Next;
	delete p;
}
void Dlt_Node(SList& sl, SNode* p) {
	if (IsEmpty(sl)) return;
	if (p == sl.Head) {
		Dlt_Head(sl);
		return;
	}
	if (p == sl.Tail) {
		Dlt_Tail(sl);
		return;
	}
	if (sl.Head == sl.Tail && sl.Head == p) {
		Init_Slist(sl);
		delete p;
	}
	SNode* q = Get_NodePrv(sl, p);
	SNode* I = p->Next;
	q->Next = I;
	delete p;
}
//xoa tat ca co ten x
void Dlt_Code(SList& sl, string s) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.ten == s) {
			SNode* q = p;
			p = p->Next;
			Dlt_Node(sl, q);
			continue;
		}
		p = p->Next;
	}
}
//xoa theo ma
void Dlt_Code1(SList& sl, string s) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.Maso == s) {
			SNode* q = p;
			p = p->Next;
			Dlt_Node(sl, q);
			return;
		}
		p = p->Next;
	}
}
void Sort3(SList &sl) {//xep theo ddiem tb
	SNode* p = sl.Head;
	while (p != NULL) {
		SNode* q = p;
		while (q != NULL) {
			if (p->Data.DiemKq < q->Data.DiemKq) {
				Swap(p, q);
			}
			q = q->Next;
		}
		p = p->Next;
	}
}
void Print(SList sl) {
	cout << setw(5) << left << "STT" << setw(25) << "Ho va ten" << setw(15) << left << "Nam sinh" << setw(20) << "Diem trung binh" << endl;
	cout << "**************************************************************************************" << endl;
	int pos = 1;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.DiemKq >= 7.0 && p->Data.DiemKq <= 8.5) {
			cout << setw(5) << left << pos << setw(25) << p->Data.Hodem + " " + p->Data.ten << setw(22) << left << p->Data.Namsinh << setw(20) << p->Data.DiemKq << endl;
			pos++;
		}
		p = p->Next;
	}
}
//Tim min,max
float min(SList sl) {
	float min = sl.Head->Data.DiemKq;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.DiemKq < min) min = p->Data.DiemKq;
		p = p->Next;
	}
	return min;
}
float max(SList sl) {
	float max = sl.Head->Data.DiemKq;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.DiemKq > max) max = p->Data.DiemKq;
		p = p->Next;
	}
	return max;
}
SNode* GetMinMax(SList sl, float x) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.DiemKq == x) return p;
		p = p->Next;
	}
	return NULL;
}
float Mincase11(SList sl) {
	float min = 999;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.DiemKq > 8.5 && p->Data.DiemKq < min) min = p->Data.DiemKq;
		p = p->Next;
	}
	return min;
}
//sinh vien co diem trung binh gan x nhat
SNode* checkavr(SList sl, float x) {
	SNode* q = sl.Head;
	float min = 999;
	SNode* p = sl.Head;
	while (p != NULL) {
		float a = p->Data.DiemKq - x;
		if (abs(a) < min) {
			min = abs(a);
			q = p;
		}
		p = p->Next;
	}
	return q;
}
void Average(SList sl,float x) {
	SNode* p = sl.Head;
	cout << "Hoc sinh co diem gan nhat la: " << endl;
	PrintStudent(checkavr(sl,x));
}
void Menu() {
	cout << "*************************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. In diem cua hoc sinh theo ma" << endl;
	cout << "3. Them sinh vien." << endl;
	cout << "4. Sap xep theo ma so" << endl;
	cout << "5. Sap xep theo ten." << endl;
	cout << "6. Xoa sinh vien theo ma." << endl;
	cout << "7. Xoa tat ca sinh vien theo ten." << endl;
	cout << "8. Sap xep diem hoc tap giam dan" << endl;
	cout << "9. In danh sach sinh vien loai kha." << endl;
	cout << "10. Sinh vien co ket qua hoc tap cao nhat/thap nhat." << endl;
	cout << "11. Sinh vien diem thap nhat trong so hoc sinh gioi." << endl;
	cout << "12. Sinh vien co diem gan voi x nhat." << endl;
	cout << "13. In danh sach." << endl;
	cout << "***************************************************" << endl;
	cout << "\tOPTION: ";
}
int main() {
	SList sl;
	Init_Slist(sl);
	int z;
	do {
		Menu();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			cout << "Nhap tu dong:..." << endl;
			InputFromFile(sl);
			InputDieuAuto(sl);
			Inputdiemtb(sl);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			cin.ignore();
			string s;
			cout << "Nhap ma sinh vien can tim: ";
			getline(cin, s);
			if (GetStd(sl, s) == NULL) {
				cout << "Khong tim thay sinh vien!" << endl;
				break;
			}
			PrintStudent(GetStd(sl, s));
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cin.ignore();
			Add_Std(sl);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			Sort1(sl);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			Sort2(sl);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			string s;
			cin.ignore();
			cout << "Nhap ma sinh vien can xoa: "; getline(cin, s);
			Dlt_Code1(sl, s);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			string s;
			cin.ignore();
			cout << "Nhap ten sinh vien can xoa: "; getline(cin, s);
			Dlt_Code(sl, s);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: {
			Sort3(sl);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 9: {
			Print(sl);
			Sort2(sl);
			system("pause");
			system("cls");
			break;
		}
		case 10: {
			cout << "Sinh vien co diem hoc tap cao nhat: " << endl;
			SNode* p = GetMinMax(sl, max(sl));
			if (p == NULL) break;
			PrintStudent(p);
			system("pause");
			system("cls");
			cout << "Sinh vien co diem hoc tap thap nhat: " << endl;
			p = GetMinMax(sl, min(sl));
			if (p == NULL) break;
			PrintStudent(p);
			system("pause");
			system("cls");
			break;
		}
		case 11: {
			SNode* p = GetMinMax(sl, Mincase11(sl));
			if (p == NULL) {
				cerr << "Khong co hoc sinh gioi(co the tu them do bo du lieu random)!" << endl;
				system("pause");
				system("cls");
				break;
			}
			PrintStudent(p);
			system("pause");
			system("cls");
			break;
		}
		case 12: {
			float x;
			cout << "Nhap so trung binh ban can tim: ", cin >> x;
			Average(sl,x);
			system("pause");
			system("cls");
			break;
		}
		case 13: {
			PrintMark(sl);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	} while (z != 0);
	return 0;
}