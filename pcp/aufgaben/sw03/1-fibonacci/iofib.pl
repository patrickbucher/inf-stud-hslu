fib(N, F) :- fib(N, 0, 1, F).
fib(0, A, _, A).
fib(N, A, B, F) :-
    N1 is N - 1,
    N1 >= 0,
    Sum is A + B,
    fib(N1, B, Sum, F).

io_fib() :-
    write('Gib eine Zahl ein: '),
    read(N),
    fib(N, F),
    format('Die ~d. Fibonacci-Zahl ist ~d', [N, F]).
