//------------------------SETUP WIFI-----------------------------
void setup_wifi() {
  // Conexión WIFI
  WiFi.mode(WIFI_STA); //para que no inicie el SoftAP en el modo normal
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED and contconexion < 50) { //Cuenta hasta 50 si no se puede conectar lo cancela
    ++contconexion;
    buscando();
    delay(250);
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
  }
  if (contconexion < 50) {
    conectado();
    res();
    Serial.println("WiFi conectado");
    Serial.println(WiFi.localIP());
    digitalWrite(13, HIGH);
  }
  else {

    m_ERROR();
    Serial.println("");
    Serial.println("Error de conexion");
    digitalWrite(13, LOW);
    int cont = 0;
    while (1) {
      if (digitalRead(35) == 0) {
        ESP.restart();
      }
      if (cont>12){
        break;
      }

      cont++;
      delay(500);
    }
    ESP.restart();
  }
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//---------------------------ESCANEAR----------------------------
void escanear() {
  int n = WiFi.scanNetworks(); //devuelve el número de redes encontradas
  Serial.println("escaneo terminado");
  if (n == 0) { //si no encuentra ninguna red
    Serial.println("no se encontraron redes");
    mensaje = "no se encontraron redes";
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    // tft.print(n);
    tft.println(mensaje);
    mensaje = "";

  }
  else
  {
    mensaje = " redes encontradas";
    Serial.print(n);
    Serial.println(" redes encontradas");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    tft.print(n);
    tft.println(mensaje);
    mensaje = "";

    for (int i = 0; i < n; ++i)
    {
      // agrega al STRING "mensaje" la información de las redes encontradas
      mensaje = (mensaje) + "<p>" + String(i + 1) + ": " + WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ") Ch: " + WiFi.channel(i) + " Enc: " + WiFi.encryptionType(i) + " </p>\r\n";
      //WiFi.encryptionType 5:WEP 2:WPA/PSK 4:WPA2/PSK 7:open network 8:WPA/WPA2/PSK
      // Clear screen
      delay(10);
    }
    String me = mensaje;
    me.replace("</p>", "");
    me.replace("<p>", "");
    tft.println(me);
    Serial.println(mensaje);
    paginaconf();
  }
}
