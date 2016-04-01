#include "Apriori.h"



int main(){

	vector<Ck> ck; // Ck 할당.
	vector<Lk> lk; // Lk 할당.

	vector<vector<int>> t; // database의 transaction 모두 저장.

	int item;

	if (!FileRead(t)) // input.txt 입력.
		return 0;

	//input 입력 후 C1 생성. C1은 특수한 경우이므로 따로 생성한다.
	vector<int> c1 = GenC1(t);

	//Lk와 Ck를 재귀적으로 생성.


	return 0;
}
