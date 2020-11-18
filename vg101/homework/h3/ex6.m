fileID = fopen('ex6.txt','w');
n = input('');
P = rot90(pascal(n));
l = length(num2str(P(ceil(n/2),ceil(n/2))));
l = l+1-mod(l,2);
format = " %"+sprintf('%d',l)+"d";
for k = 1-n:0
    fprintf(fileID,repmat(' ',1,-k*((l+1)/2)));
    for p = diag(P,k)
        fprintf(fileID,format,p);
    end
    fprintf(fileID,'\n');
end
fclose('all');
