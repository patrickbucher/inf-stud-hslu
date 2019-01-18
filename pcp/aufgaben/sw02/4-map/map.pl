n(gelb, rot). n(rot, gelb).
n(gelb, gruen). n(gruen, gelb).
n(rot, gruen). n(gruen, rot).

colors(LU, ZG, SZ, UR, OW, NW) :-
    UR = gelb,
    SZ = rot,
    n(LU, ZG), n(ZG, LU),
    n(LU, SZ), n(SZ, LU),
    n(LU, NW), n(NW, LU),
    n(LU, OW), n(OW, LU),
    n(ZG, SZ), n(SZ, ZG),
    n(SZ, UR), n(UR, SZ),
    n(SZ, NW), n(NW, SZ),
    n(NW, OW), n(OW, NW),
    n(NW, UR), n(UR, NW),
    n(UR, OW), n(OW, UR).

% colors(LU, ZG, SZ, UR, OW, NW).
% LU = UR, UR = gelb,
% ZG = NW, NW = gruen,
% SZ = OW, OW = rot ;
% false.
