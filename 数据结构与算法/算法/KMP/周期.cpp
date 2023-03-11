//https://www.acwing.com/problem/content/143/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000010;

int n;
char p[N];
int ne[N];

int main ()
{
    int cnt = 1;
    while (cin >> n, n)
    {
        memset(ne, 0, 4 * n);
        
        cin >> (p + 1);
        
        for (int i = 2, j = 0; i <= n; i++)
        {
            while (j && p[i] != p[j + 1]) j = ne[j];
            
            if (p[i] == p[j + 1]) j++;
            
            ne[i] = j;
        }
        
        cout << "Test case #" << cnt++ << endl;
        
        for (int i = 2; i <= n; i++)
        {
            //��ͼ������⣬i - ne[i] ����һ�����ܵ�ѭ����
            int t = i - ne[i];
            //�˴�������������ѭ���ڵĶ�������ж�
            if (i % t == 0 && i / t > 1)
                cout << i << ' ' << i / t << endl;
        }

        puts("");
    }
    
    return 0;
}