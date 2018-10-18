#include "build/temp/_test_actuadores.c"
#include "actuadores.h"
#include "unity.h"
 void setup(void){



}







void tearDown(void){





}





void test_actuadoresOffAfterCreate(void){

actuador_t ptAct[6];

 const struct ejemplo_s{

 uint16_t pwm;

 uint8_t estado;

 }ejemplos[] = {

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 };

 uint8_t indice;

 char mensaje[64];

 Actuadores_Create(&ptAct[0]);

 for( indice = 0; indice < sizeof(ejemplos)/sizeof (struct ejemplo_s); indice++){

  sprintf(mensaje, "Test PWM Actuador: %d", indice);

  UnityAssertEqualNumber((UNITY_INT)((ejemplos[indice].pwm)), (UNITY_INT)((ptAct[indice].PWM_actual)), ((mensaje)), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);

  sprintf(mensaje, "Test Estado Actuador: %d", indice);

  UnityAssertEqualNumber((UNITY_INT)((ejemplos[indice].estado)), (UNITY_INT)((ptAct[indice].estado)), ((mensaje)), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

 }



}





void test_encenderActuadores(void){

actuador_t ptAct[6];

 const struct ejemplo_s{

 uint16_t pwm;

 uint8_t estado;

 }ejemplos[] = {

 {.pwm = 0, .estado = INICIO_ENCENDIDO},

 {.pwm = 0, .estado = INICIO_ENCENDIDO},

 {.pwm = 0, .estado = INICIO_ENCENDIDO},

 {.pwm = 0, .estado = INICIO_ENCENDIDO},

 {.pwm = 0, .estado = INICIO_ENCENDIDO},

 {.pwm = 0, .estado = INICIO_ENCENDIDO},

 };

 uint8_t indice;

 char mensaje[64];

 Actuadores_Create(&ptAct[0]);



 for( indice = 0; indice < sizeof(ejemplos)/sizeof (struct ejemplo_s); indice++){

  Actuadores_Encender(&ptAct[indice], indice);

  sprintf(mensaje, "Test Estado Actuador: %d", indice);

  UnityAssertEqualNumber((UNITY_INT)((ejemplos[indice].estado)), (UNITY_INT)((ptAct[indice].estado)), ((mensaje)), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

 }



}
