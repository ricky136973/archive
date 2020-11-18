classdef Lights
    %LIGHTS the set of traffic lights
    
    properties
        LightArray
    end
    
    methods
        function lights = Lights(rad, width)
            %LIGHTS initialize the lights with given data
            xsign = [+1 -1 -1 +1];
            ysign = [+1 +1 -1 -1];
            lights.LightArray = [
                rectangle
                rectangle
                rectangle
                rectangle
                ];
            for i = 1:4
                lights.LightArray(i).Position = [
                    xsign(i)*width-rad
                    ysign(i)*width-rad
                    2*rad
                    2*rad
                    ];
                lights.LightArray(i).FaceColor = 'y';
                lights.LightArray(i).EdgeColor = 'none';
                lights.LightArray(i).Curvature = [1 1];
            end
            drawnow;
        end
        
        function setcolor(lights, color)
            %SETCOLOR set the color of lights
            switch color
                case 'r'
                    colors = 'rgrg';
                case 'g'
                    colors = 'grgr';
                otherwise
                    colors = [color color color color];
            end
            for i = 1:4
                lights.LightArray(i).FaceColor = colors(i);
            end
            drawnow;
        end
    end
end
