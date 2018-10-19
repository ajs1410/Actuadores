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


// enciende el actuador indicadoen el indice(retorna los datos del actuador encedido
void Actuadores_Encender(actuador_t * ptAct, uint8_t Ind_actuador){
	if (Ind_actuador < Nactuadores){
		Actuadores[Ind_actuador].estado = INICIO_ENCENDIDO;
		ptAct->estado = Actuadores[Ind_actuador].estado;  // retornamos el estado de los actuadores
	}
}

//apaga los actuadores indicados en la palabra Enc_act
void Actuadores_Apagar(actuador_t * ptAct, uint8_t Ind_actuador){
	if (Ind_actuador < Nactuadores){
		Actuadores[Ind_actuador].estado = INICIO_APAGADO;
		ptAct->estado = Actuadores[Ind_actuador].estado;  // retornamos el estado de los actuadores
	}
}




// Estados del actuador 
// ES LLAMADO DESDE UN TIMER
void Actuadores_MEF(actuador_t *Act){

switch(Act->estado){
	case INICIO_ENCENDIDO:
		Act->PWM_actual = Act->Porcentaje_pwm[INICIO_ENCENDIDO];
		Act->Tiempo_actual = Act->Tiempo[TIEMPO_INICIO_ENCENDIDO];
		Act->estado = MANTENCION_ENCENDIDO;
		break;	

	case MANTENCION_ENCENDIDO:
		if(Act->Tiempo_actual== 0)
			Act->PWM_actual = Act->Porcentaje_pwm[MANTENCION_ENCENDIDO];
		break;	

	case INICIO_APAGADO:
		Act->PWM_actual = Act->Porcentaje_pwm[INICIO_APAGADO];
		Act->Tiempo_actual = Act->Tiempo[TIEMPO_INICIO_APAGADO];
		Act->estado = MANTENCION_APAGADO;
		break;	

	case MANTENCION_APAGADO:
		if(Act->Tiempo_actual== 0)
		Act->PWM_actual = Act->Porcentaje_pwm[MANTENCION_APAGADO];
		break;
	
	default: 
		Act->PWM_actual = Act->Porcentaje_pwm[MANTENCION_APAGADO];
		break;

	}
}



// recive datos de una tabla y enciendo/apaga el actuador segun indique los valores de la tabla.
void Actuadores_EjecutarTabla(actuador_t * ptAct,uint8_t Ind_actuador, uint8_t accion){

	if (accion == ENCENDER){
		Actuadores_Encender(ptAct, Ind_actuador);
	}
	else if(accion == APAGAR){
		Actuadores_Apagar  (ptAct, Ind_actuador);
	}


} 

//------------------------------------------------------------------------------------------------------------------
#if 0
struct
uint16_t cuenta;
void (*funcion) (void);
} cola [Nactuadores];


void configurar_temporizadores(void){
cola[0].cuenta = 0;
configurar_interrupcion(100);
}

uint8_t temporizadores_activos (void){
return 0;
}


void programar_cuenta(uint16_t espera, void (*evento) (void)){
cola[0].cuenta  = espera;
cola[0].funcion = evento;

}

void incrementar_decima(void){
	if(cola[0].cuenta > 0){
		cola[0].cuenta--;
		if(cola[0].cuenta == 0){
			cola[0].funcion();
		}
	}
}


#endif
