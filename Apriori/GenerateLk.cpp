#include "Apriori.h"



Lk GenLk(Ck &c, Lk &l, transaction &t){
	cout << "LK 생성 시작 " << endl;
	Lk Candidate;
	Lk nextL;
	int csize = c.size();
	int lsize = l.size();
	int lisize = c[0].size()-1;
	// 순차 탐색을 통해서 c 중에서 min_sup이상인 것을 선택.

	//pruning 먼저 진행
	//c 중에서 마지막 원소 2개가 포함된 k-1 subset 중 l에 포함되어있지 않은 것을 버린다.
	/*cout << "pruning 시작 " << endl;
	vector<int> CheckPruning;
	if (lsize!=0)  
	for (int i = 0; i < csize; i++){ // 각각의 Candidate를 모두 비교해본다.
		int setcheck = 0;
		int subsetcheck = 0;
		for (int pos = 0; pos < lisize+1; pos++){ //모든 k-1 subset이 후보여아한다. 대신 뒤에 두 개 중 하나라도 빠지는 것은 없으므로 생략.
			int temp = 0;
			for (int j = 0; j < lsize; j++){
				// 순차 탐색을 통해 하나하나 비교함. 모든 subset이 lk에 포함되어 있다면 후보에 넣을 수 있다. 이 때 pos에 있는 것을 빼고 보면 부분집합.
				subsetcheck = 0;
				temp = 0;
				int temp2 = 0;
				while (temp2 < lisize){ // 비교를 시작한다. lisize까지의 원소가 모두 같으면 그 subset은 통과, 만약 temp==pos이면 지나간다.
					if (temp == pos)
						temp++;
					else if (c[i].at(temp) != l[j].at(temp2)){ //만약 다른 값을 가진 원소가 나오면 다음 l로 비교한다.
						break;
					}
					else if (temp == lisize){ // 만약 마지막 원소까지 같다면  subsetcheck = 1을 넣어준다.
						subsetcheck = 1;
					}
					else{ // 만약 원소가 같다면 다음 원소를 비교한다.
						temp++;
						temp2++;
					}
				}
				if (subsetcheck == 1) // 만약 마지막 원소까지 같다면 그만 진행하고 다음 pos에서 찾아본다. 아니라면 다음 li에서 찾아본다.
					break;
			}
			if (subsetcheck == 0) // 만약 subsetcheck가 0이면(subset중 다른게 있다면) 삭제, 1이면 다음 pos에서 비교해봄
				break;
			else if (pos > lisize - 2) // 만약 pos가 2개를 제외한 마지막 원소를 제한 subset까지 모두 같다면 1을 넣어준다.
			{
				setcheck = 2;
				break;
			}
		}

		if (setcheck == 2)
			CheckPruning.push_back(1);
		else
			CheckPruning.push_back(0);
	}
	else
	for (int i = 0; i < csize; i++)
		CheckPruning.push_back(1);
	// Lk 의 support를 세서 min_sup 이상인 것을 lk에 넣어준다.
	// Candidate에 들어가 있는 것의 sup만 세면 된다.
	cout << "pruning 끝 " << endl;*/
	cout << "스캔 DB 시작 candidate 사이즈 : " << csize<< endl;

	for (int i = 0; i < csize; i++){
		//sup를	세는 것은 순차탐색으로 진행한다. ScanDB를 이용해서 실행
		if (Scan(c[i], t)/*&&CheckPruning[i]*/){
			nextL.push_back(c[i]);
		}
	}
	cout << "스캔 DB 끝" << endl;
	if (nextL.size() == 0){
		cout << "더이상 Frequent한 item은 존재하지 않습니다." << endl;
	}
	else{
		cout << "LK 생성" << endl;
	}
	CoutMaximal(l, nextL);// Maximal itemset을 구하고 결과 출력.
	return nextL;
}