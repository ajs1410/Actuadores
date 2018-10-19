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

 

void test_actuadoresOffAfterCreate(void){
actuador_t  ptAct[6];
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
	const struct ejemplo_s{
	uint16_t pwm;
	uint8_t estado;
	}ejemplos[] = {
	{.pwm = 0,  .estado = INICIO_ENCENDIDO}, 
	{.pwm = 0,  .estado = INICIO_ENCENDIDO}, 
	{.pwm = 0,  .estado = INICIO_ENCENDIDO},
	{.pwm = 0,  .estado = INICIO_ENCENDIDO},
	{.pwm = 0,  .estado = INICIO_ENCENDIDO},
	{.pwm = 0,  .estado = INICIO_ENCENDIDO}, 
	};
	uint8_t indice;
	char mensaje[64];
	Actuadores_Create(&ptAct[0]);		// retorna con todos los pwm apagados
	
	for( indice = 0; indice < sizeof(ejemplos)/sizeof (struct ejemplo_s); indice++){
		Actuadores_Encender(&ptAct[indice], indice);
		sprintf(mensaje, "Test Estado Actuador: %d", indice);
		TEST_ASSERT_EQUAL_MESSAGE(ejemplos[indice].estado, ptAct[indice].estado, mensaje);
	}

}



// test que comprueba que esten apagado los actuadores
void test_apagarActuadores(void){
actuador_t  ptAct[6];
	const struct ejemplo_s{
	uint16_t pwm;
	uint8_t estado;
	}ejemplos[] = {
	{.pwm = 0,  .estado = INICIO_APAGADO}, 
	{.pwm = 0,  .estado = INICIO_APAGADO}, 
	{.pwm = 0,  .estado = INICIO_APAGADO},
	{.pwm = 0,  .estado = INICIO_APAGADO},
	{.pwm = 0,  .estado = INICIO_APAGADO},
	{.pwm = 0,  .estado = INICIO_APAGADO}, 
	};
	uint8_t indice;
	char mensaje[64];
	Actuadores_Create(&ptAct[0]);		// retorna con todos los pwm apagados
	
	for( indice = 0; indice < sizeof(ejemplos)/sizeof (struct ejemplo_s); indice++){
		Actuadores_Apagar(&ptAct[indice], indice);
		sprintf(mensaje, "Test Estado Actuador: %d", indice);
		TEST_ASSERT_EQUAL_MESSAGE(ejemplos[indice].estado, ptAct[indice].estado, mensaje);
	}

}


// test que verifica la maquina de estados.
void test_estadosActuadores(void){
actuador_t  ptAct[6];
	const struct ejemplo_s{
	uint16_t pwm;
	uint8_t estado;
	}ejemplos1[] = {
	{.pwm = 0,  .estado = MANTENCION_APAGADO}, 
	{.pwm = 0,  .estado = MANTENCION_APAGADO}, 
	{.pwm = 0,  .estado = MANTENCION_APAGADO},
	{.pwm = 0,  .estado = MANTENCION_APAGADO},
	{.pwm = 0,  .estado = MANTENCION_APAGADO},
	{.pwm = 0,  .estado = MANTENCION_APAGADO}, 
	}, ejemplos2[] = {
	{.pwm = 0,  .estado = MANTENCION_ENCENDIDO}, 
	{.pwm = 0,  .estado = MANTENCION_ENCENDIDO}, 
	{.pwm = 0,  .estado = MANTENCION_ENCENDIDO},
	{.pwm = 0,  .estado = MANTENCION_ENCENDIDO},
	{.pwm = 0,  .estado = MANTENCION_ENCENDIDO},
	{.pwm = 0,  .estado = MANTENCION_ENCENDIDO}, 
	};
	uint8_t indice;
	char mensaje[64];
	Actuadores_Create(&ptAct[0]);		// retorna con todos los pwm apagados

	for( indice = 0; indice < sizeof(ejemplos1)/sizeof (struct ejemplo_s); indice++){
		Actuadores_Apagar(&ptAct[indice], indice);
		Actuadores_MEF(&ptAct[indice]);
		sprintf(mensaje, "Test Estado Actuador: %d", indice);
		TEST_ASSERT_EQUAL_MESSAGE(ejemplos1[indice].estado, ptAct[indice].estado, mensaje);
	}


	for( indice = 0; indice < sizeof(ejemplos2)/sizeof (struct ejemplo_s); indice++){
		Actuadores_Encender(&ptAct[indice], indice);
		Actuadores_MEF(&ptAct[indice]);
		sprintf(mensaje, "Test Estado Actuador: %d", indice);
		TEST_ASSERT_EQUAL_MESSAGE(ejemplos2[indice].estado, ptAct[indice].estado, mensaje);
	}


}




// test que verifica el encendido de un actuador a tra ves de una tabla.
void test_ejecutarTabla(void){
actuador_t  ptAct[6];
	
const struct ejemplo_c{
	uint8_t accion;
	uint8_t estado;
	}ejemplosc[] = {
	{.accion = ENCENDER,  .estado = INICIO_ENCENDIDO}, 
	{.accion = ENCENDER,  .estado = INICIO_ENCENDIDO}, 
	{.accion = ENCENDER,  .estado = INICIO_ENCENDIDO},
	{.accion = ENCENDER,  .estado = INICIO_ENCENDIDO},
	{.accion = ENCENDER,  .estado = INICIO_ENCENDIDO},
	{.accion = ENCENDER,  .estado = INICIO_ENCENDIDO}, 
	};
	uint8_t indice;
	char mensaje[64];
	Actuadores_Create(&ptAct[0]);		// retorna con todos los pwm apagados
	
	for( indice = 0; indice < sizeof(ejemplosc)/sizeof (struct ejemplo_c); indice++){
		Actuadores_EjecutarTabla(&ptAct[indice], indice, ejemplosc[indice].accion);
		sprintf(mensaje, "Test Estado Actuador: %d", indice);
		TEST_ASSERT_EQUAL_MESSAGE(ejemplosc[indice].estado, ptAct[indice].estado, mensaje);
	}



}




