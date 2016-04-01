#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

static int min_sup = 50;

//함수 선언 부분
int FileRead(vector<vector<int>> &t);


// Ck와 Lk 클래스 선언.
class Ck{
public:	
	int support = 0;
	map<int, int> itemset;
private:
	void Sup_plus(){
		support++;
	}
};

class Lk{
public:
	map<int, int> itemset;
};


int main(){

	list<Ck> ck; // Ck 할당.
	list<Lk> lk; // Lk 할당.

	vector<vector<int>> t; // transaction 저장.
	map<int, int> itemset;

	int item;

	if (!FileRead(t)) // input.txt 입력.
		return 0;



	for (int i = 0; i < (int)t.size(); i++){
		for (int j = 0; j < (int)t[i].size(); j++)
			cout << t[i].at(j) << " ";
		cout << endl;
	}




	return 0;
}
