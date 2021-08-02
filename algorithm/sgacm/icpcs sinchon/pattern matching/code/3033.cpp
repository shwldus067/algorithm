#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

#define MAX_LEN 400050
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

	void init(){
		hash2_S = hash3_S = hash2_P = hash3_P = 0;
		pow2P = pow3P = 1;
		cur_idx = 0;
	}

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

bool check(int length){
	set<pll> S;

	K_R.init();
	K_R.lenP = length;

	for(int i = 0; i <= K_R.lenS - K_R.lenP; i++){
		K_R.hash_next();
		auto res = S.insert(K_R.get_hash());
		if(!res.second) return true;
	}

	return false;
}

int main(){
	int 	L, lo, hi, md, ans = 0;

	scanf("%d", &L);
	scanf(" %s", K_R.S);
	K_R.lenS = L;

	lo = 0;
	hi = L-1;
	while(lo <= hi){
		md = (lo + hi) / 2;
		if(check(md)) {
			ans = md;
			lo = md + 1;
		}
		else hi = md - 1;
	}

	printf("%d\n", ans);

}