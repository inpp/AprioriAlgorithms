#include "Apriori.h"

int main(){

	Ck ck; // Ck 할당.
	Lk lk; // Lk 할당.

	vector<vector<int>> t; // database의 transaction 모두 저장.


	if (!FileRead(t)) // input.txt 입력.
		return 0;

	//input 입력 후 C1 생성. C1은 특수한 경우이므로 따로 생성한다.
	ck = GenC1(t);



	//Lk와 Ck를 재귀적으로 생성
	GenLk(ck, lk);


	/*for (int i = 0; i < ck.size(); i++)
	{
		cout << ck[i].at(0) << endl;
	}*/

	return 0;
}
