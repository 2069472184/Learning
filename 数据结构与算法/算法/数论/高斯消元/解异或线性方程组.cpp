//https://www.acwing.com/problem/content/886/

#include <iostream>

using namespace std;

const int N = 110;

int n;
int a[N][N];

int gauss ()
{
    int r, c;
    for (r = 0, c = 0; c < n; c++)
    {
        //�ҵ���0�У�ע�⣬�˴�t�����ʼ��r��
        //��Ϊ�����ǰ��Ԫ��ȫΪ0����ôӦ��ֱ��������һ�У�
        //����һ����Ҫ�жϵ�ǰ����ĳһ��Ԫ��Ϊ0��������t = r
        //��Ȼ���������һ�еķ�����Ԫû��Ҫ��ֻҪ�Ƿ�����Ԫ����
        int t = r;
        for (int i = r; i < n; i++)
            if (a[i][c]) 
            {
                t = i;
                break;
            }

        if (!a[t][c]) continue;
        
        //����r�к�t��
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        
        //��r + 1 ~ n - 1���е�c�е�1��Ϊ0��ÿһ������Ԫ����Ӧ������㼴��
        for (int i = r + 1; i < n; i++)
            if (a[i][c])
                for (int j = n; j >= c; j--)
                    a[i][j] ^= a[r][j];
                    
        r++;
    }
    
    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (a[i][n]) return 2;
        return 1;
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                a[i][n] ^= a[i][j] * a[j][n];
        return 0;
    }
}

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%d", &a[i][j]);
            
    int t = gauss();
    
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Multiple sets of solutions");
    else 
    {
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i][n]);
    }
    
    return 0;
}