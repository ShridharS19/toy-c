#include <stdio.h>
#include <stdlib.h>
typedef unsigned char* byte_ptr;

int bis(int x, int m) {     /* set bits in x that are 1 in m */
    return x | m;
}
int bic(int x, int m) {     /* clear bits in x that are 1 in m */
    return x & ~m;
}

void show_bytes(byte_ptr b, int len){
    for(int i = len; i> 0; i--){
        printf("%.2x",b[i-1]);
    }
    
    printf("\n");
}

int main(void){
    int x = 0xFFFFFFFFu;
    int y = 0x0000000u;
    int bis_ret = bis(y, 0xff);
    int bic_ret = bic(x , 0xff);
    show_bytes((byte_ptr) &bis_ret, sizeof((bis_ret)));
    show_bytes((byte_ptr) &bic_ret, sizeof((bic_ret)));
    return EXIT_SUCCESS;
}