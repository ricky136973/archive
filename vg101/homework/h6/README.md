# Homework 6

This repo is the homework 6 by `ricohardus.cactus@hgroup-25` for the `VG101FA2020-1` course. This `README` file gives the explanations of the codes.

## Build

### Make

```shell
gcc -std=c11 -o main *.c -lm
```

### Run

```shell
./main
```

## Ex. 1

### Run

```shell
./main -ex1
```

## Ex. 2

**OJ score: `100/100`**

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

**OJ score: `100/100`**

Include `universal_set.h` in your code to use this library.

## Ex. 6

**OJ score: `100/100`**

### Run

```shell
./main -ex6
```

## Ex. 7

**OJ score: `100/100`**

Include `linked_list.h` in your code to use this library.

### Run

```shell
./main -ex7
```

### About the linked list

A linked list is a data structure consisting nodes that are linked in a linear (or circular under some circumstances) order.

#### Different types of linked list

##### Singly linked linear list

Where each node links to the next node except that the last node links to a terminator (usually `NULL` in implements).

##### Doubly linked linear list

Where each node links to the previous and the next nodes except that the first and the last nodes link to terminators for respectively the previous and the next nodes.

##### Circularly linked list

Almost identical to the linearly linked list, except for that the first and the last nodes link to each other to form a circle.

##### Skip list

A linearly linked list where each node does not only link to the next node, but link to one or more nodes further as well. The distances of these links may vary and can be set randomly, which makes the skip list a probabilistic data structure.

#### Common usages of linked list

##### Adapting to other data structures

A linked list can be adapted as a stack, (double-ended) queue, heap and hash table. Furthermore, the skip list can be used as an alternative for the balanced tree.

##### Appearance in algorithms

By tree-link decomposition algorithms (including weight decomposition and length decomposition) trees can be decomposed into several linked lists, which is useful in many situations (for example, finding the least common ancestor of two or more nodes).

An algorithm named "Algorithm X", proposed by Donald Knuth, for solving exact covering problems, involves a technique called "dancing links", which is to undo the node deletion in a doubly linked circular list.

##### Other usages

Block-chain, which is widely used in cryptocurrencies,  is a special decentralized linked list.

Multiple database systems have adopted the skip list as a linked data structure.

Linked list has also played a pivotal role in symbolic process. A symbolic expression can be stored as a nested linked list (i.e., linked lists as the data for other linked lists). The famous functional programming language Lisp processes symbolic expressions in this way.

