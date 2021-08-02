#include<iostream>
#include<set>
using namespace std;
const long long mod=1234567891;
int N, L;
set<int> s;
long long ans;
long long mat[2][2], res[2][2]={1, 0, 0, 1}, tmp[2][2];
void mul(long long a[2][2], long long b[2][2]){
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			tmp[i][j]=0;
			for(int k=0;k<2;++k){
				tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j]%mod)%mod;
			}
		}
	}
	for(int i=0;i<2;++i)for(int j=0;j<2;++j)	a[i][j]=tmp[i][j];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num, first, last, tp, cur;
	cin>>N>>L;
	for(int i=0;i<N;++i){
		cin>>num;
		bool ch=true;
		last=num%10;
		cur=num;
		while(num){
			tp=num%10;
			if(tp!=4 && tp!=7){
				ch=false;
				break;
			}
			first=tp;
			num/=10;
		}
		if(ch){
			if(s.find(cur)!=s.end())	continue;
			s.insert(cur);
			++mat[first==7][last==7];
		}
	}
	while(L){
		if(L&1){
			mul(res, mat);
		}
		mul(mat, mat);
		L>>=1;
	}
	for(int i=0;i<2;++i)for(int j=0;j<2;++j)
		ans=(ans+res[i][j])%mod;
	cout<<ans<<"\n";
	return 0;
}
