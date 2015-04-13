#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(TIM0_COMPA_vect) {
//	OCR0A = (OCR0A + 1) % 256;
}

int main(void) {
	uint8_t i;

	cli();

	DDRB |= ((1 << DDB1) | (1 << DDB0));

	TCNT0 = 0;
	OCR0A = 0;
	OCR0B = 100;

	TCCR0A |= (0b10 << COM0A0);
	TCCR0A |= (0b11 << COM0B0);
	TCCR0A |= (0b11 << WGM00);
	TCCR0B |= (0b0001 << CS00);

//	TIMSK |= (1 << OCIE0A);

	sei();

	while (1) {
		for (i = 0; i < 128; i++) {
			OCR0A = i;

			_delay_ms(10);
		}

		for (i = 128; i > 0; i--) {
			OCR0A = i;

			_delay_ms(10);
		}
	}
}
