//https://www.acwing.com/problem/content/873/

#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int n;

int main ()
{
    cin >> n;
    
    unordered_map<int, int> primes;
    
    while (n--)
    {
        int a;
        cin >> a;
        
        for (int i = 2; i <= a / i; i++)
            while (a % i == 0)
            {
                a /= i;
                primes[i]++;
            }
        
        if (a > 1) primes[a]++;
    }
    
    ll res = 1;
    //�׹�ʽ��a��������b��ָ��
    for (auto prime : primes) 
    {
        ll a = prime.first, b = prime.second;
        ll t = 1;
        //���� a^0 + a^1 + a^2 + a^3 + ���� + a^n 
        //ÿ��ѭ���� t ������� a���൱�� t ���������ټ� 1
        while (b--) t = (t * a + 1) % mod;
        res = res * t % mod;
    }
    
    cout << res;
    
    return 0;
}