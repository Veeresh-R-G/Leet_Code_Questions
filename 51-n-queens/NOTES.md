Ok so optimisation,
In safe function
​
1. since we are placing the queens from left to right
2. we need not check the right side of the board yet!
3.Also no need to check up and down in that particular column since we are placing the
in that column for the first time, so
**NO CHECKING OF THE FOLLOWING : **
1. UP
2. DOWN
3. RIGHT - TOP DIAGONAL
4. RIGHT-BOTTOM DIAGONAL
5. RIGHT-SIDE
​
Also Another error
​
In the While Loops
dont decrement (or) increment like : t1-- / t1++ this might lead to accessing the elements
of a vector which are out of range !!!!.
​
​