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
const int lm = 2e7;
bitset<lm> ip;
vector<int> p;
vec a;
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
            for (int j = i * i; j <= n; j += i * 2)
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
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size() && (ll)p[i] * p[j] <= lm; j++)
        {
            a.push_back((ll)p[i] * p[j]);
        }
    }

    sort(a.begin(), a.end());
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif(lm);

    int t;
    cin >> t;
    while (t--)
    {
        int v;
        cin >> v;
        cout << a[v - 1] << endl;
    }

    return 0;
}