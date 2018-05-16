update konto set saldo=saldo + 100 where id=2;
Insert into konto(id, saldo) values(4,4000);
select id, saldo from konto
union select null, sum(saldo) from konto;
COMMIT; 
