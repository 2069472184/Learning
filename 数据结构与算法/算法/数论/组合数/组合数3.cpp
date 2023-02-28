//https://www.acwing.com/problem/content/889/

#include <iostream>

using namespace std;

typedef long long ll;

//������
int qmi (int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (ll)res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

//���������
int C (int a, int b, int p)
{
    //��� b > a���޷�����ѡ
    if (b > a) return 0;
    
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        //������ӳ˻�
        res = (ll)res * j % p;
        //����Ԫ�����ĸ������ֻ��ͬģʱ��Ч
        res = (ll)res * qmi(i, p - 2, p) % p;
    }
    return res;
}

int lucas (ll a, ll b, int p)
{
    //��� a < p �� b < p����ôֱ�������������
    if (a < p && b < p) return C(a, b, p);
    //�˴����ܱ�֤ a/p �� b/p ��Ͷ� < p�����Ի���ֻ��дΪ lucas(a / p, b / p, p)
    else return (ll)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main ()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        ll a, b;
        int p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }
    
    return 0;
}