drop database go;
create database go character set utf8mb4 collate utf8mb4_unicode_ci;
use go;
drop table if exists users;
create table users(
account varchar(10),
nickname varchar(10),
passwd varchar(10),
level int,
integral int,
status varchar(10),
primary key(account)
);
drop table if exists rooms;
create table rooms(
id int,
name varchar(10),
player1 varchar(10),
player2 varchar(10),
readygo1 varchar(3),
readygo2 varchar(3),
status varchar(10),
primary key(id)
);
