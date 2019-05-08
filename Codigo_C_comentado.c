void inicio();

void (*isr[])() __attribute__ ((section (".vetor")))={  // Dá atributo ao ponteiro de função
		(void (*)())0x20020000, // Final da RAM de 128K
		inicio
};

void inicio(){
	*((int*)(0x40023800 + 0x30))=0x08; 		 // Habilita a PORTD
	*((int*)(0x40020C00 + 0x00))=0x01000000; // Habilita o modo output
	*((int*)(0x40020C00 + 0x04))=0x00000000; // Habilita o modo output push-pull
	*((int*)(0x40020C00 + 0x08))=0x00000000; // Habilita o modo speed low
	*((int*)(0x40020C00 + 0x0c))=0x00000000; // Habilita o modo No pull-up, pull-down
	int ligado=0x1000; //Define o valor de ligado
	int desligado=0x0000; //Define o valor de desligado
	int i;
	int *ptr=(int*)(0x40020C00 + 0x14); //Define o ponteiro para o endereço de GPIOD_ODR
loop:
	i=800000;
	*ptr=ligado;  //Liga o LED
	while(i--);
	*ptr=desligado; //Deslig o LED
	i=800000;
	while(i--);
	goto loop;
}
