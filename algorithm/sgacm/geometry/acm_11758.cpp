#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	pii a, b, c;
	cin>>a.first>>a.second;
	cin>>b.first>>b.second;
	cin>>c.first>>c.second;
	b={b.first-a.first, b.second-a.second};
	c={c.first-a.first, c.second-a.second};
	int ret=b.first*c.second-b.second*c.first;
	if(ret>0)	cout<<"1\n";
	else if(ret<0)	cout<<"-1\n";
	else	cout<<"0\n";
	return 0;
}
