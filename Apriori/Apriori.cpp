#include "Apriori.h"



int main(){

	vector<Ck> ck; // Ck �Ҵ�.
	vector<Lk> lk; // Lk �Ҵ�.

	vector<vector<int>> t; // database�� transaction ��� ����.

	int item;

	if (!FileRead(t)) // input.txt �Է�.
		return 0;

	//input �Է� �� C1 ����. C1�� Ư���� ����̹Ƿ� ���� �����Ѵ�.
	vector<int> c1 = GenC1(t);

	//Lk�� Ck�� ��������� ����.


	return 0;
}
