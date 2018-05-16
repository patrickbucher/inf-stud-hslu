START TRANSACTION; -- mySql: START statt BEGIN
select id, saldo from konto
union select null, sum(saldo) from konto;
