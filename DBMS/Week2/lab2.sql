create database insurancedata;

use insurancedata;

create table person(driver_id varchar(3), name varchar(30), address varchar(30), PRIMARY KEY(driver_id));
desc person;
create table car(reg_num varchar(10),model varchar(10),year int, primary key(reg_num));
desc car;
create table owns(driver_id varchar(3),reg_num varchar(10),
primary key(driver_id, reg_num),
foreign key(driver_id) references person(driver_id),
foreign key(reg_num) references car(reg_num));
desc owns;
create table accident(report_num int, accident_date date, location varchar(30),primary key(report_num));

create table participated(driver_id varchar(3), reg_num varchar(10),
report_num int, damage_amount int, 
primary key(driver_id, reg_num, report_num), 
foreign key(driver_id) references person(driver_id),
foreign key(reg_num) references car(reg_num),
foreign key(report_num) references accident(report_num));

insert into accident values (11, '2003-01-01','Mysore Road');
insert into accident values (12,'2004-02-02','South end Circle');
insert into accident values (13,'2003-01-21','Bull temple Road');
insert into accident values (14,'2008-02-17','Mysore Road');
insert into accident values (15,'2004-03-05','Kanakpura Road');

insert into person values ('A01', 'Richard', 'Srinivas Nagar');
insert into person values ('A02', 'Pradeep', 'Rajaji Nagar');
insert into person values ('A03', 'Smith', 'Ashok Nagar');
insert into person values ('A04', 'Venu', 'N R Colony');
insert into person values ('A05', 'John', 'Hanumanth Nagar');

insert into car values('KA052250','Indica', '1990');
insert into car values('KA031181', 'Lancer', '1957');
insert into car values('KA095477', 'Toyota', '1998');
insert into car values('KA053408', 'Honda', '2008');
insert into car values('KA041702', 'Audi', '2005');

insert into participated values ('A01', 'KA052250', 11, 10000);
insert into participated values ('A02', 'KA031181', 12, 50000);
insert into participated values ('A03', 'KA095477', 13, 25000);
insert into participated values ('A04', 'KA053408', 14, 3000);
insert into participated values ('A05', 'KA041702', 15, 5000);

select * from car order by year ASC;

select count (distinct p.report_num) as accident_count from participated p, car c where p.reg_num = c.reg.num and c.model = 'Lancer'

select * from participated order by damage_amount DSC;

seelct avg(damage_amount) as average_damage from participated;

select distinct p.name from participated p, person q where p.driver_id = q.driver_id and q.damage_amuont > (select avg(damage_amount) from participated)

select max(damage_amount) as maximum_damage from participated
