create database Employee;
use Employee;

create table Dept(DeptNo int, DName varchar(20), DLoc varchar(20),
primary key(DeptNo));

create table Project(PNo int, PLoc varchar(20), PName varchar(20),
primary key(PNo));

create table Employee(EmpNo int, Ename varchar(20), Mgr_No int, HireDate date, Sal int, DeptNo int,
primary key(EmpNo),
foreign key(DeptNo) references Dept(DeptNo));

create table Incentives(EmpNo int, Incentive_Date date, Incentive_Amount int,
primary key(EmpNo, Incentive_Date),
foreign key(empno) references Employee(EmpNo));

create table Assigned_To(EmpNo int, PNo int, Job_Role varchar(20),
primary key(EmpNo, PNo),
foreign key(EmpNo) references Employee(EmpNo),
foreign key(PNo) references Project(PNo));

insert into Dept values(1, "Human Resources", "Bangalore");
insert into Dept values(2, "Finance", "Hyderabad");
insert into Dept values(3, "Software", "Chennai");
insert into Dept values(4, "Marketing", "Mysuru");
insert into Dept values(5, "Sales", "Mangalore");
insert into Dept values(6, "IT Support", "Bangalore");

insert into Project values(1, "Bangalore", "E-commerce Platform");
insert into Project values(2, "Hyderabad", "AI Research Project");
insert into Project values(3, "Chennai", "Mobile Payment App");
insert into Project values(4, "Mysuru", "SmartCity Initiative");
insert into Project values(5, "Mangalore", "Logistics System");
insert into Project values(6, "Bangalore", "Healthcare System");

insert into Employee values(1, "Rahul", 2, "2023-01-15", 60000, 1);
insert into Employee values(2, "Sneha", 3, "2022-03-20", 55000, 2);
insert into Employee values(3, "Vikram", 1, "2021-06-10", 70000, 3);
insert into Employee values(4, "Anjali", 2, "2024-05-25", 48000, 4);
insert into Employee values(5, "Karan", 3, "2023-09-12", 52000, 5);
insert into Employee values(6, "Priya", 4, "2023-08-30", 65000, 1);
insert into Employee values(7, "Janaki", 1, "2021-07-31", 45000, 6);

insert into Incentives values(1, "2023-02-15", 5000);
insert into Incentives values(2, "2023-03-10", 3000);
insert into Incentives values(3, "2023-04-05", 4000);
insert into Incentives values(5, "2023-06-15", 3000);
insert into Incentives values(6, "2023-07-30", 6000);

insert into Assigned_To values(1, 1, "HR Manager");
insert into Assigned_To values(2, 2, "Financial Analyst");
insert into Assigned_To values(3, 3, "Lead Engineer");
insert into Assigned_To values(4, 4, "Marketing Specialist");
insert into Assigned_To values(5, 5, "Sales Executive");
insert into Assigned_To values(6, 1, "Project Coordinator");

Select EmpNo from Assigned_To where PNo in (Select PNo
from Project
where PLoc in ("Bangalore", "Hyderabad", "Mysuru"));

Select EmpNo from Employee where EmpNo not in (Select EmpNo from Incentives);

Select e.Ename, e.EmpNo, d.DName AS Dept, a.Job_Role, d.DLoc AS Dept_Location, p.PLoc AS Project_Location
from Employee e
join Dept d on e.DeptNo = d.DeptNo
join Assigned_To a on e.EmpNo = a.EmpNo
join Project p on a.PNo = p.PNo
where d.DLoc = p.PLoc;
