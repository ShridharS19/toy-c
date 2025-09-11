 #include <stdio.h>

 #define LOWER 0
 #define UPPER 300
 #define  STEP 20
 /* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300; floating-point version */
main(){
    float fahr, celsius;
    printf("FAHRENHEIT CELSIUS\n");
    for(fahr = UPPER; fahr >=LOWER ; fahr-=STEP){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf(" %5.0f %10.2f\n", fahr, celsius);
    }
}