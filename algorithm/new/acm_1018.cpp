#include<iostream>
using namespace std;

int main(){
	int M, N, i, j, k, l, min, cnt_w, cnt_b, cnt;
	cin>>N>>M;
	char ary[N][M];
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			cin>>ary[i][j];
		}
	}
	min=8*8;
	for(i=0;i+7<N;i++){
		for(j=0;j+7<M;j++){
			cnt_w=cnt_b=0;
			for(k=0;k<8;k++){
				for(l=0;l<8;l++){
					if((i+k+j+l)%2==0){
						if(ary[i+k][j+l]=='W')	cnt_b++;
						else	cnt_w++;
					}
					else{
						if(ary[i+k][j+l]=='W')	cnt_w++;
						else	cnt_b++;
					}
				}
			}
			cnt=cnt_w<cnt_b ? cnt_w:cnt_b;
			if(cnt<min)	min=cnt;
		}
	}
	cout<<min;
	return 0;
}
