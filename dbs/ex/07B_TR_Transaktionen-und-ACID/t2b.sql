select id, saldo from konto
union select null, sum(saldo) from konto;
COMMIT; 
