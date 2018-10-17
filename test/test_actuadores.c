#include "unity.h"
#include "actuadores.h"
#include "stdint.h"

#if 0
#include "mock_FreeRTOS.h"
#include "mock_FreeRTOSConfig.h"
#include "mock_os_task.h"
#include "mock_os_semphr.h"
#include "mock_os_queue.h"
#endif

 void setup(void){

}



void tearDown(void){


}


void test_actuadoresOffAfterCreate(void){
actuador_t  ptAct[6];
Actuadores_Create(&ptAct[0]); 					// retorna en le puntero ptAct el estado de cada actuador, porcentaje de pwm

TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[0].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[1].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[2].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[3].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[4].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[5].PWM_actual);

}

// test que compruba que esten apagados los actuadores
void test_encenderActuadores(void){
actuador_t  ptAct[6];
uint8_t Enc_act=0b00111111;

Actuadores_Create(&ptAct[0]); // retorna con todos los pwm apagados
Actuadores_Encender(&ptAct[0], Enc_act);

TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[0].estado); // verifico que todos los actuadores esten encendidos
TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[1].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[2].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[3].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[4].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[5].estado);

Enc_act=0b00010101;
Actuadores_Create(&ptAct[0]); // retorna con todos los pwm apagados
Actuadores_Encender(&ptAct[0], Enc_act);

TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[0].estado); // verifico que esten encendidos unicamente los actuadores indicados.
TEST_ASSERT_EQUAL_HEX8(MANTENCION_APAGADO,ptAct[1].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[2].estado);
TEST_ASSERT_EQUAL_HEX8(MANTENCION_APAGADO,ptAct[3].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[4].estado);
TEST_ASSERT_EQUAL_HEX8(MANTENCION_APAGADO,ptAct[5].estado);


}

// test que comprueba que esten apagado los actuadores
void test_apagarActuadores(void){
actuador_t  ptAct[6];
uint8_t Apagar_act=0b00111111;

Actuadores_Create(&ptAct[0]); // retorna con todos los pwm apagados
Actuadores_Apagar(&ptAct[0], Apagar_act);

TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[0].estado); // verifico que todos los actuadores esten encendidos
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[1].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[2].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[3].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[4].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[5].estado);

Apagar_act=0b00010101;
Actuadores_Create(&ptAct[0]); // retorna con todos los pwm apagados
Actuadores_Apagar(&ptAct[0], Apagar_act);

TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[0].estado); // verifico que esten encendidos unicamente los actuadores indicados.
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[2].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[4].estado);

}


void test_estadosActuadores(void){
actuador_t  ptAct[6];
uint8_t Enc_act=0b00111111;
uint8_t Apagar_act=0b00111111;

Actuadores_Create(&ptAct[0]); // retorna con todos los pwm apagados

Actuadores_Encender(&ptAct[0], Enc_act);
Actuadores_MEF(&ptAct[0]);
TEST_ASSERT_EQUAL_HEX8(MANTENCION_ENCENDIDO,ptAct[0].estado); // verifico que todos los actuadores esten encendidos

Actuadores_Apagar(&ptAct[0], Apagar_act);
Actuadores_MEF(&ptAct[0]);
TEST_ASSERT_EQUAL_HEX8(MANTENCION_APAGADO,ptAct[0].estado); // verifico que todos los actuadores esten encendidos


}
