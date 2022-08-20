#include <iostream>
using namespace std;
int main(){
    string c1,c2;
    int B;
    int n1[10005] = {0},n2[10005] = {0},n3[10005] = {0};
    cin >> B >> c1 >> c2;
    int len1 = c1.length();
    int len2 = c2.length();
    for (int i = 0;i < len1;i++){
        if (c1[len1 - i - 1] >= '0' && c1[len1 - i - 1] <= '9') n1[i] = c1[len1 - i - 1] - '0';
        else n1[i] = c1[len1 - i - 1] - 'A' + 10;
    }
    for (int i = 0;i < len2;i++){
        if (c2[len2 - i - 1] >= '0' && c2[len2 - i - 1] <= '9') n2[i] = c2[len2 - i - 1] - '0';
        else n2[i] = c2[len2 - i - 1] - 'A' + 10;
    }
    for(int i = 0; i <= len1 - 1; i++)
    {
        cout << n1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i <= len2 - 1; i++)
    {
        cout << n2[i] << " ";
    }
    cout << endl;
    int len3 = max(len1,len2);
    for (int i = 0;i < len3;i++){
        n3[i] += n1[i] + n2[i];
        cout << n3[i] << ", ";
        if (n3[i] > B - 1){
            n3[i + 1] += 1;
            n3[i] %= B;
        }
    }
    if (n3[len3] ) len3 += 1;
    for (int i = len3 - 1;i >= 0;i--){
        if (n3[i] >= 0 && n3[i] <= 9) cout << n3[i];
        else cout << (char)(n3[i] + 10 - 'A');
    } 
    return 0;
}