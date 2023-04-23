create table Administrator ( 
    Admin_FName varchar(20) Not null, 
    Admin_LName varchar(20) not null, 
    Admin_ID varchar(25), 
    Admin_PW varchar(40) not null, 
    primary key (Admin_ID)
); 
create table User ( 
    User_FName varchar(20) Not null, 
    User_LName varchar(20) not null, 
    User_ID varchar(25), 
    User_PW varchar(40) not null, 
    primary key (User_ID)
); 
create table Product ( 
    Prod_ID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    Prod_Date TIMESTAMP not null default current_timestamp,
    Prod_Category varchar(50) not null
        check (Prod_Category in ('Electronics', 'Books', 'Home', 'Clothing','Sporting Goods')), 
    Prod_condition varchar(50) not null
        check (Prod_condition in ('New', 'Like-New', 'Used (Good)', 'Used (Acceptable)')), 
    Prod_Description varchar(100) not null,
    Prod_end_date date not null, 
    Buy_Now_Price integer not null, 
    Seller_ID varchar(25), 
    foreign key (Seller_ID) references User(User_ID)
); 