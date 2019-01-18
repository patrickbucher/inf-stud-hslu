p(X) :- a(X).          % Rule r1
p(X) :- b(X), !, c(X). % Rule r2 (modified)
p(X) :- d(X).          % Rule r3

a(1).
b(2). b(3).
c(2). c(3).
d(4).
