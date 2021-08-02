#include<iostream>
#include<vector>
using namespace std;
const int mod=1000000007;
typedef vector<vector<long long> > matrix;
matrix operator*(const matrix &a, const matrix &b){
	int n=a.size();
	matrix c(n, vector<long long>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                c[i][j] += a[i][k] * b[k][j];
                c[i][j]%=mod;
            }
        }
    }
    return c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long N, exp, count=0;
	int M;
	cin>>N>>M;
	matrix skill(M, vector<long long>(M, 0));
	matrix ans(M, vector<long long>(M, 0));
	for(int i=1;i<M;i++)	skill[i][i-1]=1;
	for(int i=0;i<M;i++)	ans[i][i]=1;
	skill[0][0]=skill[0][M-1]=1;
	exp=N-M;
	if(exp<0){
		cout<<1<<"\n";
		return 0;
	}
	else if(exp==0){
		cout<<2<<"\n";
		return 0;
	}
	while(exp){
		if(exp&1){
			ans=ans*skill;
		}
		skill=skill*skill;
		exp>>=1;
	}
	count+=ans[0][0]*2;
	count%=mod;
	for(int i=1;i<M;i++){
		count+=ans[0][i];
		count%=mod;
	}
	cout<<count<<"\n";
	return 0;
}
