drop database bank;
create database bank;
use bank;
create table konto(id integer primary key, saldo float);
start transaction;
delete from konto;
insert into konto(id, saldo) values (1, 1000);
insert into konto(id, saldo) values (2, 2000);
commit;
