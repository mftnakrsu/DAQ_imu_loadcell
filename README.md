# DAQ_imu_loadcell
data acquisition system, imu, loadcell, electronic schemee

Bu kodda, collided adlı bir boolean değişken kullanarak çarpışma durumunu kontrol ediyoruz. İlk başta collided değeri false olarak ayarlanır. Ardından, yük hücresinden alınan ağırlık değeri (weight) 0.1 kg'dan büyük olduğunda ve collided değeri henüz true değilken, çarpışma durumunu yakalayıp çarpma anındaki ivme değerlerini (collisionAccX, collisionAccY, collisionAccZ) kaydediyoruz.

Platformun çarpma anındaki ivme değerlerini kullanmak için çarpma anında collisionAccX, collisionAccY ve collisionAccZ değerlerini kullanabilirsiniz. Bu değerleri işlemlerinizde veya kontrol mekanizmanızda kullanabilirsiniz.

Lütfen kodu Arduino'ya yükleyip çalıştırmadan önce, IMU'nun doğru bağlantıları yapıldığından ve HX711 yük hücresinin doğru pinlere bağlı olduğundan emin olun. Ayrıca, yük hücresinin kalibrasyonunu yapmanız gerekebilir.

https://www.electronicwings.com/arduino/mpu6050-interfacing-with-arduino-uno  
https://drive.google.com/drive/folders/1Wd2kc2rLaQUd_IHuBAPNYdlUePc5RBZ7  
![Şema](https://github.com/mftnakrsu/DAQ_imu_loadcell/assets/57320216/d57a3b64-3d4e-4350-9520-1ac54418afe1)    
![8001c16306951c598a3815baa764ccf69f1f7019](https://github.com/mftnakrsu/DAQ_imu_loadcell/assets/57320216/1c1e3183-4f05-47bd-b538-347af7c0aeb3)

![MPU6050-Pinout](https://github.com/mftnakrsu/DAQ_imu_loadcell/assets/57320216/85831991-e086-4873-8ebf-6c90f1abe885)
