//https://www.acwing.com/problem/content/340/

//��λͳ��DP
/*
״̬��ʾ��dp[i][j][u]��ʾ����������iλ�����λ��j�����ķ���ӵ��u�ĸ����ļ��ϣ�������count
״̬���֣�
    1.����jλ��Ϊu��dp[i][j][u] += dp[i][k][u];  //k��ʾ��j-1λ����
    2.����jλΪu��dp[i][j][k] += dp[i-1][k][u] + 
*/
#include<stdio.h>

int a, b;
int dp[];

int main ( int argc, char *argv[] )
{
    
    while ( scanf( "%d%d", &a, &b ), a ) 
    {
        if ( a > b ) 
        {
            int box = a;
            a = b; 
            b = box;
        }

        for ( int i = 0; i < 10; i++ )

        for ( int i = 0; i < 10; i++ ) printf( "%d ", dp[][] );
        printf( "\n" );
    }


    return 0;
}