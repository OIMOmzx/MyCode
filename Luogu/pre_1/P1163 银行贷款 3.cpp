#include <iostream>
#include <iomanip>
using namespace std;

int need_to_pay, per_month, month;
double l = 0, r = 5, mid, ans;

double pow(double n, int time)
{
    if(time == 0) return 1.00;
    if(time == 1) return n;
    else return n * pow(n, time - 1);
}

double isvalid(double k)
{
    double sum = 0;
    for(int i = 1; i <= month; i++)
    {
        sum += per_month / pow((1.000 + k), i);
    }
    return sum;
}

int main()
{
    cin >> need_to_pay >> per_month >> month;
    //cout << isvalid(0.029) << endl;
    while(r - l >= 1e-12)
    {
        mid = (l + r) / 2;
        //cout << l << ", " << r << ", " << mid << ": " << isvalid(mid) << endl;
        if(isvalid(mid) < need_to_pay) r = mid;
        else l = mid + 1e-6, ans = mid;
    }
    ans *= 100.0;
    cout << fixed << setprecision(1) << ans << endl;
    return 0;
}