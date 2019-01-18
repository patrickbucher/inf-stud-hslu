% a) add to tail
add_tail(X, [], [X]).                % add to empty list
add_tail(X, [Head | []], [Head, X]). % add to list with one element
add_tail(X, [Head | Tail], L1) :-    % add to list with n>1 elements
    add_tail(X, Tail, L2),           % add element to list without its head
    L1 = [Head | L2].                % add the head back to the list

% b) delete element by value
del([X], X, []).             % remove sole entry from empty list
del([Head | Tail], X, L1) :- % remove first entry from a list
    Head == X,
    L1 = Tail.
del([Head | Tail], X, L1) :- % remove first entry from tail, add head back
    Head \== X,
    del(Tail, X, L2),
    L1 = [Head | L2].

% c) check for list membership using del/3
mem_d(X, L) :-
    del(L, X, L1),            % X is a member of L, ...
    length(L) \== length(L1). % if L's length changes upon removing X from it

% d) reverse a list
% List      Accumulator
% [a,b,c]   []
% [b,c]     [a]
% [c]       [b,a]
% []        [c,b,a]
rev_acc([X], [], [X]).
rev_acc([], A, A).              % when the list is empty, A is the result
rev_acc([Head | Tail], A, R) :-
    A1 = [Head | A],            % first list element becomes head of Accumulator
    rev_acc(Tail, A1, R).

% e) convenience method for list reversal
rev(L, R) :-
    rev_acc(L, [], R).
