#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define length 1000
double* generate_random_double_array(int n) {
    double* arr = malloc(n * sizeof(double));
    if (arr == NULL) {
        return NULL; // Memory allocation failed
    }

    srand((unsigned int)time(NULL)); // Seed random number generator

    for (int i = 0; i < n; i++) {
        arr[i] = (double)rand() / RAND_MAX; // Random double in [0, 1]
    }

    return arr;
}

void printarr(double *a, int n){
    for (int i = 0; i<n; i++) {
        printf("%f ",a[i]);
    }
    
    printf(" \n");
}

int isSorted(double *a, int n){

    for(int i = 0; i<n-1; i++){
        if(a[i]>a[i+1]){
            return 0;
        }
    }
    return 1;
}

double* merge_sort_helper(double *a, int n, double* b)
{   
    if(n<=1)
    {
        return a;
    }
    int mid = n/2;
    double *left = merge_sort_helper(a, mid,b);
    double *right = merge_sort_helper(a + mid, n - mid,b);
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
        else if(k == n-mid){
            b[i] = left[j];
            j++;
        }
        else if(j==mid){
            b[i] = right[k];
            k++;
        }
    }
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
    double* p = generate_random_double_array(length);
    printarr(&p[0], 10);
    merge_sort(&p[0], length);
    printarr(&p[0], 10);
    if(isSorted(&p[0], length)){
        printf("sorted!");
    }
    free(p);
    return EXIT_SUCCESS;
}