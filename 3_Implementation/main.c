#include<avr/io.h>
#include<avr/eeprom.h>
#include<util/delay.h>

#define lcdport PORTA

#define signal PORTB

#define en PB2

#define rw PB1

#define rs PB0
char password[1];
char lock[0];
char key;

char keycheck();

char scankey();

void lcdcmd(unsigned char cmd);

void lcdint();
unsigned char  lcd_read();

void lcddata(unsigned char data);
void send_a_command(unsigned char command);

void send_a_character(unsigned char character);

void send_a_string(char *string_of_characters);
int main()

{

	DDRA=0xff;

	DDRB=0x0f;

	DDRD=0xf0;

	char key;

	lcdint();
	
	lcddata('E');
	lcddata('N');
	lcddata('T');
	lcddata('E');
	lcddata('R');
	lcddata(' ');
	lcddata('P');
	lcddata('A');
	lcddata('S');
	lcddata('S');
	lcddata('W');
	lcddata('O');
	lcddata('R');
	lcddata('D');
	lcdcmd(0xC0);
	
	
	

	for(int i=0;i<3;i++)
	{

		key=scankey();
		
		_delay_ms(1000);
		

		lcddata(key);
		
		
		
		
		password[i]=key;
		
		
	}
	lcdcmd(0x01);
	
	if((password[0]=='7')&&(password[1]=='9')&&password[2]=='4')
	
	{lcddata('C');
		lcddata('O');
		lcddata('R');
		lcddata('R');
		lcddata('E');
		lcddata('C');
		lcddata('T');
		lcddata(' ');
		lcddata('P');
		lcddata('A');
		lcddata('S');
		lcddata('S');
		lcddata('W');
		lcddata('O');
		lcddata('R');
		lcddata('D');
		DDRC=0xff;
		PORTC=0x02;
		_delay_ms(81000);
		PORTC=0x00;
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcddata('L');
		lcddata('O');
		lcddata('C');
		lcddata('K');
		lcddata('?');
		lcddata(' ');
		lcddata('P');
		lcddata('R');
		lcddata('E');
		lcddata('S');
		lcddata('S');
		lcddata(' ');
		lcddata('1');
		lcdcmd(0xC0);
		
		key=scankey();
		_delay_ms(8000);
		

		lcddata(key);
		lock[0]=key;
		if(lock[0]=='1')
		{DDRC=0xff;
			PORTC=0x01;
			_delay_ms(8000);
			PORTC=0x00;
			lcdcmd(0x01);
			lcddata('L');
			lcddata('O');
			lcddata('C');
			lcddata('K');
			lcddata('E');
			lcddata('D');
			_delay_ms(8000);
			return main();
		}
		
	}
	
	else
	lcddata('W');
	lcddata('R');
	lcddata('O');
	lcddata('N');
	lcddata('G');
	lcddata(' ');
	lcddata('P');
	lcddata('A');
	lcddata('S');
	lcddata('S');
	lcddata('W');
	lcddata('O');
	lcddata('R');
	lcddata('D');
	
	return main();
	
}



char scankey()

{

	char key='a';

	while(key=='a')

	{

		key=keycheck();
		
		
	}

	return key;
	

}

char keycheck()

{

	PORTD=0b11101111;

	_delay_ms(100);

	if((PIND&0b00000001)==0)

	{
		
		return '7';
		
	}

	if((PIND&0b00000010)==0)

	{

		return '8';

	}

	if((PIND&0b00000100)==0)

	{

		return '9';
		

	}
	if((PIND&0b00001000)==0)
	{
		return 'A';
	}

	PORTD=0b11011111;

	_delay_ms(100);

	if((PIND&0b00000001)==0)

	{

		return '4';

	}

	if((PIND&0b00000010)==0)

	{

		return '5';

	}

	if((PIND&0b00000100)==0)

	{

		return '6';

	}
	if((PIND&0b00001000)==0)
	{
		return 'B';
	}

	PORTD=0b10111111;

	_delay_ms(100);

	if((PIND&0b00000001)==0)

	{

		return '1';

	}

	if((PIND&0b00000010)==0)

	{

		return '2';

	}

	if((PIND&0b00000100)==0)

	{

		return '3';

	}
	if((PIND&0b00001000)==0)
	{
		return'C';
	}

	PORTD=0b01111111;

	_delay_ms(100);

	if((PIND&0b00000001)==0)

	{

		return '*';

	}

	if((PIND&0b00000010)==0)

	{

		return '0';

	}

	if((PIND&0b00000100)==0)

	{

		return '#';

	}
	if((PIND&0b00001000)==0)
	{
		return'D';
	}
	

	return 'a';

}

void lcdint()

{

	lcdcmd(0x38);

	_delay_ms(500);

	lcdcmd(0x01);

	_delay_ms(500);

	lcdcmd(0x0F);

	_delay_ms(500);
	lcdcmd(0x82);
	
	_delay_ms(500);
	lcdcmd(0x89);
	_delay_ms(500);
	lcdcmd(0x01);
	
}



void lcdcmd(unsigned char x)

{

	lcdport=x;

	signal=(0<<rs)|(0<<rw)|(1<<en);

	_delay_ms(500);

	signal=(0<<rs)|(0<<rw)|(0<<en);

	_delay_ms(500);

}

void lcddata(unsigned char data)

{

	lcdport= data;

	signal= (1<<rs)|(0<<rw)|(1<<en);

	_delay_ms(500);

	signal= (1<<rs)|(0<<rw)|(0<<en);

	_delay_ms(500);

}
unsigned char  lcd_read()
{
	

	signal= (1<<rs)|(1<<rw)|(1<<en);

	_delay_ms(500);

	signal= (1<<rs)|(1<<rw)|(0<<en);

	_delay_ms(500);
	
}