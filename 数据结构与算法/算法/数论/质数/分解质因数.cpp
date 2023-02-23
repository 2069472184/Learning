//https://www.acwing.com/problem/content/description/869/

#include <iostream>
#include <cmath>

using namespace std;

int n;

void divide (int u)
{
    //��Ϊu��ֻ���ܴ���һ����sqrt(u)���������
    //���Կ���ֱ��ö�ٵ� u / i
    for (int i = 2; i <= u / i; i++)
        //ÿ����һ�������������ͻ᲻�ϳ����Ǹ�����ֱ�����
        //�µĲ��ܱ�ԭ������������
        //���Դ˴���i�϶�����һ������
        if (u % i == 0)  
        {
            int s = 0;
            //���ϳ���������
            while (u % i == 0)
            {
                u /= i;
                s++;
            }
            
            cout << i << ' ' << s << endl;
        }
    
    //�����������sqrt(n)��������
    if (u > 1) cout << u << ' ' << 1 << endl;  
    puts("");
}

int main ()
{
    cin >> n;
    
    while (n--)
    {
        int a;
        cin >> a;
        divide(a);
    }
    
    return 0;
}