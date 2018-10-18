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
#if 0

Actuadores_Create(&ptAct[0]); 					// retorna en le puntero ptAct el estado de cada actuador, porcentaje de pwm

TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[0].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[1].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[2].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[3].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[4].PWM_actual);
TEST_ASSERT_EQUAL_HEX16(0x0000,ptAct[5].PWM_actual);
#endif




	const struct ejemplo_s{
	uint16_t pwm;
	uint8_t estado;
	}ejemplos[] = {
	{.pwm = 0,  .estado = MANTENCION_APAGADO}, 
	{.pwm = 0,  .estado = MANTENCION_APAGADO}, 
	{.pwm = 0,  .estado = MANTENCION_APAGADO},
	{.pwm = 0,  .estado = MANTENCION_APAGADO},
	{.pwm = 0,  .estado = MANTENCION_APAGADO},
	{.pwm = 0,  .estado = MANTENCION_APAGADO}, 
	};
	uint8_t indice;
	char mensaje[64];
	Actuadores_Create(&ptAct[0]);
	for( indice = 0; indice < sizeof(ejemplos)/sizeof (struct ejemplo_s); indice++){
		sprintf(mensaje, "Test PWM Actuador: %d", indice);		 	
		TEST_ASSERT_EQUAL_MESSAGE(ejemplos[indice].pwm, ptAct[indice].PWM_actual,mensaje);
		sprintf(mensaje, "Test Estado Actuador: %d", indice);
		TEST_ASSERT_EQUAL_MESSAGE(ejemplos[indice].estado, ptAct[indice].estado, mensaje);
	}




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


// test que verifica la maquina de estados.
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
TEST_ASSERT_EQUAL_HEX8(MANTENCION_APAGADO,ptAct[0].estado); // verifico que todos los actuadores esten apagados


}
  

// teste que verifica el encendido de un actuador a tra ves de una tabla.
void test_ejecutarTabla(void){
actuador_t  ptAct[6];
uint8_t Enc_act   =0b00010101;
uint8_t Apagar_act=0b00101010;
uint16_t tabla   = 0b0010101000010101;

Actuadores_Create(&ptAct[0]); // retorna con todos los pwm apagados

Actuadores_EjecutarTabla(&ptAct[0], tabla);


TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[0].estado); // verifico que todos los actuadores esten encendidos
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[1].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[2].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[3].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_ENCENDIDO,ptAct[4].estado);
TEST_ASSERT_EQUAL_HEX8(INICIO_APAGADO,ptAct[5].estado);

}
//----------------------------------------------------------------------------------------------------------------------------------------
#if 0
void prueba_evento(void){
llamada = true;
}
void esperar(uint16_t espera){
	uint8_t demora;
	for (demora = 0; demora < espera; demora++){
		incrementar_decimal();
	}
}

void test_evento_unica_vez(void){

programar_cuenta(10, prueba_evento);
esperar(10);
TEST_ASSERT(llamada);
}

void test_varias_prubas_unica_vez(void){
	const struct ejemplos{
	uint16_t cuenta;
	uint16_t espera;
	bool resultado;
	}ejemplo[] = {
	{.cuenta = 10, .espera = 9, .resultado = false}, 
	{.cuenta = 10, .espera = 9, .resultado = false}, 
	{.cuenta = 10, .espera = 9, .resultado = false}, 
	};
	uint8_t indice;
	char mensaje[64];
	for( indice = 0; indice < sizeof(ejemplos)/sizeof (struct ejemplo_s); indice++){
		sprintf(mensaje, "ejemplo %d", indice);
		setUp();
		programar_cuenta(ejemplos[indice].cuenta, prueba_evento);
		esperar(ejemplos[indice].espera);
		TEST_ASSERT_EQUAL_MESSAGE(ejemplos[indice].resultado,llamada, mensaje);
	}



}
#endif




