#include<stdio.h>
#include<algorithm>
using namespace std;
int T, N, M;
bool comp(pair<int, int> a, pair<int, int> b){
	if(a.second==b.second)	return a.first<b.first;
	return a.second<b.second;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		bool ch[N+1]={false, };
		pair<int, int> book[M];
		for(int i=0;i<M;i++){
			scanf("%d %d", &book[i].first, &book[i].second);
		}
		sort(book, book+M, comp);
		int res=0;
		for(int i=0;i<M;i++){
			for(int j=book[i].first;j<=book[i].second;j++){
				if(!ch[j]){
					res++;
					ch[j]=true;
					break;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
