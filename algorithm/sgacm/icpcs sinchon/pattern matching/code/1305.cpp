#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LEN 1000050

struct KMP{
	char S[MAX_LEN];
	char P[MAX_LEN];
	int hit_count = 0;
	vector<int> index;

	int fail_function[MAX_LEN] = {0,};

	void set_S(char *src){
		strcpy(S, src);
	}

	void set_P(char *src){
		strcpy(P, src);
	}

	void make_fail_function(){
		int j = 0;
		for(int i = 1; P[i] != '\0'; i++){
			while(j > 0 && P[i] != P[j]) j = fail_function[j-1];
			if(P[i] == P[j]) fail_function[i] = ++j;
		}
	}

	void do_KMP(){
		int j = 0;
		for(int i = 0; S[i] != '\0'; i++){
			while(j > 0 && S[i] != P[j]) j = fail_function[j-1];
			if(S[i] == P[j]) j++;
			if(P[j] == '\0'){
				hit_count++;
				index.push_back(i-j+1);
				j = fail_function[j-1];
			}
		}
	}
}kmp;

int main(){
	int L;
	scanf("%d %s", &L, kmp.P);

	kmp.make_fail_function();

	printf("%d\n", L-kmp.fail_function[L-1]);
}