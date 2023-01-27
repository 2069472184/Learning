/*
-------��Ŀ-------
����n���ƣ���i���Ƶ���ĿΪci��������һ��������ƣ�joker��������Ŀ��m��
�������ÿ���Ƹ�һ�������һ���ƣ�Ҳ������һ��joker�ͳ���ĳһ��������������Ƹ�һ�����1���ơ�
���磬��n=3ʱ��һ����4�ֺϷ������ƣ�{1,2,3}, {J,2,3}, {1,J,3}, {1,2,J}�� 
����n, m��ci�������������ɾ���������ơ�ÿ�������ֻ������һ��������������Ʋ�ʹ�ã���
-------����-------
��һ�а�����������n, m�����Ƶ�������joker�ĸ�����
�ڶ��а���n������ci����ÿ���Ƶ�������
-------���-------
�����һ���������������ɵ�������Ŀ��
-------����-------
2 <= n <= 50
0 <= m, ci <= 500,000,000
*/
#include<stdio.h>

int n, i;
long m, c[55]; 
long mid, right, left;

int check ( long mid )
{
    long sum = 0;
    for ( i = 1; i <= n; i++ ) {
        if ( c[i] < mid ) {
            sum += mid - c[i];
        }
    }
    if ( sum > m || mid < sum ) {
        return 0;
    } else {
        return 1;
    }
}

int main ( int argc, char *argv[] )
{   
    scanf( "%d %ld", &n, &m );
    for ( i = 1; i <= n; i++ ) {
        scanf( "%ld", &c[i] );
        right += c[i];   //��෽����
    }
       
    left = 0;            //���ٷ�����
    while ( left < right ) {
        mid = ( right + left + 1 ) / 2;
        if ( check( mid ) ) {
            left = mid;                         
        } else {
            right = mid - 1;
        }
    }

    printf( "%ld\n", right );   //���leftҲ��

    return 0;
}