#include<iostream>
using namespace std;
const int MAX=1000000;
bool prime[MAX+1]={false};
int main(){
    int M, N;
    prime[0]=prime[1]=true;
    for(int i=2;i*i<=MAX;i++){
    	if(prime[i]==false){
    		for(int j=i+i;j<=MAX;j+=i)
    			prime[j]=true;
		}
	}
	cin>>M>>N;
	for(int i=M;i<=N;i++){
		if(!prime[i])
			cout<<i<<"\n";
	}
	return 0;
}
