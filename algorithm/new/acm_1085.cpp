#include<iostream>
using namespace std;
int main(){
	int x, y, w, h, res1, res2;
	cin>>x>>y>>w>>h;
	res1=min(x, w-x);
	res2=min(y, h-y);
	res1=min(res1, res2);
	cout<<res1<<"\n";
	return 0;
}
