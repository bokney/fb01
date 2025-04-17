
#ifndef FB01_MAP_H
#define FB01_MAP_H

#include <stdint.h>

// Operator parameter base addresses
#define FB01_OP1_BASE  0x20
#define FB01_OP2_BASE  0x30
#define FB01_OP3_BASE  0x40
#define FB01_OP4_BASE  0x50

// Macro to compute operator parameter address
#define FB01_OP_ADDR(op, offset) (FB01_OP1_BASE + ((op) * 0x10) + (offset))

// Operator parameter offsets
#define FB01_OP_AR         0x00  // Attack Rate
#define FB01_OP_D1R        0x01  // Decay 1 Rate
#define FB01_OP_D2R        0x02  // Decay 2 Rate
#define FB01_OP_RR         0x03  // Release Rate
#define FB01_OP_SL         0x04  // Sustain Level
#define FB01_OP_DT1        0x05  // Fine Detune
#define FB01_OP_DT2        0x06  // Coarse Detune
#define FB01_OP_MUL        0x07  // Frequency Multiplier
#define FB01_OP_LEVEL      0x08  // Level
#define FB01_OP_LEVEL_FINE 0x09  // Fine Level
#define FB01_OP_KBD_SCALE  0x0A  // Keyboard Scaling
#define FB01_OP_VEL_SENS   0x0B  // Velocity Sensitivity
#define FB01_OP_RATE_SCALE 0x0C  // Rate Scaling
#define FB01_OP_AR_VEL     0x0D  // Attack Rate Velocity Sensitivity
#define FB01_OP_MOD_CARR   0x0E  // Modulator/Carrier toggle
#define FB01_OP_CURVE      0x0F  // Envelope curve

// Macros to get full addresses for an operator 0-3
#define FB01_ADDR_OP_AR(op)         FB01_OP_ADDR(op, FB01_OP_AR)
#define FB01_ADDR_OP_D1R(op)        FB01_OP_ADDR(op, FB01_OP_D1R)
#define FB01_ADDR_OP_D2R(op)        FB01_OP_ADDR(op, FB01_OP_D2R)
#define FB01_ADDR_OP_RR(op)         FB01_OP_ADDR(op, FB01_OP_RR)
#define FB01_ADDR_OP_SL(op)         FB01_OP_ADDR(op, FB01_OP_SL)
#define FB01_ADDR_OP_DT1(op)        FB01_OP_ADDR(op, FB01_OP_DT1)
#define FB01_ADDR_OP_DT2(op)        FB01_OP_ADDR(op, FB01_OP_DT2)
#define FB01_ADDR_OP_MUL(op)        FB01_OP_ADDR(op, FB01_OP_MUL)
#define FB01_ADDR_OP_LEVEL(op)      FB01_OP_ADDR(op, FB01_OP_LEVEL)
#define FB01_ADDR_OP_LEVEL_FINE(op) FB01_OP_ADDR(op, FB01_OP_LEVEL_FINE)
#define FB01_ADDR_OP_KBD_SCALE(op)  FB01_OP_ADDR(op, FB01_OP_KBD_SCALE)
#define FB01_ADDR_OP_VEL_SENS(op)   FB01_OP_ADDR(op, FB01_OP_VEL_SENS)
#define FB01_ADDR_OP_RATE_SCALE(op) FB01_OP_ADDR(op, FB01_OP_RATE_SCALE)
#define FB01_ADDR_OP_AR_VEL(op)     FB01_OP_ADDR(op, FB01_OP_AR_VEL)
#define FB01_ADDR_OP_MOD_CARR(op)   FB01_OP_ADDR(op, FB01_OP_MOD_CARR)
#define FB01_ADDR_OP_CURVE(op)      FB01_OP_ADDR(op, FB01_OP_CURVE)

// Global parameter addresses
#define FB01_ADDR_TRANSPOSE     0x60
#define FB01_ADDR_PMS           0x61
#define FB01_ADDR_AMS           0x62
#define FB01_ADDR_LFO_SPEED     0x63
#define FB01_ADDR_LFO_WAVEFORM  0x64
#define FB01_ADDR_LFO_SYNC      0x65
#define FB01_ADDR_PMD           0x66
#define FB01_ADDR_PORTAMENTO    0x67
#define FB01_ADDR_AMD           0x6B

#endif // FB01_MAP_H
