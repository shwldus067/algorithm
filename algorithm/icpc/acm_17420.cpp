#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;
int N, minv;
ll ans;
pair<int, int> arr[100001];
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%d", &arr[i].second);
	for(int i=0;i<N;++i)	scanf("%d", &arr[i].first);
	sort(arr, arr+N);
	if(arr[0].first>arr[0].second){
		ans=(ll)(arr[0].first-arr[0].second+29)/30;
		minv=arr[0].second+30*ans;
	}else{
		ans=0;
		minv=arr[0].second;
	}
	for(int i=1;i<N;){
		int day=arr[i].first, minn=0;
		while(arr[i].first==day){
			int maxv=max(arr[i].first, minv), tmp=0;
			if(arr[i].second<maxv){
				tmp=(maxv-arr[i].second+29)/30;
				ans+=(ll)tmp;
				minn=max(minn, arr[i].second+30*tmp);
			}else{
				minn=max(minn, arr[i].second);
			}
			++i;
		}
		minv=minn;
	}
	printf("%lld\n", ans);
	return 0;
}
