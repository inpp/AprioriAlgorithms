#include "Apriori.h"

void powerset(itemset &is, vector<int> x, int i, int n, int p);
void out(itemset is, vector<int> check, int n);

void CoutOutput(Lk lk){ // lk1이 lk-1, lk2가 lk
	cout << "Output 출력"<< endl;
	int lisize = lk[0].size();
	int lsize = lk.size();
	//cout << Sup_Freq->second;
	
	
	//부분 집합을 구한다. sup(s)/sup(t-s)
	vector<int> check;
	for (int i = 0; i < lsize; i++){
		powerset(lk[i], check, 0, lisize, 0);
		powerset(lk[i], check, 1, lisize, 0);
	}

	

}

void powerset(itemset &is, vector<int> check, int i, int n, int p){
	check.push_back(i);
	if (p == n){
		int size = 0;
		for (int j = 0; j < n; j++)
			size += check[j];
		if(size != n&&size != 0)
			out(is, check, n);
	}
	else if (p < n){
		powerset(is, check, 0, n, p + 1);
		powerset(is, check, 1, n, p + 1);
	}
}

void out(itemset is, vector<int> check, int n){
	cout.setf(ios::fixed);
	cout.precision(2);
	string s;
	string t;
	string t_s;
	cout << "{";
	for (int i = 0; i < n; i++){
		ostringstream ostr;
		ostr << is[i];
		if (t.size()>0)
			t += ',';
		t += ostr.str();
		
		if (check[i] == 0){
			ostringstream ostr;
			ostr << is[i];
			if (s.size() > 0)
				s += ',';
			s += ostr.str();
		}
		if (check[i] == 1){
			ostringstream ostr;
			ostr << is[i];
			if (t_s.size() > 0)
				t_s += ',';
			t_s += ostr.str();
		}
	}
	cout << s;
	cout << "}	";

	cout << "{";
	cout << t_s;
	cout << "}	";
	unordered_map<string, int>::iterator sup = Sup_Freq.find(t);
	cout << ((double)(sup->second)/5) << "	";
	unordered_map<string, int>::iterator con = Sup_Freq.find(s);
	cout << ((double)(sup->second)*100 / (double)(con->second));
	cout << endl;
}