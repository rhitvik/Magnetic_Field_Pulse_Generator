/*
 * PWM Test Circuit Rev-1.cpp
 *
 * Created: 03-02-2019 16:25:15
 * Author : RHITVIK
 */ 

#define F_CPU 1000000UL

#define LightSwitch				3
#define ReadWrite				4
#define BiPolarMood				5  

#define MrLCDsCrib				PORTD
#define DataDir_MrLCDsCrib		DDRD

#define MrLCDsControl			PORTB
#define DataDir_MrLCDsControl	DDRB

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void Check_IF_MrLCD_isBusy(void);
void Peek_A_Boo(void);
void Send_A_Command(char command);
void Send_A_Character(char character);
void Send_An_Integer(int integer);
void Send_A_String(char *stringOfCharacters);
void Send_A_String_Instantly(char *stringOfCharacters);

void initialize_FAST_PWM_params(void);
void initialize_Phase_Correct_PWM_params(void);

void Set_ADC_Vect_X_Proportions(void);
void Set_ICR_Val(void);

void calculate_Range_for_OCR(void);
void perform_Floating_op(void);
void set_OCR_Val(void);

void Initialize_ADC(void);


volatile int ADC_Channel = 0;
volatile int Channel_1_ADC_Val = 0;
volatile int Channel_2_ADC_Val = 0;

volatile int a = 0;

int ADC_Vect_set_Val = 0;
int RT_ICR_Val = 0;
int OCR_Max = 0;
int OCR_Val = 0;

float MR_duty = 0;
float OCR_Val_Float = 0;
 
int ICR1_Val = 6400;
int OCR1A_Val = 0;// change ocr value to take effect globally

int main(void)
{ 
  DataDir_MrLCDsControl |= (1<<LightSwitch) | (1<<ReadWrite) | (1<<BiPolarMood);
  MrLCDsControl &=~ (1<<LightSwitch);  MrLCDsControl &=~ (1<<ReadWrite);  MrLCDsControl &=~ (1<<BiPolarMood);
  DDRB = 0xFE;
  PORTB |= (1<<PINB0);
  PORTB &=~ (1<<PINB1);
  
  DDRC |= (1<<PINC2);
  PORTC |= (1<< PINC2);
  
  
  DDRD = 0xFF;
  PORTD= 0;
  
  char ValueSampled_Channel_1[4];
  char ValueSampled_Channel_2[4];
  char ADC_Vect_set_Val_Display[4];
  char RT_ICR_Val_Display[4];
  char OCR_Max_Display[4];
  char OCR_Val_Display[4];
  
  sei();

  _delay_ms(15);
  Send_A_Command(0x01); //clear screen

  _delay_ms(2);
  Send_A_Command(0x38);
  _delay_us(50);
  Send_A_Command(0b00001100);
  _delay_us(50);
  
  Send_A_Command(0x80);//clrscr();
  _delay_ms(2);
  Send_A_String("X");
  _delay_ms(2);
  
  Send_A_Command(0x80 + 10);//clrscr();
  _delay_ms(2);
  Send_A_String("Y");
  _delay_ms(2);
  
  Send_A_Command(0x94);//clrscr();
  _delay_ms(2);
  Send_A_String("A");
  _delay_ms(2);
  
  Send_A_Command(0x94+10);//clrscr();
  _delay_ms(2);
  Send_A_String("B");
  _delay_ms(2);
  
  Send_A_Command(0xD4);//clrscr();
  _delay_ms(2);
  Send_A_String("1A");
  _delay_ms(2);
  
  Send_A_Command(0xD4+10);//clrscr();
  _delay_ms(2);
  Send_A_String("1B");
  _delay_ms(2);

//   Send_A_Command(0x80);
//   _delay_ms(2);
//   Send_A_String("Hello World");
//   _delay_ms(2);
//   
//   Send_A_String("           ");
//   _delay_ms(2);
//   
//   while(3){
// 	  PORTC |= (1<<PINC1); PORTC |= (1<<PINC0);	  PORTB ^= (1<< PINB1);
// 
// 	  _delay_ms(500);
// 	  PORTC &=~ (1<<PINC1);
// 	  PORTC &=~ (1<<PINC0);
// 	  _delay_ms(500);	  
//   }
//   
//   while(2){
// 	  initialize_Phase_Correct_PWM_params();
// 
// 	  Send_A_Command(0x01);
// 	  _delay_ms(2);
// 	  Send_A_String("Phase_Correct_PWM");
// 	  _delay_ms(2);
// 	  
// 	  _delay_ms(2500);
// 	  
// 	  initialize_FAST_PWM_params();
// 	  Send_A_Command(0x01);
// 	  _delay_ms(2);
// 	  Send_A_String("FAST_PWM");
// 	  _delay_ms(2);
// 	  
// 	  _delay_ms(2500);v
//   }

// 
     	  //PORTB |= (1<<PINB2);


initialize_FAST_PWM_params();
ICR1 = 10000;
OCR1B = 2500;
OCR1A = 2500;

while(99){
	PORTC |= (1<< PINC2);
	_delay_ms(1000);
	PORTC &=~ (1<< PINC2);
	_delay_ms(1000);
}

while (3000){
	OCR1B = 1000;
	OCR1A = 1000;
	PORTC |= (1<< PINC2);
	
	_delay_ms(5000);
	
	OCR1B = 2000;
	OCR1A = 2000;
	PORTC &=~ (1<< PINC2);
	
	_delay_ms(5000);
	
	OCR1B = 3000;
	OCR1A = 3000;
	PORTC |= (1<< PINC2);
	
	_delay_ms(5000);
	
	OCR1B = 4000;
	OCR1A = 4000;
	PORTC &=~ (1<< PINC2);
	
	_delay_ms(5000);	
	
	OCR1B = 5000;
	OCR1A = 5000;
	PORTC |= (1<< PINC2);
	
	_delay_ms(5000);
	
	OCR1B = 6000;
	OCR1A = 6000;
	PORTC &=~ (1<< PINC2);
	
	_delay_ms(5000);
	
	OCR1B = 7000;
	OCR1A = 7000;
	PORTC |= (1<< PINC2);
	
	_delay_ms(5000);
	
	OCR1B = 8000;
	OCR1A = 8000;
	PORTC &=~ (1<< PINC2);
	
	_delay_ms(5000);
}


 
// 	while(242){
// 		
// 	}

//Initialize_ADC();

  while(1){
	  _delay_ms(20);
	  ADCSRA |= (1<<ADSC);
	  _delay_ms(20);
	  
	  if (bit_is_clear(PINB,0)){
		  //debounce via software or no need of that here as the lcd update function will be a good delay itself
		  //lock this loop to make sure that the values are locked and loaded in the register only once after the button is pressed
		  
		  PORTC ^= (1<< PINC2);
		  _delay_ms(500);	
		  initialize_FAST_PWM_params();	  
	  }
	  
	  if (ADC_Channel == 1)
	  {
		  itoa(Channel_1_ADC_Val,ValueSampled_Channel_1,10);
		  
		  Send_A_Command(0x80 + 2);
		  _delay_ms(2);
		  Send_A_String_Instantly("     ");
		  _delay_ms(2);
		  Send_A_Command(0x80 + 2);
		  _delay_ms(2);
// 		  Send_A_String_Instantly("ONE!");
// 		  _delay_ms(2);
// 		  _delay_ms(200);
		  Send_A_String_Instantly(ValueSampled_Channel_1);
		  _delay_ms(2);
		  
		  //_delay_ms(20);
		  Set_ADC_Vect_X_Proportions();
		  _delay_ms(10);
		  _delay_ms(20);
		  Set_ICR_Val();
		  _delay_ms(10);
 		  
		  itoa(ADC_Vect_set_Val,RT_ICR_Val_Display,10);
		  
		  Send_A_Command(0x94 + 2);//();
		  _delay_ms(2);
		  Send_A_String("     ");
		  _delay_ms(2);
		  Send_A_Command(0x94 + 2);//();
		  _delay_ms(2);
		  Send_A_String_Instantly(RT_ICR_Val_Display);
		  _delay_ms(2);
		  
		  itoa(RT_ICR_Val,RT_ICR_Val_Display,10);
		  
		  Send_A_Command(0xD4 + 3);//();
		  _delay_ms(2);
		  Send_A_String("     ");
		  _delay_ms(2);
		  Send_A_Command(0xD4  + 3);//();
		  _delay_ms(2);
		  Send_A_String_Instantly(RT_ICR_Val_Display);
		  _delay_ms(2);
		  
		}	 
		//else
		if (ADC_Channel == 2)
		{
			itoa(Channel_2_ADC_Val,ValueSampled_Channel_2, 10);
	  
			Send_A_Command(0x80+ 10 + 2);//();
			_delay_ms(2);
			Send_A_String("     ");
			_delay_ms(2);
			Send_A_Command(0x80+ 10 + 2);//();
			_delay_ms(2);
// 			Send_A_String_Instantly("TWO!");
// 			_delay_ms(2);
// 			_delay_ms(200);
			Send_A_String_Instantly(ValueSampled_Channel_2);
			_delay_ms(2);
			
			// _delay_ms(20);
			calculate_Range_for_OCR();
			_delay_ms(10);
			perform_Floating_op();
			_delay_ms(20);
			set_OCR_Val();
			_delay_ms(10);

			itoa(OCR_Max,OCR_Max_Display,10);

			Send_A_Command(0x94+ 10 + 2);//();
			_delay_ms(2);
			Send_A_String("     ");
			_delay_ms(2);
			Send_A_Command(0x94+ 10 + 2);//();
			_delay_ms(2);
			Send_A_String_Instantly(OCR_Max_Display);
			_delay_ms(2);

			itoa(OCR_Val,OCR_Val_Display,10);

			Send_A_Command(0xD4+ 10 + 3);//();
			_delay_ms(2);
			Send_A_String("     ");
			_delay_ms(2);
			Send_A_Command(0xD4+ 10 + 3);//();
			_delay_ms(2);
			Send_A_String_Instantly(OCR_Val_Display);
			_delay_ms(2);
		}
	}
  
}

void Check_IF_MrLCD_isBusy(void){
	DataDir_MrLCDsCrib = 0;
	MrLCDsControl |= 1<<ReadWrite;
	MrLCDsControl &=~ 1<<BiPolarMood;	
	while (MrLCDsCrib >= 0x80){
		Peek_A_Boo();
	}
	DataDir_MrLCDsCrib = 0xFF;
}
void Peek_A_Boo(void){
	MrLCDsControl |= 1<<LightSwitch;
// 	asm volatile ("nop");
// 	asm volatile ("nop");
	_delay_us(50);//Calibrate it further
	MrLCDsControl &=~ 1<<LightSwitch;
}
void Send_A_Command(char command){
	Check_IF_MrLCD_isBusy();
	MrLCDsCrib = command;
	MrLCDsControl &=~ (1<<ReadWrite|1<<BiPolarMood);
	Peek_A_Boo();
	MrLCDsCrib = 0;
}
void Send_A_Character(char character){
	Check_IF_MrLCD_isBusy();
	MrLCDsCrib = character;
	MrLCDsControl &=~ 1<<ReadWrite;
	MrLCDsControl |= 1<<BiPolarMood;
	Peek_A_Boo();
	MrLCDsCrib = 0;
}
void Send_An_Integer(int integer){
	Check_IF_MrLCD_isBusy();
	MrLCDsCrib = integer;
	MrLCDsControl &=~ 1<<ReadWrite;
	MrLCDsControl |= 1<<BiPolarMood;
	Peek_A_Boo();
	MrLCDsCrib = 0;
}
void Send_A_String(char *stringOfCharacters){
	while(*stringOfCharacters > 0){
		Send_A_Character(*stringOfCharacters++);
		_delay_ms(10);//change to comfort
	}
}
void Send_A_String_Instantly(char *stringOfCharacters){
	while(*stringOfCharacters > 0){
		Send_A_Character(*stringOfCharacters++);
	}
}

void initialize_FAST_PWM_params(void){//make sure that  pin is set to output mode....and initialize it to 0
	TCCR1A |= (1<<WGM11) | (1<<COM1A1)| (1<<COM1B1);// for OC1A | non-inverting mode
	TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS10);
	ICR1 = ICR1_Val;
	OCR1A = 0;	
	OCR1B = 0;
}
void initialize_Phase_Correct_PWM_params(void){
	TCCR1A |= (1<<WGM11) | (1<<COM1A1);// | (1<<COM1B1);// for OC1A | non-inverting mode
	TCCR1B |= (1<<WGM13) | (1<<CS10);
	TCCR1B &=~ (1<<WGM12);
	ICR1 = ICR1_Val;
	OCR1A = 0;
	OCR1B = 0;
}

void Initialize_ADC(void){
	ADCSRA |= (1<<ADPS2) | (1<<ADIE); //pre-scalar factor = 16 | ISR invoke on conversion enabled
	ADMUX  |= (1<<ADLAR) | (1<<REFS0); // ADC left adjustment register chosen | AVCC with external capacitor at AREF pin is selected as reference
	ADCSRA |= (1<<ADEN); //ADC Enable
	ADCSRA |= (1<<ADSC); //start conversion
}
ISR(ADC_vect){
	uint8_t the_low = ADCL;
	uint8_t the_high = ADCH;
	uint16_t ten_bit_value = the_high<<2 | the_low>>6;
	a = ten_bit_value;
	
	switch(ADMUX){
		case 0x60:
		Channel_1_ADC_Val = a;
		ADC_Channel = 1;
		ADMUX = 0x61;
		break;
		
		case 0x61:		
		Channel_2_ADC_Val = a;
		ADC_Channel = 2;
		ADMUX = 0x60;
		break;
	}
	
}

void Set_ADC_Vect_X_Proportions(void){
	ADC_Vect_set_Val = (Channel_1_ADC_Val/7) + 1;
}
void Set_ICR_Val(void){
	RT_ICR_Val = 49 + ADC_Vect_set_Val;
}

void set_OCR_Val(void){
	OCR_Val = OCR_Val_Float;
}
void calculate_Range_for_OCR(void){
	OCR_Max = RT_ICR_Val;
}

void perform_Floating_op(void){
	MR_duty = Channel_2_ADC_Val/102;
	OCR_Val_Float = OCR_Max*MR_duty/10;
}