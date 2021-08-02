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
	long long N;
	int M;
	cin>>N>>M;
	matrix skill(M, vector<long long>(M, 0));
	matrix ans(M, vector<long long>(M, 0));
	for(int i=1;i<M;i++)	skill[i][i-1]=1;
	for(int i=0;i<M;i++)	ans[i][i]=1;
	skill[0][0]=skill[0][M-1]=1;
	while(N){
		if(N&1){
			ans=ans*skill;
		}
		skill=skill*skill;
		N>>=1;
	}
	
	cout<<ans[0][0]<<"\n";
	return 0;
}
