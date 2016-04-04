#include "Apriori.h"

unordered_map<string, int> Sup_Freq;
int min_sup;
int tsize;
vector<int> tisize;
transaction t; // database�� transaction ��� ����.
ofstream f;
int main(int argc, char *argv[]){

	Ck ck; // Ck �Ҵ�.
	Lk lk; // Lk �Ҵ�.
	cout << argv[0] << endl << argv[1] << endl << argv[2] << endl <<argv[3];

	if (!FileRead(argv[2])) // input.txt �Է�.
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
	//input �Է� �� C1 ����. C1�� Ư���� ����̹Ƿ� ���� �����Ѵ�.
	ck = GenC1(t);
	lk = GenLk(ck, lk);
	f.open(argv[3]);
	//Lk�� Ck�� ��������� ����
	while (lk.size() > 0){
		ck = GenCk(lk);
		lk = GenLk(ck, lk);
		if(lk.size()>0)CoutOutput(lk);// ��� ���.
	}

	f.close();
	return 0;
}