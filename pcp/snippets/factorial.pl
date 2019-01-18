fak(0, 1).
fak(A, B) :-
    A > 0,
    A1 is A - 1,
    fak(A1, B1),
    B is A * B1.
