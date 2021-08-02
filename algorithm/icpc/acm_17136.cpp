#include<iostream>
using namespace std;
int arr[10][10], ans=26;
void sol(int x, int *a){
	int done=1;
	int ret=a[0]+a[1]+a[2]+a[3]+a[4];
	if(ans<ret)	return;
	for(int i=x;i<10;++i){
		for(int j=0;j<10;++j){
			if(!arr[i][j])	continue;
			done=0;
			for(int k=0;k<5;++k){
				if(a[k]>4)	continue;
				if(i+k>9 || j+k>9)	continue;
				int f=1;
				for(int r=0;r<k+1;++r){
					for(int c=0;c<k+1;++c){
						if(!arr[i+r][j+c]){
							f=0;break;
						}
					}
					if(!f)	break;
				}
				if(f){
					for(int r=0;r<k+1;++r)
						for(int c=0;c<k+1;++c)
							arr[i+r][j+c]=0;
					a[k]++;
					sol(i, a);
					for(int r=0;r<k+1;++r)
						for(int c=0;c<k+1;++c)
							arr[i+r][j+c]=1;
					a[k]--;
				}
			}
			if(arr[i][j])	return;
		}
	}
	if(done){
		if(ans>ret)	ans=ret;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<10;++i)for(int j=0;j<10;++j)	cin>>arr[i][j];
	int num[5]={0, 0, 0, 0, 0};
	sol(0, num);
	if(ans>25)	cout<<"-1\n";
	else	cout<<ans<<"\n";
	return 0;
}
