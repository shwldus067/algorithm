#include<cstdio>
#include<cmath>
using namespace std;
#define PI 3.14159265358979323846
int cnt[3];
double r[3][101], x[3][2], rt[3];
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		double a, b, d1, d2;
		int k;
		scanf("%lf %lf %d", &a, &b, &k);
		double R=((a+b)-sqrt(a*a+b*b))/2, ans;
		if(k==1){
			printf("%.10lf\n", R*R*PI);
			continue;
		}
		x[1][1]=a;x[2][0]=b;
		cnt[0]=cnt[1]=cnt[2]=1;
		r[0][0]=r[1][0]=r[2][0]=R;
		for(int i=0;i<3;++i){
			d1=R-x[i][0];
			d2=R-x[i][1];
			rt[i]=sqrt(d1*d1+d2*d2);
			r[i][1]=(R*(rt[i]-R))/(rt[i]+R);
		}
		while(--k){
			int idx=0;
			double mr=0;
			for(int i=0;i<3;++i){
				if(r[i][cnt[i]]>mr)	mr=r[i][cnt[i]], idx=i;
			}
			ans=mr;
			r[idx][cnt[idx]]=r[idx][cnt[idx]-1]+mr*2;
			mr=r[idx][cnt[idx]];
			cnt[idx]++;
			r[idx][cnt[idx]]=(R*(rt[idx]-mr))/(rt[idx]+R);
		}
		printf("%.10lf\n", ans*ans*PI);
	}
	return 0;
}
