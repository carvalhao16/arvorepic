int leitura=0;
int conta=0;
void pausa(unsigned short i){
unsigned short j;
for(j=0;j<i;j++){
Delay_ms(10);
}}
unsigned int notas [] = {262,349,349,392,349,330,294,294,
392,392,440,392,349,330,362,362,440,440,494,440,392,349,294,262,262,294,392,330,349,262,349,349,392,349,330,294,294,294,
392,392,440,392,349,330,262,262,440,440,494,440,392,294,262,262,294,392,330,349,262};
unsigned short tempos [] = {4,4,8,8,4,4,4,4,8,8,4,4,4,4,8,8,4,4,8,4,4,4,2,4,4,8,8,4,4,4,4,8,8,4,4,4,4,8,8,4,4,8,4,4,4,2,4};
unsigned short k;
void interrupt() {
conta=conta++;
if(conta==5){
 portc.f5 = ~portc.f5;
 conta=0;}
 tmr0l = 0x38;
 tmr0h = 0x1A;
 intcon.tmr0if = 0;
}

void main () {
//PWm
Pwm1_init(4000);
pwm1_set_duty(0);
pwm1_start();
//timer
t0con = 0b10000111;
tmr0l = 0x38;
tmr0h = 0x1A;
intcon.tmr0if = 0;
intcon.gieh = 1;
intcon.tmr0ie = 1;
rcon.ipen = 1;
intcon2.tmr0ip = 1;

ADCON1=14;
CMCON=0x07;
Sound_Init(&PORTC,1);
trisb = 0;
trisc = 0b00000000;
portb = 0xff;
portb = 0x00;
TRISA.f0=1;
while(1){
leitura = Adc_Read(0)/4;
pwm1_set_duty(leitura);
if (PORTC.f5==0){
 PORTB = 0b00000001 ;
 PORTC.f6=1;
 delay_ms(400) ;
  PORTB =0b10000010 ;
  delay_ms(400) ;
 PORTB = 0b01000100  ;
 delay_ms(400) ;
 PORTB = 0b00101000  ;
 delay_ms(400) ;
 PORTB = 0b00010000 ;
 delay_ms(400) ;
 PORTB = 0b00101000  ;
 delay_ms(400) ;
 PORTB = 0b01000100 ;
 delay_ms(400) ;
 PORTB = 0b10000010;
 delay_ms(400) ;
 PORTB = 0b00000001 ;
  delay_ms(400) ;
}

if(PORTC.f5==1){
  PORTB =0b01010101 ;
  PORTC.f6=1;
  delay_ms(400) ;
  PORTB =0b10101010 ;
  PORTC.f6=0;
  delay_ms(400) ;
  PORTB =0b01010101 ;
  PORTC.f6=1;
  delay_ms(400) ;
  PORTB =0b10101010 ;
  PORTC.f6=0;
  delay_ms(400) ;
  PORTB =0b01010101 ;
  PORTC.f6=1;
  delay_ms(400) ;
  PORTB =0b10101010 ;
  PORTC.f6=0;
  delay_ms(400) ;
  PORTB =0b01010101 ;
  PORTC.f6=1;
  delay_ms(400) ;
  PORTB =0b10101010 ;
  PORTC.f6=0;
  delay_ms(400) ;
  PORTB =0b01010101 ;
  PORTC.f6=1;
  delay_ms(400) ;
 }
 for(k=0;k<25;K++){
 leitura = Adc_Read(0)/4;
 Pwm1_Set_Duty(leitura) ;
 PORTB = rand()%255;
Sound_Play(notas[k],100*tempos[k]);

}
}
}
