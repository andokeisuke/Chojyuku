//角加速度データをパブリッシュ(2020/02/23成功)
//使用センサMPU9250
//http://akiracing.com/2018/02/04/how_to_use_mpu9250/
//MPU9250
#include <Wire.h>
//ROS
#include <ros.h>
#include <std_msgs/Float64.h>

//定数
//main
#define MAIN_FREQUENCY 10 //[Hz]
//MPU9250
#define MPU9250_ADDRESS 0x68//I2CでのMPU9250のスレーブアドレス
#define PWR_MGMT_1 0x6b//電源管理のアドレス，スリープモード解除用
#define GYRO_CONFIG 0x1b//ジャイロセンサ設定用のアドレス
#define GYRO_FS_SEL_250DPS 0x00//ジャイロセンサのレンジ(250DPS)
#define GYRO_FS_SEL_500DPS 0x08//ジャイロセンサのレンジ(500DPS)
#define GYRO_FS_SEL_1000DPS 0x10//ジャイロセンサのレンジ(1000DPS)
#define GYRO_FS_SEL_2000DPS 0x18//ジャイロセンサのレンジ(2000DPS)

//グローバル変数
//MPU9250
volatile float gyroRange;//計算で使用するので，選択したレンジを入力する定数
volatile uint8_t accGyroTempData[14];//センサからのデータ格納用配列
//ジャイロセンサの16bit出力生データ
volatile int16_t gx = 0;
volatile int16_t gy = 0;
volatile int16_t gz = 0;
//ジャイロセンサからの角速度[deg/sec]
volatile float gyroX = 0;
volatile float gyroY = 0;
volatile float gyroZ = 0;

//ROS
ros::NodeHandle nh;

std_msgs::Float64 pubData;
ros::Publisher pub("gyro_raw", &pubData);

//main function
void setup() {
  Wire.begin();//I2C通信を開始する
  //Serial.begin(115200);//シリアル通信を開始する

  //ROS
  nh.initNode();
  nh.advertise(pub);

  //MPU9250
  i2cWriteByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x00);//スリープモードを解除
  i2cWriteByte(MPU9250_ADDRESS, GYRO_CONFIG, GYRO_FS_SEL_2000DPS);//ジャイロセンサの測定レンジの設定
  gyroRange = 2000.0;//計算で使用するので，選択したレンジを入力する
}

void loop() {
  //get sensor data
  MPU9250();

  //Serial.print(gyroX);
  //Serial.print("\t");
  //Serial.print(gyroY);
  //Serial.print("\t");
  //Serial.println(gyroZ);

  //publish sensor data
  pubData.data = gyroZ;
  pub.publish(&pubData);
  nh.spinOnce();
}

//MPU9250 main function
void MPU9250() {
  //0x3bから，14バイト分をaccGyroDataにいれる
  i2cRead(MPU9250_ADDRESS, 0x3b, 14, accGyroTempData);

  //accGyroTempData[12]を左に8シフトし(<<)，accGyroTempData[13]を足し合わせる(|)
  gx = (accGyroTempData[8] << 8)  | accGyroTempData[9];
  gy = (accGyroTempData[10] << 8) | accGyroTempData[11];
  gz = (accGyroTempData[12] << 8) | accGyroTempData[13];

  //16bit生データを[deg/sec]データに変換
  gyroX = gx * gyroRange / 32768.0;
  gyroY = gy * gyroRange / 32768.0;
  gyroZ = gz * gyroRange / 32768.0;
}

//I2C functions
void i2cRead(uint8_t Address, uint8_t Register, uint8_t NBytes, volatile uint8_t* Data) {//指定したアドレスのデータを読む関数
  Wire.beginTransmission(Address);//指定したアドレスと通信を始める
  Wire.write(Register);//レジスタを書き込む
  Wire.endTransmission();//通信を終了する

  Wire.requestFrom(Address, NBytes);//スレーブからNByteのデータを要求する
  uint8_t index = 0;
  while (Wire.available()) {
    Data[index++] = Wire.read();//データを読み込む
  }
}
void i2cWriteByte(uint8_t Address, uint8_t Register, volatile uint8_t Data) {//指定したアドレスにデータを書き込む関数
  Wire.beginTransmission(Address);//指定したアドレスと通信を始める
  Wire.write(Register);//指定するレジスタを書き込む
  Wire.write(Data);//データを書き込む
  Wire.endTransmission();//通信を終了する
}
