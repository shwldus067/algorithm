#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll absf(ll a){
	if(a<0)	return -a;
	return a;
}
int main(){
	int N, arr[5000], a, b, c;
	ll res=3e9;
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%d", arr+i);
	sort(arr, arr+N);
	for(int i=0;i<N-2;++i){
		int l=i+1, r=N-1;
		while(l!=r){
			ll sum=(ll)arr[i]+arr[l]+arr[r];
			if(absf(sum)<res)	a=i, b=l, c=r, res=abs(sum);
			if(sum<0)	++l;
			else if(sum>0)	--r;
			else	break;
		}
		if(res==0)	break;
	}
	printf("%d %d %d\n", arr[a], arr[b], arr[c]);
	return 0;
}
