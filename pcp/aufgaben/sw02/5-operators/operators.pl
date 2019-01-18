female(mary). female(liz). female(mia). female(tina). female(ann). female(sue).
male(mike). male(jack). male(fred). male(tom). male(joe). male(jim).
parent(mary, mia). parent(mary, fred). parent(mary, tina).
parent(mike, mia). parent(mike, fred). parent(mike, tina).
parent(liz, tom). parent(liz, joe).
parent(jack, tom). parent(jack, joe).
parent(mia, ann).
parent(tina, sue). parent(tina, jim).
parent(tom, sue). parent(tom, jim).

% a)
mother(M, C) :- parent(M, C), female(M).
:- op(999, xfx, mother).

% b)
offspring(O, P) :- parent(P, O).
offspring(O, P) :- offspring(O, X), offspring(X, P).
:- op(1111, xfx, offspring).
