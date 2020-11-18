# Homework 1
This repo is the homework 1 by `ricohardus.cactus@hgroup-25` for the `VG101FA2020-1` course. This `README` file gives the explanations of the codes.

## Ex. 1
A `README` file shall give a description for a software or a program. Usually the function, the guide of installation, the list of all components and the author's information will be included. This file itself is an example for a `README` file.

## Ex. 2
**OJ score: `10/10`**

The value of `x'*y-w` ($x^T\cdot y-w$) is `0`. Here's the proof (for the sake of simplicity we denote $\sum:=\sum_{i=1}^4$):
$$
\begin{aligned}
&x^T\cdot y-w\\
=&x^T\cdot y-\sum z_i\\
=&x^T\cdot y-\sum x_iy_i\\
=&x^T\cdot y-x^T\cdot y\\
=&0
\end{aligned}
$$
Thus $x^T\cdot y-w=0$.

## Ex. 3
**OJ score: `10/10`**

There're $24\times60\times60=86400$ seconds per day.

## Ex. 4
**OJ score: `10/10`**

The **division with remainder** shall be used to calculate the remaining distance along with the laps. We calculate the quotient by take the integer part of the original quotient, and the remainder by the `mod(a,m)` function.

## Ex. 5
**OJ score: `10/10`**

Eratosthenes measured the length of shadows in Alexandria when the sunlight straightly casted on Syene. By assuming the sunlight is a made up of parallel rays, he measured the angle of arc between Syene and Alexandria with the angle of sunlight in Alexandria that time, which is about 7 degrees. He knew that the distance between these two cities is 5000 stades (length unit in the ancient Greece, a.k.a stadion/stadia, $1\,\text{km}\approx6.3\,\text{stades}$), thus he calculated that the length of an one-degree-arc on the surface of Earth is approx 700 stades. Therefore, he got that the circumference of Earth is approx 252,000 stades, or 40000km.

## Ex. 6
**OJ score: `10/10`**

The ratio between different units can be derived from the info in the PDF. `swtich-case` is used to implement different kinds of convertions.

## Ex. 7
The following functions are used to implement the reqiured calculations:

- `primes(n)` returns all the prime numbers less than or equal to `n`.
- `randi(imax,sz)` returns an array of uniformly distributed pseudorandom integers between `1` and `imax` where size vector `sz` defines `size(X)`.
- `prod(A)`  returns the product of the array elements of `A`.
