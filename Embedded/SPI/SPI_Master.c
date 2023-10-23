// #include "stm32f10x.h"
// #include "stm32f10x_rcc.h"
// #include "stm32f10x_gpio.h"

#define SCK 	GPIO_Pin_5
#define MOSI 	GPIO_Pin_6
#define SS 	GPIO_Pin_7
#define PORT 	GPIOA

void spi_Init();
void transmitData(uint8_t Data);

void endCondition();
void startCondition();
void Clock();



int main(){
	spi_Init();	
	uint8_t data = 8;
	
	
	while(1){				
		transmitData(data);
	}
	
	return 0;
	
}

void spi_Init(){
	
  GPIO_InitTypeDef  gpio_SPI;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	
  gpio_SPI.GPIO_Mode = GPIO_Mode_Out_PP;
  gpio_SPI.GPIO_Pin = SCK|MOSI|SS;
  gpio_SPI.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &gpio_SPI); 
	
	GPIO_ResetBits(GPIOA, SCK|MOSI);	
	GPIO_SetBits(GPIOA, SS);
	
}

void transmitData(uint8_t data){
	
	startCondition();
	
	for (int i = 0; i < 8; i++){
			if (( data & (0x80 >> i)) == 0) GPIO_ResetBits(GPIOA, MOSI);
			else GPIO_SetBits(GPIOA, MOSI);
			Clock();
	}
	
	endCondition();
	for (int i = 0; i < 100000000; i++){}
}

void startCondition(){
	GPIO_ResetBits(GPIOA, SS);
}

void endCondition(){
	GPIO_SetBits(GPIOA, SS);
}

void Clock(){
	GPIO_ResetBits(GPIOA, SCK);
	for (int i = 0; i < 50000000; i++){}
	GPIO_SetBits(GPIOA, SCK);
	for (int i = 0; i < 50000000; i++){}
	
}
