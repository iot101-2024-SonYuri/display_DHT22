#include <Arduino.h>
#include <DHTesp.h>

DHTesp dht;
int interval = 2000;
unsigned long lastDHTReadMillis = 0;
float humidity = 0;
float temperature = 0;

void setup() {
    Serial.begin(115200);  // 기본 시리얼 포트를 UART0로 설정
    dht.setup(17, DHTesp::DHT22); // DHT 센서를 GPIO 17에 연결
    delay(1000);

    Serial.println(); 
    Serial.println("Humidity (%)\tTemperature (C)");
}


void readDHT22() {
    unsigned long currentMillis = millis();

    if(currentMillis - lastDHTReadMillis >= interval) {
        lastDHTReadMillis = currentMillis;

        humidity = dht.getHumidity();  // 습도 읽기
        temperature = dht.getTemperature();  // 온도 읽기
    }
}

void loop() {
    readDHT22();
    Serial.printf("%.1f\t %.1f\n", temperature, humidity);  // Serial로 출력
    delay(1000);
}
