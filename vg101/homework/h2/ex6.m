% Generate the name of days
literals = [
    "Sunday"
    "Monday"
    "Tuesday"
    "Wednesday"
    "Thursday"
    "Friday"
    "Saturday"
];

args = input('');
Day = args(1);
Month = args(2);
Year = args(3);

% Revise the date to meet the Zeller standard
switch Month
    case {1,2}
        Month = Month+10;
        Year = Year-1;
    otherwise
        Month = Month-2;
end

% Initialize the parameters and calculate the formula
d = Day;
m = Month;
y = mod(Year,100);
c = (Year-y)/100;
day = 1+mod(d+floor((13*m-1)/5)+y+floor(y/4)+floor(c/4)-2*c,7);
disp(literals(day));
