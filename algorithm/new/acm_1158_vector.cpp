#include<iostream>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int N, K, cur=0;
	vector<int> v;
	cin>>N>>K;
	for(int i=0;i<N;i++)
		v.push_back(i+1);
	cout<<"<";
	for(int i=0;i<N-1;i++){
		cur+=K-1;
		if(cur>=v.size())
			cur=cur%v.size();
		cout<<v[cur]<<", ";
		v.erase(v.begin()+cur);
	}
	cout<<v[0]<<">\n";
	return 0;
}
