#include "Apriori.h"

int main(){

	Ck ck; // Ck �Ҵ�.
	Lk lk; // Lk �Ҵ�.

	transaction t; // database�� transaction ��� ����.

	if (!FileRead(t)) // input.txt �Է�.
		return 0;

	//input �Է� �� C1 ����. C1�� Ư���� ����̹Ƿ� ���� �����Ѵ�.
	ck = GenC1(t);
	lk = GenLk(ck, lk, t);


	//Lk�� Ck�� ��������� ����
	while (lk.size() > 0){
		ck = GenCk(lk);
		lk = GenLk(ck, lk, t);
	}

	return 0;
}