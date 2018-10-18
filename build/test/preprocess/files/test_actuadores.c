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

  UnityAssertEqualNumber((UNITY_INT)((ejemplos[indice].pwm)), (UNITY_INT)((ptAct[indice].PWM_actual)), ((mensaje)), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

  sprintf(mensaje, "Test Estado Actuador: %d", indice);

  UnityAssertEqualNumber((UNITY_INT)((ejemplos[indice].estado)), (UNITY_INT)((ptAct[indice].estado)), ((mensaje)), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

 }









}





void test_encenderActuadores(void){

actuador_t ptAct[6];

uint8_t Enc_act=0b00111111;



Actuadores_Create(&ptAct[0]);

Actuadores_Encender(&ptAct[0], Enc_act);



UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[1].estado)), (

((void *)0)

), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[3].estado)), (

((void *)0)

), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[5].estado)), (

((void *)0)

), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_HEX8);



Enc_act=0b00010101;

Actuadores_Create(&ptAct[0]);

Actuadores_Encender(&ptAct[0], Enc_act);



UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((MANTENCION_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[1].estado)), (

((void *)0)

), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((MANTENCION_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[3].estado)), (

((void *)0)

), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((MANTENCION_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[5].estado)), (

((void *)0)

), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_HEX8);





}





void test_apagarActuadores(void){

actuador_t ptAct[6];

uint8_t Apagar_act=0b00111111;



Actuadores_Create(&ptAct[0]);

Actuadores_Apagar(&ptAct[0], Apagar_act);



UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[1].estado)), (

((void *)0)

), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[3].estado)), (

((void *)0)

), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[5].estado)), (

((void *)0)

), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_HEX8);



Apagar_act=0b00010101;

Actuadores_Create(&ptAct[0]);

Actuadores_Apagar(&ptAct[0], Apagar_act);



UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_HEX8);



}







void test_estadosActuadores(void){

actuador_t ptAct[6];

uint8_t Enc_act=0b00111111;

uint8_t Apagar_act=0b00111111;



Actuadores_Create(&ptAct[0]);



Actuadores_Encender(&ptAct[0], Enc_act);

Actuadores_MEF(&ptAct[0]);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((MANTENCION_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_HEX8);



Actuadores_Apagar(&ptAct[0], Apagar_act);

Actuadores_MEF(&ptAct[0]);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((MANTENCION_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(137), UNITY_DISPLAY_STYLE_HEX8);





}







void test_ejecutarTabla(void){

actuador_t ptAct[6];

uint8_t Enc_act =0b00010101;

uint8_t Apagar_act=0b00101010;

uint16_t tabla = 0b0010101000010101;



Actuadores_Create(&ptAct[0]);



Actuadores_EjecutarTabla(&ptAct[0], tabla);





UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(155), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[1].estado)), (

((void *)0)

), (UNITY_UINT)(156), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(157), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[3].estado)), (

((void *)0)

), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(159), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[5].estado)), (

((void *)0)

), (UNITY_UINT)(160), UNITY_DISPLAY_STYLE_HEX8);



}
