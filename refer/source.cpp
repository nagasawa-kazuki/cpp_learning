#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// 生徒クラス
class Student {
public:
	// IDセット関数
	void SetID(int num) {
		id = num;
	}
	// 名前セット関数
	void SetName(const char* str) {
		strcpy_s(name, str);
	}
	// ID取得関数
	int GetID() {
		return id;
	}
	// 名前取得関数
	char* GetName() const {
		return (char*) name;
	}
private:
	int id; // ID
	char name[30]; // 名前
};

// 科目
enum class Subjects {Math, English, Science};

// テストクラス
class Exam {
public:
	// 情報設定関数
	void SetInfo(int id, const char* name, Subjects s, int num);
	// 点数取得関数
	int GetPoint() const;
	// 教科取得
	Subjects GetSubject() {
		return subject;
	}
	// 生徒オブジェクト
	Student student;
private:
	Subjects subject; // 科目
	int point; // 点数
};

void Exam::SetInfo(int id, const char *name, Subjects s, int num) {
	student.SetID(id);
	student.SetName(name);
	subject = s;
	point = num;
}

int Exam::GetPoint() const {
	return point;
}

void PrintResult(Exam &Exami) {
	cout << Exami.student.GetName() << endl;
	const char *subname[] = { "数学", "英語", "理科" };
	cout << subname[(int)Exami.GetSubject()] << Exami.GetPoint() << "点" << endl;
}

double GetAvg(const Exam* Exam, int num) {
	double sum = 0;
	for (int i = 0; i < num; i++) {
		sum += Exam[i].GetPoint();
	}
	return sum / num;
}

int main() {
	Exam Exam[3];

	const char *name = "しおり";

	Exam[0].SetInfo(1, name, Subjects::Math, 60);
	Exam[1].SetInfo(1, name, Subjects::English, 75);
	Exam[2].SetInfo(1, name, Subjects::Science, 88);

	PrintResult(Exam[0]);
	PrintResult(Exam[1]);
	PrintResult(Exam[2]);
	cout << endl;
	cout << "平均: " << GetAvg(Exam, 3) << "点" << endl;
	return 0;

}