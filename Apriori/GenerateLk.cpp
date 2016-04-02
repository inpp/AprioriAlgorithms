#include "Apriori.h"

Lk GenLk(Ck &c, Lk &l){
	Lk Candidate;
	Lk nextL;
	
	// 순차 탐색을 통해서 c 중에서 min_sup이상인 것을 선택.
	for (int i = 0; i < c.size(); i++){
		for (int j = i+1; j < c.size(); j++){
			// 순차 탐색을 통해 하나하나 비교함. 앞의 원소는 모두 같고 마지막 원소만 다르다면 후보에 넣을 수 있다.
			int temp = 0;
			int check = 0;
			while (temp<c[i].size()-1){
				if (c[i].at(temp) != c[j].at(temp)){
					temp++;
					check = 1;
					break;
				}
			}
			if (check == 0){ // 만약 모든 k-1의 subset이 frequent하다면, lk의 후보에 넣는다.
				itemset Frequent = c[i];
				Frequent.push_back(c[j].at(c[j].size()-1));
				Candidate.push_back(Frequent);
			}
		}
	}
	
	cout << "test" << endl;
	for (int i = 0; i < Candidate.size(); i++){
		cout << Candidate[i].at(0) << " ";
		cout << Candidate[i].at(1) << endl;
	}
	// Lk 의 support를 세서 min_sup 이상인 것을 lk에 넣어준다.
	// Candidate에 들어가 있는 것의 sup만 세면 된다.
	for (int i = 0; i < Candidate.size(); i++){
		//sup를 세는 것은 순차탐색으로 진행한다. ScanDB를 이용해서 실행
	}


	return nextL;
}