:- use_module(library(clpr)).

riddle :-
    { T = 15, M = 3 * T, M + X = 2 * (T + X) },
    format('In ~f Jahren wird die Mutter nur noch doppelt so alt sein wie ihre Tochter', [X]).
