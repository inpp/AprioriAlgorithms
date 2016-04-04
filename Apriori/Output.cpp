#include "Apriori.h"
//#include <set>

//template<typename Set> std::set<Set> powerset(const Set& s, size_t n);
//template<typename Set> std::set<Set> powerset(const Set& s);
void powerset(itemset &is, vector<int> x, int i, int n, int p);
void out(itemset is, vector<int> check, int n);



void CoutOutput(Lk lk){ // lk1이 lk-1, lk2가 lk
	int lisize = lk[0].size();
	int lsize = lk.size();
	
	//부분 집합을 구한다. sup(s)/sup(t-s)
	vector<int> check;
	for (int i = 0; i < lsize; i++){
		powerset(lk[i], check, 0, lisize, 0);
		powerset(lk[i], check, 1, lisize, 0);
	}
//	for (int i = 0; i < lsize; i++)
//		powerset(lk[i]);
}

/*template<typename Set> std::set<Set> powerset(const Set& s, size_t n)
{
	typedef typename Set::const_iterator SetCIt;
	typedef typename std::set<Set>::const_iterator PowerSetCIt;
	std::set<Set> res;
	if (n > 0) {
		std::set<Set> ps = powerset(s, n - 1);
		for (PowerSetCIt ss = ps.begin(); ss != ps.end(); ss++)
		for (SetCIt el = s.begin(); el != s.end(); el++) {
			Set subset(*ss);
			subset.push_back(*el);
			res.insert(subset);
		}
		res.insert(ps.begin(), ps.end());
	}
	else
		res.insert(Set());
	return res;
}
template<typename Set> std::set<Set> powerset(const Set& s)
{
	return powerset(s, s.size());
}*/




void powerset(itemset &is, vector<int> check, int i, int n, int p){
	if (p == n && i==1){
		int size = 0;
		for (int j = 0; j < n; j++)
			size += check[j];
		if(size != n&&size != 0)
			out(is, check, n);
	}
	else if (p < n){
		check.push_back(i);
		powerset(is, check, 0, n, p + 1);
		powerset(is, check, 1, n, p + 1);
	}
}

void out(itemset is, vector<int> check, int n){
	f.setf(ios::fixed);
	f.precision(2);
	string s;
	string t;
	string t_s;
	f << "{";
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
	f << s;
	f << "}	";

	f << "{";
	f << t_s;
	f << "}	";
	unordered_map<string, int>::iterator sup = Sup_Freq.find(t);
	f << ((double)(sup->second)/5) << "	";
	unordered_map<string, int>::iterator con = Sup_Freq.find(s);
	f << ((double)(sup->second)*100 / (double)(con->second));
	f << endl;
}
