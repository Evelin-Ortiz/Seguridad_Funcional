#include <xc.h>
#include "CONFIG.h"
#include "Color_RGB.h"

void Color(unsigned char red,unsigned char green,unsigned char blue){
    ldatae =0;
    ROJO  = red;
    VERDE = green;
    AZUL  = blue;
    
    
}