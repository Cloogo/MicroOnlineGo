drop database go;
create database go character set utf8 collate utf8_general_ci;
use go;
drop table if exists users;
create table users(
account varchar(10),
nickname varchar(10),
passwd varchar(10),
level int,
rank int,
win int,
lose int,
draw int,
year int,
month tinyint,
day tinyint,
sex tinyint,
state tinyint,
roomid int,
primary key(account)
);
drop table if exists rooms;
create table rooms(
id int,
name varchar(10),
player1 varchar(10),
player2 varchar(10),
state varchar(10),
komi tinyint,
mainTime tinyint,
period tinyint,
periodTimes tinyint,
player1ready tinyint,
player2ready tinyint,
primary key(id)
);
