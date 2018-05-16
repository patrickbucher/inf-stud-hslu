START TRANSACTION;
update konto set saldo=saldo - 100 where id=1;
select id, saldo from konto
union select null, sum(saldo) from konto;
