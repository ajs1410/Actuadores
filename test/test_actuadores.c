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


