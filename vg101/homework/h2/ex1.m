% Loop until valid year recieved
while true
    try
        str = input('Please input a year (A.D.):','s');
        args = sscanf(str,'%d');
        n = args(1);
        if n<0
            error('invalid year');
        end
    catch E
        disp('Please input a valid year.');
        continue;
    end
    break;
end

% Caculate if it is leap
if mod(n,4)~=0
    flag = false;
elseif mod(n,100)~=0
    flag = true;
elseif mod(n,400)~=0
    flag = false;
else
    flag = true;
end

% Output
if flag
    disp('This is a leap year.');
else
    disp('This is not a leap year.');
end
