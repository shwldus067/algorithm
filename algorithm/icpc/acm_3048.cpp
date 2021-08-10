#include<iostream>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N1, N2, T;
	char arr1[30], arr2[30], arr[30]={0, };
	bool dir[30]={0, };
	cin>>N1>>N2>>arr1>>arr2>>T;
	int n1=strlen(arr1), n2=strlen(arr2), n=n1+n2;
	for(int i=0;i<n1;++i){
		dir[arr1[i]-'A']=0;
		arr[n1-i-1]=arr1[i];
	}
	for(int i=0;i<n2;++i){
		dir[arr2[i]-'A']=1;
		arr[n1+i]=arr2[i];
	}
	for(int i=0;i<T;++i){
		for(int j=1;j<n;++j){
			if(!dir[arr[j-1]-'A'] && dir[arr[j]-'A']){
				char tmp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=tmp;
				j++;
			}
		}
	}
	cout<<arr<<"\n";
	return 0;
}
