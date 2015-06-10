function [x_appr, r_inf, delta_x_inf] = solve(n, dis)
for i = 1 : n
    for j = 1 : n
        H(i, j) = 1 / (i + j - 1);
    end;
    x(i) = 1;
end;
H
b = H * x';
b = b + dis
U = Cholesky(H)
y = solveL(U, b)
x_appr = solveU(U', y)
r = b - H * x_appr'
delta_x = x_appr - x
r_inf = norm(r, inf)
delta_x_inf = norm(delta_x, inf)