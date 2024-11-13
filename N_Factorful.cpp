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
const int lm = 1e6 + 123;
bitset<lm> ip;
vector<int> p;
int a[lm];
int cnt[21][lm]; // আমরা 21 নিচ্ছি, কারণ 0 থেকে 20 পর্যন্ত divisors হতে পারে।

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
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    for (int j = 2; j <= n; j += 2)
    {
        a[j]++;
    }
    for (int i = 3; i <= n; i += 2)
    {
        if (ip[i] == true)
        {
            for (int j = i; j <= n; j += i)
            {
                a[j]++;
            }
        }
    }

    for (int c = 0; c <= 20; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            cnt[c][i] = cnt[c][i - 1] + (a[i] == c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif(lm);
    int n;
    cin >> n;
    while (n--)
    {
        int A, B, c;
        cin >> A >> B >> c;
        int ans = cnt[c][B] - cnt[c][A - 1];
        cout << ans << endl;
    }

    return 0;
}
