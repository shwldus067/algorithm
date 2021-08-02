#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<long long> > matrix;
const int mod=1000003;
int N, S, E, T;
int ans;
matrix operator *(const matrix &a, const matrix &b){
	int n=N*5;
    matrix c(n, vector<long long>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                c[i][j] += (a[i][k] * b[k][j])%mod;
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
	cin>>N>>S>>E>>T;
	int s=N*5;
	matrix mat(s, vector<long long>(s, 0));
	char t;
	S--, E--;
	for(int i=0;i<N;i++){
		for(int j=1;j<5;j++){
			mat[i*5+j][i*5+j-1]=1;
		}
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>t;
			if(t=='1')	mat[i*5][j*5]=1;
			else if(t>'1')	mat[i*5][j*5+t-'1']=1;
		}
	matrix ans(s, vector<long long>(s));
    for(int i=0;i<s;i++){
    	ans[i][i]=1;
	}
	while(T){
        if(T&1){
            ans = ans * mat;
        }
        mat = mat * mat;
        T>>=1;
    }
    cout<<ans[S*5][E*5]<<"\n";
	return 0;
}
