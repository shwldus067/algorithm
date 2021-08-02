#include<iostream>
using namespace std;

int main(){
	int N, max, rem;
	cin>>N;
	max=N/5;
	rem=N%5;
	if(rem==0)	cout<<max<<endl;
	else if(rem==3)	cout<<max+1<<endl;
	else{
		while(max>0){
			max--;
			rem+=5;
			if((rem%3)==0){
				cout<<max+(rem/3)<<endl;
				return 0;
			}
		}
		cout<<-1<<endl;
	}
	return 0;
}
