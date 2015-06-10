x = [0.520 3.1   8.0 17.95 28.65 39.62 50.65 78 104.6 156.6 208.6 260.7 312.50 364.4 416.3 468 494 507 520]
y = [5.288 9.4 13.84 20.20 24.90 28.44 31.10 35  36.9  36.6  34.6  31.0  26.34  20.9  14.8 7.8 3.7 1.5 0.2]
dy0 = 1.86548
dyn = -0.046115
xi = [2 30 130 350 515]
xt = 0 : 520;
pp = csape(x, y, 'complete', [dy0, dyn]);
yi = ppval(pp, xi)
yt = ppval(pp, xt);
ppder = fnder(pp);
yider = ppval(ppder, xi)
ytder = ppval(ppder, xt);
ppder2 = fnder(ppder);
yider2 = ppval(ppder2, xi)
ytder2 = ppval(ppder2, xt);
plot(x, y, 'o', xi, yi, '*', xi, yider, '*', xi, yider2, '*', xt, yt, xt, ytder, xt, ytder2);