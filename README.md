# Rummikub
Compute Rummikub's available combinations.  
I didn't think about JOKER.

## INPUT
There should be total 52 numbers in 13x4 form.

### Example
1 1 1 1 0 0 0 0 0 0 0 0 0  
0 0 0 0 1 1 1 1 0 0 0 0 0  
0 0 0 0 0 0 0 0 1 1 1 1 0  
1 1 1 0 0 0 0 0 0 0 0 0 0

Each row means color, and each col means number.  
Row 0 means certain color. For example, I think row 0 is Black, 1 is Red, 2 is Yellow, 3 is Black.  
Col 0 means number 1. Then, for example, col 11 means number 12.  
  
Each cell's number means how many card exists.
2 means there are two cards whose color and number is same.

## OUTPUT
Output will be printed in each case's combination.
### Example
I found available case!!  
0/1 0/2 0/3 0/4   
1/5 1/6 1/7 1/8   
2/9 2/10 2/11 2/12   
3/1 3/2 3/3   
End case.  

Each line means a group of combination.  
Each group is consisted of cards which are formed "row number(color)/num".  
