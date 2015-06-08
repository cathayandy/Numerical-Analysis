t = 1 : 0.5 : 8
y = [33.4 79.5 122.65 159.05 189.15 214.15 238.65 252.2 287.55 280.50 296.65 301.65 310.40 318.15 325.15]
A = polyfit(t, y, 2);
z = polyval(A, t);
plot(t, y, 'r*', t, z, 'b')
lny = log(y)
B = polyfit(t, lny, 1)
lnw = polyval(B, t)
w = exp(lnw)
hold on;
plot(t, w, 'r');
hold off;
