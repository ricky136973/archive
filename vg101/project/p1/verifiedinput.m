function result = verifiedinput(prompt, f)
%VERIFIEDINPUT prompt for input until verified by f
while true
    try
        str = input(prompt,'s');
        args = sscanf(str,'%d');
        x = args(1);
        if ~f(x)
            error('invalid');
        end
    catch E
        disp('Invalid input.');
        continue;
    end
    break;
end
result = x;
end