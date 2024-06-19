/**
 * Jon Durrant.
 *
 * Simple Animation of a Bitmap on an OLED 128x64 screen
 */

#include "pico/stdlib.h"
extern "C"{
#include <ssd1306.h>
}
#include <cstdio>
#include "bellboy.h"


void drawBellboy(ssd1306_t *pOled, int xOffset){
	ssd1306_clear(pOled);

	for (int y=0; y < 64; y++){
		for (int x=0; x < 64; x++){
			if (
					((x + xOffset) >= 0 ) &&
					((x + xOffset) < 128 )
					){
					//Byte Index
					int b = y * 8 + x /8;
					//Mask
					int mask = 1  << (x % 8);
					if ((BELLBOY[b] & mask) > 0){
						ssd1306_draw_pixel(
								pOled,
								x + xOffset,
								y);
				}
			}
		}
	}


	ssd1306_show(pOled);

}



int main() {
	stdio_init_all();
	sleep_ms(2000);
	printf("GO\n");


	i2c_init(i2c0, 400000);
	gpio_pull_up(12);
	gpio_pull_up(13);
	gpio_set_function(12, GPIO_FUNC_I2C);
	gpio_set_function(13, GPIO_FUNC_I2C);
	ssd1306_t oled;
	oled.external_vcc=false;
	bool res = ssd1306_init(
			&oled,
			128,
			64,
			0x3c,
			i2c0);

	if (res){
		for (;;){
			for (int x = -64; x < 128; x++){
				drawBellboy(&oled, x);
			}
		}
	} else {
		printf("Oled Init failed\n");
	}


}
