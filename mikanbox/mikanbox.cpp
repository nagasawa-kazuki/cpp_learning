#include <stdio.h>

// ミカン箱クラス
class MikanBox {
public:
	// コンストラクタ
	MikanBox(int num) {
		total = num;
	}
	// ミカンを追加する関数
	void Add(int addmikan) {
		total += addmikan;
	}
	// ミカンを減らす関数
	void Del(int delmikan) {
		total -= delmikan;
		// ゼロ以下になったらEmpty()を呼び出す
		if (total < 0) {
			Empty();
		}
	}
	// 0以下の場合は0にする
	void Empty() {
		total = 0;
	}
	// 合計を返す関数
	int GetTotal() {
		return total;
	}
private:
	// 合計を保持する変数
	int total;
};

int main() {
	// ミカン箱オブジェクト作成
	MikanBox myMikanBox(2);

	myMikanBox.Add(10);
	myMikanBox.Del(1);
	printf("箱の中のミカンの合計は%dです.\n", myMikanBox.GetTotal());
}