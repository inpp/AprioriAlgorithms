#include "Apriori.h"

int main(){

	Ck ck; // Ck 할당.
	Lk lk; // Lk 할당.

	transaction t; // database의 transaction 모두 저장.

	if (!FileRead(t)) // input.txt 입력.
		return 0;

	//input 입력 후 C1 생성. C1은 특수한 경우이므로 따로 생성한다.
	ck = GenC1(t);
	lk = GenLk(ck, lk, t);


	//Lk와 Ck를 재귀적으로 생성
	while (lk.size() > 0){
		ck = GenCk(lk);
		lk = GenLk(ck, lk, t);
	}

	return 0;
}