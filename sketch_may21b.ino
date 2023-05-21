#include <MPU6050_tockn.h>
#include <Wire.h>
#include <HX711.h>

MPU6050 mpu6050(Wire);
HX711 scale;

// Yük hücresinin bağlı olduğu pinler
const int LOADCELL_DOUT_PIN = 5;
const int LOADCELL_SCK_PIN = 6;

bool collided = false;  // Çarpışma durumu kontrolü
float collisionAccX, collisionAccY, collisionAccZ;  // Çarpma anındaki ivme değerleri

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(1); // Varsayılan olarak 1 kullanıyoruz
  scale.tare();

  Serial.print("\n");
}

void loop() {
  mpu6050.update();

  // IMU verilerini seri port üzerinden yazdır
  Serial.print("GyroX: "); Serial.print(mpu6050.getAngleX());
  Serial.print("\tGyroY: "); Serial.print(mpu6050.getAngleY());
  Serial.print("\tGyroZ: "); Serial.println(mpu6050.getAngleZ());

  // Yük hücresinden ağırlık değerini al
  float weight = scale.get_units();

  // Ağırlığı seri port üzerinden yazdır
  Serial.print("Ağırlık: ");
  Serial.print(weight);
  Serial.println(" kg");

  // Platformun aşağı düşme anındaki ivme verisini al
  if (!collided && weight > 0.1) {
    collided = true;
    collisionAccX = mpu6050.getAccX();
    collisionAccY = mpu6050.getAccY();
    collisionAccZ = mpu6050.getAccZ();
    Serial.print("Çarpışma Anı - AccX: ");
    Serial.print(collisionAccX);
    Serial.print("\tAccY: ");
    Serial.print(collisionAccY);
    Serial.print("\tAccZ: ");
    Serial.println(collisionAccZ);
  }

  delay(500);
}
