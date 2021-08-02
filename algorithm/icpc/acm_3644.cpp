#include<stdio.h>
#include<vector>
using namespace std;
typedef vector<char> vc;
void update(vc& a){
	a.push_back(0);
	int l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]>9)	a[i+1]++, a[i]-=10;
	}
	if(a[l-1]==0)	a.pop_back();
}
void add(vc& a, vc& b){
	int l=b.size();
	a.resize(l);
	for(int i=0;i<l;i++){
		a[i]+=b[i];
	}
}
int main(){
	int n;
	vc C[10001];
	C[3].push_back(4);
	C[4].push_back(7);
	for(int i=5;i<=10000;i++){
		C[i]=C[i-2];
		add(C[i], C[i-1]);
		update(C[i]);
	}
	while(scanf("%d", &n)!=EOF){
		for(int i=C[n].size()-1;i>=0;i--){
			printf("%d", C[n][i]);
		}
		printf("\n");
	}
	return 0;
}
