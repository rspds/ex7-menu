/* ========================================================================================================
 
   Curso de Arduino e AVR 134
   
   WR Kits Channel


   Menu no Formato de Lista com Display LCD I2C

    
   Autor: Eng. Wagner Rambo  Data: Agosto de 2017
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits | dailymotion.com/wrkits
   
======================================================================================================== */


// ========================================================================================================
// --- Bibliotecas Auxiliares ---
#include <LiquidCrystal.h>


// ========================================================================================================
// --- Mapeamento de Hardware ---
#define     menu     12
#define     enter    11
#define 		voltar   10
#define 		QUANT_C1 2
#define 		QUANT_C2 4


// ========================================================================================================
// --- Protótipo das Funções ---
void readButts();
void list_menu1();
void menu_select();


// ========================================================================================================
// --- Declaração de Objetos ---
LiquidCrystal lcd(7,  //RS no digital 7
                  6,  //EN no digital 6
                  5,  //D4 no digital 5
                  4,  //D5 no digital 4
                  3,  //D6 no digital 3
                  2); //D7 no digital 2


// ========================================================================================================
// --- Variáveis Globais ---
int      lineC1[5] = {0,1,2,3,4},
         lineC2[5] = {0,1,2,3,4},
         menu_number = 1;

boolean  menu_flag  = 0,
         enter_flag = 0,
         voltar_flag = 0,
         sub_menuC1 = 0;
         sub_menuC2 = 0;


// ========================================================================================================
// --- Configurações Iniciais ---
void setup()
{

  //Serial.begin(9600);
  pinMode(menu,  INPUT_PULLUP);
  pinMode(enter, INPUT_PULLUP);
 

  
 lcd.begin (16,4);
 lcd.setBacklight(HIGH);
 lcd.setCursor(0,0);
 lcd.print(">");
 
 
} //end setup


// ========================================================================================================
// --- Loop Infinito ---
void loop()
{


	camada1();  


  
} //end loop

void camada1();  
{
  if(!sub_menuC1)
  {
    lcd.setCursor(1,line[0]);
    lcd.print("1) Motor        ");
    lcd.setCursor(1,line[1]);
    lcd.print("2) Light        ");
    lcd.setCursor(1,line[2]);
    lcd.print("3) Valve        ");
    lcd.setCursor(1,line[3]);
    lcd.print("4) Actuator     ");
    lcd.setCursor(1,line[4]);
    lcd.print("5) Help         ");
  }
  

  readButts();
}
 
void camada2();  
{
  if(!sub_menuC1)
  {
    lcd.setCursor(1,line[0]);
    lcd.print("1) Motor        ");
    lcd.setCursor(1,line[1]);
    lcd.print("2) Light        ");
    lcd.setCursor(1,line[2]);
    lcd.print("3) Valve        ");
    lcd.setCursor(1,line[3]);
    lcd.print("4) Actuator     ");
    lcd.setCursor(1,line[4]);
    lcd.print("5) Help         ");
  }
  

  readButts();
}
  
void readButtsC1()
{
  
   if(!digitalRead(menu))  menu_flag  = 0x01;
   if(!digitalRead(enter)) enter_flag = 0x01;

   if(digitalRead(menu) && menu_flag)
   {
       menu_flag = 0x00;
       list_menu(lineC1, QUANT_C1);
       menu_number+=1;
       if(menu_number > 5) menu_number = 1;
    
   } //end if menu

   if(digitalRead(enter) && enter_flag)
   {
      enter_flag = 0x00; 
      sub_menuC1 = !sub_menuC1;
      menu_select();
    
   } //end if menu
  
  
} //end readButts

void readButtsC2()
{
  
   if(!digitalRead(menu))  menu_flag  = 0x01;
   if(!digitalRead(enter)) enter_flag = 0x01;

   if(digitalRead(menu) && menu_flag)
   {
       menu_flag = 0x00;
       list_menu(lineC2, QUANT_C2);
       menu_number+=1;
       if(menu_number > 5) menu_number = 1;
    
   } //end if menu

   if(digitalRead(enter) && enter_flag)
   {
      enter_flag = 0x00; 
      sub_menuC1 = !sub_menuC1;
      menu_select();
    
   } //end if menu
  
  
} //end readButts


void list_menu(int line[], int quantidade)
{
	int index, i, line_bk[i];

  for(i=quantidade; i>-1; i--) 
  {
     index = i-1;
     line_bk[i] = line[i];
     
     if(index < 0) line[i] = line_bk[i+4];
     
     else line[i] = line[i-1];

  }

} //end list_menu


void menu_selectC3()
{

    switch(menu_number)
    {
       case 1: 
               lcd.setCursor(1,0);
               lcd.print("Motor Control  ");
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
       case 2: 
               lcd.setCursor(1,0);
               lcd.print("Light Control  ");
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
       case 3: 
               lcd.setCursor(1,0);
               lcd.print("Valve Control  ");
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
       case 4: 
               lcd.setCursor(1,0);
               lcd.print("Actuator Ctrl  ");
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
       case 5: 
               lcd.setCursor(1,0);
               lcd.print("Help System    ");
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
      
    } //end switch
  
 
} //end menu_select




