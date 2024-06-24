#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"


/*
 * 	Macro define
 * */
typedef void (*event_proc_t)(void*);
typedef void (*void_proc_t)(void*);
typedef void (*init_proc_t)(void);

#define MAX_PROCS_IN_IO_LOOP	4
#define TASKS_IN_EVENT_LOOP 2

#define SIZE_OF_EVENT_TASK_STACK		1024

#define EVLP_TASK_PRIORITY				tskIDLE_PRIORITY+1
#define IOLP_TASK_PRIORITY				(configMAX_PRIORITIES - 1)
#define SIZE_OF_EVENT_QUE				64
/*
 * 	Struct define
 * */

/* Event */
typedef struct _event_st{
	const char*		n;			// event name
	event_proc_t	p;			// event callback handler
	void*			d;			// event data for callback
#ifdef EVENT_WITH_INFO
	uint32_t 		t;			// event time
#endif
}event_t,*event_p;

/* Event s */
typedef struct _event_loop{
	TaskHandle_t	task[TASKS_IN_EVENT_LOOP];	//TaskHandler of event
	QueueHandle_t	que;						//QueueHandler
}event_loop_t,*event_loop_p;


/* Process */
typedef struct _ioproc{
	void_proc_t 	p;			// Process function
	const char* 	n;			// Process Name
}iotk_proc_t,*iotk_proc_p;

/* Process cluster*/
typedef struct _IOLP_st{
	TaskHandle_t		task;	//TaskHandler
	SemaphoreHandle_t	sema;	//SemaphoreHandler
	iotk_proc_t			procs[MAX_PROCS_IN_IO_LOOP];	//Process cluster
}iotk_loop_t,*iotk_loop_p;


/*
 * Module variables
 * */
static event_loop_t event_loop = {0};
static event_loop_t *elop = &event_loop;

static iotk_loop_t iotk_handle = {0};
static iotk_loop_p iotk = &iotk_handle;


static void eloopHandle(init_proc_t init)
{
	QueueHandle_t 	que = elop->que;
	event_t			event;

	if(init != NULL)
		init();

	for( ; ; ) {
		if(xQueueReceive(que, &event, (TickType_t) portMAX_DELAY) == pdPASS){
			if(event.p != NULL){
				event.p(event.d);
			}
		}
	}
}
static void iotkHandle(init_proc_t init)
{
	iotk_proc_p pp;

	if(init != NULL)
		init();

	for( ; ; ){
		xSemaphoreTake(iotk->sema, (TickType_t) portMAX_DELAY);
		for(pp = iotk->procs; pp < (iotk->procs+MAX_PROCS_IN_IO_LOOP); pp++){
			if(pp->p != NULL)
				pp->p(NULL);
		}
	}
}


void LOOP_Start(init_proc_t init_proc)
{
	BaseType_t result;

	iotk->sema = xSemaphoreCreateBinary();

	result = xTaskCreate((TaskFunction_t)iotkHandle, "iotk", SIZE_OF_EVENT_TASK_STACK,
		(void* const)NULL, IOLP_TASK_PRIORITY, &iotk->task);


	elop->que = xQueueCreate(SIZE_OF_EVENT_QUE,sizeof(event_t));

	result = xTaskCreate((TaskFunction_t)eloopHandle,"evlp0", SIZE_OF_EVENT_TASK_STACK,
		(void* const)NULL,	IOLP_TASK_PRIORITY, &elop->task[0]);

}
