function perm = randp(S, l)
%RANDP generate a random permutation with given length
if l<=0
    perm = [];
    return;
end
i = randi(length(S));
perm = [S(i) randp(setdiff(S,S(i)),l-1)];
end