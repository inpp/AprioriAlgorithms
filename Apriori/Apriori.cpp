#include "Apriori.h"

int main(){

	Ck ck; // Ck �Ҵ�.
	Lk lk; // Lk �Ҵ�.

	vector<vector<int>> t; // database�� transaction ��� ����.


	if (!FileRead(t)) // input.txt �Է�.
		return 0;

	//input �Է� �� C1 ����. C1�� Ư���� ����̹Ƿ� ���� �����Ѵ�.
	ck = GenC1(t);



	//Lk�� Ck�� ��������� ����
	GenLk(ck, lk);


	/*for (int i = 0; i < ck.size(); i++)
	{
		cout << ck[i].at(0) << endl;
	}*/

	return 0;
}
