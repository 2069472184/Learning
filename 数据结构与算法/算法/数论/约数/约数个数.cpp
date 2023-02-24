//https://www.acwing.com/problem/content/872/

//��ö��ÿ�����������ӷֽ�������浽��ϣ����
//�����ù�ʽ�󼴿�
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int n;

int main ()
{
    cin >> n;
    
    unordered_map<int, int> prime;
    
    while (n--)
    {
        int x;
        cin >> x;
        //��ǰ������������ӷֽ����
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                prime[i]++;
            }
        }
        //��Ҫ���˴���sqrt(n)��������
        if (x > 1) prime[x]++;
    }
    
    ll res = 1;
    for (auto k : prime) res = res * (k.second + 1) % mod; 
    
    cout << res;
    
    return 0;
}