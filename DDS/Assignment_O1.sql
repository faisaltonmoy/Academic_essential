clear screen;

DROP TABLE Student CASCADE CONSTRAINTS;
DROP TABLE Borrows CASCADE CONSTRAINTS;
DROP TABLE Book CASCADE CONSTRAINTS;
DROP TABLE Author CASCADE CONSTRAINTS;

CREATE TABLE Student( studentID int, name varchar2(30), phone varchar2(11), age int, PRIMARY KEY(studentID) ); 

CREATE TABLE Author( authorID int, a_name varchar2(30), a_age int, PRIMARY KEY(authorID) );

CREATE TABLE Book( bookID int, title varchar2(50), genre varchar2(30), datePublished date, authorID int, PRIMARY KEY(bookID),FOREIGN KEY(authorID) REFERENCES Author(authorID) );

CREATE TABLE Borrows( bookID int, dateBorrowed date, studentID int,FOREIGN KEY(bookID) REFERENCES Book(bookID),FOREIGN KEY(studentID) REFERENCES Student(studentID) );

INSERT INTO Student VALUES (1, 'Samin', '01710101010', 25);
INSERT INTO Student VALUES (2, 'Moin', '01920202020', 19);
INSERT INTO Student VALUES (3, 'Tanvir', '01830303030', 27);
INSERT INTO Student VALUES (4, 'Sojib', '01640404040', 21);
INSERT INTO Student VALUES (5, 'Risad', '01550504050', 20);
INSERT INTO Student VALUES (6, 'Mahi', '01360606060', 23);
INSERT INTO Student VALUES (7, 'Tonmoy', '01270707070', 22);

INSERT INTO Author VALUES (1, 'Jonathan Swift' , 80);
INSERT INTO Author VALUES (2, 'Stefano Ceri' , 66);
INSERT INTO Author VALUES (3, 'Humayun Ahmed' , 63);
INSERT INTO Author VALUES (4, 'Rick Riordan' , 57);
INSERT INTO Author VALUES (5, 'Muhammed Zafar Iqbal' , 68);

INSERT INTO Book VALUES (1, 'Gullivers Travels', 'Fantasy', DATE '1726-01-11', 1);
INSERT INTO Book VALUES (2, 'Himu', 'Fiction', DATE '1993-05-21', 3);
INSERT INTO Book VALUES (3, 'Daughter of the Deep', 'Fiction', DATE '2021-10-26', 4);
INSERT INTO Book VALUES (4, 'Dipu number 2', 'Novel', DATE '1996-02-17', 5);
INSERT INTO Book VALUES (5, 'Glina', 'SciFi', DATE '2019-04-20', 5);
INSERT INTO Book VALUES (6, 'Distributed Database', 'Tech', DATE '2008-05-12', 2);

INSERT INTO Borrows VALUES (5, DATE '2021-12-13' , 4);
INSERT INTO Borrows VALUES (6, DATE '2021-10-03' , 6);
INSERT INTO Borrows VALUES (3, DATE '2021-01-15' , 3);
INSERT INTO Borrows VALUES (1, DATE '2021-11-29' , 5);
INSERT INTO Borrows VALUES (6, DATE '2021-11-25' , 7);

SELECT a_age as Author_Age from Author A Inner Join Book B ON A.authorID = B.authorID WHERE B.title = 'Gullivers Travels';

SELECT * FROM 
(SELECT A.a_name as Author_Name from Author A Inner Join Book B ON A.authorID = B.authorID WHERE B.genre = 'Fiction' ORDER BY A.a_age ASC)
WHERE ROWNUM = 1;

SELECT A.a_name as Author_Name from Author A Inner Join Book B ON A.authorID = B.authorID WHERE B.datePublished = TO_DATE('20/Apr/2019','dd/mon/yyyy');

COMMIT;