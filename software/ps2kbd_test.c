#include "ps2kbd.h"

#include <avr/io.h>
#include <avr/interrupt.h>

int
main()
{
  unsigned char	c;

  kbd_init();

  DDRB |= 0x1F;
  DDRC |= 0x3F;
  DDRD |= 0x03;

  // Enable pull-ups for buttons
  PORTD |= _BV(PD6);
  PORTD |= _BV(PD7);

  // Set ~RESET pin as output
  DDRD |= _BV(PD4);

  sei();

  while(1) {
    PORTD |= _BV(PD4);
    while (c = kbd_getchar()) {
      PORTC = c;
      if (c & 0x40) {
        PORTD |= _BV(PD0);
      } else {
        PORTD &= ~_BV(PD0);
      }
      if (c & 0x80) {
        PORTD |= _BV(PD1);
      } else {
        PORTD &= ~_BV(PD1);
      }
      PORTB = kbd_get_status();
    }
    PORTD &= ~_BV(PD4);
  }
	
  return 0;
}
