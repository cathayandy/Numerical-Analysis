function x = solveU(U, b)
[m, n] = size(U);
for ii = 1 : n
    i = n - ii + 1;
    if U(i, i) == 0
        break;
    end;
    x(i) = b(i);
    for jj = (i + 1) : n
        j = n - jj + i + 1;
        x(i) = x(i) - U(i, j) * x(j);
    end;
    x(i) = x(i) / U(i, i);
end;