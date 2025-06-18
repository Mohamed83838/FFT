#include<stdlib.h>
#include "include/FFT.h"
#include <math.h>
#include<stdio.h>
Complex* fft(Complex* input ,int n)
{
    Complex* output = malloc(n * sizeof(Complex));
    Complex numb;
    if (!output) 
    {
        printf("An error Occured while Allocating Mmeory");
        exit(1);
    }

    if (n==1)
    {
        output[0]=input[0];
        return output;
    }
    
    
    Complex p0[n/2];
    Complex p1[n/2];
    
  for (int i = 0; i < n / 2; i++) {
    p0[i] = input[2 * i];
    p1[i] = input[2 * i + 1];
}
    
    Complex* res0 = fft(p0,n/2);
    Complex* res1 = fft(p1,n/2);

    for (int i = 0; i < n/2; i++)
    {
        numb= (Complex){cos(((2*M_PI)*i)/n),sin(((2*M_PI)*i)/n)};
        output[i] = addcomplex(res0[i],mulitply(numb,res1[i])) ;       
        output[i+n/2] = addcomplex(res0[i],neg(mulitply(numb,res1[i]))) ;  
    }
    free (res0);
    free(res1);
    return output;
    

}

int main()
{
    Complex input[]={{5,0},{3,0},{1,0},{6,0}};
    Complex* result = fft(input,4);
 
 for (int i = 0; i < 4; i++) {
    printf("result[%d] = %f + %fi\n", i, result[i].real, result[i].imag);
}
free(result);
    return 0;
}