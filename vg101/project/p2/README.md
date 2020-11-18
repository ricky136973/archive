# OneCard

[![GPLv3-or-Later](http://www.gnu.org/graphics/gplv3-or-later.svg)](http://www.gnu.org/licenses/gpl-3.0.html)

[TOC]

## Introduction

This is the Project 2 by Richard Runze Xue (ID `520370910098`, a.k.a `ricohardus.cactus`) for the `VG101FA2020-1`. This project mainly features a card game named 'OneCard', based on the widely played card game 'Uno'.

## Build

`gcc` and `make` are required to build this project. In the root directory of the project execute the following commands:

```shell
make
./onecard
```

## Usage

```
-h|--help                print this help message\n"	
--log filename           write the logs in filename (default: onecard.log)\n"
-n n|--player-number=n   n players, n must be larger than 2 (default: 4)\n"
-c c|--initial-cards=c   deal c cards per player, c must be at least 2 (default: 5)\n"
-d d|--decks=d           use d decks 52 cards each, d must be at least 2 (default: 2)\n"
-r r|--rounds=r          play r rounds, r must be at least 1 (default: 1)\n"
-a|--auto                run in demo mode\n";
```

## Special Rules

This version of OneCard allows player to play multiple identical cards at one move. However, for the functional cards their effects will not be accumulated, id est, they only work as a single functional card when played.



