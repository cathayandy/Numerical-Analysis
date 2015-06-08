function [x, lamda] = power_method(v, A)
u = v;
lamda = -1;
while true
    v = A * u;
    if abs(max(abs(v)) - lamda) < 1e-5
        lamda = max(abs(v))
        break;
    end;
    lamda = max(abs(v))
    u = v / lamda;
end;
x = u;