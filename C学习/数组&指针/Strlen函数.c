#include<stdio.h>
#include<string.h>

//���鷽��
/*int mylen(const char *s){
    int count=0;
    while(s[count]!='\0'){
        count++;
    }
    return count;
}*/

//ָ�뷽��
int mylen(const char *s){
    int count=0;
    while(*s){
        *s++;
        count++;
    }
    return count;
}

int main(){
    char line[]="Hello";
    printf("strlen=%d\n",mylen(line));
    printf("sizeof=%d\n",sizeof(line));
    return 0;
}