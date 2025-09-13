#include <stdio.h>
#define MASK 0xFFu
typedef char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = len-1; i >=0; i--)
    {
        printf(" %02x", (unsigned char) start[i]);
    }
    printf("\n");
}
int mask1(int var){
    return(var|~MASK);
}
int mask2(int var){
    return(var^MASK);
}
int mask3(int var){
    return(var&~MASK);
}
int main(void){
    int test = 0x98FDECBA;
    int test1 = mask1(test);
    show_bytes((byte_pointer) &test1, sizeof(test));
    int test2 = mask2(test);
    show_bytes((byte_pointer) &test2, sizeof(test));
    int test3 = mask3(test);
    show_bytes((byte_pointer) &test3, sizeof(test));
    return 0;
}