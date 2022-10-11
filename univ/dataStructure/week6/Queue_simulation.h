#define MAX_SIMUL_TIME 20  
#define MAX_PRINTING_TIME 5  
#define JOB_ARRIVAL_PROB 0.5 
#define boolean unsigned char
#define true 1
#define false 0


int current_time = 0;
int new_job_id = 0;	

int current_job_id;	
int remaining_time;	

int total_wait_time;	
int num_printed_jobs;	

typedef struct {
	int id;				
	int arrival_time;	
	int duration;		
}Job;
typedef Job Element;

typedef struct queue *queue_pointer;
typedef struct queue {
	Element item;
	queue_pointer link;
}queue;
queue_pointer front, rear;


void insert_job_into_queue(int id, int arrival_time, int duration);
void process_next_job();
boolean is_job_arrived();

boolean is_printer_idle();

double random();		
int get_random_duration();

void addq(Job e);
Element deleteq();
boolean is_queue_empty();
void queue_show();		

void addq(Job e) {
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));

	temp->item = e;
	temp->link = NULL;

	if (front == NULL) front = rear = temp;
	else {
		rear->link = temp;
		rear = temp;
	}
}

Element deleteq() {
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	Element a;

	a = front->item;
	temp = front;
	front = front->link;

	free(temp);
	return a;
}

void queue_show() {
	printf("queue print : [ ");
	for (queue_pointer temp = front; temp != NULL; temp = temp->link)
		printf("%d ", temp->item.id);
	printf("]\n");
}

void insert_job_into_queue(int id, int arrival_time, int duration) {
	Job  p;

	p.id = id;
	p.arrival_time = arrival_time;
	p.duration = duration;
	addq(p); 
	printf("job <%d> : id, duration = %d . \n", id, duration);
}


void process_next_job() {
	Job p;
	p = deleteq();

	current_job_id = p.id;
	remaining_time = p.duration - 1;
	total_wait_time += (current_time - p.arrival_time); 

	++num_printed_jobs;	
	printf("current job id -job<%d>... \n", current_job_id);
}


boolean is_job_arrived() {
	if (random() < JOB_ARRIVAL_PROB) return true;
	else return false;
}


boolean is_printer_idle() {
	if (remaining_time <= 0) return true;
	else return false;
}

double random() {
	return rand() / (double)RAND_MAX;
}

int get_random_duration() {
	return (int)(MAX_PRINTING_TIME * random()) + 1;
}

boolean is_queue_empty() {
	if (front == NULL) return true;
	else return false;
}
