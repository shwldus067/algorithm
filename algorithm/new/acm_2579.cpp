#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int score[N+1]={0};
	int stair[N+1];
	stair[0]=0;
	for(int i=1;i<=N;i++){
		cin>>stair[i];
	}
	if(N==1){
		cout<<stair[1];
		return 0;
	}
	else if(N==2){
		cout<<stair[1]+stair[2];
		return 0;
	}
	score[1]=stair[1];
	score[2]=score[1]+stair[2];
	for(int i=3;i<=N;i++){
		if((score[i-3]+stair[i-1]+stair[i])>score[i-2]+stair[i]){
			score[i]=score[i-3]+stair[i-1]+stair[i];
		}
		else{
			score[i]=score[i-2]+stair[i];
		}
	}
	cout<<score[N];
	return 0;
}

