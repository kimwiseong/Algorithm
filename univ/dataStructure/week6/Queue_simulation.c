#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "Queue_simulation.h"

void main() {
	int duration;
	srand(time(NULL));
	while (current_time < MAX_SIMUL_TIME) {
		printf("\n----- time %d ----- \n", current_time);
		if (is_job_arrived()) {
			++new_job_id;
			duration = get_random_duration();
			insert_job_into_queue(new_job_id, current_time, duration);
		}

		if (is_printer_idle()) {
			if (!is_queue_empty()) process_next_job();
		}

		else {
			printf("Job <%d> current job id ... \n", current_job_id);
			--remaining_time;
		}

		queue_show();
		++current_time;
	}

	printf("\n num printed job = %d\n", num_printed_jobs);
	printf("avg wait time \t = %lf\n", (double)total_wait_time / num_printed_jobs);
}