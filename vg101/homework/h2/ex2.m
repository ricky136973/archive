% Initialize a list of Pythagorean primes
MAX_N = 100;
P = primes(MAX_N);
Pyth = P(mod(P,4)==1);

x = input('');

% Find p
for p = Pyth
    if p > x
        break;
    end
end

% Find a and b
a = 1;
b = sqrt(p-a);
while b~=floor(b)
    a = a+1;
    b = sqrt(p-a^2);
end

fprintf('%d = %d^2 + %d^2\n',p,a,b);