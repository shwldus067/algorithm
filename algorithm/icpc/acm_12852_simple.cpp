#include<iostream>
#include<vector>
using namespace std;
int ans=1e7;
vector<int> list, arr;
void sol(int n, int x){
	if(list.size()>=ans)	return;
	list.push_back(n);
	if(n==1){
		arr.clear();
		for(int i:list)	arr.push_back(i);
		ans=arr.size();
		list.pop_back();
		return;
	}
	if(!(n%3))	sol(n/3, 0);
	if(!(n%2))	sol(n/2, 0);
	if(x<2)	sol(n-1, x+1);
	list.pop_back();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	sol(N, 0);
	cout<<ans-1<<"\n";
	for(int i:arr)	cout<<i<<" ";
	cout<<"\n";
	return 0;
}
