function set = randpset(S, l, n)
%RANDPSET generate a random subset of permutations with given length and size
set = repmat([],n,1);
for i = 1:n
    while true
        perm = randp(S,l);
        flag = true;
        for j = 1:i-1
            if perm==set(j,:)
                flag = false;
                break;
            end
        end
        if flag
            set(i,:) = perm;
            break;
        end
    end
end
end