#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main (void) {
	char inst[10];
	int tableCnt, orderCnt;
	int no, time;
	vector<pair<int, int> > list;

	scanf("%d %d%*c", &orderCnt, &tableCnt);
	while (orderCnt --) {
		scanf("%s", inst);
		switch (inst[0])
		{
		case 'o' : {
			scanf("%d %d%*c", &no, &time);
			list.push_back(make_pair(time, no));

			break;
		}
		case 's' : {
			sort (list.begin(), list.end());
			break;
		}
		case 'c' : {
			scanf("%d%*c", &no);

			vector<pair<int, int> >::iterator iter;
			for (iter = list.begin(); iter != list.end(); ++ iter) {
				if (iter->second == no) {
					list.erase(iter);
					break;
				}
			}
			break;
		}
		default:
			break;
		}

		if (list.size()) {
			for (int i = 0; i < list.size(); ++ i) {
				printf("%d ", list[i].second);
			} printf("\n");
		} else {
			printf("sleep\n");
		}
	}

	return 0;
}