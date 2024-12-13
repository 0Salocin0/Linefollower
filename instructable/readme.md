# Instructable
Instructable: 

o) Locaties van onderdelen & montage van de robot:
-> In de bijlage voeg ik mijn "carrosserie" toe die geprint is met SolidWorks, zodat je een idee krijgt van wat ik heb gebruikt. Ik heb een klein breadboard aan de bovenkant van de carrosserie bevestigd. De batterijen heb ik aan de binnenkant vastgemaakt om het gewicht beter te verdelen en te voorkomen dat alles volledig achteraan zit. De motoren heb ik met secondelijm aan de onderkant bevestigd, en de sensor heb ik aan de voorkant aan de onderzijde geplaatst, zodat deze het parcours kan detecteren. Daarnaast heb ik een knop toegevoegd als derde punt, zodat de auto soepel over de grond kan glijden.

o) Installatie van software:
-> Ik heb de code via een USB-C-kabel overgezet naar de ESP32. Om de variabelen Kp, Kd en Ki aan te passen, verbind ik mijn smartphone met de ESP32 en stuur ik de naam van de variabele samen met de nieuwe waarde. Bijvoorbeeld: Kp 75.

Technische documentatie: 
o) Datasheets, elektronisch schema:
-> Zijn in een map. Ik heb de elektronisch schema's getekend met mijn tablet. Ik heb geen software gebruikt om die te tekenen. 

o) Alle softwarebestanden:
-> Zit in een map (arduino -> project -> batmobile)

Afwerking: 
Ik ben begonnen met het testen van de motoren. Hiervoor heb ik een code geschreven waarmee elke motor vooruit en achteruit draait, met een toenemende en afnemende snelheid. Deze code kun je terugvinden bij de Proof of Concepts. Toen dit werkte, heb ik een nieuwe code geschreven om ervoor te zorgen dat ik de waarden van alle 8 sensoren op de QTR-8A kon uitlezen. Ook deze code staat bij de Proof of Concepts.

Nadat dit gelukt was, liet ik de carrosserie printen en heb ik alle onderdelen samengevoegd. Dit proces wordt beschreven bij Locaties van de onderdelen & montage van de robot. Vervolgens heb ik de benodigde code aangepast om de auto te laten rijden en deze geüpload naar de ESP32.


### stap 1
bestel alle componenten uit de bill of materials  
