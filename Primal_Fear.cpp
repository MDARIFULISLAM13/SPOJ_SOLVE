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
const int lm = 1e6 + 123;
bitset<lm> ip;
vector<int> p;
vector<int> cnt(1e6 + 123, 0);
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
    cnt[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        if (ip[i] == true)
        {
            string s = to_string(i);
            if (s.find('0') != string::npos)
            {
                cnt[i] = cnt[i - 1];
                continue;
            }

            while (s.size() > 0)
            {

                s.erase(0, 1);
                if (s.size() == 0)
                {
                    cnt[i] = cnt[i - 1] + 1;
                    break;
                }
                int x = stoi(s);
                if (ip[x] == false)
                {
                    cnt[i] = cnt[i - 1];

                    break;
                }
            }
        }
        else
        {
            cnt[i] = cnt[i - 1];
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
        int v;
        cin >> v;
        cout << cnt[v] << endl;
    }

    return 0;
}