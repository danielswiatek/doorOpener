# Vorbereitung

## Treiber installieren

Damit Du deinen ESP anschließen kannst musst Du noch Treiber installieren. Getestet habe ich es nur unter Mac. Es gibt jedoch auch Treiber für Windows. https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads

## Arduino IDE

Zum Programmieren verwenden wir die IDE von Arduino. Es gibt eine neue (Future Version) die ist cooler und basiert auf VSCODE. https://www.arduino.cc/en/software#future-version-of-the-arduino-ide

## Board Library hinzufügen

Diesen Punkt kannst Du ggf. überspringen. Versuche mal den nächsten Punkt. Sollte dein Gerät nicht auftauchen, dann musst Du mit diesem Schritt fortfahren. 

Wenn Du die IDE geöffnet hast kannst Du unter File (Mac) auf Einstellungen gehen und unter "Additional boards manager URls" folgende Urls hinzufügen: 

- https://arduino.esp8266.com/stable/package_esp8266com_index.json
- https://dl.espressif.com/dl/package_esp32_index.json

du kannst diese mit "," trennen. Anschließen kannst Du in der vertikalen Menüleiste (nur in der Future Version) das zweite Symbol von Oben anklicken und nach deinem ESP suchen. Für den ESP32 z.B. "esp32" eingeben und installieren.

## ESP anschließen und testen

Nun kannst Du den ESP anschließen und im Dropdown (oben in der Leiste) auf "Select Board and Port" klicken. 

Unter MacOS gibt es ein Problem weshalb Du ein Mikro USB zu USB B Kabel unter umständen nicht direkt mit einem USB-C Dongle betreiben kannst. Das Gerät erkennt den esp dann nicht. Für den Fall musst Du ein USB 2.0 Kabel oder einen Dongle dazwischen schalten. Der Fall tritt unregelmäßig auf. 