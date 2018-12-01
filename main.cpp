/*
 * FRDM-K64F-USB-Keyboard
 * Author: DC MS AB 
 */

#include "mbed.h"
#include "USBMouseKeyboard.h"

/* Create interrupts for handling buttons press events */
InterruptIn button_sw2(SW2);
InterruptIn button_sw3(SW3);

/* Create green LED object */
DigitalOut green_led(LED_GREEN);

/* Create USB keyboard object */
USBKeyboard frdm_keyboard;

/* Define global flags for control of prints connected with button presses */
bool sw2_pressed = false;
bool sw3_pressed = false;

/* Interrupt handlers for buttons press events */
void sw2_int_handler() {
    sw2_pressed = true;
    green_led = !green_led;
}

void sw3_int_handler() {
    sw3_pressed = true;
    green_led = !green_led;
}

/* Functions for printing a text bonded with each button */
void print_txt_sw2(a) {
    frdm_keyboard.printf(a);
}

void print_txt_sw3() {
    frdm_keyboard.printf("Litwo ojczyzno moja ty jestes jak zdrowie ile cie trzeba cenic ten tylko sie dowie kto cie stracil dzis pieknosc twa w calej ozdobie widze i opisuje bo tesknie ku tobie\n\r");
}

/* Main body of the application */
int main(void) {
    /* Initialize LED */
    green_led = 0;
    
    /* Setup interrupts for falling edge detected on the buttons pins */
    button_sw2.fall(&sw2_int_handler);
    button_sw3.fall(&sw3_int_handler);
		string a = "Litwo ojczyzno moja ty jestes jak zdrowie ile cie trzeba cenic ten tylko sie dowie kto cie stracil dzis pieknosc twa w calej ozdobie widze i opisuje bo tesknie ku tobie";
		int key = 3
    
    /* Check what button was pressed and print appropriate text */
    while (true) {
			
        if(sw2_pressed) {
					string a = "Litwo ojczyzno moja ty jestes jak zdrowie ile cie trzeba cenic ten tylko sie dowie kto cie stracil dzis pieknosc twa w calej ozdobie widze i opisuje bo tesknie ku tobie";
					int key = 3
					for(int i = 0; a[i] != '\0';++i{
							char x = a[i];
							if (x >= 'a' && x <= 'z'){
								x = x + key;
								if (ch > 'z'){
									x = x - 'z' + 'a' -1;
								}
								a[i] = x
							}
						}	
						
          print_txt_sw2(a);
          sw2_pressed = false;
        }
        if(sw3_pressed) {
            print_txt_sw3();
            sw3_pressed = false;
        }
        
        /* Wait for interrupts */
        wait(0.5f);
    }

    /* This place shall never be reached! */
}
