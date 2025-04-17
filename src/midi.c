
#include "midi.h"
#include <stdio.h>
#include "portmidi.h"

int fb01_midi_init(int device_id) {
    return 0;
}

void fb01_midi_close(void) {

}

int send_fb01_param(
    uint8_t param_addr, uint8_t value, uint8_t device_number
) {
    return 0;
}
