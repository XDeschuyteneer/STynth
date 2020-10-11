#include <stdio.h>

int main(void)
{

    uint8_t i = 0;

    printf("STOP\n");
    
    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    while (1) {
	printf("loop %d\n", i);
	i++;
    }

    printf("STOP\n");
    
    return 0;
}
