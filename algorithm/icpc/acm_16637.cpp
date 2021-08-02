#include<iostream>
using namespace std;
int N, ans=-(1<<31);
char exp[20];
bool par[20];
void sol(int k){
	if(k<N){
		for(int i=k;i<N;i+=2){
			sol(i+2);
			par[i]=1;
			sol(i+4);
			par[i]=0;
		}
	}
	else{
		int res=exp[0];
		for(int i=1;i<N;i+=2){
			int tmp=exp[i+1], f=0;
			if(par[i+2]){
				f=2;
				switch(exp[i+2]){
					case '+':
						tmp=tmp+(int)exp[i+3];
						break;
					case '-':
						tmp=tmp-(int)exp[i+3];
						break;
					case '*':
						tmp=tmp*(int)exp[i+3];
						break;
				}
			}
			switch(exp[i]){
				case '+':
					res=res+tmp;
					break;
				case '-':
					res=res-tmp;
					break;
				case '*':
					res=res*tmp;
					break;
			}
			i+=f;
		}
		if(ans<res)	ans=res;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>exp;
	for(int i=0;i<N;i+=2){
		exp[i]=exp[i]-'0';
	}
	sol(1);
	cout<<ans<<"\n";
	return 0;
}
