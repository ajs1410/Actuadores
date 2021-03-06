#ifndef _ACTUADORES_H_
#define _ACTUADORES_H_




#include "stdint.h"


#ifdef __cplusplus
extern "C" {
#endif

#define NESTADOSpwm 4
#define NESTADOStiempo 2
#define Nactuadores 6

#define TIEMPO_INICIO_ENCENDIDO 0
#define TIEMPO_INICIO_APAGADO 1
#define ENCENDER 1
#define APAGAR 2
#define MANTENER 3

typedef enum {INICIO_ENCENDIDO,MANTENCION_ENCENDIDO, INICIO_APAGADO,MANTENCION_APAGADO} estadoMEF_Actuador_t;

typedef struct{
estadoMEF_Actuador_t estado;
uint16_t PWM_actual;
uint16_t Tiempo_actual;
uint16_t Porcentaje_pwm[NESTADOSpwm];
uint16_t Tiempo[NESTADOStiempo];
}actuador_t;







void Actuadores_Create(actuador_t * ptAct);
void Actuadores_Encender(actuador_t * ptAct, uint8_t Ind_actuador);
void Actuadores_Apagar(actuador_t * ptAct, uint8_t Ind_actuador);
void Actuadores_EjecutarTabla(actuador_t * ptAct,uint8_t Ind_actuador, uint8_t accion);


#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _DRIVER_UART_H_ */

