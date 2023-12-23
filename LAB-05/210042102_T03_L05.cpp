#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second

double xy, xz, yz, r;

double Area_xlm(double xl){
	double lm = (yz / xy) * xl;
	double xm = (xz / xy) * xl;
	double s = (lm + xm + xl) / 2;

	return sqrtl(s * (s - lm) * (s - xm) * (s - xl));
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m, q, i, t;

	double mid;

	cin >> t;

	for(int c = 1; c <= t; c++){
		cin >> xy >> xz >> yz >> r;

		double s = (xy + yz + xz) / 2;
		double area_xyz = sqrtl(s * (s - xy) * (s - yz) * (s - xz));

		double lo = 0, hi = xy;


		m = 1000000;
		while(m--){
			mid = (lo + hi) / 2;
			double area_xlm = Area_xlm(mid);
			if(area_xlm > r * (area_xyz - area_xlm)) hi = mid - 1;
			else lo = mid + 1;
		}

		cout << "Case " << c << ": ";
		cout<< fixed << setprecision(10);
		cout << mid << "\n";
	}


	return 0;
}

// 4
// 8.134 9.098 7.123 5.10
// 7 8 9 10
// 100 100 100 2
// 10 12 14 1
