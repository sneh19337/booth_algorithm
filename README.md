# booth_algorithm
A cpp project to show the simulated version of how booth algorithm works
This is a coding project to demonstrate the Booth’s algorithm to multiply signed integers. This code is written in c plus plus language . 
The code takes two numbers as input. These two numbers can be 
1.Negative , Negative
2. Negative, Positive
3. Negative, Positive
4. Positive ,Positive 
The code is written according to the flow of the algorithm of Booth-
1.	This code multiplies the two signed numbers in 2’s complement notion.
2.	Let Q be the multiplier, M be the multiplicant.
3.	Let P be a register initially having 0 as its value.
4.	Also initialize a register named Q-1 having single bit.
5.	If QQ-1 are either 00 or 11 the do right shifting 
6.	If QQ-1=10 then do Q=-M+Q
7.	If QQ-1=01 then do Q=Q+M
8.	Then do the right shift



An example from the code made in this project
Enter two numbers that are to be multiplied : -5 10



Step No.    P      Q    Q-1
0         00000  01010  0
1         00000  00101  0
        + 00101
          00101
2         00010  10010  1
        + 11011
          11101
3         11110  11001  0
        + 00101
          00011
4         00001  11100  1
        + 11011
          11100
5         11110  01110  0

Product in binary number is : 11110 01110

                      CONSTRAINTS
The code has register having variable bits . It can give answer from 1 bit to 64 bits.
THAT means it can give answers in integer from the range  -128 to 127 bytes. 
The code can’t multiply numbers greater than 8 digits. If one number is 8 bit and another one is less than 8 then it still works.
The code gives result for large numbers  in as many as 64 bits which sometimes becomes inconvenient to read. But the code also gives answer as decimal number . Hence , somehow each answer can be checked.  
                          ASSUMPTION
1.	The code can give answers in variable bits according to the number given as  input.
2.	The code can take numbers positive as well as negative.
3.	The code assumes that the numbers are signed integers.
4.	The code assumes that the given input is in decimal which it later changes to binary and gives a binary output.
5.	The code shows each step according to algorithm.
6.	This code shows step no, P, Q,Q-1 in each step that has been calculated.
7.	Final answer can be seen in the last step.
