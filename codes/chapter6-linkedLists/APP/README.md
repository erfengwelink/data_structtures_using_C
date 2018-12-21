# Applications of linked lists

Linked lists can be used to represent polynomials and the different operations that can be performed on them. In this section, we will see how polynomials are represented in the memory using linked lists.

## Polynomial representation

Let us see how a polynomial is represented in the memory using a linked lists. Consider a polynomial 6x^3 + 9x^2 +7x + 1. Every individual term in a polynomial consists of two parts, a coefficient and a power. Here, 6,9,7, and 1 are the coefficients of the terms that
have 3,2,1,and 0 as their powers respectively.

Every term of a polynomial can be represented as a node of the linked list. following shows the linked representation of the terms of the above polynomial.

    +-----------+     +-----------+     +-----------+     +-----------+
    | 6 | 3 |   |---->| 9 | 2 |   |---->| 7 | 1 |   |---->| 1 | 0 |   |
    +-----------+     +-----------+     +-----------+     +-----------+


Now that we know how polynomials are represented using nodes of a linked list, let us write a program to perform operations on polynomials.

# Example
Write a program to store a polynomial using linked list. Also, perform addition and subtraction on two polynomials.
(details seeing at applications_of_lists.c)