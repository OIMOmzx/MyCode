#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 1000010;
int num, option;
double height, weight;
double boy_low_standard, boy_high_standard, girl_low_standard, girl_high_standard;

inline int read()
{
    int s = 0, f = 0;
    char ch = ' ';
    while(!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while(isdigit(ch))
    {
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return (f) ? (-s) : (s);
}

class solution
{
    public:
        void boy(double bmi)
        {
            cout << "Boy:";
            if(bmi < boy_low_standard)
            {
                cout << "Too thin!" << endl;
            }
            else if(bmi >= boy_low_standard && bmi <= boy_high_standard)
            {
                cout << "Not too thin, or not too fat." << endl;
            }
            else
            {
                cout << "Too fat" << endl;
            }
        }

        void girl(double bmi)
        {
            cout << "Girl:";
            if(bmi < girl_low_standard)
            {
                cout << "Too thin!" << endl;
            }
            else if(bmi >= girl_low_standard && bmi <= girl_high_standard)
            {
                cout << "Not too thin, or not too fat." << endl;
            }
            else
            {
                cout << "Too fat" << endl;
            }
        }
};

int main()
{
    while(1)
    {
        num++;
        cout << "Case" << num << ':' << endl;
        cout << "You should input three variables next, you height(m), weight(kg), and if you are a boy or a girl" << endl;
        cin >> height >> weight;
        option = read();
        cout << "Because I cannot remember the standard, so I need you to input them. ', 'First in pust the lower limit, then the higher limit; First boys, then girls" << endl;
        cin >> boy_low_standard >> boy_high_standard >> girl_low_standard >> girl_high_standard;
        int bmi = weight * 1.0 / (height * height);
        solution object;
        if(option == 1) object.boy(bmi);
        if(option == 0) object.girl(bmi);
    }
    return 0;
}