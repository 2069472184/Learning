//https://www.acwing.com/problem/content/description/894/

#include <iostream>

using namespace std;
const int N = 100010;

int c[N], res;

int main ()
{
    int n;
    cin >> n;
    //�ӵ�һ��̨�׿�ʼ����
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &c[i]);
        //��������̨�����������
        if (i % 2) res ^= c[i];
    }
    
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}