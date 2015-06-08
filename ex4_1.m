for i = 1 : 10
    for j = 1 : 10
        A(i, j) = 1 / (i + j - 1);
    end;
    b(i) = 1 / i;
end;
A
b
Jacobi(zeros(1, 10), A, b)
SOR(zeros(1, 10), A, b, 1.25)
