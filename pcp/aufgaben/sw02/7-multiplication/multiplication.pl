% multiplication with zero: zero
mult(_, 0, 0).
mult(0, _, 0).

% multiply by adding A to A B times
mult(A, B, P) :-
    B > 0,
    B1 is B - 1,
    mult(A, B1, X),
    P is X + A.
