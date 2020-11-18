# Homework 3

This repo is the homework 3 by `ricohardus.cactus@hgroup-25` for the `VG101FA2020-1` course. This `README` file gives the explanations of the codes.

## Ex. 1

**OJ score: `10/10`**

To optimize the algorithm the summation formula of geometric series is used:
$$
\sum_{k=0}^{n-1}q^k=\frac{q^n-1}{q-1}
$$
In this case we have $q=2$ and $n=64$ for 64 squares on a chessboard. Thus the answer is $2^{64}-1$ or $18446744073709551615$.

## Ex. 2

The car illustrated is exactly the one appeared in *Project 1*.

## Ex. 3

**OJ score: `100/100`**

The dataset of items is stored as a structure array. Fields include `Type`, `Color`, `Quantity` and `Bought`.

## Ex. 4

The output will be dumped into `ex4.txt`.

## Ex. 5

**OJ score: `100/100`**

Algorithm.  *(Bisection Method)*

------

**Input:**

- $f$: The function $f(x)$ to be solved in given interval,
- $a$: The lower bound of the interval,
- $b$: The upper bound of the interval

**Output:**

- The root $r\in(a,b)$ that $f(r)=0$

------

1. $c\leftarrow \frac{a+b}{2}$
2. **if** $f(c)=0$ **then** $r\leftarrow c$
3. **if** $f(a)f(c)<0$ **then** $r\leftarrow$ *bisection* with $b\leftarrow c$
4. **otherwise** $r\leftarrow$ *bisection* with $a\leftarrow c$
5. **return** $r$

------

## Ex. 6

The output will be dumped into `ex6.txt`.