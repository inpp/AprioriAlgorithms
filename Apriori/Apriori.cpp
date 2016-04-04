#include "Apriori.h"

unordered_map<string, int> Sup_Freq;
int min_sup;
int tsize;
vector<int> tisize;
transaction t; // database의 transaction 모두 저장.
ofstream f;
int main(int argc, char *argv[]){

	Ck ck; // Ck 할당.
	Lk lk; // Lk 할당.
	cout << argv[0] << endl << argv[1] << endl << argv[2] << endl <<argv[3];

	if (!FileRead(argv[2])) // input.txt 입력.
		return 0;
	tsize = t.size();

	std::stringstream ss(argv[1]);
	int temp;
	ss >> temp;
	cout << "temp"<<temp;
	min_sup = t.size() *temp / 100;
	cout << "min sup : " << min_sup;

	for (int i = 0; i < tsize; i++)
		tisize.push_back(t[i].size());
	//input 입력 후 C1 생성. C1은 특수한 경우이므로 따로 생성한다.
	ck = GenC1(t);
	lk = GenLk(ck, lk);
	f.open(argv[3]);
	//Lk와 Ck를 재귀적으로 생성
	while (lk.size() > 0){
		ck = GenCk(lk);
		lk = GenLk(ck, lk);
		if(lk.size()>0)CoutOutput(lk);// 결과 출력.
	}

	f.close();
	return 0;
}