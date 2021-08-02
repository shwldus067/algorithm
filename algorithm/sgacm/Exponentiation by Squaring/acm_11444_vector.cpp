#include <iostream>
#include <vector>
using namespace std;
long long n;
const long long mod = 1000000007;
typedef vector<vector<long long> > matrix;

matrix operator *(const matrix &a, const matrix &b){
    matrix c(2, vector<long long>(2));
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            for(int k = 0;k<2;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j]%=mod;
        }
    }
    return c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    matrix ans(2, vector<long long>(2));
    ans[0][0]=ans[1][1]=1;
    matrix a(2, vector<long long>(2));
    a[0][0]=a[0][1]=a[1][0]=1;
    while(n){
        if(n % 2){
            ans = ans * a;
        }
        a = a * a;
        n>>=1;
    }
    cout<<ans[1][0]<<"\n";
    return 0;
}
