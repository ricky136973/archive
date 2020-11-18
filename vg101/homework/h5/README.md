# Homework 5

This repo is the homework 5 by `ricohardus.cactus@hgroup-25` for the `VG101FA2020-1` course. This `README` file gives the explanations of the codes.

## Build

### Make

```shell
gcc -std=c99 -o main *.c -lm
```

### Run

```shell
./main
```

## Ex. 1

**OJ score: `150/150`**

### Run

```shell
./main -ex1
```

## Ex. 2

**OJ score: `120/120`**

### Run

```shell
./main -ex2
```

## Ex. 3

**OJ score: `100/100`**

### Run

```shell
./main -ex3
```

## Ex. 4

**OJ score: `100/100`**

### Run

```shell
./main -ex4
```

## Ex. 5

### Run

```shell
./main -ex5
```

## Ex. 6

### Divide and Conquer

The "Divide and Conquer" strategy is to divide a problem into multiple sub-problems and solve them respectively.

### Karatsuba Algorithm

For two non-negative integers $a$ and $b$, with digits of $M$ and $N$ respectively, let
$$
a=2^mx_1+x_0\quad b=2^ny_1+y_0
$$
then problem of multiplying two numbers is divided into four sub-problems of multiplying smaller numbers recursively, which is
$$
ab=2^{m+n}x_1y_1+2^mx_1y_0+2^nx_0y_1+x_0y_0
$$
In the algorithm provided, $m=M-1$ and $n=N-1$, so the time complexity is $O(\max\{M,N\})$. Karatsuba algorithm optimizes this process by assigning
$$
m=\left\lfloor\frac{M}{2}\right\rfloor\quad n=\left\lfloor\frac{N}{2}\right\rfloor
$$
The time complexity is thus reduced to $O(\log\max\{M,N\})$.

### Run

```shell
./main -ex6
```

