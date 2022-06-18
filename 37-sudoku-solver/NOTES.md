Ok this is come clever calculation of that particular 3*3 grid
​
Its like 3 way set-Associative mapping (Lol dw I have a B in MPCA..sed life)
​
the 9 rows and 9 columns are being grouped in groups of 3-3
​
so individually, we can access these small matrices using offests --> 0 , 1 , 2
​
To get the ROW or COL we do the below to check it in a Single Loop
<br/>
**ROW = 3 * (row / 3) + ( i / 3)
COL = 3 * (col / 3) + ( i % 3)**