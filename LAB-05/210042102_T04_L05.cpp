/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀B⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠐⡑⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠈⠀⠀⢌⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠈⠀⠀⠀⠀⠢⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀A⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠊⠀⠀⠀⠀⠀⠀⡑⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡂⠁⠂⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠐⠈⠀⠀⠀⠀⠀⠀⠀⢌⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡂⠀⠀⠀⠁⠢⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠢⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡂⠀⠀⠀⠀⠀⠀⠑⠠⢀⠀E⠀⡀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡑⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡐⡐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢌⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀ ⡂⠀⠀⠀⠀⠀⠀⠀⠀⠠⠈⢐⠈⠈⠐⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠢⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡂⠀⠀⠀⠀⠀⠀⡄⠁⠁⠀⢐⠀⠀⠀⠀⠁⠢⡀⡀⠀⠀⠀⠀⠀⠀⠀⠀⡑⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡂⠀⠀⠀⠀⠄⠁⠀⠀⠀⠀⢐⠀⠀⠀⠀⠀⠀⠀⠐⠠⢀⠀⠀⠀⠀⠀⠀⢌⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡂⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⢐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠢⢀⠀⠀⠀⠢⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡂⠂⠂⠀⠀⠀⠀⠀⠀⠀⠀⢐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠢⢀⢑⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀C⠀⠁⠁⠁⠁⠁⠁⠁⠁⠁⠁F⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠈⠀D⠀

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second

signed main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	double AD, BC, EF;

	cin >> t;

	for(int cs = 1; cs <= t; cs++){
		cin >> AD >> BC >> EF;

		double hi = INT_MAX, lo = 0, mid; // binary search for CD

		int k = 1000000;

		while(k--){
			mid = (hi + lo) / 2;
			double CD = mid;

			double AC = sqrtl(AD * AD - CD * CD);
			double BD = sqrtl(BC * BC - CD * CD);

			if(EF * (AC + BD) < (AC * BD)) lo = mid + 1; // EF = 1 / ((1 / AC) + (1 / BD))
			else hi = mid - 1;
		}

		cout << "Case " << cs << ": ";
		cout << fixed << setprecision(15);
		cout << mid << "\n";
	}

	return 0;
}
