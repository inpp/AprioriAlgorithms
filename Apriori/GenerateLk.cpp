#include "Apriori.h"



Lk GenLk(Ck &c, Lk &l){
	cout << "LK 생성 시작 " << endl;
	Lk Candidate;
	Lk nextL;
	int csize = c.size();
	int lsize = l.size();
	int lisize = c[0].size()-1;
	// 순차 탐색을 통해서 c 중에서 min_sup이상인 것을 선택.

	int a = c[0].size();
	cout << "스캔 DB 시작 candidate 사이즈 : " << csize<< endl;

	for (int i = 0; i < csize; i++){
		//sup를	세는 것은 순차탐색으로 진행한다. ScanDB를 이용해서 실행
		if (Scan(c[i], a)/*&&CheckPruning[i]*/){
			nextL.push_back(c[i]);
		}
	}
	cout << "스캔 DB 끝" << endl;
	if (nextL.size() == 0){
		cout << "더이상 Frequent한 item은 존재하지 않습니다." << endl;
	}
	else{
		cout << "LK 생성" << nextL.size() << endl;
	}
	return nextL;
}