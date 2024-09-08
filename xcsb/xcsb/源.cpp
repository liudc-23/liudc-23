#include<stdio.h>
int main(){
    float n=0;
    scanf("%f",&n);
    for(int i=0;i<n;i++){
        int k=(10-i);
        for(int j=0;j<k;j++){
            printf(" ");
        }
        for(int j=0;j<2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }
}