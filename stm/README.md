### projeto stm
descrevendo o projeto para o stm 32
#### conectando a placa ao wsl

lembrando que foi usado o Ubuntu 20:04
##### terminal powershell (admnistration mode)
usbipd list
usbipd bind --busid 2-2 - esse comando  é necessario uma unica vez
usbipd attach --wsl --busid 2-1
##### terminal wsl
lsusb *oque deve mostrar o dispositivo*

#### monitoramento serial wsl
sudo apt-get install minicom
sudo minicom -s
sudo minicom


#### modelo 

o modelo da placa usada foi STM32F103C8T6
#### comando usado para o projeto stm

pio project init --board bluepill_f103c8
pio run --target upload

[documetação blue pill](https://components101.com/microcontrollers/stm32f103c8t8-blue-pill-development-board)

### pinos ligados ao led Embutido
PC13 -> led verde

### ROS

STM32 não possui comunicação serial, portanto a ideia é usar o ros para realizar a comuincação com o sistema operacional freertos


### STM32CubeMX

programa instalado que gera o projeto do stm32 com suas especificações.

### executando o stm no vs code
cmake .
make
openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg *código para o programador do stm*

#### em outro terminal
gdb-multiarch test1.elf
target extended-remote :3333
load
continue


#### caminho de especificações

cd /usr/local/STMicroelectronics/STM32Cube/STM32CubeMX;

./STM32CubeMX
