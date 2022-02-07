#include <avr/io.h>
#define TRIG_PIN	3
#define ECHO_PIN	2
#define SENSOR_DIR      _(DDRD)
#define SENSOR_PORT     _(PORTD)
#define SENSOR_PIND	_(PIND)

// include this line to avoid SFR_REG issues
#define _(s) _SFR_IO_ADDR(s)
