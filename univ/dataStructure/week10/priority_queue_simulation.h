#define MAX_SIMUL_TIME 20
#define MAX_PRINTING_TIME 10 
#define JOB_ARRIVAL_PROB 0.5 
#define boolean unsigned char
#define true 1
#define false 0
#define MAX_PQ_SIZE 1000 

int current_time = 0;
int new_job_id = 0; 
int current_job_id; 
int remaining_time; 
int total_wait_time; 
int num_printed_jobs; 

typedef struct {
	int key;
	int id;
	int arrival_time;
	int duration;
} Job;
typedef Job Element;

Element PQ[MAX_PQ_SIZE];
int PQ_size = 0;

void insert_job(int id, int arrival_time, int duration);
void process_next_job();
boolean is_job_arrived();
boolean is_printer_idle();
double random(); 
int get_random_duration(); 
void insert_PQ(Element item);
Element delete_PQ();
void PQ_show();
boolean is_PQ_empty();


void process_next_job() {
	Job p;
	p = delete_PQ();
	
	current_job_id = p.id;
	remaining_time = p.duration - 1;
	total_wait_time += current_time - p.arrival_time;
	++num_printed_jobs;
	printf("current_job_id <%d>... \n", current_job_id);
}

void insert_job(int id, int arrival_time, int duration) {
	Job p;
	p.key = duration; p.id = id; p.arrival_time = arrival_time; p.duration = duration;
	insert_PQ(p);
	printf("id job <%d>, duration = %d \n", id, duration);
}

void insert_PQ(Element item) {
	int i = ++PQ_size;
	while ((i != 1) && (item.key < PQ[i / 2].key)) {
		PQ[i] = PQ[i / 2];
		i /= 2;
	}
	PQ[i] = item;
}

Element delete_PQ() {
	if (is_PQ_empty()) {
		printf("\n Heap is empty !!! \n");
		exit(1);
	}
	Element max = PQ[1];
	Element temp = PQ[PQ_size--]; int c = 2, p = 1;
	while (c <= PQ_size) {
		if ((c < PQ_size) && (PQ[c].key > PQ[c + 1].key)) c++;
		if (temp.key <= PQ[c].key) break;
		PQ[p] = PQ[c];
		p = c;
		c *= 2;
	}
	PQ[p] = temp;
	return max;
}

void PQ_show() {
	printf("PQ show : [");
	for (int i = 1; i <= PQ_size; i++)
		printf(" <%d %d>", PQ[i].key, PQ[i].id);
	printf(" ]\n");
}

boolean is_PQ_empty(){
	if (PQ_size == 0) return true;
	return false;
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