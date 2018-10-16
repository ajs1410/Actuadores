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
