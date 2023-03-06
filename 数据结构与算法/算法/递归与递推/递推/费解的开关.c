//https://www.acwing.com/problem/content/97/

//��Ŀ���ʣ������˳���޹أ��Ͱ����йأ���ÿ��������ఴһ��

/*
ö�ٵ�һ�еĲ���(32�����)���ڶ��еĲ����ɵ�һ�в�����Ľ���������Դ����ơ�
�����һ�е�ʱ���������һ�е���������ȫ����˵������������
*/

//�ݹ��һ�У�λ����
//��2~4�еĲ�������¼ƫ����
//ʱ�临�Ӷȣ�32*25*5*500 = 2*10^6 = 2000000
#include<stdio.h>
#include<string.h>

int n;
int state[7][7], backup[7][7];
int dx[5] = { 0, 1, -1, 0, 0 }, dy[5] = { 0, 0, 0, -1, 1 };   //ƫ����С���ɣ���ͬλ����ɵĶ�Ԫ���ʾһ������ƫ��

void turn ( int x, int y )
{
    for ( int i = 1; i <= 5; i++ )
    {
        int a = x + dx[i], b = y + dy[i];
        //if ( a < 1 || a > 5 || b < 1 || b > 5 ) continue;
        state[a][b] ^= 1;   //�����������Ը�Ч��ʵ��1��0�Ļ���
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    while ( n-- ) 
    {
        for ( int i = 1; i <= 5; i++ ) 
            for ( int j = 1; j <= 5; j++ )
            {
                scanf( "%1d", &state[i][j] );
                backup[i][j] = state[i][j];  //����һ�����״̬�������������һ�е�һ������������ԭ
            }
 
        int res = 7; 
        for ( int op = 0; op < 32; op++ )  //���۵�һ�е����в�����������λ�����ƣ���ʮ������
        {
            int step = 0;   //step��¼��ʵ��������
            
            //���Ȱ���op�Ķ�������ʽ0��1������˳��Ե�һ�н��в���
            for ( int i = 0; i < 5; i++ )  
                if ( op >> i & 1 )   //���Ϊ����˵����Ӧλ����1���������1����ܹ��ܺõ��ж϶���������0λ��1����0
                {
                    step++;
                    turn( 1, i+1 );
                } 
            
            //�Ե�2~4�����ν��в���
            for ( int i = 1; i <= 4; i++ ) 
                for ( int j = 1; j <= 5; j++ )
                    if ( state[i][j] == 0 )
                    {
                        step++;
                        turn( i+1, j );
                    } 
                    
            //�ж����һ���Ƿ���
            int judge = 1;
            for ( int i = 1; i <= 5; i++ )
                if ( state[5][i] == 0 )
                {
                    judge = 0;
                    break;
                }
            if ( judge ) res = res>step?step:res;
            
            //��ԭ����ԭ״̬
            for ( int i = 1; i <= 5; i++ )
                for ( int j = 1; j <= 5; j++ )
                    state[i][j] = backup[i][j];
        } 

        if ( res > 6 ) res = -1;
        
        printf( "%d\n", res );
    }

    return 0;
}
