# DAQ_imu_loadcell
data acquisition system, imu, loadcell, electronic schemee

Bu kodda, collided adlı bir boolean değişken kullanarak çarpışma durumunu kontrol ediyoruz. İlk başta collided değeri false olarak ayarlanır. Ardından, yük hücresinden alınan ağırlık değeri (weight) 0.1 kg'dan büyük olduğunda ve collided değeri henüz true değilken, çarpışma durumunu yakalayıp çarpma anındaki ivme değerlerini (collisionAccX, collisionAccY, collisionAccZ) kaydediyoruz.

Platformun çarpma anındaki ivme değerlerini kullanmak için çarpma anında collisionAccX, collisionAccY ve collisionAccZ değerlerini kullanabilirsiniz. Bu değerleri işlemlerinizde veya kontrol mekanizmanızda kullanabilirsiniz.

Lütfen kodu Arduino'ya yükleyip çalıştırmadan önce, IMU'nun doğru bağlantıları yapıldığından ve HX711 yük hücresinin doğru pinlere bağlı olduğundan emin olun. Ayrıca, yük hücresinin kalibrasyonunu yapmanız gerekebilir.
