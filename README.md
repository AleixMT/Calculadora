# Calculadora
Calculator of combinated operations using integers. 

## Usage
You can use parenthesis () for priority, and the operators + - * / % ^ are available.
Write your query expressions in a text file and execute the program.

## About the Calculator
The Calculator works in the same way as a compiler. Has severals phases to treat an operation:
· Check that all symbols in the entrance file are correct
· Check that the parenthesys make sense, being the redundant parenthesis accepted by the algorithm.
· Check that the meaning of the operations is okay, having every symbol separated by another with a number.
· A recursive process starts, that digests the expression using recursivity. On every iteration:
  1. Parenthesis are deleted.
  2. The operation to calcule is selected.
  3. Due to recursion two things can happen:
    · One or two recursive calls are made to split the expression in smaller parts.
    · An operation of one single operator is done (e.g. 3+5 ), and the result is returned to the calling function, returning from the recursive call.

## Examples of usage
```
(56*2+3)^2%2
2^(2+5)/2^2
5*4+1*4*6+(3*4+2*5*(4+2/1))
5*(4+2+3)*4*5+3*(2-2)
(((10+2)+5)+5)*(20-2)
(20-2)*(((10+2)+5)+5)
(3*(10+2))+((5+4)*(20-2))
```
· You can also use the calculator to check if an arithmeetical expression is correct.

## Authors

* **Aleix Mariné Tena** - [AleixMT](https://github.com/AleixMT)
* **Cristòfol Daudén Esmel** - [toful](https://github.com/toful)
