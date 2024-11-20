create database supplier;

use supplier;

create table parts (
    pid int primary key,
    pname varchar(50),
    color varchar(20)
);

create table suppliers (
    sid int primary key,
    sname varchar(50)
);

create table supply (
    pid int,
    sid int,
    cost decimal(10, 2),
    primary key (pid, sid),
    foreign key (pid) references parts(pid),
    foreign key (sid) references suppliers(sid)
);

insert into parts (pid, pname, color) values
(20001, 'book', 'red'),
(20002, 'charger', 'blue'),
(20003, 'mobile', 'red'),
(20004, 'pen', 'green'),
(20005, 'pencil', 'red');
select * from parts;

insert into suppliers (sid, sname) values
(10001, 'acme widget'),
(10002, 'johns'),
(10003, 'reliance'),
(10004, 'doe supplies');
select * from suppliers;

insert into supply (pid, sid, cost) values
(20001, 10001, 50),
(20002, 10001, 60),
(20003, 10002, 55),
(20004, 10001, 40),
(20005, 10001, 30),
(20001, 10002, 70),
(20002, 10002, 65),
(20003, 10003, 45);
select * from supply;

select distinct pname
from parts
where pid in (select pid from supply);

select sname
from suppliers s
where not exists (
    select pid
    from parts
    where pid not in (
        select pid
        from supply
        where sid = s.sid
    )
);

select sname
from suppliers s
where not exists (
    select pid
    from parts
    where color = 'red' and pid not in (
        select pid
        from supply
        where sid = s.sid
    )
);

select pname
from parts p
where pid in (
    select pid
    from supply
    where sid = (select sid from suppliers where sname = 'acme widget')
)
and pid not in (
    select pid
    from supply
    where sid <> (select sid from suppliers where sname = 'acme widget')
);

select distinct s.sid
from supply s
join (
    select pid, avg(cost) as avgcost
    from supply
    group by pid
) a on s.pid = a.pid
where s.cost > a.avgcost;

select p.pid, s.sname
from supply sup
join suppliers s on sup.sid = s.sid
join parts p on sup.pid = p.pid
where sup.cost = (
    select max(cost)
    from supply
    where pid = p.pid
);

drop database supplier;
