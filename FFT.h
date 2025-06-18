#ifndef FFT
#define FFT

#include<stdlib.h>
#define M_PI 3.14159265358979323846
typedef struct 
{
   double real;
   double imag;
} Complex;

Complex addcomplex(Complex num1 , Complex num2)
{
    Complex result;
    result.real= num1.real + num2.real ;
    result.imag =num1.imag + num2.imag ;
    return result;
}

Complex mulitply( Complex num1 , Complex num2)
{
    Complex result;
    result.real= num1.real * num2.real - num1.imag * num2.imag;
    result.imag =num1.imag + num2.real + num1.real*num2.imag ;
    return result;
}
Complex neg(Complex num)
{
    return (Complex){num.real,num.imag};
}
Complex* fft(Complex* input, int n);


#endif