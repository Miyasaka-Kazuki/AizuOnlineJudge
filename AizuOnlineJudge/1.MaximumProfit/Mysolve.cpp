#include<stdio.h>
#include<math.h>

static const int Rt_MAX = 100000;

int main() {
	int n; //������
	int Rt[Rt_MAX]; //���i
	int max; //�ő嗘�v
	int min; //�ŏ����i

	//����
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &Rt[i]);
	}

	//�v�Z
	max = -2000000000;
	min = Rt[0];
		//+1����X�^�[�g
	for (int i = 1; i < n; i++) {
		if (Rt[i] - min > max) {
			max = Rt[i] - min;
		}
		if (Rt[i] < min) {
			min = Rt[i];
		}
	}

	printf_s("%d\n", max);
	return 0;
}