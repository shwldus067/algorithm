#include<iostream>
#include<cstring>
using namespace std;
int trie[100000][10];
bool fin[100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char str[12];
	int N, T;
	cin>>T;
	while(T--){
		cin>>N;
		int n=0;
		memset(trie[0], 0, sizeof(trie[0]));
		bool chk=1;
		for(int i=0;i<N;++i){
			cin>>str;
			if(!chk)	continue;
			int t=0;
			for(int j=0;chk && str[j];++j){
				int cur=str[j]-'0';
				if(!trie[t][cur]){	//이전에 동일한 순서로 번호가 나온 적이 있는지 
					++n;
					fin[n]=0;
					memset(trie[n], 0, sizeof(trie[n]));
					trie[t][cur]=n;	//없다면 다음은 n번째 행으로 가도록 
				}
				t=trie[t][cur];	//현재 값의 위치로 
				if(fin[t])	chk=0;	//이전 번호 중 현재 번호의 prefix가 있는지 체크 
			}
			if(chk){
				fin[t]=1;	//마지막 번호의 지점 체크 
				for(int j=0;j<10;++j){	//현재 번호가 이전 번호의 prefix인지 체크 
					if(trie[t][j]>0){
						chk=0;
						break;
					}
				}
			}
		}
		if(chk)	cout<<"YES\n";
		else	cout<<"NO\n";
	}
	return 0;
}
