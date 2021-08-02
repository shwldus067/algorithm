#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a, b, c, ans=4;
	for(int i=1;(a=i*i)<=n;++i){
		if(a==n){
			ans=min(ans, 1);
		}
		for(int j=1;(b=a+j*j)<=n;++j){
			if(b==n){
				ans=min(ans, 2);
			}
			for(int k=1;(c=b+k*k)<=n;++k){
				if(c==n){
					ans=min(ans, 3);
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
