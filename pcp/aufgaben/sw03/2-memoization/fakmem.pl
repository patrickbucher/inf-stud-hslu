:- dynamic(fak_as/2).
fak(0, 1).
fak(A, B) :-
    fak_as(A, B),
    format('(Hinweis: Fakultät von ~d war gespeichert)', [A]).
fak(A, B) :-
    A > 0,
    A1 is A - 1,
    fak(A1, B1),
    B is A * B1,
    asserta(fak_as(A, B)).
fak_clear :-
    retractall(fak_as(_, _)),
    write('(Hinweis: Alle gespeicherten Werte wurden gelöscht)').
