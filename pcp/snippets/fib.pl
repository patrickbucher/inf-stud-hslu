fib(0, 0).
fib(1, 1).
fib(N, F) :-
    N > 1,
    fib(N-1, F1),
    fib(N-2, F2),
    F is F1 + F2.
