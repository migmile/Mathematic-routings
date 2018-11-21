real function integral(a,b,f)
implicit none
real a,b,f,ff
external f
real x,dx
integer i 
integer:: n=10
integral=0
dx=(b-a)/n

x=a+dx/2.
do while(x<=b) 
    ff=f(x)
	integral=integral+ff
	x=x+dx
end do
integral=integral*dx
end