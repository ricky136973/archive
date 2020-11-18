stade_per_deg=700; % The length of a one-degree-arc on Earth in stades
circ_stade=360*stade_per_deg; % The circumference of Earth in stades
circ_km=circ_stade/6.3; % The circumference of Earth in kilometers
rad_km=circ_km/(2*pi); % The radius of Earth in kilometers
disp(circ_km);
disp(rad_km);
