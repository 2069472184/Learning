#include<stdio.h>

typedef union{
    int i;
    char ch[sizeof(int)];
}CHI;

int main(int argc,char const *argv[]){
    CHI chi;
    int i;
    chi.i=1234;
    for(i=0;i<sizeof(int);i++){
        printf("%02hhX",chi.ch[i]);   //���ΪD2040000����Ϊx86ϵͳ��С��ϵͳ����λ��ǰ��1234ת��Ϊ16���ƺ��Ϊ0x04D2
    }
    printf("\n");
    return 0;   
}