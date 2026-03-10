#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "vivo";
const char* password = "12345678";

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;

void setup_wifi()
{
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
}

void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");

    if (client.connect("ESP32Client"))
    {
      Serial.println("connected");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup()
{
  Serial.begin(115200);

  setup_wifi();

  client.setServer(mqtt_server, 1883);
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }

  client.loop();

  long now = millis();

  if (now - lastMsg > 5000)
  {
    lastMsg = now;

    String data = "{";

data += "\"IP\":\"";
data += WiFi.localIP().toString();
data += "\",";

data += "\"MAC\":\"";
data += WiFi.macAddress();
data += "\",";

data += "\"RSSI\":";
data += String(WiFi.RSSI());
data += ",";

data += "\"Heap\":";
data += String(ESP.getFreeHeap());
data += ",";

data += "\"Uptime\":";
data += String(millis()/1000);

data += "}";

    client.publish("esp32/monitor", data.c_str());

    Serial.println(data);
  }
}