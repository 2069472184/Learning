//https://www.acwing.com/problem/content/845/

//���ضԽ���
#include <iostream>
#include <cstring>

using namespace std;

int n;
int p[11], pre[11][11];
int mark[11][11];

void dfs (int k)
{
    if (k == n + 1) 
    {
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= n; j++ )
                if (mark[i][j]) cout << 'Q';
                else cout << '.';
            puts("");
        }
        puts("");

        return;
    }
    
    for ( int i = 1; i <= n; i++ )
        if (p[i] == 0 && pre[k][i] == 0)
        {
            p[i] = 1;
            for ( int j = i + 1; j <= n && k + j - i <= n; j++ ) pre[k + j - i][j]++;
            for ( int j = i - 1; j >= 1 && k + i - j <= n; j-- ) pre[k + i - j][j]++;
            mark[k][i] = 1;
            dfs(k + 1);
            p[i] = 0;
            for ( int j = i + 1; j <= n && k + j - i <= n; j++ ) pre[k + j - i][j]--;
            for ( int j = i - 1; j >= 1 && k + i - j <= n; j-- ) pre[k + i - j][j]--;
            mark[k][i] = 0;
        }
}

int main () 
{
    cin >> n;
    
    dfs(1);
    
    return 0;
}

//��ȻҲ������������������ʾ���Խ��ߺͷ��Խ��ߣ��۲쵽��ͬһ���Խ����� k + i ʼ�ղ���
//��ͬһ���Խ����� n - i + k ʼ�ղ���