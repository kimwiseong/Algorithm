#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "priority_queue_simulation.h"
void main() {
	int duration;
	// srand(time(NULL));
	while (current_time < MAX_SIMUL_TIME) {
		printf("\n----- time %d ----- \n", current_time);
		
		if (is_job_arrived()) {
			++new_job_id;
			duration = get_random_duration();
			insert_job(new_job_id, current_time, duration);
		}
		
		if (is_printer_idle()) {
			if (!is_PQ_empty()) process_next_job();
		}
		
		else {
			printf(" current_job_id <%d> \n", current_job_id);
			--remaining_time;
		}
		
		PQ_show();
		++current_time;
	}
	
	printf("\n num_printed_jobs job = %d \n", num_printed_jobs);
	printf("avg_wait_time = %f \n\n", (double)total_wait_time / num_printed_jobs);
}
