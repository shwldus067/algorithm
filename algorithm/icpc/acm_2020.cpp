#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
int n, m, K;
string str;
bool cmp1(int a1, int a2){
	return str.substr(a1)<str.substr(a2);
}
bool cmp2(const pii &a1, const pii &a2){
	return str.substr(a1.first, a1.second)<str.substr(a2.first, a2.second);
}
vi suffixarray(){
	vi arr(n);
	for(int i=0;i<n;++i)	arr[i]=i;
	sort(arr.begin(), arr.end(), cmp1);
	return arr;
}
int prefix(int a1, int a2){
	int ret=0;
	while(a1<str.size() && a2<str.size() && str[a1]==str[a2]){
		++ret;
		++a1;
		++a2;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>K>>str;
	vii vec;
	vi arr=suffixarray();
	for(int i=0;i+m-1<arr.size();++i){
		int l=prefix(arr[i],  arr[i+m-1]);
		if(l)	vec.push_back({arr[i], l});
	}
	sort(vec.begin(), vec.end(), cmp2);
	bool chk[1000]={0, };
	int cnt=0;
	string ans;
	for(int i=0;i<n;++i){
		for(int j=0;j<vec.size();++j){
			if(i>=vec[j].second || (j>0 && i<vec[j-1].second && !chk[j] 
			&& str[vec[j].first+i]==str[vec[j-1].first+i]))	continue;
			chk[j]=1;
			--K;
			++cnt;
			if(K==0)	ans=str.substr(vec[j].first, i+1);
		}
	}
	cout<<cnt<<"\n";
	cout<<ans<<"\n";
	return 0;
}
