#include <bcm2835.h>
#include <stdio.h>

#define  KEY  20

int main(int argc, char **argv)
{
    if (!bcm2835_init())return 1;
    // Sets the pin as input.
    bcm2835_gpio_fsel(KEY, BCM2835_GPIO_FSEL_INPT);
    // Sets the Pull-up mode for the pin.
    bcm2835_gpio_set_pud(KEY, BCM2835_GPIO_PUD_UP);
    printf("Key Test Program!!!!\n");  
    while (1)
    {  
        // Reads the current level on the specified pin and returns either HIGH or LOW (0 or 1).
        if(bcm2835_gpio_lev(KEY) == 0)
        {  
            printf ("KEY PRESS\n") ;
            while(bcm2835_gpio_lev(KEY) == 0)
                bcm2835_delay(100);
        }  
        bcm2835_delay(100);
    }  
    bcm2835_close();
    return 0;
}

// The Code is From : https://www.waveshare.com/wiki/Raspberry_Pi_Tutorial_Series:_External_Button