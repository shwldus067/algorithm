#include<iostream>
#include<cstdlib>
using namespace std;
int N, sum=0, mn, Q=15;
bool arr[20][20];
void g(int r){
	for(int i=0;i<N;i++){
		arr[r][i]=!arr[r][i];
		if(arr[r][i])	sum++;
		else sum--;
	}
}
void f(int c){
	for(int i=0;i<N;i++){
		arr[i][c]=!arr[i][c];
		if(arr[i][c])	sum++;
		else	sum--;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	char t;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>t;
			if(t=='T'){
				arr[i][j]=true;
				sum++;
			}
		}
	}
	mn=sum;
	while(Q--){
		for(int i=0;i<70;i++){
			int x=rand()%(N*2);
			int y=sum;
			if(x<N){
				g(x);
				if(sum<=y)	i=-1;
				else	g(x);
			}
			else{
				f(x-N);
				if(sum<=y)	i=-1;
				else	f(x-N);
			}
		}
		mn=min(mn, sum);
		for(int i=0;i<N;i++)	if(rand()%2)	g(i);
		for(int i=0;i<N;i++)	if(rand()%2)	f(i);
	}
	cout<<mn<<"\n";
	return 0;
}
