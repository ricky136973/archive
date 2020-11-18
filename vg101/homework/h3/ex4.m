fileID = fopen('ex4.txt','w');
n = input('');
for i = 0:10
    fprintf(fileID,'%d x %d = %d\n',n,i,n*i);
end
fclose('all');
