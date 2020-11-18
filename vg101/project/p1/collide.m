function flag = collide(pos1, pos2)
%COLLIDE test two rectangles on a plane if they collide
X1 = [pos1(1) pos1(1)+pos1(3)];
Y1 = [pos1(2) pos1(2)+pos1(4)];
X2 = [pos2(1) pos2(1)+pos2(3)];
Y2 = [pos2(2) pos2(2)+pos2(4)];
flag = lap(X1,X2) && lap(Y1,Y2);
end

function flag = lap(pos1, pos2)
%LAP test two segments on an axis if they lap
flag = pos1(1)<=pos2(2) && pos1(2)>=pos2(1);
end