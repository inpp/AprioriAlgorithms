#include "Apriori.h"

Lk GenLk(Ck &c, Lk &l){
	Lk Candidate;
	Lk nextL;
	int csize = c.size();
	int lsize = l.size();
	int lisize = c[0].size()-1;
	// 순차 탐색을 통해서 c 중에서 min_sup이상인 것을 선택.

	int a = c[0].size();

	for (int i = 0; i < csize; i++){
		//sup를	세는 것은 순차탐색으로 진행한다. ScanDB를 이용해서 실행
		if (Scan(c[i], a)/*&&CheckPruning[i]*/){
			nextL.push_back(c[i]);
		}
	}
	if (nextL.size() == 0){
		cout << l[0].size() << "보다 큰 k값을 가지는 Frequent한 item은 존재하지 않습니다." << endl;
	}
	else{
		cout << "L" << nextL[0].size() << "생성 " << nextL.size() << endl;
	}
	return nextL;
}