#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// ���k�N���X
class Student {
public:
	// ID�Z�b�g�֐�
	void SetID(int num) {
		id = num;
	}
	// ���O�Z�b�g�֐�
	void SetName(const char* str) {
		strcpy_s(name, str);
	}
	// ID�擾�֐�
	int GetID() {
		return id;
	}
	// ���O�擾�֐�
	char* GetName() const {
		return (char*) name;
	}
private:
	int id; // ID
	char name[30]; // ���O
};

// �Ȗ�
enum class Subjects {Math, English, Science};

// �e�X�g�N���X
class Exam {
public:
	// ���ݒ�֐�
	void SetInfo(int id, const char* name, Subjects s, int num);
	// �_���擾�֐�
	int GetPoint() const;
	// ���Ȏ擾
	Subjects GetSubject() {
		return subject;
	}
	// ���k�I�u�W�F�N�g
	Student student;
private:
	Subjects subject; // �Ȗ�
	int point; // �_��
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
	const char *subname[] = { "���w", "�p��", "����" };
	cout << subname[(int)Exami.GetSubject()] << Exami.GetPoint() << "�_" << endl;
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

	const char *name = "������";

	Exam[0].SetInfo(1, name, Subjects::Math, 60);
	Exam[1].SetInfo(1, name, Subjects::English, 75);
	Exam[2].SetInfo(1, name, Subjects::Science, 88);

	PrintResult(Exam[0]);
	PrintResult(Exam[1]);
	PrintResult(Exam[2]);
	cout << endl;
	cout << "����: " << GetAvg(Exam, 3) << "�_" << endl;
	return 0;

}