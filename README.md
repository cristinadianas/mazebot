# MazeBot

## Introducere

Proiectul MazeBot își propune să exploreze principiile de bază ale roboticii autonome prin construirea unui robot capabil să navigheze în mod independent într-un mediu definit de utilizator. 

## Descriere generală

Proiectul constă în dezvoltarea unui robot autonom capabil să navigheze și să iasă dintr-un labirint desenat pe hârtie / printat. Robotul utilizează o combinație de senzori (pentru detectarea liniilor labirintului), algoritmi de luare a deciziilor și un sistem de control motorizat pentru a se deplasa eficient pe trasee complexe. Robotul este proiectat să identifice traseele, să evite blocajele și să găsească cea mai scurtă cale către ieșirea din labirint.

Robotul este plasat la intrarea în labirintul desenat pe hârtie și, utilizând senzorii, identifică liniile și structura acestuia. După ce colectează informații despre traseu, aplică algoritmi de decizie pentru a găsi cea mai scurtă cale către ieșire. Robotul este capabil să gestioneze situații precum bucle infinite sau dead ends.

## Hardware Design

### Componente folosite (Bill of Materials)

Componentele au fost achizitionate de aici: https://roboromania.ro/produs/robot-kit-2wd-urmarire-linie-modul-cu-5-senzori-line-following/

- Placă de dezvoltare UNO R3 cu cablu USB: https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf
- Modul senzor urmărire linie cu 5x TCRT5000: https://www.alldatasheet.com/datasheet-pdf/pdf/26406/VISHAY/TCRT5000.html
- Modul driver motoare L298N: https://www.alldatasheet.com/datasheet-pdf/pdf/22440/STMICROELECTRONICS/L298N.html
- Kit șasiu robot 2WD
- Suport baterii 4AA
- 4 baterii AA 1.5 V
- 6 cabluri tată-tată
- 9 cabluri mamă-tată
- 4 piloni metal 15 mm
- 4 piulițe
- 4 șuruburi 5 mm
- 4 șuruburi 40 mm
- bandă adezivă neagră (pentru formarea traseului)
- bandă dublu adezivă

### Diagrama bloc
![Blank diagram](https://github.com/user-attachments/assets/2f516868-3e43-42aa-a71d-d376461ace93)

### Schema electrică
![Smooth Rottis-Krunk](https://github.com/user-attachments/assets/0de85492-5424-4430-bd07-ee84b0136876)
<img width="664" alt="Screenshot 2025-01-16 at 9 35 29 AM" src="https://github.com/user-attachments/assets/8d78feeb-531e-4537-a2a7-93a4cc4af1f4" />

### Pini Arduino Uno
- 5 V - conectează arduino la motor și conectează senzorii la power supply
- GND - ground pentru senzori și pentru motor
- D8 - conectează senzorii
- D9 - conectează senzorii
- D10 - conectează senzorii
- D11 - conectează senzorii
- D12 - conectează senzorii
- D3 - conectat la motor (enA)
- D2 - conectat la motor (in1)
- D4 - conectat la motor (in2)
- D6 - conectat la motor (enB)
- D5 - conectat la motor (in3)
- D7 - conectat la motor (in4)

### Pini senzori IR
- GND - conectat la ground
- Vcc - conectat la power supply (arduino 5 V)
- S1 - conectează senzorul la arduino (D8)
- S2 - conectează senzorul la arduino (D9)
- S3 - conectează senzorul la arduino (D10)
- S4 - conectează senzorul la arduino (D11)
- S5 - conectează senzorul la arduino (D12)

### Pini Motor
- 12 V - conectat la baterie
- GND - conectat la ground
- 5 V - conectat la arduino
- OUT1 - conectat la gear motor
- OUT2 - conectat la gear motor
- OUT3 - conectat la gear motor
- OUT4 - conectat la gear motor
- enA - conectat la arduino (D3)
- enB - conectat la arduino (D6)
- in1 - conectat la arduino (D2)
- in2 - conectat la arduino (D4)
- in3 - conectat la arduino (D5)
- in4 - conectat la arduino (D7)

### Alte specificații
Cei 5 senzori IR au rolul de a detecta linia neagră de pe suprafața albă.
Motorul are rolul de a cotrola roțile.
Power supply-ul folosit este de 6 V (din maximul de 12 V pe care îl permite motorul)
Toate conexiunile au fost realizate folosind GPIO.

## Software Design

## Rezultate obținute

## Concluzii

## Jurnal

## Bibliografie / Resurse

Acest proiect este inspirat de robotul Ozobot (https://ozobot.com/), care, pe lângă alte funcționalități, este un line follower. În acest proiect voi replica independent această caracteristică și îi voi adăuga o funcționalitate specifică, aceea de a rezolva un labirint.
