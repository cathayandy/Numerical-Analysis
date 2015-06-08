function x = SOR(x, A, b, omega)
while true
    y = x;
    for i = 1 : n
        s = 0;
        for j = 1 : n
            if i ~= j
                s = s + A(i, j) * x(j);
            end;
        end;
        x(i) = (1 - omega) * x(i) + omega * (b(i) - s) / a(i, i);
    end;
    if norm(x - y, inf) < 1e-4
        break;
    end;
end;