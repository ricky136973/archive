% Step 1
x=[3;2;6;8];
y=[4;1;3;5];
disp(x);
disp(y);
% Step 2
y=[y;sum(x)];
disp(x);
disp(y);
x=[3;2;6;8];
y=[4;1;3;5];
% Step 3
x=x.^y;
disp(x);
disp(y);
x=[3;2;6;8];
y=[4;1;3;5];
% Step 4
y=y./x;
disp(y);
disp(x);
x=[3;2;6;8];
y=[4;1;3;5];
% Step 5
z=x.*y;
disp(x);
disp(y);
disp(z);
% Step 6
w=sum(z);
disp(z);
disp(w);
% Step 7
disp(x);
disp(y);
disp(w);
disp(x'*y-w);
clearvars;
