# H-Bridge proof of concept
De motoren heb ik via amazon gekocht. Ik heb de goedkoopste genomen die ik toen zag. De H-brug ben ik gaan kopen in GOTRON in Gent. 
De proof of concept demonstreert dat beide motoren correct functioneren, zowel in snelheid als in richting, via een L293B H-brug.

De test begint met de linker motor en schakelt daarna over naar de rechter motor.
Snelheid en richting:

Voor elke motor draait de code de motor:
- Vooruit: Van traag naar snel, en dan weer van snel naar traag.
- Achteruit: Van traag naar snel, en weer van snel naar traag.
- Doel:
Dit proces toont aan dat de motoren probleemloos werken over het volledige snelheidsbereik in beide richtingen. Problemen met de hardware of software zouden hiermee zichtbaar worden.
