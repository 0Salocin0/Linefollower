# Sensoren proof of concept
Ik een ESP32 gekocht op amazon en de QTR-8 sensor op polulu. 
De proof of concept valideert de correcte werking van de QTR-8A lijnsensor, die acht individuele sensoren gebruikt om lichtintensiteit te meten.

Data-invoer:
De code leest de waarden van alle 8 ingangen van de sensor.
De ruwe sensorwaarden worden gemapt zodat zwarte oppervlakken worden weergegeven met hogere waarden, terwijl lichtere oppervlakken lagere waarden tonen.
Doel:

Dit toont aan dat de QTR-8A sensor nauwkeurig onderscheid maakt tussen zwart en wit, wat essentieel is voor lijnvolging. Eventuele afwijkingen in sensorwaarden worden zichtbaar tijdens de test.
