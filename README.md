# push_swap

push_swap is an individual 42 school algorithm project where we have to sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.

## Status

* Success
* Grade: 84/100

## Rules

We have two stacks named **a** ans **b**. At the beginning, **a** contains a random number of positive or negative numbers without any duplicate and **b** is empty. The goal is to sort in ascending order numbers into stack **a**.

We have to use the following operations:
* ```sa``` : swap **a** - Swap the first two elements at the top of stack **a**. Do nothing if there is only one or no elements.
* ```sb``` : swap **b** - Swap the first two elements at the top of stack **b**. Do nothing if there is only one or no elements.
* ```ss``` : Do ```sa``` and ```sb``` at the same time.
* ```pa``` : push **a** - Take the first element at the top of **b** and put it at the top of **a**. Do nothing if **b** is empty.
* ```pb``` : push **b** - Take the first element at the top of **a** and put it at the top of **b**. Do nothing if **a** is empty.
* ```ra``` : rotate **a** - Shift up all elements of stack **a** by one. The first element becomes the last one.
* ```rb``` : rotate **b** - Shift up all elements of stack **b** by one. The first element becomes the last one.
* ```rr``` : Do ```ra``` and ```rb``` at the same time.
* ```rra``` : reverse rotate **a** - Shift down all elements of stack **a** by one. The last element becomes the first one.
* ```rrb``` : reverse rotate **b** - Shift down all elements of stack **b** by one. The last element becomes the first one.
* ```rrr``` : Do ```rra``` and ```rrb``` at the same time.

## Project content

This project contains a **libft** folder which is a library that we had to create as the first 42 school project. This folder also includes files corresponding to the following 42 school project: **ft_printf** and **get_next_line**.

There are two ```checker_OS``` programs which are used to check that the ```push_swap``` program sorts the list of numbers given as input.

## Usage

Use ```make``` command to compile then run it with:
```
./push_swap <list of numbers>
```
Example:
```
./push_swap 2 1 3 6 5 8
```
or:
```
./push_swap "2 1 3 6 5 8"
```
The program can be checked with the provided checkers, like this:
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```
***
Made by Thibaut Charpentier: <thibaut.charpentier42@gmail.com>
