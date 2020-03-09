CREATE TABLE Gym (
Name Varchar(15),
GymID Varchar(15) NOT NULL,
Phone Varchar(11),
Street Varchar(30),
City Varchar(15),
ProvState Varchar(30),
Postal Varchar(6),
PRIMARY KEY(GymID),
UNIQUE(GymID) );

CREATE TABLE Person (
EmergencyContactPhone Varchar(11) NOT NULL,
PersonGymID Varchar(15) NOT NULL,
Phone Varchar(11),
Street Varchar(30),
City Varchar(15),
ProvState Varchar(30),
Postal Varchar(6),
TFlag INT NOT NULL DEFAULT 0,
MFlag INT NOT NULL DEFAULT 1,
PRIMARY KEY(PersonGymID),
UNIQUE (PersonGymID) );

CREATE TABLE WorksFor(
GymID Varchar(15) NOT NULL,
PersonGymID Varchar(15) NOT NULL,
PRIMARY KEY (GymID , PersonGymID),
UNIQUE(GymID , PersonGymID),
FOREIGN KEY (GymID) REFERENCES Gym(GymID),
FOREIGN KEY (PersonGymID) REFERENCES Person(PersonGymID) );

CREATE TABLE Has (
GymID Varchar(15) NOT NULL,
PersonGymID Varchar(15) NOT NULL,
PRIMARY KEY (GymID , PersonGymID),
UNIQUE (GymID,PersonGymID),
FOREIGN KEY (GymID) REFERENCES Gym(GymID),
FOREIGN KEY (PersonGymID) REFERENCES Person(PersonGymID) );

CREATE TABLE Membership (
PersonGymID Varchar(15) NOT NULL,
RenewalDate DATE NOT NULL,
TrainingRoomAccess BOOLEAN DEFAULT TRUE,
PoolAccess BOOLEAN DEFAULT TRUE,
PricePerMonth FLOAT NOT NULL,
PRIMARY KEY(PersonGymID),
UNIQUE (PersonGymID) );

CREATE TABLE BillingReport (
GymID Varchar(15) NOT NULL,
PersonGymID Varchar(15) NOT NULL,
ReceiptPrice FLOAT,
Date DATE NOT NULL,
PRIMARY KEY(PersonGymID,Date),
FOREIGN KEY(PersonGymID) REFERENCES Person(PersonGymID),
UNIQUE (PersonGymID,Date) );

CREATE TABLE Reservable (
ManufactureNumber Varchar(15) NOT NULL,
Description Varchar(100),
GymID Varchar(15) NOT NULL,
PRIMARY KEY(ManufactureNumber),
UNIQUE (ManufactureNumber) );

CREATE TABLE Machine (
MuscleType Varchar(15),
ManufactureNumber Varchar(15) NOT NULL,
PRIMARY KEY(ManufactureNumber),
FOREIGN KEY(ManufactureNumber) REFERENCES Reservable(ManufactureNumber),
UNIQUE (ManufactureNumber) );

CREATE TABLE Accessory (
AccessoryType Varchar(15),
ManufactureNumber Varchar(15) NOT NULL,
PRIMARY KEY(ManufactureNumber),
FOREIGN KEY(ManufactureNumber) REFERENCES Reservable(ManufactureNumber),
UNIQUE (ManufactureNumber) );

CREATE TABLE Room (
ActivityType Varchar(15),
RoomNumber Varchar(15) NOT NULL,
PRIMARY KEY(RoomNumber),
UNIQUE (RoomNumber) );

CREATE TABLE Session (
SessionID Varchar(15) NOT NULL,
PersonGymID Varchar(15) NOT NULL,
SessionType Varchar(30) DEFAULT 'Generic',
MuscleGroup Varchar(30),
TrainerID Varchar(15) NOT NULL,
PRIMARY KEY(SessionID),
UNIQUE (SessionID) );

CREATE TABLE Reserves (
PersonGymID Varchar(15) NOT NULL,
ManufactureNumber Varchar(15),
RoomNumber Varchar(15),
SessionID Varchar(15),
Date DATE NOT NULL,
StartTime TIME NOT NULL,
EndTime TIME NOT NULL,
WeightRange INT,
PRIMARY KEY(PersonGymID,Date,StartTime),
FOREIGN KEY(ManufactureNumber) REFERENCES Reservable(ManufactureNumber),
FOREIGN KEY(RoomNumber) REFERENCES Room(RoomNumber),
FOREIGN KEY(SessionID) REFERENCES Session(SessionID),
UNIQUE (PersonGymID,Date,StartTime) );

CREATE TABLE Books (
PersonGymID Varchar(15) NOT NULL,
SessionID Varchar(15) NOT NULL,
PRIMARY KEY(PersonGymID,SessionID),
FOREIGN KEY(PersonGymID) REFERENCES Person(PersonGymID),
FOREIGN KEY(SessionID) REFERENCES Session(SessionID),
UNIQUE (PersonGymID,SessionID) );

CREATE TABLE Buys (
MonthlyPayDate DATE NOT NULL,
PersonGymID Varchar(15) NOT NULL,
PRIMARY KEY(MonthlyPayDate,PersonGymID),
FOREIGN KEY(PersonGymID) REFERENCES Membership(PersonGymID),
UNIQUE (PersonGymID) );

