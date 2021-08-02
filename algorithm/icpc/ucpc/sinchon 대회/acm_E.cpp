#include<iostream>
#include<cstring>
using namespace std;
long long arr[1000000], l, r;
char input[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	int i=0;
	if(input[i]=='-'){
		i++;
		int tmp=0;
		while(input[i]>='0' && input[i]<='9'){
			tmp=tmp*10+(int)(input[i]-'0');
			i++;
		}
		arr[r++]=-tmp;
	}
	while(i<strlen(input)){
		if(input[i]>='0' && input[i]<='9'){
			int tmp=0;
			while(input[i]>='0' && input[i]<='9'){
				tmp=tmp*10+(int)(input[i]-'0');
				i++;
			}
			arr[r++]=tmp;
		}
		else{
			if(input[i]=='*'){
				arr[r++]=0;
			}
			else if(input[i]=='/'){
				arr[r++]=1;
			}
			else if(input[i]=='+'){
				arr[r++]=2;
			}
			else{
				arr[r++]=3;
			}
			i++;
		}
	}
	r--;
	long long ans;
	while(l<r){
		if(arr[l+1]/2 == arr[r-1]/2){
			int a=arr[l];
			switch (arr[l+1]){
				case 0:
					a=a*arr[l+2];
					break;
				case 1:
					a=a/arr[l+2];
					break;
				case 2:
					a=a+arr[l+2];
					break;
				case 3:
					a=a-arr[l+2];
					break;
			}
			int b=arr[r-2];
			switch (arr[r-1]){
				case 0:
					b=b*arr[r];
					break;
				case 1:
					b=b*arr[r];
					break;
				case 2:
					b=b*arr[r];
					break;
				case 3:
					b=b*arr[r];
					break;
			}
			if(a<b){
				ans=b;
				r-=2;
				arr[r]=b;
			}
			else{
				ans=a;
				l+=2;
				arr[l]=a;
			}
		}
		else if(arr[l+1]/2 > arr[r-1]/2){
			int b=arr[r-2];
			switch (arr[r-1]){
				case 0:
					b=b*arr[r];
					break;
				case 1:
					b=b*arr[r];
					break;
				case 2:
					b=b*arr[r];
					break;
				case 3:
					b=b*arr[r];
					break;
			}
			ans=b;
			r-=2;
			arr[r]=b;
		}
		else{
			int a=arr[l];
			switch (arr[l+1]){
				case 0:
					a=a*arr[l+2];
					break;
				case 1:
					a=a/arr[l+2];
					break;
				case 2:
					a=a+arr[l+2];
					break;
				case 3:
					a=a-arr[l+2];
					break;
			}
			ans=a;
			l+=2;
			arr[l]=a;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
