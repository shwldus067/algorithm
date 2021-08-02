#include<iostream>
#include<set>
using namespace std;
int Z, N, M, rain[1000001], t;
int res[1000001];
bool y;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>Z;
	while(Z--){
		cin>>N>>M;
		set<int> drink;
		set<int>::iterator iter;
		fill(rain, rain+N+1, -1);
		fill(res, res+M+1, -1);
		y=true;
		for(int i=1;i<=M;i++){
			cin>>t;
			if(t==0){
				drink.insert(i);
				res[i]=0;
			}
			else{
				iter=drink.upper_bound(rain[t]);
				if(iter==drink.end()){
					while(i<M){
						cin>>t;
						i++;
					}
					y=false;
					break;
				}
				res[*iter]=t;
				rain[t]=i;
				drink.erase(iter);
			}
		}
		if(y){
			cout<<"YES\n";
			for(int i=1;i<=M;i++){
				if(res[i]!=-1){
					cout<<res[i]<<" ";
				}
			}
			cout<<"\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}
