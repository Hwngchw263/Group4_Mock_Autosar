#include "os.h"
#include "switch.h"


volatile static bool g_PwmSignal = 0u; 


/*******************************************************************************
 * TODO: 
 * Add your needed shared variables 
 ******************************************************************************/
static uint8_t g_PwmCounter = 0u;

/*******************************************************************************
 * TODO: 
 * Add the tasks & callback prototypes (DeclareTask(XX))
 ******************************************************************************/
DeclareTask(AppTask_PulseWidthUpdate); 
DeclareTask(AppTask_PwmOn); 
ALARMCALLBACK(PwmOff); 

void SystemInit(void) {}
int main(void) {
  StartOS();
  while (1)
    ; /* Should not be executed */
  return 0;
}

/*******************************************************************************
 * TODO: 
 * Add your implementation for AppTask_PulseWidthUpdate task 
 ******************************************************************************/
TASK(AppTask_PulseWidthUpdate) {
  
  static bool l_DirectionIsUp = true;
  if (l_DirectionIsUp) {
    g_PwmCounter++;
    if (9u == g_PwmCounter) {
      l_DirectionIsUp = false;
    }
  } 
  else {
    g_PwmCounter--;
    if (1u == g_PwmCounter) {
      l_DirectionIsUp = true;
    }
  }

  TerminateTask();
}

/*******************************************************************************
 * TODO: 
 * Add your implementation for AppTask_PwmOn task 
 ******************************************************************************/
TASK(AppTask_PwmOn) {

  g_PwmSignal = true; 
  SetRelAlarm(Alrm_PwmOff, g_PwmCounter, (TickType)0); 

  TerminateTask(); 
}

/*******************************************************************************
 * TODO: 
 * Add your implementation for PwmOff callback 
 ******************************************************************************/
ALARMCALLBACK(PwmOff) {
  g_PwmSignal = false; 
}
