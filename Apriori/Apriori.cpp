#include "Apriori.h"

int main(){

	Ck ck; // Ck �Ҵ�.
	Lk lk; // Lk �Ҵ�.

	transaction t; // database�� transaction ��� ����.


	if (!FileRead(t)) // input.txt �Է�.
		return 0;

	//input �Է� �� C1 ����. C1�� Ư���� ����̹Ƿ� ���� �����Ѵ�.
	ck = GenC1(t);



	//Lk�� Ck�� ��������� ����
	do{
		lk = GenLk(ck, lk, t);
		ck = GenCk(lk);
	} while (lk.size() > 0);

	return 0;
}