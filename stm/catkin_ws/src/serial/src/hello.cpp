#include "ros/ros.h"
#include "std_msgs/String.h"

// Definições específicas para STM32
#ifdef STM32
#include "stm32f1xx_hal.h"
#endif

ros::NodeHandle* nh;

std_msgs::String str_msg;
ros::Publisher chatter;

char hello[13] = "hello world!";

void setup() {
  // Cria o NodeHandle após a inicialização do ROS
  nh = new ros::NodeHandle();
  
  // Cria o publisher corretamente
  chatter = nh->advertise<std_msgs::String>("chatter", 10);
}

void loop() {
  // Preenche a mensagem
  str_msg.data = hello;
  
  // Publica a mensagem
  chatter.publish(str_msg);

  // Faz o ROS processar callbacks
  ros::spinOnce();

  // Delay: usa HAL_Delay para STM32, ros::Duration para PC
  #ifdef STM32
    HAL_Delay(1000);  // Usado no ambiente STM32
  #else
    ros::Duration(1).sleep();  // Usado no ambiente desktop
  #endif
}

int main(int argc, char** argv) {
  // Inicializa o ROS
  ros::init(argc, argv, "hello_ros");

  setup();

  while (ros::ok()) {
    loop();
  }

  return 0;
}
