
#ifndef FB01_PATCH_H
#define FB01_PATCH_H

#include <stdint.h>

#define PATCH_SIZE 128
#define NUM_OPERATORS 4

typedef struct _Global {
    uint8_t portamento;
    uint8_t transpose;
    uint8_t pms;            // Pitch Modulation Sensitivity
    uint8_t ams;            // Amplitude Modulation Sensitivity
    uint8_t pmd;            // Pitch Modulation Depth
    uint8_t amd;            // Amplitude Modulation Depth
    uint8_t lfo_speed;
    uint8_t lfo_waveform;
    uint8_t lfo_sync;
} Global;

typedef struct _Operator {
    uint8_t ar;             // Attack Rate
    uint8_t d1r;            // Decay 1 Rate
    uint8_t d2r;            // Decay 2 Rate
    uint8_t rr;             // Release Rate
    uint8_t sl;             // Sustain Level
    uint8_t dt1;            // Fine Detune
    uint8_t dt2;            // Coarse Detune
    uint8_t mul;            // Frequency multiplier
    uint8_t level;          // Level
    uint8_t level_fine;     // Fine level control
    uint8_t kbd_scale;      // Key scaling
    uint8_t vel_sens;       // Velocity sensitivity
    uint8_t rate_scale;     // Rate scaling
    uint8_t ar_vel;         // Attack velocity sensitivity
    uint8_t mod_carrier;    // 0=modulator, 1=carrier
    uint8_t curve;          // envelope curve type
} Operator;

typedef struct _Patch {
    uint8_t patchNumber;
    uint8_t bankNumber;
    uint8_t midiChannel;
    Operator operators[NUM_OPERATORS];
    Global global;
} Patch;

#endif // FB01_PATCH_H
