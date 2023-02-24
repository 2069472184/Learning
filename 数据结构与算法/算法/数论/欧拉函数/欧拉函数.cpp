//https://www.acwing.com/problem/content/875/

#include <iostream>

using namespace std;

int n;

int oula (int a)
{
    int res = a;
    for (int i = 2; i <= a / i; i++)
        if (a % i == 0)
        {
            //�˴�ע�⣬һ��Ҫ�������������˷��������
            res = res / i * (i - 1);
            while (a % i == 0) a /= i;
        }
    if (a > 1) res = res / a * (a - 1);
    
    return res;
}

int main ()
{
    cin >> n;
    
    while (n--)
    {
        int a;
        cin >> a;
        cout << oula(a) << endl;
    }
    
    return 0;
}