#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "periph/gpio.h"
#include "xtimer.h"

#define UNUSED(param) (void)param

static char stack0[THREAD_STACKSIZE_MAIN];
static char stack1[THREAD_STACKSIZE_MAIN];
static char stack2[THREAD_STACKSIZE_MAIN];

typedef struct {
    uint8_t led_id;
    uint8_t led_toggle_time;
} t_params;

static void* tn_handler(void* arg)
{
    uint8_t led_id = ((t_params*) arg)->led_id;
    uint8_t led_toggle_time = ((t_params*) arg)->led_toggle_time;
    while (1) {
	printf("t-%d handler - sleeping %d seconds\n", led_id, led_toggle_time);
	switch (led_id) {
	case 0:
	    LED0_TOGGLE;
	    break;
	case 1:
	    LED1_TOGGLE;
	    break;
	case 2:
	    LED2_TOGGLE;
	    break;
	}
	xtimer_sleep(led_toggle_time);
    }
    return NULL;
}

static void b1_handler(void *arg)
{
    UNUSED(arg);
    printf("b1 pressed\n");
}

void init(void)
{
    xtimer_init();
    gpio_init(LED0_PIN, GPIO_OUT);
    gpio_init(LED1_PIN, GPIO_OUT);
    gpio_init(LED1_PIN, GPIO_OUT);
    LED0_OFF;
    LED1_OFF;
    LED2_OFF;
}

int main(void)
{
    printf("START\n");
    init();
    t_params t0_params = {.led_id=0, .led_toggle_time=1};
    thread_create(stack0, sizeof(stack1),
                  THREAD_PRIORITY_MAIN - 1,
                  0,
                  tn_handler,
                  (void*) &t0_params,
		  "thread0");
    t_params t1_params = {.led_id=1, .led_toggle_time=2};
    thread_create(stack1, sizeof(stack1),
                  THREAD_PRIORITY_MAIN - 1,
                  0,
                  tn_handler,
                  (void*) &t1_params,
		  "thread1");
    t_params t2_params = {.led_id=2, .led_toggle_time=4};
    thread_create(stack2, sizeof(stack1),
                  THREAD_PRIORITY_MAIN - 1,
                  0,
                  tn_handler,
                  (void*) &t2_params,
		  "thread2");

    gpio_init_int(BTN0_PIN, GPIO_IN, GPIO_FALLING, b1_handler, NULL);

    printf("STOP\n");
    
    return 0;
}
