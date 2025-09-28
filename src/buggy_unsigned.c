/* WARNING: This is buggy code */
float sum_elements(float a[], unsigned length)
{
    int i;
    float result = 0;
    for (i = 0; i <= (int)length-1; i++)
    {
        result += a[i];
    }
    
    return result;
}

int main(void){
    float a[] = {0.0,.0};
    sum_elements(a,0);
    return 1;
}