#include <cmath>
#include <iostream>
using namespace std;

	// вычисление определенного интеграла методом Симпсона
    double Simpson( const double a,const double b,double (*f)(double x),const int N)
    {
       double xp,x,xn;
       double I=0,I1=0;
       double h=(b-a)/N;
       x=a+h;
       for (int i=1;i<N;i+=2)
       {
		I1 += f(x);
		std::cout << x << " " << I1 << "\n";
		x += (h + h);
       }
	   I1 *= 4;
	   std::cout << "\n";
	   I = 0;
	   x = a + h+h;
	   for (int i = 1; i < N-1; i += 2)
	   {
		   I += f(x);
		   std::cout << x << " " << I << "\n";
		   x += (h + h);
	   }
	   I *= 2;

	   I = f(a) + f(b)+I+I1;
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
    for(;;) {  // В принципе на случай расходимостей лучше поставить ограничитель по числу итераций...
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
		if (fabs((sum1 - 2.*sum2) / sum1) <= eps) return (h*sum1) / 3. + h * (2.*sum2 - sum1) / 45.; else
		{
			std::cout << N << "   :" << sum1 << "  " << sum2 << "\n";
			N *= 2.;
		}
    };
    return (h*sum1)/3.;
};

double fun(double x)
{
	return x / (x*x*x*x + 4);// sin(x);
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
 std::cout<<Simpson(0.,5.,fun,10)<<"\n"; 
//  std::cout<<Simpson1(0.,3.14159, 0.001, fun);
 return 0;
}