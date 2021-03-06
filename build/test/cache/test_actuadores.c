#include "build/temp/_test_actuadores.c"
#include "actuadores.h"
#include "unity.h"
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

  UnityAssertEqualNumber((UNITY_INT)((ejemplos[indice].pwm)), (UNITY_INT)((ptAct[indice].PWM_actual)), ((mensaje)), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

  sprintf(mensaje, "Test Estado Actuador: %d", indice);

  UnityAssertEqualNumber((UNITY_INT)((ejemplos[indice].estado)), (UNITY_INT)((ptAct[indice].estado)), ((mensaje)), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((UNITY_INT)((ejemplos[indice].estado)), (UNITY_INT)((ptAct[indice].estado)), ((mensaje)), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

 }



}









void test_apagarActuadores(void){

actuador_t ptAct[6];

 const struct ejemplo_s{

 uint16_t pwm;

 uint8_t estado;

 }ejemplos[] = {

 {.pwm = 0, .estado = INICIO_APAGADO},

 {.pwm = 0, .estado = INICIO_APAGADO},

 {.pwm = 0, .estado = INICIO_APAGADO},

 {.pwm = 0, .estado = INICIO_APAGADO},

 {.pwm = 0, .estado = INICIO_APAGADO},

 {.pwm = 0, .estado = INICIO_APAGADO},

 };

 uint8_t indice;

 char mensaje[64];

 Actuadores_Create(&ptAct[0]);



 for( indice = 0; indice < sizeof(ejemplos)/sizeof (struct ejemplo_s); indice++){

  Actuadores_Apagar(&ptAct[indice], indice);

  sprintf(mensaje, "Test Estado Actuador: %d", indice);

  UnityAssertEqualNumber((UNITY_INT)((ejemplos[indice].estado)), (UNITY_INT)((ptAct[indice].estado)), ((mensaje)), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

 }



}







void test_estadosActuadores(void){

actuador_t ptAct[6];

 const struct ejemplo_s{

 uint16_t pwm;

 uint8_t estado;

 }ejemplos1[] = {

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 {.pwm = 0, .estado = MANTENCION_APAGADO},

 }, ejemplos2[] = {

 {.pwm = 0, .estado = MANTENCION_ENCENDIDO},

 {.pwm = 0, .estado = MANTENCION_ENCENDIDO},

 {.pwm = 0, .estado = MANTENCION_ENCENDIDO},

 {.pwm = 0, .estado = MANTENCION_ENCENDIDO},

 {.pwm = 0, .estado = MANTENCION_ENCENDIDO},

 {.pwm = 0, .estado = MANTENCION_ENCENDIDO},

 };

 uint8_t indice;

 char mensaje[64];

 Actuadores_Create(&ptAct[0]);



 for( indice = 0; indice < sizeof(ejemplos1)/sizeof (struct ejemplo_s); indice++){

  Actuadores_Apagar(&ptAct[indice], indice);

  Actuadores_MEF(&ptAct[indice]);

  sprintf(mensaje, "Test Estado Actuador: %d", indice);

  UnityAssertEqualNumber((UNITY_INT)((ejemplos1[indice].estado)), (UNITY_INT)((ptAct[indice].estado)), ((mensaje)), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);

 }





 for( indice = 0; indice < sizeof(ejemplos2)/sizeof (struct ejemplo_s); indice++){

  Actuadores_Encender(&ptAct[indice], indice);

  Actuadores_MEF(&ptAct[indice]);

  sprintf(mensaje, "Test Estado Actuador: %d", indice);

  UnityAssertEqualNumber((UNITY_INT)((ejemplos2[indice].estado)), (UNITY_INT)((ptAct[indice].estado)), ((mensaje)), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);

 }





}











void test_ejecutarTabla(void){

actuador_t ptAct[6];



const struct ejemplo_c{

 uint8_t accion;

 uint8_t estado;

 }ejemplosc[] = {

 {.accion = 1, .estado = INICIO_ENCENDIDO},

 {.accion = 1, .estado = INICIO_ENCENDIDO},

 {.accion = 1, .estado = INICIO_ENCENDIDO},

 {.accion = 1, .estado = INICIO_ENCENDIDO},

 {.accion = 1, .estado = INICIO_ENCENDIDO},

 {.accion = 1, .estado = INICIO_ENCENDIDO},

 };

 uint8_t indice;

 char mensaje[64];

 Actuadores_Create(&ptAct[0]);



 for( indice = 0; indice < sizeof(ejemplosc)/sizeof (struct ejemplo_c); indice++){

  Actuadores_EjecutarTabla(&ptAct[indice], indice, ejemplosc[indice].accion);

  sprintf(mensaje, "Test Estado Actuador: %d", indice);

  UnityAssertEqualNumber((UNITY_INT)((ejemplosc[indice].estado)), (UNITY_INT)((ptAct[indice].estado)), ((mensaje)), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_INT);

 }







}
