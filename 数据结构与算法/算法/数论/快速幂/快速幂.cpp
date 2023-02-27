//https://www.acwing.com/problem/content/877/

#include <iostream>

using namespace std;

typedef long long ll;

int qmi (int a, int k, int p)
{
    //res�洢���ݽ�� mod p���϶���int��Χ��
    int res = 1;
    //��������k�Ķ���������ÿһλ����Ӧ2��һ������
    while (k)
    {
        //���k�Ķ���������δ�����꣬�͸��½��
        //k�ĵ�nλ������λ��Ӧa^(2^(n - 1))
        if (k & 1) res = (ll)res * a % p;
        //k����һλ
        k >>= 1;
        //a�ݴμ�һ
        a = (ll)a * a % p; 
    }

    return res;
}

int main ()
{
    int n;
    scanf("%d", &n);
    
    while (n--)
    {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);
        
        printf("%d\n", qmi(a, k, p));
    }
    
    return 0;
}