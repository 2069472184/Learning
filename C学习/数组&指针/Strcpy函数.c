#include<stdio.h>
#include<string.h>

//ָ������
char *mycpy(char *dst,const char *src){
    char *ret=dst;   //&dst[0]����dst�滻       
    while(*src){
        *dst++=*src++;
    }
    dst='\0';
    return ret;
}

//��������
/*char *mycpy(char *dst,char *src){
    int i=0;
    char *p=src;
    printf("%p\n",p+1);
    printf("%p\n",src+1);
    while(src[i]){
        dst[i]=src[i];
        i++;     
    }  
    dst[i]='\0';
    return dst;
}*/


int main(){
    char a[10];
    scanf("%s",&a);
    char b[10];
    scanf("%s",&b);
    printf("b=%s\n",mycpy(b,a));
    return 0;
} 