/*!
\file   seguridad.c
\date   2022-06-28
\author Fulvio Vivas <fyvivas@unicauca.edu.co>
\brief  Security House.

\par Copyright
Information contained herein is proprietary to and constitutes valuable
confidential trade secrets of unicauca, and
is subject to restrictions on use and disclosure.

\par
Copyright (c) unicauca 2022. All rights reserved.

\par
The copyright notices above do not evidence any actual or
intended publication of this material.
******************************************************************************
*/
#include <xc.h>
#include <pic16f887.h>  /*Header file PIC16f887 definitions*/
#include <stdio.h>
#include <string.h>
#include "CONFIG.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "Color_RGB.h"

//Fila salida del micro entrada del teclado
const char password[5] ={'1','5','9','8',0};
char pass_user[5];
unsigned char idx = 0;
int intentos=4;

void main() {

    char key = '0';
    //Configura Fosc = 8Mhz interno, Fuente de Fosc del sistema = interno
    OSCCON = 0x71; //Configura oscilador interno (FOSC = 8Mhz)
    ANSEL=0;
    LCD_Init(); //Inicializa el LCD

    keypad_init(); //Inicializa el keypad

    while (1) {
        if (intentos>0){
        LCD_String_xy(0,0,"INGRESE CLAVE");
        LCD_Command(0xC0); 
        do{
            key = keypad_getkey();
            if(key != 0){
                LCD_Char('*');/* display pressed key on LCD16x2 */
                //LCD_Char(key);/* display pressed key on LCD16x2 */
                pass_user[idx++] = key;
            }
            __delay_ms(100);
        }while(idx < 4);
        
        if(strncmp(pass_user,password,4)==0){
            LCD_Clear();
            LCD_String_xy(0,0,"Clave Correcta :D");
            Color(0,1,0);
        }
        else {
            LCD_Clear();
            LCD_String_xy(0,0,"Clave Incorrecta :C");
            Color(0,0,1);
            LCD_Clear();
            LCD_String_xy(0,0,"Otro Intento :C");
            intentos--;
        }}    
        else{   
        LCD_String_xy(0,0,"SISTEMA BLOQUEADO ^-^");
        Color(1,0,0);
        __delay_ms(2000);
        LCD_Clear();
        Color(0,0,0);
        }
        __delay_ms(2000);
        LCD_Clear();
        idx = 0;
        Color(0,0,0);
        }
}