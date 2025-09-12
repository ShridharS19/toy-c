#include <stdio.h>
main(){
    int c;
    int charSet[256];
    for(int i =0;i<256;i++){
        charSet[i]=0;
    }
    while((c = getchar())!='\n'){
        charSet[c]++;
    }
    for(int i =0;i<256;i++){
        if(charSet[i]!=0){
            printf("%c \t", i);
        }
        for(int j =0; j<charSet[i];j++){
            printf("|");
        }
        if(charSet[i]!=0){
            printf("\n");
        }
    }
}