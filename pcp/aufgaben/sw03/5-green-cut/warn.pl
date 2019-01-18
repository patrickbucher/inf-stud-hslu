%warn(T) :- T < 80, write('Temperatur ok'), !.
%warn(T) :- T < 100, write('Temperatur sehr warm'), !.
%warn(_) :- write('Temperatur zu heiss').

warn(T) :- T < 80, write('Temperatur ok').
warn(T) :- T >= 80, T < 100, write('Temperatur ok').
warn(T) :- T >= 100, write('Temperatur zu heiss').

% Das Originalprogramm ist insofern eine Optimierung, dass es die Evaluation
% nach dem ersten Match abbricht. Dadurch kann jede Regel davon ausgehen, dass
% die oberhalb von ihr stehenden Regeln keinen Match erzeugt haben, und muss
% die obenstehenden Bedingungen nicht erneut prüfen. Die Reihenfolge ist
% aber wichtig. (Im umgeschriebenen Programm ist die Reihenfolge der Prädikate
% beliebig).
