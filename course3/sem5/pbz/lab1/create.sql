IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='suppliers' AND xtype='U')
BEGIN
    CREATE TABLE suppliers
    (
        id INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
        name VARCHAR(50) NOT NULL, 
        status INT NOT NULL,
        city VARCHAR(50) NOT NULL
    );
END;

IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='details' AND xtype='U')
BEGIN
    CREATE TABLE details
    (
        id INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
        name VARCHAR(50) NOT NULL, 
        color VARCHAR(50) NOT NULL,
        size INT NOT NULL,
        city VARCHAR(50) NOT NULL
    );
END;

IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='projects' AND xtype='U')
BEGIN
    CREATE TABLE projects
    (
        id INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
        name VARCHAR(50) NOT NULL, 
        city VARCHAR(50) NOT NULL
    );
END;

IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='counts' AND xtype='U')
BEGIN
    CREATE TABLE counts
    (
        supplier_id INT NOT NULL,
        details_id INT NOT NULL,
        project_id INT NOT NULL,
        count INT NOT NULL,
        FOREIGN KEY (supplier_id) REFERENCES suppliers(id),
        FOREIGN KEY (details_id) REFERENCES details(id),
        FOREIGN KEY (project_id) REFERENCES projects(id)
    );
END;

INSERT INTO suppliers (name, status, city) VALUES 
('Петров', 20, 'Москва'), 
('Синицин', 10, 'Таллинн'),
('Федоров', 30, 'Таллинн'),
('Чаянов', 20, 'Минск'),
('Крюков', 30, 'Киев');

INSERT INTO details (name, color, size, city) VALUES
('Болт', 'Красный', 12, 'Москва'),
('Гайка', 'Зеленая', 17, 'Минск'),
('Диск', 'Черный', 17, 'Вильнюс'),
('Диск', 'Черный', 14, 'Москва'),
('Корпус', 'Красный', 12, 'Минск'),
('Крыши', 'Красный', 19, 'Москва');

INSERT INTO projects (name, city) VALUES
('ИПР1', 'Минск'), 
('ИПР2', 'Таллинн'), 
('ИПР3', 'Псков'), 
('ИПР4', 'Псков'), 
('ИПР5', 'Москва'), 
('ИПР6', 'Саратов'), 
('ИПР7', 'Москва');

INSERT INTO counts(supplier_id, details_id, project_id, count) VALUES
(1, 1, 1, 200),
(1, 1, 2, 700),
(2, 4, 1, 400),
(2, 2, 2, 200),
(2, 3, 3, 200),
(2, 3, 4, 500),
(2, 3, 5, 600),
(2, 3, 6, 400),
(2, 3, 7, 800),
(2, 5, 2, 100),
(3, 3, 1, 200),
(3, 4, 2, 500),
(4, 6, 3, 300),
(4, 6, 7, 300),
(5, 2, 2, 200),
(5, 2, 4, 100),
(5, 5, 5, 500),
(5, 5, 7, 100),
(5, 6, 2, 200),
(5, 1, 2, 100),
(5, 3, 4, 200),
(5, 4, 4, 800),
(5, 4, 4, 400),
(5, 6, 4, 500);

--номер 1(24)
--получить номера поставщиков со статусом, меньшим чем у поставщика п1

select id 
from suppliers
where status < (select status from suppliers where id = 1);


--номер 2(19)
--получить имена проектов, обеспечиваемых поставщиком П1. 

select pr.name from projects pr
join counts c on c.project_id = pr.id
where c.supplier_id = 1

--номер 3(27)
--получить номера поставщиков, поставляющих деталь д1 для некоторого проекта, в кол-ве, 
--большем среднего кол-ва деталей д1 в поставках этого проекта
SELECT DISTINCT c.supplier_id
FROM counts c
JOIN details d ON c.details_id = d.id
WHERE d.id = 1
AND c.count > (
    SELECT AVG(c2.count)
    FROM counts c2
    WHERE c2.project_id = c.project_id
    AND c2.details_id = c.details_id
);


--номер 4(6)
--получить все такие тройки "номера поставщиков-номера деталей-номера проектов", для которых выводимый поставщик, 
--деталь и проект размещены в одном городе
select c.supplier_id, c.details_id, c.project_id from counts c
join suppliers s on c.supplier_id = s.id
join details d on c.supplier_id = d.id
join projects pr on c.supplier_id = pr.id
where s.city = d.city and d.city = pr.city;


--номер 5(1)
--получить полную инфу обо всех проектах
select * from projects p
join counts c on c.project_id = p.id



--номер 6(9)
--получить номера делатей, поставляемый поставщиком в Лондоне
select c.details_id from counts c
join suppliers s on c.supplier_id = s.id
where s.city = 'Лондон'

--номер 7(13)
--Получить номера проектов, обеспечиваемых по крайней мере одним поставщиком не из того же города.
select distinct c.project_id from counts c
join suppliers s on c.supplier_id = s.id
join projects p on c.project_id = p.id
where s.city <> p.city;


--номер 8(35)
--Получить пары "номер поставщика-номер детали", такие, что данный поставщик не поставляет данную деталь. 
select s.id, d.id 
from suppliers s 
cross join details d 
where not exists (
    select 1 
    from counts c 
    where c.supplier_id = s.id and c.details_id = d.id
);

--номер 9(18)
--Получить номера деталей, поставляемых для некоторого проекта со средним количеством больше 320. 
select details_id from counts
group by details_id
having avg(count) > 320;

--номер 10(33)
--Получить все города, в которых расположен по крайней мере один поставщик, одна деталь или один проект. 
select city from suppliers
UNION
select city from details
UNION
select city from projects

--use lab

