#include "config.inc"

	.section    .text
        .global     sonar
	.org        0x0000

sonar:
	; initialize the CPU clock to run at full speed
	ldi             r24, 0x80
        sts             CLKPR, r24              ; allow access to clock setup
        sts             CLKPR, r1               ; run at full speed

        sbi             SENSOR_DIR, TRIG_PIN         ; sets pin 3's direction to output => Trig Pin
        cbi             SENSOR_DIR, ECHO_PIN         ; sets pin 2's direction to input  <= Echo Pin
        cbi             SENSOR_PORT, TRIG_PIN        ; sets the output to LOW
trig:						
        sbi             SENSOR_PORT, TRIG_PIN        ; set Trig Pin to HIGH to send a ultrasonic wave burst
        call            tenMicroDelay                ; HIGH signal must continue for 10 microseconds
        cbi             SENSOR_PORT, TRIG_PIN        ; set the output to LOW after waves are sent
echo:
        clr             r21                     ; clear counter value
echowait:
        call            Delay        		; giving it time to travel 1cm
        inc             r21                     ; increment counter for each cm
        sbic            SENSOR_PIND, ECHO_PIN	; break out of loop if echo received
        rjmp            echowait                ; otherwise keep waiting for the echo
        clr		r25			; zero out high bits of return register
        mov		r24, r21                ; set lower bits to the value of counter
        call            Delay
        ret					; return to calling function
Delay:
        ldi             r18, 2                  ; set loop to 2
	ldi		r19, 41                 ; set inner loop to 41
1:      dec		r19			
	brne		1b
	dec		r18
	brne		1b			
	ret					; return after ~1 cm of travel


tenMicroDelay:
        ldi             r18, 50                 ; set loop to 50
1:      dec		r18			
	brne		1b
	ret					; return after 10 microseconds
        

