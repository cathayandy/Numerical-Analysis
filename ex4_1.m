for i = 1 : 10
    for j = 1 : 10
        A(i, j) = 1 / (i + j - 1);
    end;
    b(i) = 1 / i;
end;
A
b
% Jacobi(zeros(1, 10), A, b)
i = 1.25
[x, tmp] = SOR(zeros(1, 10), A, b, 1.25)
k = 1;
for i = 0.1 : 0.05 : 1.9
    i
    [x, n(k)] = SOR(zeros(1, 10), A, b, i);
    x
    n(k)
    k = k + 1;
end;
i = 1 : 37;
plot(i, n);
