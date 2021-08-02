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
				if(!trie[t][cur]){	//������ ������ ������ ��ȣ�� ���� ���� �ִ��� 
					++n;
					fin[n]=0;
					memset(trie[n], 0, sizeof(trie[n]));
					trie[t][cur]=n;	//���ٸ� ������ n��° ������ ������ 
				}
				t=trie[t][cur];	//���� ���� ��ġ�� 
				if(fin[t])	chk=0;	//���� ��ȣ �� ���� ��ȣ�� prefix�� �ִ��� üũ 
			}
			if(chk){
				fin[t]=1;	//������ ��ȣ�� ���� üũ 
				for(int j=0;j<10;++j){	//���� ��ȣ�� ���� ��ȣ�� prefix���� üũ 
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
