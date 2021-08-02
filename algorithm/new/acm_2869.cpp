#include<iostream>
using namespace std;
int main(){
	int A, B, V, day, cnt;
	cin>>A>>B>>V;
	V-=A;
	if(V<=0){
		cout<<1;
		return 0;
	}
	day=A-B;
	cnt=V/day;
	if(V%day!=0){
		cnt++;
	}
	cout<<++cnt;
	return 0;
}
