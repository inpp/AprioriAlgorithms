#include "Apriori.h"



Lk GenLk(Ck &c, Lk &l, transaction &t){
	Lk Candidate;
	Lk nextL;

	// 순차 탐색을 통해서 c 중에서 min_sup이상인 것을 선택.

	//pruning 먼저 진행

	
	// Lk 의 support를 세서 min_sup 이상인 것을 lk에 넣어준다.
	// Candidate에 들어가 있는 것의 sup만 세면 된다.
	for (int i = 0; i < c.size(); i++){
		//sup를 3세는 것은 순차탐색으로 진행한다. ScanDB를 이용해서 실행
		if (Scan(c[i], l, t)){
			nextL.push_back(c[i]);
		}
	}
	cout << "Print nextLk" << endl;
	for (int i = 0; i < nextL.size(); i++){
		for (int j = 0; j < nextL[i].size();j++){
			cout << nextL[i].at(j) << " ";
		}
		cout << endl;
	}
	if (nextL.size() == 0){
		cout << "k = " << l[0].size() << "이상의 Frequent한 item은 존재하지 않습니다." << endl;
	}

	return nextL;
}