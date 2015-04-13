#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIM1_COMPA_vect) {
}

int main() {
	cli();

	DDRB |= (1 << DDB1);

	TCNT1 = 0;
	OCR1A = 31;
	OCR1C = 31;

	PORTB &= ~(1 << PB1);

	TCCR1 |= (1 << CTC1);
	TCCR1 &= ~(1 << PWM1A);
	TCCR1 &= ~(1 << COM1A1);
	TCCR1 |= (1 << COM1A0);
//	TCCR1 |= ((1 << CS13) | (1 << CS12));
//	TCCR1 &= ~((1 << CS11) | (1 << CS10));
	TCCR1 |= ((1 << CS13) | (1 << CS12) | (1 << CS11) | (1 << CS10));

	TIMSK |= (1 << OCIE1A);

	sei();

	while (1) {
	}
}
