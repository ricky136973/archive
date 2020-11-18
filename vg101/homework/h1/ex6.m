lengths=input('');
command=input('','s');
switch command
    case 'stones to pounds'
        ratio=14;
    case 'pounds to kg'
        ratio=6.35/14;
    case 'kg to stones'
        ratio=1/6.35;
    otherwise
        warning('Unexpected command.');
end
disp(lengths*ratio);
