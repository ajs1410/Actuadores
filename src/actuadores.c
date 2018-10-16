#include "actuadores.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"


#include "os_task.h"
#include "os_queue.h"
#include "os_semphr.h"
#include "os_timer.h"

#include "os_list.h"
#include "os_mpu_wrappers.h"
#include "os_event_groups.h"

actuador_t Actuadores[Nactuadores];

QueueHandle_t queActuadores[Nactuadores];

#define NO_TEST 0


// Inicializa a todos los actuadores apagados
void Actuadores_Create(actuador_t * ptAct){
uint16_t i;
for(i = 0; i < Nactuadores ; i++){
	Actuadores[i].PWM_actual = Actuadores[i].Porcentaje_pwm[MANTENCION_APAGADO];
	Actuadores[i].estado = MANTENCION_APAGADO;
	ptAct[i].PWM_actual = Actuadores[i].PWM_actual;
	ptAct[i].estado = Actuadores[i].estado;
}

}


// enciende los actuadores indicados en la palabra Enc_act
void Actuadores_Encender(actuador_t * ptAct, uint8_t Enc_act){

uint16_t i;
for(i = 0; i < Nactuadores ; i++){
	if ( (Enc_act >> i) & 1 ){
		Actuadores[i].estado = INICIO_ENCENDIDO;
		ptAct[i].estado = Actuadores[i].estado;  // retornamos el estado de los actuadores
	}
}

}

//apaga los actuadores indicados en la palabra Enc_act
void Actuadores_Apagar(actuador_t * ptAct, uint8_t Apagar_act){

uint16_t i;
for(i = 0; i < Nactuadores ; i++){
	if ( (Apagar_act >> i) & 1 ){
		Actuadores[i].estado = INICIO_APAGADO;
		ptAct[i].estado = Actuadores[i].estado;  // retornamos el estado de los actuadores
	}
}

}

