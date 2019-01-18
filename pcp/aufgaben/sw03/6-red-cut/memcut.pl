mem(X, [X | _]).      % X as list header (ignore tail)
mem(X, [_ | Tail]) :- % X in list tail (ignore header)
    mem(X, Tail).

% Der Aufruf.
%   L = [_, _, _], mem(a, L), mem(b, L), mem(c, L).
% muss am Ende das Cut-Prädikat verwenden
%   L = [_, _, _], mem(a, L), mem(b, L), mem(c, L), !.
% damit nur ein Ergebnis ausgegeben wird.
%
% Mit dem Red Cut gibt es nur ein Ergebnis statt zuvor sechs. Das Prädikat hat
% somit eine andere Semantik: Es tut etwas anderes.
