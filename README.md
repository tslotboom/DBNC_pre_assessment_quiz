# DBNC_pre_assessment_quiz
Preasessment quiz for DBNC embedded software developer role


Q1:

Running:

`./test_q1.sh`

Output of test_q1.sh:

Input: N = 0, M = 0
ERROR: N and M must be positive integers

Input: N = 0, M = 1
ERROR: N and M must be positive integers

Input: N = 1, M = 0
ERROR: N and M must be positive integers

Input: N = -1, M = -1
ERROR: N and M must be positive integers

Input: N = 1, M = 1
Output: 1x1

Input: N = 1, M = 2
Output: 1x1, 1x1

Input: N = 2, M = 1
Output: 1x1, 1x1

Input: N = 2, M = 2
Output: 2x2

Input: N = 5, M = 6
Output: 5x5, 1x1, 1x1, 1x1, 1x1, 1x1

Input: N = 8, M = 5
Output: 5x5, 3x3, 2x2, 1x1, 1x1

Input: N = 9, M = 9
Output: 9x9

Input: N = 34, M = 21
Output: 21x21, 13x13, 8x8, 5x5, 3x3, 2x2, 1x1, 1x1


Q2:

Q2A:

f(A) is a conversion from decimal to base62, and then a coversion of the digits
in the regular base62 number to an encoded base62 number, with the order of 
encoded digits as follows:
from:
0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
to:
C7xicPMGvzAZyTNodmwnVlD3B6H0Oup8E21W9sqLQX4YjSeUhIRJgafFtrKlbk

Q2B:
f(30001) = GIF
f(55555) = NOi
f(77788) = VNQ

Q2C:
The upper limit of this function is the largest possible base62 number with 
three digits, which is 238327, or "kkk" in the encoded base62 format..