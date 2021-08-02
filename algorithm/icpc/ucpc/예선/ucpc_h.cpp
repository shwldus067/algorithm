#include<iostream>
#include<algorithm>
using namespace std;
int N;
int a[3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int tmp, num1=0, num2=0, num3=0;
	for(int i=0;i<N;++i){
		cin>>tmp;
		if(tmp>3){
			num3+=tmp/6;
			if(tmp%3==1){
				num1++;
				a[1]++;
			}
			else if(tmp%3==2){
				num2++;
				a[2]++;
			}
			else{
				a[0]++;
			}
		}
		else{
			a[tmp%3]++;
		}
	}
	if(a[1]==a[2]){
		cout<<"YES\n";
		return 0;
	}
	int one, two;
	if(a[1]>a[2]){
		one=a[1]-a[2], two=0;
		if(one%3==0 && one<=num3*3){
			cout<<"YES\n";
			return 0;
		}
		while(num1--){
			two+=2;
			one--;
			if(one<two)	break;
			if(one==two){
				cout<<"YES\n";
				return 0;
			}
			if((one-two)%3==0 && (one-two)<=num3*3){
				cout<<"YES\n";
				return 0;
			}
		}
		cout<<"NO\n";
		return 0;
	}
	else{
		one=0, two=a[2]-a[1];
		if(two%3==0){
			cout<<"YES\n";
			return 0;
		}
		cout<<"NO\n";
		return 0;
	}
	return 0;
}
