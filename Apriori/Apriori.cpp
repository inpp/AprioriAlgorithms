#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

static int min_sup = 50;

//�Լ� ���� �κ�
int FileRead(vector<vector<int>> &t);


// Ck�� Lk Ŭ���� ����.
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

	list<Ck> ck; // Ck �Ҵ�.
	list<Lk> lk; // Lk �Ҵ�.

	vector<vector<int>> t; // transaction ����.
	map<int, int> itemset;

	int item;

	if (!FileRead(t)) // input.txt �Է�.
		return 0;



	for (int i = 0; i < (int)t.size(); i++){
		for (int j = 0; j < (int)t[i].size(); j++)
			cout << t[i].at(j) << " ";
		cout << endl;
	}




	return 0;
}
