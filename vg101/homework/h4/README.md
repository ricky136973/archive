# Homework 4

This repo is the homework 4 by `ricohardus.cactus@hgroup-25` for the `VG101FA2020-1` course. This `README` file gives the explanations of the codes.

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

**OJ score: `100/100`**

This code also compiles if `<complex.h>` is not supported, under which circumstance a customized `complex_t` structure will be implemented instead.

### Run

```shell
./main -ex1
```



## Ex. 2

**OJ score: `100/100`**

The code uses the Euclidean method to calculate the greatest common divisor, which is based on the following fact:
$$
(a,b)=(\lfloor\frac{a}{b}\rfloor b+a\operatorname{mod}b,b)=(a\operatorname{mod}b,b)=(b,a\operatorname{mod}b)
$$
Here is the algorithm:

```reStructuredText
**algorithm** greatest common divisor (gcd)
**input**:
	two natural numbers *a* and *b* that are not both equal to 0
**output**:
	the greatest common divisor of *a* and *b*

**if** *b* = 0
	**return** *a*
**else**
	**return** gcd(*b*, *a* mod *b*)
```

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

The question 3 supports the following data types:

```c
_Bool

char
signed char
unsigned char

short int
unsigned short int
int
unsigned int
long int
unsigned long int
long long int
unsigned long long int

float
double
long double

#ifndef __STDC_NO_COMPLEX__
float _Complex
double _Complex
long double _Complex
#endif //__STDC_NO_COMPLEX__

#if defined __STDC_IEC_559_COMPLEX__ && defined _Imaginary_I
float _Imaginary
double _Imaginary
long double _Imaginary
#endif // defined __STDC_IEC_559_COMPLEX__ && defined _Imaginary_I

void*
```

Notice that the size of the types varies on different architectures and systems. The code uses `sizeof` to adapt to different situations.

### Run

```shell
./main -ex4
```

## Ex. 5

**OJ score: `100/100`**

In function `long int mpow(int a, int b)`, it is required that `a >= 0`.  The range of the return value is within `0` and `LONG_MAX` (defined in `<limits.h>`, may be `2147483647` or `9223372036854775807` on different platforms).

### Run

```shell
./main -ex5
```
