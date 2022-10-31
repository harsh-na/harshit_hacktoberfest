#include <iostream>
using namespace std;
  
class Complex {
    public:
        int real, imaginary;

    Complex(int r = 0, int i = 0)
    {
        real = r;
        imaginary =i;
    }
    
    Complex add(Complex C1, Complex C2)
    {
        Complex obj;
        obj.real = C1.real + C2.real;
        obj.imaginary = C1.imaginary + C2.imaginary;
        return obj;
    }
    
    Complex  multi(Complex C1,Complex C2)
    { 
    Complex obj;
    obj.real=C1.real*C2.real - C1.imaginary*C2.imaginary;
    obj.imaginary=C1.real*C2.imaginary + C2.real*C1.imaginary;
    return obj;
    }
};
    
  
int main()
{
    Complex c;
    cout<<"Default Complex number:"<<c.real<<" + "<<c.imaginary<<" i "<<endl;
    
    Complex C1(3, 2);
    cout<<"Complex number 1 : "<< C1.real
                << " + "<< C1.imaginary<<" i "<<endl;
 
    Complex C2(9, 5);
    cout<<"Complex number 2 : "<< C2.real
                << " + "<< C2.imaginary<<" i "<<endl;
    Complex C3;
    C3 = C3.add(C1, C2);
    cout<<"Sum of complex number : "
                       << C3.real << " + "
                       << C3.imaginary<<" i "<<endl;
    Complex C4;
    C4=C4.multi(C1,C2);
    cout<<"Multiplication of complex number : "
                       << C4.real << " + "
                       << C4.imaginary<<" i "<<endl;
                       
}