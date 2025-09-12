#include <stdio.h>
  /* copy input to output; 1st version */
   main()
    {  
        int c;
        int prev = 0; 
         while ((c=getchar()) != EOF) 
         { 
            if(prev==0 || (c != ' ' && c != '\t')){
               putchar(c);
            }
            if( c == ' ' || c == '\t'){
               prev = 1;
            }else{
               prev = 0;
            }
         } 
    }