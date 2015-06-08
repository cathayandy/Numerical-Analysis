function x = Jacobi(x, A, b)
[m, n] = size(b);
while true
    y = x
    pause();
    for i = 1 : n
        s = 0;
        for j = 1 : n
            if i ~= j
                s = s + A(i, j) * y(j);
            end;
        end;
        s
        x(i) = (b(i) - s) / A(i, i);
    end;
    if norm(x - y, inf) < 1e-4
        break;
    end;
end;