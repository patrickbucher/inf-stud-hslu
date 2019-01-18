:- use_module(library(clpr)).
fib_clpr(N, F) :- { N = 0, F = 0 }.
fib_clpr(N, F) :- { N = 1, F = 1 }.
fib_clpr(N, F) :-
    { N >= 2, F = F1 + F2, F1 > 0, F2 >= 0, F1 >= F2, N1 = N - 1, N2 = N - 2 },
    fib_clpr(N2, F2),
    fib_clpr(N1, F1).

% a) Das Programm terminiert nicht.
%
% b) Es wird unendlich lange nach einer (weiteren) Lösung gesucht, die nicht
% existiert. Das Ziel fib_clpr(N1, F1) soll für N1=2 eine zusätzliche Lösung
% für F1 finden, es kann jedoch nur eine geben.
%
% c) Es benötigt mehrere Anpassungen:
%     - Die Reihenfolge der beiden letzten Prädikate muss vertauscht werden,
%       sodass der triviale/terministische Fall N=1, F=1 früher ausgewertet wird
%       als der Fall N=2, F=2. Da für N=1 immer nur eine Lösung existieren kann,
%       schlägt die Suche nach einer weiteren Lösung fehl, bevor die Suche nach
%       einer zweiten Lösung für N=2 aufgenommen werden kann. Das Programm
%       terminiert.
%     - Es sind weitere Constraints zu definieren:
%       - F1 muss grösser als 0 sein
%       - F2 muss grösser/gleich 0 sein
%       - F1 muss grösser/gleich F2 sein (reduziert die Anzahl der Möglichkeiten)
