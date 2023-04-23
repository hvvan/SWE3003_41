delete from Administrator;
delete from User;
delete from Product;
insert into Administrator values ('Jihwan','Kim','jihwankk', 'jihwankk');
insert into User values ( 'Heungmin','Son','user1', 'user1');
insert into User values ('Harry','Kane','user2', 'user2');
insert into User values ('KangIn','Lee','user3', 'user3');
insert into Product values (1, current_timestamp,'Electronics','New','Good','2022-12-29',10000, 'user3');