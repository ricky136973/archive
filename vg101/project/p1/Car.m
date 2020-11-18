classdef Car
    %CAR a car
    
    properties (Constant)
        Charset = ['A':'Z' '0':'9'];
        Colorset = 'rgbcmy';
    end
    
    properties
        ID
        Width
        Length
        Direction
        Body
        Vector
        Lawful
        Passthrough
        Passby
        Offroad
    end
    
    methods (Static)
        function ID = generateID()
            persistent IDpool;
            if isempty(IDpool)
                IDpool = randpset(1:36,5,60);
            end
            ID = "";
            ID = ID+char(Car.Charset(randi(26)));
            ID = ID+"-";
            ID = ID+Car.Charset(IDpool(1,:));
            IDpool = IDpool(2:end,:);
        end
    end
    
    methods
        function car = Car(entry, direction, width, length, lawful)
            %CAR construct a new car
            
            car.ID = Car.generateID;
            car.Width = width;
            car.Length = length;
            car.Direction = direction;
            car.Lawful = lawful;
            car.Passthrough = false;
            car.Passby = false;
            car.Offroad = false;
            
            switch direction
                case 'E'
                    offset = [-car.Length -car.Width/2];
                    span = [car.Length car.Width];
                case 'S'
                    offset = [-car.Width/2 0];
                    span = [car.Width car.Length];
                case 'W'
                    offset = [0 -car.Width/2];
                    span = [car.Length car.Width];
                case 'N'
                    offset = [-car.Width/2 -car.Length];
                    span = [car.Width car.Length];
                otherwise
                    error('unrecognized direction');
            end
            
            car.Body = rectangle;
            car.Body.Position = [entry+offset span];
            car.Body.FaceColor = Car.Colorset(randi(6));
        end
        
        function value = get.Vector(car)
            switch car.Direction
                case 'E'
                    value = [+1 0];
                case 'S'
                    value = [0 -1];
                case 'W'
                    value = [-1 0];
                case 'N'
                    value = [0 +1];
                otherwise
                    error('unrecognized direction');
            end
        end
        
        function move(car,rate)
            %MOVE move the car in given rate
            car.Body.Position = car.Body.Position + [rate*car.Vector 0 0];
        end
    end
end

