# Project 1

[![GPLv3-or-Later](http://www.gnu.org/graphics/gplv3-or-later.svg)](http://www.gnu.org/licenses/gpl-3.0.html)

[TOC]

## Introduction

This is the Project 1 by Runze 'Richard' Xue (ID `520370910098`, a.k.a `ricohardus.cactus`) for the `VG101FA2020-1`. This project mainly features the simulation of the traffic on a crossroad, using the plot for graphic output.

## Using

`MATLAB 2018a` or later is required to execute this program.

Execute this program by running `main.m` and input the parameters according to the prompts. You can alter the amount of cars to be generated, duration of lights and the possibility of drivers to violate the traffic rule (namely, crossing through when the light is not green).

There are eight different colors and two different sizes of vehicles, which will be generated randomly.

Every vehicle will be assigned a unique plate ID. The IDs of those vehicles violating the traffic rule will be displayed after the program terminates.

## Algorithm

### Changing the color of lights

Upon receiving user's input, the program will generate a series of light status for each second. To ensure that the lights for two directions not being red or green at the same time, the lights on one direction will be set reversely. Here is the algorithm:

```reStructuredText
**algorithm** lightchange
**input**:
	the predefined status *s* of lights for the current second (red, green or orange)
**output**:
	(no output)

**switch** *s*
	**case** red
		set the color of one direction to red and the other to green
	**case** green
		set the color of one direction to green and the other to red
	**case** orange
		set the color of both directions to orange
update other animations and wait for another second
```

### Motion of vehicles

The class of `Car` defined in `Car.m` includes a variety of properties recording its different status of various aspects, on which the algorithm of motion of vehicles id based. Here is the algorithm:

```reStructuredText
**algorithm** motion
**input**:
	the vehicle *C* to be desided whether it shall move forward, along with its direction *D*
**output**:
	(no output)

**if** *C* is out of the crossroad
	do nothing
**elseif** *C* has passed through the lights
	move forward
**elseif** the light for *D* is green
	move forward
**elseif** the vehicle is to the front of the lights
	**if** the vehicle obeys the traffic rules
		stop
	**else**
		move forward
		record the plate ID of *C* as violaters
**elseif** the frontmost vehicle has stopped
	stop
**else**
	move forward
```

### Recursive permutation generation

To generate the plate ID, a recursive permutation generation algorithm is used. Here is the algorithm:

```reStructuredText
**algorithm** randperm
**input**:
	a set *S*
	length *l* of the permutation
**output:**
	a permutation

**if** l=0
	**return** empty
**else**
	*x* := randomly selected element from *S*
	**return** x+randperm(*S*-*x*,*l*-1)
```