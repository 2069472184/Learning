//�˷���ʱ�临�Ӷ�ΪO( N )
//��Щ�ܹ�������ʱ�����еĴ��붼�Ǻô���
#include<stdio.h>

#define N 10000

int a[N];

int MaxSubSum ( const int *a, int left, int right )
{
    int ThisSum = 0, MaxSum = 0, j;
    for ( j = left; j<=right; j++ ) {
        ThisSum += a[j];
        if ( ThisSum > MaxSum ) {
            MaxSum = ThisSum;
        } else if ( ThisSum < 0 ) {
            ThisSum = 0;
        }
    }
    return MaxSum;
}

int main ( int argc, char *argv[] )
{
    int result, num, leftborder, rightborder, i = 0;

    scanf( "%d %d", &leftborder, &rightborder );
    scanf( "%d", &num );
    while ( num != 0 ) {
        a[i++] = num;
        scanf( "%d", &num );
    } 

    result = MaxSubSum( a, leftborder, rightborder );
    printf( "%d\n", result );
    return 0;
}