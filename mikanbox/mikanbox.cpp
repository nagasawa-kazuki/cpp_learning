#include <stdio.h>

// �~�J�����N���X
class MikanBox {
public:
	// �R���X�g���N�^
	MikanBox(int num) {
		total = num;
	}
	// �~�J����ǉ�����֐�
	void Add(int addmikan) {
		total += addmikan;
	}
	// �~�J�������炷�֐�
	void Del(int delmikan) {
		total -= delmikan;
		// �[���ȉ��ɂȂ�����Empty()���Ăяo��
		if (total < 0) {
			Empty();
		}
	}
	// 0�ȉ��̏ꍇ��0�ɂ���
	void Empty() {
		total = 0;
	}
	// ���v��Ԃ��֐�
	int GetTotal() {
		return total;
	}
private:
	// ���v��ێ�����ϐ�
	int total;
};

int main() {
	// �~�J�����I�u�W�F�N�g�쐬
	MikanBox myMikanBox(2);

	myMikanBox.Add(10);
	myMikanBox.Del(1);
	printf("���̒��̃~�J���̍��v��%d�ł�.\n", myMikanBox.GetTotal());
}