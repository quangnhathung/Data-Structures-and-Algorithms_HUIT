#include"Dictionary.h"
using namespace std;

void Input(DictNode* bucket[], string s) {
	ifstream file(s);
	if (!file.is_open()) {
		cout << "Mo file that bai!" << endl;
		return;
	}
	string str;
	while (getline(file, str)) {
		stringstream s1(str);
		Vocabulary x;
		getline(s1,x.Word, '-');
		getline(s1, x.Meaning,'-');
		Insert(bucket, CreataDictNode(x));
	}
	cout << "Successfully"<<endl;
}