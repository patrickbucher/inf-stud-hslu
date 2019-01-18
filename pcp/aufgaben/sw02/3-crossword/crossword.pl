word(n, e, u).
word(t, o, p).
word(t, o, t).
word(b, r, o, t).
word(g, r, a, u).
word(h, a, l, t).
word(a, l, l, e).
word(j, e, t, z, t).
word(s, a, g, e, n).
word(u, n, t, e, n).
word(z, e, c, k, e).

crosswords(L2, L7, L8, L9, L10, L14, L16, L20, L21, L22, L23, L24) :-
    word(L2, L8, L14, L20),
    word(L7, L8, L9, L10),
    word(L10, L16, L22),
    word(L20, L21, L22, L23, L24).

% crosswords(L2, L7, L8, L9, L10, L14, L16, L20, L21, L22, L23, L24).
