# MazeBot

## Introducere

Proiectul MazeBot își propune să exploreze principiile de bază ale roboticii autonome prin construirea unui robot capabil să navigheze în mod independent într-un mediu definit de utilizator. 

## Descriere generală

Proiectul constă în dezvoltarea unui robot autonom capabil să navigheze și să iasă dintr-un labirint desenat pe hârtie / printat. Robotul utilizează o combinație de senzori (pentru detectarea liniilor labirintului) și un sistem de control motorizat pentru a se deplasa eficient pe trasee complexe.

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
- carton
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

Robotul folosește senzori pentru a detecta o linie neagră de pe suprafața pe care se află și a o urmări. Din cei 5 senzori, au fost folosiți doar 2 (far left și far right) deoarece au fost suficienți pentru realizarea proiectului.

Am definit toți pinii cu care urmează să lucrez.
Funcția setup() inițializează pinii senzorilor drept INPUT pentru a putea primi informații legate de suprafața pe care se află, iar pinii motorului au fost setați drept OUTPUT, ei controlând deplasarea robotului. Totodată, a fost setată rata de transfer pentru inițializarea interfeței serial.
În funcția loop() este realizat programul care verifică în nod continuu starea senzorilor și, în funcție de aceasta, ajustează direcția în care merge (se rotește). Valorile senzorilor și decizia luată de program (de a merge la stânga, la dreapta, înainte sau de a se opri) este afișată pe interfața serial.
Funcția rotateMotor() realizează controlul direcției în care se deplasează robotul.

Senzorii IR au fost calibrați manual, folosind informațiile din interfața serial.

### Utilizarea funcționalităților din laborator
* Laborator 0: GPIO.
Conexiunile dintre placa arduino și senzori și dintre placa arduino și motor au fost realizate folosind GPIO.
* Laborator 1: USART.
Pentru a testa funcționalitatea programului, au fost folosite mesaje afișate pe interfața serială.
* Laborator 3: PWM.
Pentru a controla motorul, au fost folosiți pini cu PWM (pulse width modulation). Acest lucru permite controlarea vitezei cu care se rotesc roțile. În acest sens, pinii 3 și 6 de pe arduino (care permit PWM) au fost conectați la pinii enA și enB ai motorului.

## Rezultate obținute
![WhatsApp Image 2025-01-16 at 11 29 01 AM](https://github.com/user-attachments/assets/cac3e26d-53f0-4bf0-a5c7-a747c2c211d2)
![WhatsApp Image 2025-01-16 at 11 29 00 AM](https://github.com/user-attachments/assets/44faefc9-fd2a-42eb-84cb-45be310e9667)
![WhatsApp Image 2025-01-16 at 11 29 00 AM (1)](https://github.com/user-attachments/assets/8d6d16a4-b704-4bcd-b7b6-c77a461db4e2)
![WhatsApp Image 2025-01-16 at 11 29 01 AM (1)](https://github.com/user-attachments/assets/1d4be59a-020c-4b2e-aa1f-fb003c50498c)
![WhatsApp Image 2025-01-16 at 11 29 01 AM (2)](https://github.com/user-attachments/assets/6cd1b353-62ae-465b-8bcf-6aec04a6734e)
![WhatsApp Image 2025-01-16 at 11 29 01 AM (3)](https://github.com/user-attachments/assets/83184172-f9c4-4a37-bef7-d228b97216e9)
![WhatsApp Image 2025-01-16 at 11 29 01 AM (4)](https://github.com/user-attachments/assets/ea751542-3815-4cf3-87b4-490ca2f6c4ad)
![WhatsApp Image 2025-01-16 at 11 29 01 AM (5)](https://github.com/user-attachments/assets/58214a01-724e-4982-bb7e-468fd329a215)

## Concluzii

Proiectul a fost interesant de realizat, atât complicat cât și plăcut. Realizând acest proiect mi-am dezvoltat cunoștințele de robotică și de electronică.

## Bibliografie / Resurse

Acest proiect este inspirat de robotul Ozobot (https://ozobot.com/), care, pe lângă alte funcționalități, este un line follower. În acest proiect voi replica independent această caracteristică.
https://www.youtube.com/watch?v=GPVC84D5ULw&list=LL&index=2
