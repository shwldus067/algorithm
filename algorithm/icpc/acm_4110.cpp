#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int l, w, cx, cy, tx, ty, n;
	while (1) {
		scanf("%d %d %d %d %d %d %d", &l, &w, &cx, &cy, &tx, &ty, &n);
		if(!l)	break;
		double ans = 1e9;
		for (int i = 0; i < 201; ++i) {
			for (int j = 0; j < 201; ++j) {
				if (abs(100 - i) + abs(100 - j) == n) {
					int x, y;
					if (i & 1) x = (i - 99) * l - tx;
					else x = (i - 100) * l + tx;
					if (j & 1) y = (j - 99) * w - ty;
					else y = (j - 100) * w + ty;
					bool f = 0;
					for (int ii = min(i, 100); ii <= max(i, 100); ++ii) {
						for (int jj = min(j, 100); jj <= max(j, 100); ++jj) {
							if (ii == i && jj == j) continue;
							int xx, yy;
							if (ii & 1) xx = (ii - 99) * l - tx;
							else xx = (ii - 100) * l + tx;
							if (jj & 1) yy = (jj - 99) * w - ty;
							else yy = (jj - 100) * w + ty;
							int ax=x-xx, ay=y-yy, bx=cx-xx, by=cy-yy;
							if (ax*by==ay*bx) {
								if (ii == 100 && jj == 100) {
									if ((xx < cx) == (x < cx) && (yy < cy) == (y < cy)) f = 1;
								}
								else f = 1;
							}
						}
					}
					if (!f) {
						ans = min(ans, sqrt((x - cx)*(x-cx)+(y - cy)*(y-cy)));
					}
				}
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
