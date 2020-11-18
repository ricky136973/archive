global eps;

f = input('');
x = input('');
precision = input('');
eps = 1/10^(precision+1);

% Calculate the root by the secant method
r = secant_iterative(f,x(1),x(2));

% Round to given precision
r = round(r*10^precision)/10^precision;

format longg;
disp(r);

function r = secant_iterative(f,x1,x2)
%SECANT_ITERATIVE secant method (iterative)
global eps;
x = [x1 x2];
n = 2;
while abs(x(n)-x(n-1))>=eps
    n = n+1;
    x(n) = (x(n-2)*f(x(n-1))-x(n-1)*f(x(n-2)))/(f(x(n-1))-f(x(n-2)));
end
r = x(n);
end

function r = secant_recursive(f,x1,x2)
%SECANT_RECURSIVE secant method (recursive)
global eps;
x3 = (x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
if abs(x3-x2)<eps
    r = x3;
else
    r = secant_recursive(f,x2,x3);
end
end