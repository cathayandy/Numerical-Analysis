A = [5 -4 1; -4 6 -4; 1 -4 7]
va = [1 0 0]'
[x, lamda] = power_method(va, A)
B = [25 -41 10 -6; -41 68 -17 10; 10 -17 5 -3; -6 10 -3 2]
vb = [1 0 0 0]'
[x, lamda] = power_method(vb, B)
