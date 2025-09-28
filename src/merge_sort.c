#include <stdlib.h>
#include <stdio.h>

void printarr(double *a, int n){
    for (int i =0; i<n; i++) {
        printf("%f ",a[i]);
    }
    
    printf(" \n");
}

double* merge_sort_helper(double *a, int n, double* b)
{   
    printf("n %d \n",n);
    if(n<=1)
    {
        return a;
    }
    int mid = n/2;
    printf("mid and n-mid %d %d  \n",mid,n-mid);
    double *left = merge_sort_helper(a, mid,b);
    double *right = merge_sort_helper(a + mid, n - mid,b);
    //printf("%f", (a+4)[0]);
    printf("left array \n");
    printarr(left,mid);
    
    printf("right array \n");
    printarr(right,n-mid);
    int j = 0;
    int k = 0;
    for(int i = 0; i<n;i++)
    {
        if( (k<n-mid) && (left[j]>=right[k]))
        {
            b[i] = right[k];
            k++;
        }
        else if(j<mid && (left[j]<right[k]))
        {
            b[i] = left[j];
            j++;
        }
    }
    printf("merged \n");
    printarr(b,n);
    for(int i = 0; i<n;i++)
    {
        left[i] = b[i];
    }
    return(left);
}
double* merge_sort(double *a, int n)
{
    double *aux = malloc(n * sizeof(double));
    if (!aux) { perror("malloc"); exit(EXIT_FAILURE); }
    double* ret = merge_sort_helper(a,n, aux);
    free(aux);
    return (ret);
    
}
int main(void)
{
    double p[] = {3.14,2.5,5.77,1.618,2.71828};
    merge_sort(&p[0], 5);
    printarr(&p[0], 5);
    return EXIT_SUCCESS;
}