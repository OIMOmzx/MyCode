#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct node
{
    double x, y;
}a, b, c, d;
double p, q, r;

double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double work(double x1, double y1, double x2, double y2)
{
    double res1 = dis(x1, y1, a.x, a.y);
    double res2 = dis(x2, y2, d.x, d.y);
    double res3 = dis(x1, y1, x2, y2);
    return res1 / p + res2 / q + res3 / r;
}

double check(double nx, double ny)
{
    node l, r, lmid, rmid;
    l.x = c.x, l.y = c.y; 
    r.x = d.x, r.y = d.y;
    while(fabs(r.x - l.x) > 1e-12 || fabs(r.y - l.y) > 1e-12)
    {
        lmid.x = l.x + (r.x - l.x) / 3.0;
        rmid.x = r.x - (r.x - l.x) / 3.0;
        lmid.y = l.y + (r.y - l.y) / 3.0;
        rmid.y = r.y - (r.y - l.y) / 3.0;

        if(work(nx, ny, lmid.x, lmid.y) < work(nx, ny, rmid.x, rmid.y))
        {
            r.x = rmid.x;
            r.y = rmid.y;
        }
        else
        {
            l.x = lmid.x;
            l.y = lmid.y;
        }
    }
    return work(nx, ny, lmid.x, lmid.y);
}

int main()
{
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    cin >> p >> q >> r;

    node l, r, lmid, rmid;
    l.x = a.x, l.y = a.y; 
    r.x = b.x, r.y = b.y;
    while(fabs(r.x - l.x) > 1e-12 || fabs(r.y - l.y) > 1e-12)
    {
        lmid.x = l.x + (r.x - l.x) / 3.0;
        rmid.x = r.x - (rs.x - l.x) / 3.0;
        lmid.y = l.y + (r.y - l.y) / 3.0;
        rmid.y = r.y - (r.y - l.y) / 3.0;

        if(check(lmid.x, lmid.y) < check(rmid.x, rmid.y))
        {
            r.x = rmid.x;
            r.y = rmid.y;
        }
        else
        {
            l.x = lmid.x;
            l.y = lmid.y;
        }
    }

    printf("%.2f\n", check(l.x, l.y));
    return 0;
}