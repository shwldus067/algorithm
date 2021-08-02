#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin>>k;
	while(k!=0){
		int ary[k];
		bool perm[k]={false, };
		for(int i=0;i<k;i++){
			cin>>ary[i];
		}
		fill(perm, perm+6, true);
		do{
			int cnt=0, i=0;
			while(cnt<6){
				if(perm[i]){
					cout<<ary[i]<<" ";
					cnt++;
				}
				i++;
			}
			cout<<"\n";
		}while(prev_permutation(perm, perm+k));
		cout<<"\n";
		cin>>k;
	}
	return 0;
}
