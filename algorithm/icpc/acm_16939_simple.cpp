#include<stdio.h>
int a[8]={5, 6, 17, 18, 21, 22, 13, 14};
int b[8]={1, 3, 5, 7, 9, 11, 24, 22};
int c[8]={3, 4, 17, 19, 10, 9, 16, 14};
int cube[25];
int rot(int *arr, int t){
	int tmp[25];
	for(int i=1;i<25;++i)	tmp[i]=cube[i];
	for(int i=0;i<8;++i){
		int j=i+t;
		if(j<0)	j+=8;
		else if(j>7)	j-=8;
		tmp[arr[j]]=cube[arr[i]];
	}
	for(int i=1;i<25;i+=4)for(int j=1;j<4;++j){
		if(tmp[i]!=tmp[i+j])	return 0;
	}
	return 1;
}
int sol(){
	if(rot(a, 2))	return 1;
	if(rot(a, -2))	return 1;
	if(rot(b, 2))	return 1;
	if(rot(b, -2))	return 1;
	if(rot(c, 2))	return 1;
	if(rot(c, -2))	return 1;
	return 0;
}
int main(){
	for(int i=1;i<25;++i)	scanf("%d", &cube[i]);
	printf("%d\n", sol());
	return 0;
}
