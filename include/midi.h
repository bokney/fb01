
#ifndef FB01_MIDI_H
#define FB01_MIDI_H

#include <stdint.h>

int fb01_midi_init(int device_id);
void fb01_midi_close(void);
int send_fb01_param(uint8_t param_addr, uint8_t value, uint8_t device_number);

#endif // FB01_MIDI_H
