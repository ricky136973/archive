length=input('');
lap=floor(length/400);
disp(lap);
rem=mod(length,400);
if rem~=0
    disp(400-rem);
end
