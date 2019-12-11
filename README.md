# 導入方法

必要なパッケージ  

sudo apt-get install ros-kinetic-gmapping  
sudo apt-get install ros-kinetic-openslam-gmapping  
sudo apt-get install ros-kinetic-slam-gmapping  
sudo apt-get install ros-kinetic-map-server  
sudo apt-get install ros-kinetic-amcl  
sudo apt-get install ros-kinetic-move-base  

sudo apt-get install ros-kinetic-urg-node  
sudo apt-get install ros-kinetic-rosserial-arduino  
sudo apt-get install ros-kinetic-rosserial  

sudo apt-get install ros-kinetic-joy  
sudo apt-get install ros-kinetic-joystick-drivers  


# 注意

catkin_makeの際<vw_cmd.h>または<unit_cmd.h>がないと怒られたら、問題のパッケージをsrcから取り除いてcatkin_makeし、その後いれなおしてcatkin_makeする  
すぐに反映されない場合はsource devel setup.bashのコマンドを打つ  





# パッケージ  

見方  

#パッケージ名

実行形式ファイル名

param  
変数の型　変数名：　説明  

pub,sub  
[トピック名]（メッセージ型）：説明  


# ｃｈｊｋ 

chjk_node  

	param  
	double alpha: ロボットの中心から右前の駆動輪までの極座標の角度（前方をｙ座標正にして）【deg】  
	double r:ロボットの中心から駆動輪までの極座標の距離[m]  


	pub  
	[left_front](chjk/unit_cmd)：左前のロボット座標でのステア・駆動指令[rad][m/s]  
	[right_front](chjk/unit_cmd)：右前のロボット座標でのステア・駆動指令[rad][m/s]  
	[left_rear](chjk/unit_cmd)：左後のロボット座標でのステア・駆動指令[rad][m/s]  
	[left_rear](chjk/unit_cmd)：左後のロボット座標でのステア・駆動指令[rad][m/s]  

	sub  
	[pose](geometry_msgs/Pose2D):グローバル座標での姿勢位置[m][rad]  
	[cmd](chjk/vw_cmd):グローバル座標での速度指令[rad/s][m/s]  


# chjk_odometry  

	1.chjk_odometry_node

		param
		double enc_per_m: エンコーダが１ｍあたりに増加するエンコーダ数

		pub
		[tf](tf/Message):ロボットのフレームを/base_link,オドメトリ座標フレームを/odomとしてその間の移動、回転の情報


		sub
		[enc](std_msgs/Int64):自己位置推定用のエンコーダの値
		[gyro_pose](std_msgs/Int16):ジャイロによって推定した姿勢の値[deg]
		[cmd](chjk/vw_cmd):グローバル座標での速度指令[rad/s][m/s]




	2.pose_estimate_out_node

		pub
		[pose](geometry_msgs/Pose2D):グローバル座標での姿勢位置[m][rad]

		sub
		[tf](tf/Message):ロボットのフレームを/base_link,グローバル座標フレームを/mapとしてその間の移動、回転の情報



# joy_controller 

joy_controller_node  

	param  
	double MAX_VEL: ロボットの最大速度[m/s]  
	double MAX_ANGULAR_VEL:　ロボットの最大角加速度[rad/s]  

	pub  
	[cmd](chjk/vw_cmd):グローバル座標での速度指令[rad/s][m/s]  

	sub  
	[joy](sensor_msgs/Joy): joyコントローラの入力  
	＊左スティックでｘｙ座標の速度、左スティックの右半面、正の回転、左半面、負の回転  







