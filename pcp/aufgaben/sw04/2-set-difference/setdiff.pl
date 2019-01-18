set_difference([], _, []).
set_difference(L, [], L).
set_difference([H|T], L, R) :-
    \+ member(H, L),
    !,
    append([H], R1, R),
    set_difference(T, L, R1).
set_difference([_|T], L, R) :-
    set_difference(T, L, R).
