/*******************************************************************************
 * leds.c
 ******************************************************************************/

#include "leds.h"

/*******************************************************************************
 * Controle des leds -> off
 ******************************************************************************/
void led_off(char led_number)
{
    FILE *file = NULL;

    switch(led_number)
    {
        case 0 : 
            //system("echo 0 > /sys/class/leds/beaglebone::usr0/brightness");
            file = fopen(BEAGLE_LED_PATH ":usr0/brightness", "w");
            if(file){
                fprintf(file, "0");
                fflush(file);
                fclose(file);
            }
        break;
        case 1 :
            file = fopen(BEAGLE_LED_PATH ":usr1/brightness", "w");
            if(file){
                fprintf(file, "0");
                fflush(file);
                fclose(file);
            }
            //system("echo 0 > /sys/class/leds/beaglebone::usr1/brightness");
        break;
        case 2 :
            //system("echo 0 > /sys/class/leds/beaglebone::usr2/brightness");
            file = fopen(BEAGLE_LED_PATH ":usr2/brightness", "w");
            if(file){
                fprintf(file, "0");
                fflush(file);
                fclose(file);
            }
        break;
        case 3 :
            //system("echo 0 > /sys/class/leds/beaglebone::usr3/brightness");
            file = fopen(BEAGLE_LED_PATH ":usr3/brightness", "w");
            if(file){
                fprintf(file, "0");
                fflush(file);
                fclose(file);
            }
        break;
    }
}

/*******************************************************************************
 * Controle des leds -> on
 ******************************************************************************/
void led_on(char led_number)
{
    FILE *file = NULL;
    switch(led_number)
    {
        case 0 : 
            //system("echo 1 > /sys/class/leds/beaglebone::usr0/brightness");
            file = fopen(BEAGLE_LED_PATH ":usr0/brightness", "w");
            if(file){
                fprintf(file, "1");
                fflush(file);
                fclose(file);
            }
        break;
        case 1 :
            file = fopen(BEAGLE_LED_PATH ":usr1/brightness", "w");
            if(file){
                fprintf(file, "1");
                fflush(file);
                fclose(file);
            }
            //system("echo 1 > /sys/class/leds/beaglebone::usr1/brightness");
        break;
        case 2 :
            //system("echo 1 > /sys/class/leds/beaglebone::usr2/brightness");
            file = fopen(BEAGLE_LED_PATH ":usr2/brightness", "w");
            if(file){
                fprintf(file, "1");
                fflush(file);
                fclose(file);
            }
        break;
        case 3 :
            //system("echo 1 > /sys/class/leds/beaglebone::usr3/brightness");
            file = fopen(BEAGLE_LED_PATH ":usr3/brightness", "w");
            if(file){
                fprintf(file, "1");
                fflush(file);
                fclose(file);
            }
        break;
    }
}
