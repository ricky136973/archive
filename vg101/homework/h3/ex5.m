format longG;

f = input('');
I = input('');
a = I(1);
b = I(2);
r = bisection(f,a,b);

disp(round(r,3));

function r = bisection(f, a, b)
%BISECTION find the root within given interval by bisection
c = (a+b)/2;
if f(c)==0
    r = c;
elseif f(a)*f(c)<0
    r = bisection(f,a,c);
else
    r = bisection(f,c,b);
end
end
