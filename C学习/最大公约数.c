/*���b����0�����������a�������Լ����
���򣬼���a����b����������a����b����b�����Ǹ�������
�ص���һ����

a   b   t
12  18  12
18  12  6
12  6   0
6   0      */

#include<stdio.h>
int main(){
    int a,b;
    int t;
    scanf("%d %d",&a,&b);

    /*  
    t=a%b;//����a>b
    while(t!=0){
        a=b;
        b=t;
        t=a%b;
        printf("t=%d\n",t);
    }*/

    for(int i=2;i<((a<b)?a:b);i++){
        if(a%i==0&&b%i==0){
            printf("���Լ����%d\n",i);
        }
    }

    return 0;
}