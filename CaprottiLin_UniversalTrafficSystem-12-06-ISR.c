#include "stm32f4xx.h"
#include <setjmp.h>

#define RS 0x20     /* PB5 mask for reg select */
#define EN 0x80     /* PB7 mask for enable */

void delayMs(int n);
void LCD_nibble_write(char data, unsigned char control);
void LCD_command(unsigned char command);
void LCD_data(char data);
void LCD_init(void);
void PORTS_init(void);
volatile int flag;
volatile int flag1;

volatile int flags0;
volatile int flags2;

volatile int hansflag;		//Hans' flags are used in Urban Traffic with Crossing to enable sensible transitions
volatile int hansflag2;

int main(void) {
    /* initialize LCD controller */
    LCD_init();
		
				LCD_data('H');
        LCD_data('E');
        LCD_data('L');
        LCD_data('L');
        LCD_data('O');
				LCD_data(33);
        delayMs(1500);
				
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
				
				LCD_data('W');
        LCD_data('E');
        LCD_data('L');
        LCD_data('C');
        LCD_data('O');
				LCD_data('M');
				LCD_data('E');
				LCD_data(32); //blank space
				LCD_data('T');
				LCD_data('O');
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
				
        LCD_data('H');
        LCD_data('A');
        LCD_data('N');
        LCD_data(39);
				LCD_data('S');
				LCD_data(32);		
				LCD_data(38);	
				LCD_data(32);		
				LCD_data('N');
        LCD_data('I');
        LCD_data('G');
				LCD_data('E');
				LCD_data('L');
        LCD_data(39);
				LCD_data('S');
		
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
				
				
				LCD_data('P');
        LCD_data('R');
        LCD_data('O');
        LCD_data('P');
        LCD_data('R');
				LCD_data('I');
				LCD_data('E');
				LCD_data('T');
				LCD_data('A');
				LCD_data('R');
				LCD_data('Y');
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
				
				LCD_data('T');
        LCD_data('R');
        LCD_data('A');
        LCD_data('F');
        LCD_data('F');
				LCD_data('I');
				LCD_data('C');
				LCD_data(32);
				LCD_data('S');
				LCD_data('Y');
				LCD_data('S');
				LCD_data('T');
				LCD_data('E');
				LCD_data('M');
				LCD_data(33);
       
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
				
				LCD_data('S');
        LCD_data('E');
        LCD_data('L');
        LCD_data('E');
        LCD_data('C');
				LCD_data('T');
				LCD_data(32);
				LCD_data(39);
				LCD_data(49);
				LCD_data(39);
				LCD_data(32);
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
			
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
			
				
				LCD_data('F');
        LCD_data('O');
				LCD_data('R');
				LCD_data(32);
				LCD_data('U');
        LCD_data('R');
        LCD_data('B');
        LCD_data('A');
        LCD_data('N');
				LCD_data(32);
				LCD_data('M');
        LCD_data('O');
				LCD_data('D');
				LCD_data('E');
				LCD_data(46); //period in ascii
				
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
				
				LCD_data('S');
        LCD_data('E');
        LCD_data('L');
        LCD_data('E');
        LCD_data('C');
				LCD_data('T');
				LCD_data(32);
				LCD_data(39);
				LCD_data(50);
				LCD_data(39);
				LCD_data(32);
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
			
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
			
				LCD_data('F');
        LCD_data('O');
				LCD_data('R');
				LCD_data(32);
				LCD_data('R');
        LCD_data('U');
        LCD_data('R');
        LCD_data('A');
        LCD_data('L');
				LCD_data(32);
				LCD_data('M');
        LCD_data('O');
				LCD_data('D');
				LCD_data('E');
				LCD_data(46); //period in ascii
				
			delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);

				LCD_data('S');
        LCD_data('E');
        LCD_data('L');
        LCD_data('E');
        LCD_data('C');
				LCD_data('T');
				LCD_data(32);
				LCD_data(39);
				LCD_data(51);
				LCD_data(39);
				LCD_data(32);
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
			
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
			
				
				LCD_data('F');
        LCD_data('O');
				LCD_data('R');
				LCD_data(32);
				LCD_data('U');
        LCD_data('R');
        LCD_data('B');
        LCD_data('A');
        LCD_data('N');
				LCD_data(32);
				LCD_data('C');
        LCD_data('R');
				LCD_data('O');
				LCD_data('S');
				LCD_data('S');
				LCD_data(46); //period in ascii

				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);

				LCD_data('S');
        LCD_data('E');
        LCD_data('L');
        LCD_data('E');
        LCD_data('C');
				LCD_data('T');
				LCD_data(32);
				LCD_data(39);
				LCD_data(52);
				LCD_data(39);
				LCD_data(32);
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
				LCD_data(46); //period in ascii
			
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
			
				
				LCD_data('F');
        LCD_data('O');
				LCD_data('R');
				LCD_data(32);
				LCD_data('R');
        LCD_data('U');
        LCD_data('R');
        LCD_data('A');
        LCD_data('L');
				LCD_data(32);
				LCD_data('C');
        LCD_data('R');
				LCD_data('O');
				LCD_data('S');
				LCD_data('S');
				LCD_data(46); //period in ascii

					delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
				 
				RCC->APB2ENR |= 0x00004000;             /* enable SYSCFG clock */


				SYSCFG->EXTICR[2] &= ~0x00F0;       /* clear port selection for EXTI9 */
				SYSCFG->EXTICR[2] |= 0x0020;        /* select port C for EXTI9 */
    
			EXTI->IMR |= 0x200;                /* unmask EXTI9 */
			EXTI->FTSR |= 0x200;               /* select falling edge trigger */
			
				GPIOC->PUPDR |= 0x00040000;
				GPIOC->MODER = 0x00000000;
				GPIOC->MODER |= 0x00515555;
				GPIOB->MODER =	0x00000000;
				GPIOB->MODER |=	0x00155411;
						
		
				NVIC_EnableIRQ(EXTI9_5_IRQn);     /* enable interrupt in NVIC */
				__enable_irq();

				//Mode Selection
				RCC->AHB1ENR |= 7;
				GPIOC->MODER |=0x00510055;
				
				
	while (1){			
				int a = ((GPIOA->IDR) & 0x01E0);
				a = a>>5;

		switch(a){
		
			
					case 1:   //This is Urban Traffic mode
		
   LCD_command(1); /* clear LCD display */
   LCD_data('R');
   LCD_data('u');
	 LCD_data('n');
	 LCD_data('n');
   LCD_data('i');
   LCD_data('n');
   LCD_data('g');
   LCD_data(32);
	 LCD_data('U');
   LCD_data('r');
	 LCD_data('b');
	 LCD_data('a');
	 LCD_data('n');
   LCD_data(46);
   LCD_data(46);
   LCD_data(46);
					
		GPIOC->ODR |= 0x00000801;
		delayMs(5000);
		GPIOC->ODR = 0x00000000;
		
		GPIOC->ODR |= 0x00000802;
		delayMs(2000);
		GPIOC->ODR = 0x00000000;
		
	
		GPIOC->ODR |= 0x0000000C;
		delayMs(5000);
		GPIOC->ODR = 0x00000000;	
		
			
		GPIOC->ODR |= 0x00000404;
		delayMs(2000);
		GPIOC->ODR = 0x00000000;					
	
		
						break;
	
					case 2: //This is Rural Traffic mode
						
								
				LCD_command(1); /* clear LCD display */		
				LCD_data('R');
        LCD_data('u');
				LCD_data('n');
				LCD_data('n');
        LCD_data('i');
        LCD_data('n');
        LCD_data('g');
				LCD_data(32);
				LCD_data('R');
        LCD_data('u');
				LCD_data('r');
				LCD_data('a');
				LCD_data('l');
        LCD_data(46);
        LCD_data(46);
        LCD_data(46);
    
							
					
		GPIOC->ODR |= 0x00000801; /*state S0 */
		delayMs(5000);
						
				while((GPIOC->IDR & 0x00002000)&&(a==2)){}
		GPIOC->ODR = 0x00000000;
						
		GPIOC->ODR |= 0x00000802;
		delayMs(2000);
		GPIOC->ODR = 0x00000000;
		
		GPIOC->ODR |= 0x0000000C;
		delayMs(5000);
					while ((GPIOC->IDR & 0x00002000)&&(a==2)){}
		GPIOC->ODR = 0x00000000;	

		GPIOC->ODR |= 0x00000404;
		delayMs(2000);
		GPIOC->ODR = 0x00000000;				
		
		
						
					break;								//This is the end of Rural Traffic mode
						
					case 4:	//This is Urban Traffic with Crosswalk mode
					
						__enable_irq();
					
				
				LCD_command(1); /* clear LCD display */		
				LCD_data('U');
        LCD_data('r');
				LCD_data('b');
				LCD_data('a');
        LCD_data('n');
        LCD_data(32);
        LCD_data('X');
				LCD_data(39);
				LCD_data('i');
        LCD_data('n');
				LCD_data('g');
        LCD_data(46);
        LCD_data(46);
        LCD_data(46);
				
					flags0 = 1;
					flags2 = 0; 			
					hansflag = 0;
					hansflag2 = 0;
		
	
				NVIC_DisableIRQ(EXTI9_5_IRQn); 
				GPIOC->ODR |= 0x00000801;
				delayMs(5000);										//state s0; NSR, EWG
				GPIOC->ODR = 0x00000000;
				NVIC_EnableIRQ(EXTI9_5_IRQn); 
				
				
				if(hansflag == 0){
				NVIC_DisableIRQ(EXTI9_5_IRQn); 
				GPIOC->ODR |= 0x00000802;
				delayMs(2000);									//state s1; NSR, EWY
				GPIOC->ODR = 0x00000000;
				NVIC_EnableIRQ(EXTI9_5_IRQn); 
				}
				
				flags0 = 0;
				flags2 = 1; 
				hansflag = 0;
				hansflag2 = 0;
				
				NVIC_DisableIRQ(EXTI9_5_IRQn); 
				GPIOC->ODR |= 0x0000000C;
				delayMs(5000);										//state s2; NSG, EWR
				GPIOC->ODR = 0x00000000;	
				NVIC_EnableIRQ(EXTI9_5_IRQn); 
				
				
				if(hansflag2 == 0){
				NVIC_DisableIRQ(EXTI9_5_IRQn); 
				GPIOC->ODR |= 0x00000404;
				delayMs(2000);										//state s3; NSY, EWR
				GPIOC->ODR = 0x00000000;	
				NVIC_EnableIRQ(EXTI9_5_IRQn); 							
				}
									
				__disable_irq();	
					break;					//This is the end of Urban Traffic with Crosswalk mode
							
					case 8:			//This is Rural Traffic with Crosswalk mode
			__disable_irq();

	
			NVIC_EnableIRQ(EXTI9_5_IRQn);     /* enable interrupt in NVIC */
			
			__enable_irq();
				LCD_command(1); /* clear LCD display */		
				LCD_data('R');
        LCD_data('u');
				LCD_data('r');
				LCD_data('a');
        LCD_data('l');
        LCD_data(32);
        LCD_data('X');
				LCD_data(39);
				LCD_data('i');
        LCD_data('n');
				LCD_data('g');
        LCD_data(46);
        LCD_data(46);
        LCD_data(46);
    
		label2:							
		flags0 = 1; 		//flag for state 0 to be interpreted by the interrupt function (so system doesn't transition directly to EWR/NSR -- this ensures a yellow state)
		flags2 = 0;			
		flag =	 0;
		flag1 =	 0;
		
		
		NVIC_DisableIRQ(EXTI9_5_IRQn);										//Ensures a minimum time for EWG to be active in which an interrupt cannot be called
		GPIOC->ODR |= 0x00000801; /*state S0: NSR, EWG*/
		delayMs(2000);
		NVIC_EnableIRQ(EXTI9_5_IRQn);	
		
		
		while(GPIOC->IDR & 0x00002000){
		flags0=1; 			
		if(flag==1){
			goto label;
							 }	
																	}
								
		NVIC_DisableIRQ(EXTI9_5_IRQn);	
		GPIOC->ODR = 0x00000000;
		GPIOC->ODR |= 0x00000802;  					/*state S1: NSR, EWY*/
		delayMs(2000);
		NVIC_EnableIRQ(EXTI9_5_IRQn);	
																	
		label:	
		NVIC_DisableIRQ(EXTI9_5_IRQn);
		flags0 = 0;
		flags2 = 1;
		flag =0;
		flag1 =0;
		
																	
		GPIOC->ODR = 0x00000000;
		GPIOC->ODR |= 0x0000000C; 					/*state S2: NSG, EWR */
		delayMs(2000);
		NVIC_EnableIRQ(EXTI9_5_IRQn);										
		
	
				
	while (GPIOC->IDR & 0x00002000){
	if(flag1==1){
		flags2 = 1; 
		goto label2;
							}	
	}
			flag =0;
			flag1 =0;
			flags2 = 0; 
	
	NVIC_DisableIRQ(EXTI9_5_IRQn);	
		GPIOC->ODR = 0x00000000;	
	GPIOC->ODR |= 0x00000404;  /*state S3: NSY, EWR */
		delayMs(2000);
	NVIC_EnableIRQ(EXTI9_5_IRQn);				
		GPIOC->ODR = 0x00000000;
		
	break;
									
			
				default:			
					
				LCD_data('Y');
        LCD_data('o');
				LCD_data('u');
				LCD_data('r');
        LCD_data(32);
        LCD_data('i');
        LCD_data('n');
				LCD_data('p');
        LCD_data('u');
				LCD_data('t');
        LCD_data(46);
        LCD_data(46);
        LCD_data(46);
				
				delayMs(1500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
								
				LCD_data(46);
        LCD_data(46);
        LCD_data(46);
        LCD_data('i');
				LCD_data('s');
				LCD_data(32);
				LCD_data('g');
        LCD_data('a');
        LCD_data('r');
				LCD_data('b');
        LCD_data('a');
				LCD_data('g');
				LCD_data('e');
        LCD_data(46);
 
					delayMs(9500);
			/* clear LCD display */
      	LCD_command(1);
        delayMs(1000);
								
											}
										}
									}
void EXTI9_5_IRQHandler(void) {
// if (EXTI->PR == 0x200) {       /* interrupt from PC9 (use this if there are multiple interrupts)*/

		if(flags0==1){	/*if in state S0 */	
			
			GPIOC->ODR = 0x00000000;
			GPIOC->ODR |= 0x00000802;			
			delayMs(2000);
			GPIOC->ODR = 0x00000000;
			flags0=0;
		} 	 								
	 
		if(flags2==1){	/*if in state S2 */	
			
			GPIOC->ODR = 0x00000000;
			GPIOC->ODR |= 0x00000404;			 //finish out yellow
			delayMs(2000);
			GPIOC->ODR = 0x00000000;
			flags2=0;
		} 	
	
									GPIOC->ODR = 0x00000904;
//									GPIOB->ODR = sev_seg1[i];
//									GPIOC->ODR = sev_seg[i];
									GPIOB->ODR = 0x00000605;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 9
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;
										
									GPIOC->ODR = 0x00000904;
									GPIOB->ODR = 0x00000745;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 8
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;	
										
									GPIOC->ODR = 0x00000804;
									GPIOB->ODR = 0x00000405;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 7
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;		
										
									GPIOC->ODR = 0x00000904;
									GPIOB->ODR = 0x00000740;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 6
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;	
										
									GPIOC->ODR = 0x00000904;
									GPIOB->ODR = 0x00000641;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 5
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;	
									
									GPIOC->ODR = 0x00000904;
									GPIOB->ODR = 0x00000604;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 4
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;
									
									GPIOC->ODR = 0x00000904;
									GPIOB->ODR = 0x00000445;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 3
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;
									
									GPIOC->ODR = 0x00000904;
									GPIOB->ODR = 0x00000145;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 2
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;
									
									GPIOC->ODR = 0x00000804;
									GPIOB->ODR = 0x00000404;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 1
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;
									
									GPIOC->ODR = 0x00000804;
									GPIOB->ODR = 0x00000745;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 0
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;
									
									GPIOC->ODR = 0x00000804;
									GPIOB->ODR = 0x00000000;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment BLANK
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;
									
									GPIOC->ODR = 0x00000804;
									GPIOB->ODR = 0x00000745;
									delayMs(1000);										//Outputting NSR, EWR, and seven-segment 0
									GPIOC->ODR = 0x00000000;
									GPIOB->ODR = 0x00000000;
			EXTI->PR = 0x200;         									 /* clear interrupt pending flag */
			flag = 1;
			flag1 = 1;
			hansflag = 1;
			hansflag2 = 1;
//}
   
}


/* initialize GPIOB/C then initialize LCD controller */
void LCD_init(void) {
    PORTS_init();

    delayMs(20);                /* LCD controller reset sequence */
    LCD_nibble_write(0x30, 0);
    delayMs(5);
    LCD_nibble_write(0x30, 0);
    delayMs(1);
    LCD_nibble_write(0x30, 0);
    delayMs(1);

    LCD_nibble_write(0x20, 0);  /* use 4-bit data mode */
    delayMs(1);
    LCD_command(0x28);          /* set 4-bit data, 2-line, 5x7 font */
    LCD_command(0x06);          /* move cursor right */
    LCD_command(0x01);          /* clear screen, move cursor to home */
    LCD_command(0x0F);          /* turn on display, cursor blinking */
}

void PORTS_init(void) {
    RCC->AHB1ENR |=  0x07;          /* enable GPIOA/B/C clock */

    /* PORTB 5 for LCD R/S */
    /* PORTB 7 for LCD EN */
    GPIOB->MODER &= ~0x0000CC00;    /* clear pin mode */
  //  GPIOB->MODER |=  0x00004400;    /* set pin output mode */
		GPIOB->MODER |=  0x00004500;    /* set pin output mode */
    GPIOB->BSRR = 0x00800000;       /* turn off EN */
		GPIOA->MODER =  0x00000000;
		GPIOA->PUPDR = 0x00015400;
    /* PC4-PC7 for LCD D4-D7, respectively. */
    GPIOC->MODER &= ~0x0000FF00;    /* clear pin mode */
    GPIOC->MODER |=  0x00005500;    /* set pin output mode */
}

void LCD_nibble_write(char data, unsigned char control) {
    /* populate data bits */
    GPIOC->BSRR = 0x00F00000;       /* clear data bits */
    GPIOC->BSRR = data & 0xF0;      /* set data bits */

    /* set R/S bit */
    if (control & RS)
        GPIOB->BSRR = RS;
    else
        GPIOB->BSRR = RS << 16;

    /* pulse E */
    GPIOB->BSRR = EN;
    delayMs(0);
    GPIOB->BSRR = EN << 16;
}

void LCD_command(unsigned char command) {
    LCD_nibble_write(command & 0xF0, 0);    /* upper nibble first */
    LCD_nibble_write(command << 4, 0);      /* then lower nibble */

    if (command < 4)
        delayMs(2);         /* command 1 and 2 needs up to 1.64ms */
    else
        delayMs(1);         /* all others 40 us */
}

void LCD_data(char data) {
    LCD_nibble_write(data & 0xF0, RS);      /* upper nibble first */
    LCD_nibble_write(data << 4, RS);        /* then lower nibble */

    delayMs(1);
}

/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n) {
    int i;

    /* Configure SysTick */
    SysTick->LOAD = 16000;  /* reload with number of clocks per millisecond */
    SysTick->VAL = 0;       /* clear current value register */
    SysTick->CTRL = 0x5;    /* Enable the timer */

    for(i = 0; i < n; i++) {
        while((SysTick->CTRL & 0x10000) == 0) /* wait until the COUNTFLAG is set */
            { }
    }
    SysTick->CTRL = 0;      /* Stop the timer (Enable = 0) */
}