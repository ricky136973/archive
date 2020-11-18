fps = 12;
spf = 1/fps;

% Prompt for input
n = verifiedinput('Input the number of cars [1-60]: ',...
    @(x) x>=1 && x<=60);
w = 2;
p = verifiedinput('Input the posibility (%) of cars violating traffic rules [0-100]: ',...
    @(x) x>=0 && x<=100)/100;
g = verifiedinput('Input the duration (sec) of the green light [1-60]: ',...
    @(x) x>=1 && x<=60);
o = verifiedinput('Input the duration (sec) of the orange light [1-60]: ',...
    @(x) x>=1 && x<=60);
r = verifiedinput('Input the duration (sec) of the red light [1-60]: ',...
    @(x) x>=1 && x<=60);

ax = gca;
range = 12;
width = w;
center = [-w -w 2*w 2*w];

cycle = [repmat('g',1,g) repmat('y',1,o) repmat('r',1,r) repmat('y',1,o)];

% Draw the background
axis equal;
axis([-range +range -range +range],'off');
canvas = rectangle(...
    'Position',[-range -range 2*range 2*range],...
    'FaceColor','w',...
    'EdgeColor','none'...
    );

% Draw the side lines
line([+width +range],[+width +width],'Color','k','LineWidth',1);
line([+width +width],[+width +range],'Color','k','LineWidth',1);
line([-width -width],[+width +range],'Color','k','LineWidth',1);
line([-width -range],[+width +width],'Color','k','LineWidth',1);
line([-width -range],[-width -width],'Color','k','LineWidth',1);
line([-width -width],[-width -range],'Color','k','LineWidth',1);
line([+width +width],[-width -range],'Color','k','LineWidth',1);
line([+width +range],[-width -width],'Color','k','LineWidth',1);

% Draw the central lines
line([+width +range],[0 0],'Color','#aaa','LineStyle','--');
line([0 0],[+width +range],'Color','#aaa','LineStyle','--');
line([-width -range],[0 0],'Color','#aaa','LineStyle','--');
line([0 0],[-width -range],'Color','#aaa','LineStyle','--');

% Initialize the set of lights
drawnow;
lights = Lights(0.5,width);

entries = [
    +range +0.5*width;
    -0.5*width +range;
    -range -0.5*width;
    +0.5*width -range;
    ];
directions = 'WSEN';

% Main loop
loop = 0;
running = [true true true true];
cars = [];
rioters = [];
try
    m = n;
    while m>0
        for c = cycle
            lights.setcolor(c);
            switch c
                case 'g'
                    passX = true;
                    passY = false;
                case 'r'
                    passX = false;
                    passY = true;
                otherwise
                    passX = false;
                    passY = false;
            end
            if loop==0 && n~=0
                d = randi(4);
                if running(d)
                    cars = [cars Car(entries(d,:),directions(d),1,2+0.5*randi(2),rand>=p)];
                    n = n-1;
                end
            end
            for f = 1:fps
                for i = 1:length(cars)
                    if cars(i).Offroad
                        continue;
                    end
                    cars(i).Passthrough = collide(cars(i).Body.Position,center);
                    if cars(i).Passby
                        cars(i).move(spf);
                        cars(i).Offroad = ~collide(cars(i).Body.Position,canvas.Position);
                        if cars(i).Offroad
                            m = m-1;
                        end
                        continue;
                    end
                    switch cars(i).Direction
                        case 'W'
                            d = 1;
                        case 'S'
                            d = 2;
                        case 'E'
                            d = 3;
                        case 'N'
                            d = 4;
                    end
                    if cars(i).Passthrough
                        switch cars(i).Direction
                            case {'E','W'}
                                pass = passX;
                            case {'N','S'}
                                pass = passY;
                        end
                        if pass
                            running(d) = true;
                            cars(i).Passby = true;
                            cars(i).move(spf);
                        elseif ~cars(i).Lawful
                            running(d) = true;
                            cars(i).Passby = true;
                            cars(i).move(spf);
                            rioters = [rioters cars(i).ID];
                        else
                            running(d) = false;
                        end
                    elseif running(d)
                        cars(i).move(spf);
                    end
                end
                for i = 1:length(cars)
                    if ~cars(i).Passthrough
                        continue
                    end
                    for j = i+1:length(cars)
                        if ~cars(j).Passthrough
                            continue
                        end
                        if collide(cars(i).Body.Position,cars(j).Body.Position)
                            error('collide');
                        end
                    end
                end
                pause(spf);
            end
            loop = mod(loop+1,4);
        end
    end
    disp('All cars passed safely.');
catch E
    if E.message=="collide"
        disp('Car crash occured.');
    else
        disp('Program terminated.');
    end
end
disp('The following vehical(s) have violated traffic rules:');
for r = rioters
    disp(r);
end