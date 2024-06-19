/**
 * Jon Durrant.
 *
 * Blink LED on Raspberry PICO
 * Display the word blink on an Oled screen
 */

#include "pico/stdlib.h"
extern "C"{
#include <ssd1306.h>
}
#include <cstdio>

#define DELAY 500 // in microseconds



/***
 * Draw the word testing on the Oled Screen
 */
void drawTest(ssd1306_t *pOled){
	ssd1306_draw_string(
			pOled,
			0,
			2,
			2,
			"Testing");

	ssd1306_draw_line(
			pOled,
			2, 25,
			80, 25);
}

/***
 * Deaw the word Testing amd Blink on the Screen
 */
void drawBlink(ssd1306_t *pOled){
	drawTest(pOled);
	ssd1306_draw_string(
			pOled,
			0,
			30,
			2,
			"Blink");
}

int main() {
	stdio_init_all();
	sleep_ms(2000);
	printf("GO\n");

	//Setup the OLED Screen
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

	//If setup OK then write the test text on OLED
	if (res){
		ssd1306_clear(&oled);
		drawTest(&oled);
		ssd1306_show(&oled);
	} else {
		printf("Oled Init failed\n");
	}



    const uint LED_PIN = 2;
    gpio_init(LED_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) { // Loop forever
        gpio_put(LED_PIN, 1);
        ssd1306_clear(&oled);
		drawBlink(&oled);
		ssd1306_show(&oled);
        sleep_ms(DELAY);

        gpio_put(LED_PIN, 0);
        ssd1306_clear(&oled);
		drawTest(&oled);
		ssd1306_show(&oled);
        sleep_ms(DELAY);
    }

}
