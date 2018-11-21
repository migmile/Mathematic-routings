#include <math.h>
#include <iostream>
using namespace std;

	// ���������� ������������� ��������� ������� ��������
    double Simpson( const double a,const double b,double (*f)(double x),const int N)
    {
       double xp,x,xn;
       double I=0;
       double h=(b-a)/N;
       xp=a;
       for (int i=1;i<N-1;i+=2)
       {
        x=xp+h;
        xn=x+h;
        I+= ( f(xp)+4.*f(x)+f(xn) );
        xp=x;
       }
      return I*h/3.;
    }

double Simpson1(double a, double b, double eps, double (*f)(double))
{

    double N = 4.;
    double sum1 = 0., sum2 = 0.;
    double x, h;
    double index1, index2;
    unsigned int i;
    double func;
    for(;;) {  // � �������� �� ������ ������������� ����� ��������� ������������ �� ����� ��������...
        h = (b-a)/N;
        sum1 = sum2 = -(f(a)+f(b));
        index1 = index2 = 4.;
        i = 0;
        for(x = a; x <= b+h/2.; x+=h) {
            sum1 +=  (index1 = 6.-index1)*(func=f(x));
            if (i++%2==0) {
                sum2 += (index2 = 6.-index2)*func;
            };
        };
        if (fabs((sum1-2.*sum2)/sum1)<=eps) return (h*sum1)/3.+h*(2.*sum2-sum1)/45.; else N*=2.;
    };
    return (h*sum1)/3.;
};

double fun(double x)
{
 return sin(x);
}

int main()
{
/* std::cout<<Simpson(0.,3.14159,fun,3)<<"\n";
 std::cout<<Simpson(0.,3.14159,fun,5)<<"\n"; 
 std::cout<<Simpson(0.,3.14159,fun,10)<<"\n"; 
 std::cout<<Simpson(0.,3.14159,fun,20)<<"\n"; 
 std::cout<<Simpson(0.,3.14159,fun,50)<<"\n"; 
 std::cout<<Simpson(0.,3.14159,fun,80)<<"\n"; 
 std::cout<<Simpson(0.,3.14159,fun,100)<<"\n"; 
*/
 std::cout<<Simpson(0.,3.14159,fun,800)<<"\n"; 
  std::cout<<Simpson1(0.,3.14159, 0.001, fun);
 return 0;
}