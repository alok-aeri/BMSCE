create database bank_data;
use bank_data;

create table loan(loan_no int primary key, branchname varchar(30), amount int);
insert into loan values(1, "SBI-CJ", 1000);
insert into loan values(2, "SBI-RR", 2000);
insert into loan values(3, "SBI-SR", 3000);
insert into loan values(4, "SBI-PR", 4000);
insert into loan values(5, "SBI-JM", 5000);
select * from loan;

create table depositer(cust_name varchar(20), acc_no int, primary key(cust_name, acc_no),unique (acc_no));
insert into depositer values("Avinash", 1);
insert into depositer values("Dinesh", 2);
insert into depositer values("Nikhil", 4);
insert into depositer values("Ravi", 5);
insert into depositer values("Avinash", 8);
insert into depositer values("Dinesh", 10); 
insert into depositer values("Nikihl", 11);
select * from depositer;

create table bankcust(cust_name varchar(20), cust_street varchar(30), city varchar(15), foreign key(cust_name) references depositer(cust_name));
insert into bankcust values("Avinash", "Bull_Temple_Road", "Bengaluru");
insert into bankcust values("Dinesh", "Bannergatta_Road", "Bengaluru");
insert into bankcust values("Mohan", "National_College_Road", "Bengaluru");
insert into bankcust values("Nikhil", "Akbar_Road", "Delhi");
insert into bankcust values("Ravi", "Prithviraj_Road", "Delhi");
select * from bankcust;

create table bankacc(acc_no int primary key, branchname varchar(30), balance int, foreign key(branchname) references branch(branchname));
insert into bankacc values(1, "SBI-CJ", 2000);
insert into bankacc values(2, "SBI-RR", 5000);
insert into bankacc values(4, "SBI-PR", 9000);
insert into bankacc values(5, "SBI-JM", 8000);
insert into bankacc values(8, "SBI-RR", 4000);
insert into bankacc values(10, "SBI-RR", 5000);
insert into bankacc values(11, "SBI-JM", 2000);

create table branch(branchname varchar(30) primary key,branchcity varchar(20),assets int);
insert into branch values("SBI-CJ", "Bengaluru", 50000);
insert into branch values("SBI-RR", "Bengaluru", 10000);
insert into branch values("SBI-SR", "Bengaluru", 20000);
insert into branch values("SBI-PR", "Delhi", 10000);
insert into branch values("SBI-JM", "Delhi", 20000);

select cust_name from depositer where acc_no IN (
    select acc_no from bankacc where branchname in (
        select branchname from branch where branchcity = 'Delhi'))
group by cust_name having COUNT(DISTINCT acc_no) = (
    select COUNT(*) from branch where branchcity = 'Delhi');

select distinct b.cust_name from bankcust b
join loan l on b.cust_name = l.branchname
left join depositer d on b.cust_name = d.cust_name
where d.cust_name is null;


select distinct b.cust_name from bankcust b join bankacc a ON b.cust_name = a.branchname join loan l ON l.branchname = a.branchname where a.branchname = 'SBI-CJ' OR a.branchname = 'SBI-RR' OR a.branchname = 'SBI-SR';


select branchname from branch where assets > (
    select MAX(assets)
    from branch
    where branchcity = 'Bengaluru'
);


delete from bankacc where branchname IN (
    select branchname from branch where branchcity = 'Bombay'
);
