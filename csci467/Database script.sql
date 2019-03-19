
DROP TABLE IF EXISTS QuoteLineItem;
DROP TABLE IF EXISTS SecretNote;
DROP TABLE IF EXISTS Quote;
DROP TABLE IF EXISTS SalesPerson;



CREATE TABLE SalesPerson (
UserID							int NOT NULL AUTO_INCREMENT,
FirstName						char(25),
LastName						char(25),
Password						char(25),
AccumulatedCommission		decimal(9,2),
Address						char(45),
City							char(20),
State							char(14),
PRIMARY KEY					(UserID) );


CREATE TABLE Quote (
QuoteID			int NOT NULL AUTO_INCREMENT,
Price				decimal(10,2),
Sanctioned		ENUM('FALSE','TRUE') NOT NULL DEFAULT 'FALSE',
Email				char(55),
Discount			decimal(10,2),
Status				char(10),
CustomerID		int,
UserID				int,
PRIMARY KEY 		(QuoteID),
FOREIGN KEY		(UserID) REFERENCES SalesPerson(UserID) );


CREATE TABLE QuoteLineItem (
QuoteLineItemID		int NOT NULL AUTO_INCREMENT,
Price					decimal(9,2),
Description			char(255),
QuoteID				int,
PRIMARY KEY 			(QuoteLineItemID),
FOREIGN KEY 			(QuoteID) REFERENCES Quote(QuoteID) );


CREATE TABLE SecretNote (
SecretNoteID		int NOT NULL AUTO_INCREMENT,
Note				char(255),
QuoteID			int,
PRIMARY KEY		(SecretNoteID),
FOREIGN KEY 		(QuoteID) REFERENCES Quote(QuoteID) );



