/**
 *
 * Author : Md.Ariful Islam
 * Date : 20-08-2024
 * time : 04:53:23
 *
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define endl "\n";
#define ft float
#define du double
#define ull unsigned long long
#define vec vector<ll>
const int lm = 1e7 + 123;
bitset<lm> ip;
vector<int> p;
void arif(int n)
{
    p.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        ip[i] = true;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (ip[i] == true)
        {
            for (int j = i + i; j <= n; j += i)
            {
                ip[j] = false;
            }
        }
    }

    ip[2] = true;
    for (int i = 3; i <= n; i += 2)
    {
        if (ip[i] == true)
        {
            p.push_back(i);
        }
    }
}
void pf(int n)
{
    for (auto i : p)
    {
        if (i * i > n)
        {
            break;
        }
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                cout << " x " << i;
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        cout << " x " << n;
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif(lm);
    int n;
    while (cin >> n)
    {
        cout << 1;
        pf(n);
    }

    return 0;
}