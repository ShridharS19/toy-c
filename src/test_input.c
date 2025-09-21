#include <stdio.h>
#include <stdlib.h>
typedef unsigned char* byte_ptr;
void show_bytes(byte_ptr b, int len){
    for (int i = len; i>0; i--) {
        printf("%.2x",b[i-1]);
    }
    printf("\n");
}
int bitwise_equals(int a, int b){
    return (!(a^b));
}
int main(int argc, char *argv[])
{    
    if (argc < 3) {
        printf("Usage: %s num1 num2\n", argv[0]);
        return 1; // exit with error
    }

    int a = atoi(argv[1]);  // convert string to int
    int b = atoi(argv[2]);
    printf("%d", bitwise_equals(a,b));
    return EXIT_SUCCESS;
}