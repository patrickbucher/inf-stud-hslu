/*DROP DATABASE uni;*/

create database uni;

use uni;

CREATE TABLE studenten
       (MatrNr         INTEGER,
        Name           VARCHAR(30),
        Semester       INTEGER
        );

CREATE TABLE professoren
       (PersNr         INTEGER,
        Name           VARCHAR(30),
        Rang           CHAR(2),
        Raum           INTEGER
        );

CREATE TABLE assistenten
       (PersNr         INTEGER,
        Name           VARCHAR(30),
        Fachgebiet     VARCHAR(30),
        Boss           INTEGER
        );

CREATE TABLE vorlesungen
       (VorlNr         INTEGER,
        Titel          VARCHAR(30),
        SWS            INTEGER,
        gelesenVon     INTEGER
        );

CREATE TABLE hoeren
       (MatrNr         INTEGER,
        VorlNr         INTEGER
        );

CREATE TABLE voraussetzen
       (Vorgänger     INTEGER,
        Nachfolger     INTEGER
        );

CREATE TABLE pruefen
       (MatrNr         INTEGER,
        VorlNr         INTEGER,
        PersNr         INTEGER,
        Note           NUMERIC
        );

INSERT INTO studenten(MatrNr, Name, Semester) 
VALUES (24002, 'Xenokrates', 18); 
 
INSERT INTO studenten(MatrNr, Name, Semester) 
VALUES (25403, 'Jonas', 12); 
 
INSERT INTO studenten(MatrNr, Name, Semester) 
VALUES (26120, 'Fichte', 10); 

INSERT INTO studenten(MatrNr, Name, Semester) 
VALUES (26830, 'Aristoxenos', 8); 
 
INSERT INTO studenten(MatrNr, Name, Semester) 
VALUES (27550, 'Schopenhauer', 6); 

INSERT INTO studenten(MatrNr, Name, Semester) 
VALUES (28106, 'Carnap', 3); 
 
INSERT INTO studenten(MatrNr, Name, Semester) 
VALUES (29120, 'Theophrastos', 2); 
 
INSERT INTO studenten(MatrNr, Name, Semester) 
VALUES (29555, 'Feuerbach', 2); 
 

INSERT INTO professoren(PersNr, Name, Rang, Raum) 
VALUES (2125, 'Sokrates', 'C4', 226); 

INSERT INTO professoren(PersNr, Name, Rang, Raum) 
VALUES (2126, 'Russel', 'C4', 232);  
 
INSERT INTO professoren(PersNr, Name, Rang, Raum) 
VALUES (2127, 'Kopernikus', 'C3', 310); 
 
INSERT INTO professoren(PersNr, Name, Rang, Raum) 
VALUES (2133, 'Popper', 'C3', 052); 
 
INSERT INTO professoren(PersNr, Name, Rang, Raum) 
VALUES (2134, 'Augustinus', 'C3', 309); 
 
INSERT INTO professoren(PersNr, Name, Rang, Raum) 
VALUES (2136, 'Curie', 'C4', 036); 
 
INSERT INTO professoren(PersNr, Name, Rang, Raum) 
VALUES (2137, 'Kant', 'C4', 007); 
 
 
 
INSERT INTO assistenten(PersNr, Name, Fachgebiet, Boss) 
VALUES (3002, 'Platon', 'Ideenlehre', 2125); 
 
INSERT INTO assistenten(PersNr, Name, Fachgebiet, Boss) 
VALUES (3003, 'Aristoteles', 'Syllogistik', 2125); 
 
INSERT INTO assistenten(PersNr, Name, Fachgebiet, Boss) 
VALUES (3004, 'Wittgenstein', 'Sprachtheorie', 2126); 
 
INSERT INTO assistenten(PersNr, Name, Fachgebiet, Boss) 
VALUES (3005, 'Rhetikus', 'Planetenbewegung', 2127); 
 
INSERT INTO assistenten(PersNr, Name, Fachgebiet, Boss) 
VALUES (3006, 'Newton', 'Keplersche Gesetze', 2127); 
 
INSERT INTO assistenten(PersNr, Name, Fachgebiet, Boss) 
VALUES (3007, 'Spinoza', 'Gott und Natur', 2134); 


 
INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5001, 'Grundzuege', 4, 2137);

INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5041, 'Ethik', 4, 2125);
 
INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5043, 'Erkenntnistheorie', 3, 2126);
 
INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5049, 'Maeeutik', 2, 2125);
 
INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (4052, 'Logik', 4, 2125);
 
INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5052, 'Wissenschaftstheorie', 3, 2126); 
 
INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5216, 'Bioethik', 2, 2126); 
 
INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5259, 'Der Wiener Kreis', 2, 2133); 
 
INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5022, 'Glaube und Wissen', 2, 2134); 
 
INSERT INTO vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (4630, 'Die 3 Kritiken', 4, 2137); 


 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (26120, 5001); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (27550, 5001); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (27550, 4052); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (28106, 5041); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (28106, 5052); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (28106, 5216); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (28106, 5259); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29120, 5001); 

INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29120, 5041); 

INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29120, 5049); 

INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29555, 5022); 

INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (25403, 5022);  
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29555, 5001);  
 
 
 
INSERT INTO voraussetzen(Vorgänger, Nachfolger) 
VALUES (5001, 5041); 
 
INSERT INTO voraussetzen(Vorgänger, Nachfolger) 
VALUES (5001, 5043); 
 
INSERT INTO voraussetzen(Vorgänger, Nachfolger) 
VALUES (5001, 5049); 
 
INSERT INTO voraussetzen(Vorgänger, Nachfolger) 
VALUES (5041, 5216);  

INSERT INTO voraussetzen(Vorgänger, Nachfolger) 
VALUES (5043, 5052);  

INSERT INTO voraussetzen(Vorgänger, Nachfolger) 
VALUES (5041, 5052); 
 
INSERT INTO voraussetzen(Vorgänger, Nachfolger) 
VALUES (5052, 5259); 
 


INSERT INTO pruefen(MatrNr, VorlNr, PersNr, Note) 
VALUES (28106, 5001, 2126, 1.0);

INSERT INTO pruefen(MatrNr, VorlNr, PersNr, Note) 
VALUES (25403, 5041, 2125, 2.0);

INSERT INTO pruefen(MatrNr, VorlNr, PersNr, Note) 
VALUES (27550, 4630, 2137, 2.0);

commit;
