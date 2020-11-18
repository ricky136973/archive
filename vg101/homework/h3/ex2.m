axis equal;
ax = gca;

drawHouse(ax,[0 0],1);
drawCar(ax,[1.25 0],0.3);
drawnow;

function drawHouse(ax, pos, size)
%DRAWHOUSE draw a house
points = size*[
    0.0000 0.6180
    1.0000 0.6180
    1.0000 0.0000
    0.0000 0.0000
    0.0000 0.6180
    0.5000 0.9119
    1.0000 0.6180
    ];
X = pos(1)+points(:,1);
Y = pos(2)+points(:,2);
line(ax,X,Y);
end

function drawCar(ax, pos, size)
%DRAWCAR draw a car
rectangle(ax,'Position',[pos size*[2 1]],'FaceColor','r');
end
