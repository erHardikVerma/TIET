--Pasenger Table
CREATE TABLE passenger (
  p_id int PRIMARY KEY,
  p_fname varchar(20),
  p_lname varchar(20),
  email varchar(20) UNIQUE,
  p_gender varchar(1),
  p_age int CHECK (p_age >= 18) )

insert into passenger values(1,'Hardik','Verma','hardik@gmail.com','M',20)
insert into passenger values(2,'Sanyam','Sood','sanyam@gmail.com','M',20)
insert into passenger values(3,'Namit','Nayyar','namit@gmail.com','M',19)

select * from passengers

--Train Table
CREATE TABLE train (
  t_no int PRIMARY KEY,
  t_name varchar(50),
  source varchar(20),
  destination varchar(20),
  start_time timestamp,
  avail_seats int CHECK (avail_seats > 0),
  total_seats int 
)


INSERT INTO train VALUES (1, 'Shatabdi Express', 'Ludhiana', 'Delhi', 
       to_timestamp('2023-05-09 14:30:00', 'YYYY-MM-DD HH24:MI:SS'), 450, 500);
INSERT INTO train VALUES (2, 'Duronto Express', 'Patial', 'Ambala', 
       to_timestamp('2023-05-010 08:30:00', 'YYYY-MM-DD HH24:MI:SS'), 519, 576);
INSERT INTO train VALUES (3, 'Vande Bharat', 'Mumbai', 'Delhi', 
       to_timestamp('2023-05-14 17:30:00', 'YYYY-MM-DD HH24:MI:SS'), 1072, 1128);



--Ticket Table
CREATE TABLE ticket (
  pnr_no int PRIMARY KEY,
  seat_no varchar(15) NOT NULL,
  p_id int REFERENCES passenger(p_id),
  t_id int REFERENCES train(t_id)
)

INSERT INTO ticket VALUES (1001, '1NA005043W', 1, 3);
INSERT INTO ticket VALUES (1002, '1A001057NW', 2, 1);
INSERT INTO ticket VALUES (1003, '2A003017W', 3, 2);

--Station Table
CREATE TABLE station (
  st_no int PRIMARY KEY,
  st_name varchar(20) )

insert into station values(194701, 'Delhi')
insert into station values(194702, 'Mumbai')
insert into station values(194791, 'Ludhiana')
insert into station values(194711, 'Patiala')

--Schedule
CREATE TABLE schedule (
  Start_time varchar(10),
  End_time varchar(10),
  no_haults int,
  t_no int REFERENCES train(t_no),
  st_no int REFERENCES station(st_no)
)

INSERT INTO schedule VALUES ('14:00', '20:00', 0, 1, 194791);
INSERT INTO schedule VALUES ('16:30', '18:30', 0, 2, 194711);
INSERT INTO schedule VALUES ('09:15', '11:45', 5, 3,194701);
 
 --multivalued Phone Number Table 
 CREATE TABLE phone_numbers (
  phone_number VARCHAR2(20) NOT NULL,
  p_id INT REFERENCES passenger(p_id)
);
INSERT INTO phone_numbers VALUES ('9501798568', 1);
INSERT INTO phone_numbers VALUES ('8725991949', 2);
INSERT INTO phone_numbers VALUES ('8437931762', 3);
INSERT INTO phone_numbers VALUES ('8102103831', 3);
INSERT INTO phone_numbers VALUES ('9102283044', 1);

select * from phone_numbers

--Triggers
--1) Trigger to update the available seats in the Train table after a new ticket is booked:
CREATE TRIGGER update_avial_seats
AFTER INSERT ON ticket
FOR EACH ROW
UPDATE train
SET avial_seats = avial_seats - 1
WHERE t_no = NEW.t_id;

--2) Trigger to prevent inserting a new Passenger if the email or phone number already exists in the database:
CREATE TRIGGER check_duplicate_contact_info
BEFORE INSERT ON passenger
FOR EACH ROW
BEGIN
  IF (EXISTS (SELECT 1 FROM passenger WHERE email = NEW.email OR ph_no = NEW.ph_no)) THEN
    SIGNAL SQLSTATE '45000'
    SET MESSAGE_TEXT = 'Email or phone number already exists';
  END IF;
END;

--3) Trigger to prevent inserting a new Ticket if the specified seat number is already booked:
CREATE TRIGGER check_duplicate_seat_number
BEFORE INSERT ON ticket
FOR EACH ROW
BEGIN
  IF (EXISTS (SELECT 1 FROM ticket WHERE seat_no = NEW.seat_no AND t_id = NEW.t_id)) THEN
    SIGNAL SQLSTATE '45000'
    SET MESSAGE_TEXT = 'Seat already booked';
  END IF;
END;

--4) Trigger to update the available seats in the Train table after a Ticket is canceled:
CREATE TRIGGER update_avial_seats_on_delete
AFTER DELETE ON ticket
FOR EACH ROW
UPDATE train
SET avial_seats = avial_seats + 1
WHERE t_no = OLD.t_id;


--Procedures
--1) Procedure to get the list of Passengers with their booked Tickets for a specific Train:
CREATE PROCEDURE get_passengers_with_tickets(
  IN t_no int
)
BEGIN
  SELECT p.p_id, p.p_fname, p.p_lname, p.email, p.ph_no, p.p_gender, p.p_age, t.pnr_no, t.t_amount, t.t_date, t.str_time, t.seat_no
  FROM passenger p
  JOIN ticket t ON p.p_id = t.p_id
  WHERE t.t_id = t_no;
END;

--2) Procedure to get the number of available seats for a specific Train:
CREATE PROCEDURE get_available_seats(
  IN t_no int,
  OUT avial_seats int
)
BEGIN
  SELECT avial_seats INTO avial_seats FROM train WHERE t_no = t_no;
END;
