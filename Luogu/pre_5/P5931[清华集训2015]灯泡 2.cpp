#include <iostream>
#include <iomanip>
using namespace std;

const int Max = 10000010;
long long n;
double H, h, D;

double ans(double x) 
{
    if(x <= h * D / H) return x + (H - (H - h) * D / (D - x));
    else return x - D + ((D - x) * H / (H - h));
}
int main() 
{
	cin >> n;
	for(int i = 1; i <= n; i++) 
    {
		cin >> H >> h >> D;
		double l = 0, r = Max;
	    while(r - l >= 1e-7) 
        {
		    double lmid = l + (r - l) / 3;
		    double rmid = r - (r - l) / 3;
		    if(ans(lmid) > ans(rmid)) r = rmid;
		    else l = lmid;
	    }
	    cout << fixed << setprecision(3) << ans(l) + 1e-10 << endl;
	}
	return 0; 
} 