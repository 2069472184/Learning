//https://www.acwing.com/problem/content/118/

//ֻ�Ͱ����Ĵ����йأ���˳���޹�
//ö�٣����������п��ܵķ�������һһ�ж��Ƿ��������
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N (int)pow(2.0,16.0)

char start[5][5], copy[5][5];
int trance[13][3], guide[13][3];    //�д洢x���꣬�д洢y����

void turn ( int x, int y )
{
    for ( int i = 0; i < 4; i++ ) 
    {
        start[i][y] = ( start[i][y]=='+' )?'-':'+';
    }
    for ( int j = 0; j < 4; j++ )
    {
        if ( j == y ) continue;
        start[x][j] = ( start[x][j]=='+' )?'-':'+';
    }
}

int main ( int argc, char *argv[] )
{   
    for ( int i = 0; i < 4; i++ )
        gets( start[i] );

    memcpy( copy, start, sizeof(start) );

    int result = 17;    //�����16�β���������Ϊ�˱�֤��16�β���Ϊ���ٲ��������������Ҳ����¼�����ݣ���Ҫ��result�ĳ�ʼ���ֵ��+1
    for ( long op = 0; op < N; op++ ) 
    {
        int step = 0;
        for ( int i = 0; i < 16; i++ )
            if ( op >> i & 1 )      //���Ϊ���桱�൱�ڸ�λ���л�����
            {
                trance[step][0] = i/4;
                trance[step++][1] = i - i/4 * 4;    
                turn( i/4, i - i/4 * 4 );
            }

        int flag = 1;
        for ( int j = 0; j < 16; j++ )
            if ( start[j/4][j - j/4 * 4] == '+' ) 
            {
                flag = 0;
                break;
            }
        
        if ( flag && result > step ) 
        {
            result = step;
            for ( int i = 0; i < step; i++ )
            {
                guide[i][0] = trance[i][0];
                guide[i][1] = trance[i][1];
            }
        }

        memcpy( start, copy, sizeof(copy) );
    }

    printf( "%d\n", result );
    for ( int i = 0; i < result; i++ )
        printf( "%d %d\n", guide[i][0]+1, guide[i][1]+1 );

    return 0;
}