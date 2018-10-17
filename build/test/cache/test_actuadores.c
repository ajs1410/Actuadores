#include "build/temp/_test_actuadores.c"
#include "actuadores.h"
#include "unity.h"
 void setup(void){



}







void tearDown(void){





}





void test_actuadoresOffAfterCreate(void){

actuador_t ptAct[6];

Actuadores_Create(&ptAct[0]);



UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ptAct[0].PWM_actual)), (

((void *)0)

), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_HEX16);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ptAct[1].PWM_actual)), (

((void *)0)

), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_HEX16);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ptAct[2].PWM_actual)), (

((void *)0)

), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_HEX16);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ptAct[3].PWM_actual)), (

((void *)0)

), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_HEX16);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ptAct[4].PWM_actual)), (

((void *)0)

), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX16);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ptAct[5].PWM_actual)), (

((void *)0)

), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);



}





void test_encenderActuadores(void){

actuador_t ptAct[6];

uint8_t Enc_act=0b00111111;



Actuadores_Create(&ptAct[0]);

Actuadores_Encender(&ptAct[0], Enc_act);



UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[1].estado)), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[3].estado)), (

((void *)0)

), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[5].estado)), (

((void *)0)

), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_HEX8);



Enc_act=0b00010101;

Actuadores_Create(&ptAct[0]);

Actuadores_Encender(&ptAct[0], Enc_act);



UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((MANTENCION_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[1].estado)), (

((void *)0)

), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((MANTENCION_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[3].estado)), (

((void *)0)

), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((MANTENCION_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[5].estado)), (

((void *)0)

), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_HEX8);





}





void test_apagarActuadores(void){

actuador_t ptAct[6];

uint8_t Apagar_act=0b00111111;



Actuadores_Create(&ptAct[0]);

Actuadores_Apagar(&ptAct[0], Apagar_act);



UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[1].estado)), (

((void *)0)

), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[3].estado)), (

((void *)0)

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[5].estado)), (

((void *)0)

), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_HEX8);



Apagar_act=0b00010101;

Actuadores_Create(&ptAct[0]);

Actuadores_Apagar(&ptAct[0], Apagar_act);



UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_HEX8);



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

), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_HEX8);



Actuadores_Apagar(&ptAct[0], Apagar_act);

Actuadores_MEF(&ptAct[0]);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((MANTENCION_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[0].estado)), (

((void *)0)

), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_HEX8);





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

), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[1].estado)), (

((void *)0)

), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[2].estado)), (

((void *)0)

), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[3].estado)), (

((void *)0)

), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_ENCENDIDO)), (UNITY_INT)(UNITY_INT8 )((ptAct[4].estado)), (

((void *)0)

), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_HEX8);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((INICIO_APAGADO)), (UNITY_INT)(UNITY_INT8 )((ptAct[5].estado)), (

((void *)0)

), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_HEX8);





}
