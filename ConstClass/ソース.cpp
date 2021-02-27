#include <iostream>
#include <string.h>

using namespace std;

class Person {
public:
	Person() {
		name = NULL;
		age = 0;
		phonenum[0] = '\0';
	}
	Person(const char* str) {
		init(str, 0, "");
	}
	Person(const char* str, int yy, const char* pn) {
		init(str, yy, pn);
	}
	Person(const Person &psn) {
		init(psn.name, psn.age, psn.phonenum);
	}
	void init(const char* str, int yy, const char* pn) {
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
		age = yy;
		strcpy_s(phonenum, pn);
	}
	void SetName(const char* str) {
		if (name != NULL) {
			delete[] name;
		}
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
	}
	void SetAge(const int yy) {
		age = yy;
	}
	void SetPhoneNum(const char* pn) {
		strcpy_s(phonenum, pn);
	}
	char* GetName() {
		return name;
	}
	int GetAge() {
		return age;
	}
	char* GetPhoneNum() {
		return phonenum;
	}
private:
	char* name;
	int age;
	char phonenum[15];
};

int main() {
	Person Shiori1("しおりお嬢さん");
	Shiori1.SetAge(20);
	Shiori1.SetPhoneNum("222-3333-4444");

	Person Shiori2("しおり先生", 30, "222-3333-4444");

	Person Shiori3(Shiori2);
	Shiori3.SetName("しおり兄貴");
	Shiori3.SetAge(24);

	Person* p[] = { &Shiori1, &Shiori2, &Shiori3 };

	for (int i = 0; i < 3; i++) {
		cout << "名前:" << p[i]->GetName() << " 年齢:" << p[i]->GetAge()
			<< " 電話番号:" << p[i]->GetPhoneNum() << endl;
	}
}