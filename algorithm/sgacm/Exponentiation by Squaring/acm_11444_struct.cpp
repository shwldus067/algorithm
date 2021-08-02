#include<iostream>
using namespace std;
const long long mod=1000000007;
struct matrix{
	long long a1, a2, b1, b2;
	matrix operator*(matrix tmp){
		return matrix(a1*tmp.a1+a2*tmp.b1,
			a1*tmp.a2+a2*tmp.b2,
			b1*tmp.a1+b2*tmp.b1,
			b1*tmp.a2+b2*tmp.b2);
	}
	matrix(long long a1, long long a2, long long b1, long long b2):
		a1(a1%mod), a2(a2%mod), b1(b1%mod), b2(b2%mod){
		};
};
matrix get_mat(long long n){
	if(n==0)	return matrix(1, 0, 0, 1);
	if(n==1)	return matrix(1, 1, 1, 0);
	matrix tmp=get_mat(n/2);
	return tmp*tmp*get_mat(n%2);
}
int main(){
	long long n;
	cin>>n;
	cout<<get_mat(n).b1<<"\n";
	return 0;
}
