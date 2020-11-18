global literals1;
global literals2;

literals1 = [
    "one"
    "two"
    "three"
    "four"
    "five"
    "six"
    "seven"
    "eight"
    "nine"
    "ten"
    "eleven"
    "twelve"
    "thirteen"
    "fourteen"
    "fifteen"
    "sixteen"
    "seventeen"
    "eighteen"
    "nineteen"
];

literals2 = [
    "ten"
    "twenty"
    "thirty"
    "fourty"
    "fifty"
    "sixty"
    "seventy"
    "eighty"
    "ninety"
];

n = input('');
words = int2words(n);
str = "";
for word = words
    str = str + " " + word;
end
disp(str);

function words = int2d2words(n)
%INT2D2WORDS transform a 2-digit integer to array of words
global literals1;
global literals2;
words = string.empty;
switch n
    case 0
        words = string.empty;
    case num2cell(1:19)
        words = [words literals1(n)];
    otherwise
        m = mod(n,10);
        n = (n-m)/10;
        words = [literals2(n) int2d2words(m)];
end
end

function words = int3d2words(n)
%INT3D2WORDS transform a 3-digit integer to array of words
global literals1;
m = mod(n,100);
n = (n-m)/100;
words = string.empty;
if n~=0
    words = [literals1(n) "hundred"];
end
if m~=0
    words = [words "and" int2d2words(m)];
end
end

function words = int9d2words(n)
%INT9D2WORDS transform a 9-digit integer to array of words
words = string.empty;
m = [0 0 0];
for i = 1:3
    m(i) = mod(n,1000);
    n = (n-m(i))/1000;
end
if m(3)~=0
    words = [words int3d2words(m(3)) "million"];
end
if m(2)~=0
    words = [words int3d2words(m(2)) "thousand"];
end
if m(1)~=0
    words = [words int3d2words(m(1))];
end
end

function words = int2words(n)
%INT2WORDS transform an integer to array of grammatically valid words
words = int9d2words(n);
if isempty(words)
    words = [words "zero"];
end
if words(1)=="and"
    words = words(2:end);
end
end
