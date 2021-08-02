#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX_LEN 2000050
#define MOD (1000000000000000LL + 37)

using namespace std;

typedef pair<long long int, long long int> pll;

struct Karp_Rabin{
	char S[MAX_LEN];
	char P[MAX_LEN];
	int lenS = 0;
	int lenP = 0;
	int cur_idx = 0;

	long long int hash2_P = 0;
	long long int hash3_P = 0;
	long long int hash2_S = 0;
	long long int hash3_S = 0;

	long long int pow2P = 1;
	long long int pow3P = 1;

	void make_hash_P(){
		long long int pow3 = 1;
		long long int pow2 = 1;

		for(int i = 0; i < lenP; i++){
			hash2_P += P[lenP-i-1]*pow2%MOD;
			hash3_P += P[lenP-i-1]*pow3%MOD;
			hash2_P %= MOD;
			hash3_P %= MOD;
			pow2 *= 2;
			pow3 *= 3;
			pow2 %= MOD;
			pow3 %= MOD;
		}
	}

	void hash_next(){
		long long int pow3 = 1;
		long long int pow2 = 1;

		if(cur_idx == 0){
			for(int i = 0; i < lenP; i++){
				hash2_S += S[lenP-i-1]*pow2%MOD;
				hash3_S += S[lenP-i-1]*pow3%MOD;
				hash2_S %= MOD;
				hash3_S %= MOD;
				pow2 *= 2;
				pow3 *= 3;
				pow2 %= MOD;
				pow3 %= MOD;
			}
			pow2P = pow2;
			pow3P = pow3;
		}
		else if(cur_idx <= lenS-lenP){
			hash2_S = 2*hash2_S - S[cur_idx-1]*pow2P + S[cur_idx + lenP - 1];
			hash2_S = (hash2_S%MOD+MOD)%MOD;
			hash3_S = 3*hash3_S - S[cur_idx-1]*pow3P + S[cur_idx + lenP - 1];
			hash3_S = (hash3_S%MOD+MOD)%MOD;
		}
		else{
			cur_idx = -1;
			hash2_S = 0;
			hash3_S = 0;
		}
		cur_idx++;
	}

	pll get_hash(){
		return {hash2_S, hash3_S};
	}

	bool match(){
		if(hash2_S == hash2_P && hash3_S == hash3_P) return true;
		return false;
	}
}K_R;

int get_gcd(int a, int b){
	if(b == 0) return a;
	return get_gcd(b, a%b);
}

int main(){
	int 	N, gcd;
	int 	hit_count = 0;
	char 	tmp_input;

	scanf("%d", &N);
	K_R.lenP = N;
	K_R.lenS = N + N - 1;

	for(int i = 0; i < N; i++){
		scanf(" %c", &tmp_input);
		K_R.S[i] = K_R.S[i + N] = tmp_input;
	}

	for(int i = 0; i < N; i++){
		scanf(" %c", &tmp_input);
		K_R.P[i] = tmp_input;
	}

	K_R.make_hash_P();

	for(int i = 0; i < N; i++){
		K_R.hash_next();
		if(K_R.match()) hit_count++;
	}

	gcd = get_gcd(K_R.lenP, hit_count);
	printf("%d/%d\n", hit_count/gcd, K_R.lenP/gcd);
}