# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

[TOC]

## [m3] - 2020-10-13

### Added

- New features allowing cars to move or stop under different circumstances.
- Introduce two different size of cars and randomly generate them.
- Allow users to set the possibility for a car to violate the traffic rules.
- Collision handling implemented.
- Extra functions to generate random permutations.
-  Document a `README` file to illustrating the usage and the algorithms.

### Changed

- The plate ID for a car is now generated using random permutations.

### Removed

- All `global` variables are replaced for the sake of better code quality.

## [m2] - 2020-10-06

### Added

- New class `Car.m` for implementing cars.
- Prototype animation of moving cars.

### Changed

- Changed main loop into a frame-wise loop.

### Removed

- Removed some unused input prompt and partially replaced with predefined values.

## [m1] - 2020-10-01
### Added

- Crossroad and traffic light.
- Essential input queries. (Not all inputs will be used currently.)