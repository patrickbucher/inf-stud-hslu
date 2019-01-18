female(mary). female(liz). female(mia). female(tina). female(ann). female(sue).
male(mike). male(jack). male(fred). male(tom). male(joe). male(jim).
parent(mary, mia). parent(mary, fred). parent(mary, tina).
parent(mike, mia). parent(mike, fred). parent(mike, tina).
parent(liz, tom). parent(liz, joe).
parent(jack, tom). parent(jack, joe).
parent(mia, ann).
parent(tina, sue). parent(tina, jim).
parent(tom, sue). parent(tom, jim).

% a) mother/2 and father/2
mother(M, C) :- parent(M, C), female(M).
father(F, C) :- parent(F, C), male(F).

% mother(X, tina).
% X = mary.
% 
% father(X, sue).
% X = tom.
%
% mother(X, jim).
% X = tina.
%
% father(X, jim).
% X = tom.
%
% mother(mary, X).
% X = mia ;
% X = fred ;
% X = tina.
% false.

% b) sibling/2
sibling(A, B) :- parent(X, A), parent(X, B).

% sibling(mia, fred).
% true .
%
% sibling(mia, mia).
% true

% c) grandmother/2
grandmother(G, C) :- female(G), parent(G, P), parent(P, C).

% grandmother(X, ann).
% X = mary.
%
% grandmother(liz, X).
% X = sue ;
% X = jim ;
% false.
%
% grandmother(X, jim).
% X = mary ;
% X = liz ;
% false.

% d) offspring/2
offspring(O, P) :- parent(P, O).
offspring(O, P) :- offspring(O, X), offspring(X, P).

% offspring(ann, mary).
% true .
%
% offspring(sue, X).
% X = tina ;
% X = tom ;
% X = mary ;
% X = mike ;
% X = liz ;
% X = jack ;
% false.
