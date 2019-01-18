:- use_module(library(clpfd)).

% points by finishing position
points(1, 25).
points(2, 18).
points(3, 15).
points(4, 12).
points(5, 10).
points(6, 8).
points(7, 6).
points(8, 4).
points(9, 2).
points(10, 1).

% current championship standings
current(hamilton, 348).
current(vettel, 294).
current(raikkoennen, 236).
current(bottas, 227).

driverchampion(Hamilton, Vettel) :-
    Hamilton #\= Vettel,
    H1 + H #> V1 + V + (1 * 25), % one race to go after current race
    current(hamilton, H1),
    current(vettel, V1),
    points(Hamilton, H),
    points(Vettel, V),
    label([H, V, H1, V1]).

constructorchampion(Hamilton, Bottas, Vettel, Raikkoennen) :-
    current(hamilton, H1),
    current(bottas, B1),
    current(vettel, V1),
    current(raikkoennen, R1),
    points(Hamilton, H),
    points(Bottas, B),
    points(Vettel, V),
    points(Raikkoennen, R),
    H + H1 + B + B1 #> V + V1 + R + R1 + 1 * (25 + 18),
    all_distinct([Hamilton, Bottas, Vettel, Raikkoennen]),
    label([H, H1, B, B1, V, V1, R, R1]).
