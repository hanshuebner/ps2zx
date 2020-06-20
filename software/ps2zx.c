
#include <sys/types.h>

#include "ps2kbd.h"

uint8_t current_matrix[5];

main()
{
  kbd_init();

  sei();
}
