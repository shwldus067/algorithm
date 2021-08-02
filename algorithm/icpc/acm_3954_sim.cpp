#include<cstdio>
using namespace std;
int T, M, C, I, m, i, n;
char code[4100], input[4100], mem[100000];
int sol(int x, int l){
	int y, a, num=0;
	if(l){
		y=x-1, a=1;
		while(a){
			y++;
			if(code[y]==']')	a--;
			else if(code[y]=='[')	++a;
		}
		if(!mem[m]){	//jump
			n=2;
			return y;
		}
	}
	else y=C;
	do{
		for(a=x;a<y;a++, num++){
			switch(code[a]){
				case '-': mem[m]--;break;
				case '+': mem[m]++;break;
				case '<': m=m?m-1:M-1;break;
				case '>': m=m<M-1?m+1:0;break;
				case '[': a=sol(a+1, l+1);num+=n-1;break;
				case ',': mem[m]=i<I?input[i++]:255;
			}
			if(a<0)	return -1;
		}
		if(num++>50000000){
			printf("Loops %d %d\n", x-1, y);
			return -1;
		}
	}while(l && mem[m]);	//']'
	n=num;
	return y;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d\n", &M, &C, &I);
		scanf("%s\n%s", code, input);
		for(int i=0;i<M;++i)	mem[i]=0;
		m=i=0;
		n=sol(0, 0);
		if(n>0)	printf("Terminates\n");
	}
	return 0;
}
