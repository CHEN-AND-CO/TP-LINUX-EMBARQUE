/*******************************************************************************
 * leds.h
 ******************************************************************************/

// Le test ci-dessous permet d'eviter les inclusions multiples
#ifndef _LEDS_H
#define _LEDS_H

#define BEAGLE_LED_PATH "/sys/class/leds/beaglebone:green"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Protos
void led_off(char led_number);
void led_on(char led_number);
#endif
