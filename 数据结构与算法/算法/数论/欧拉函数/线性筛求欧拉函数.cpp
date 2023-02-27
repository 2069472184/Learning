//https://www.acwing.com/problem/content/876/

#include <iostream>

using namespace std;

const int N = 1000010;

typedef long long ll;

int primes[N], cnt;
int phi[N];
bool st[N];

ll get_eulers (int n)
{
    //��1���ʵ�������1����
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) 
        {
            primes[cnt++] = i;
            //����i��ŷ��������Ϊph[i] = i - 1��1 ~ i - 1����i����
            phi[i] = i - 1;
        }
        
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
            
            if (i % primes[j] == 0)
            {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
        }
    }
    
    ll res = 0;
    for (int i = 1; i <= n; i++) res += phi[i];
    return res;
}

int main ()
{
    int n;
    cin >> n;
    
    cout << get_eulers(n) << endl;
    
    return 0;
}