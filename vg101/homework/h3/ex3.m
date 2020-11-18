items = [
    Item("Jumpers",  "Blue",   2, [04 2005])
    Item("Jumpers",  "Brown",  3, [02 2013])
    Item("Jumpers",  "Green",  5, [01 2015])
    
    Item("Trousers", "Black",  3, [06 2012])
    Item("Trousers", "Grey",   2, [04 2011])
    Item("Trousers", "White",  1, [12 2013])
    
    Item("T-shirts", "Blue",   1, [05 2010])
    Item("T-shirts", "Green",  2, [09 2014])
    Item("T-shirts", "Red",    3, [01 2012])
    Item("T-shirts", "White",  2, [03 2008])
    Item("T-shirts", "Yellow", 1, [11 2012])
    ];

quantity = 0;
month = 0;

[~,i] = max([items.Quantity]);
str = items(i).Type+" "+items(i).Color;
age = 2020-floor(mean([items.Bought]));

disp(str);
disp(age);

function item = Item(type, color, quantity, bought)
%ITEM class-like constructor for item
item.Type     = type;
item.Color    = color;
item.Quantity = quantity;
item.Bought   = bought(1)/12+bought(2);
end
