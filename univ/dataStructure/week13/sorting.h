#define MAX_SIZE 10
#define boolean unsigned char
#define true 1
#define false 0

int original[] = { 25, 5, 37, 1, 61, 11, 59, 15, 48, 19 };
int num_compare;

// insertion sort
void insertion_sort(int list[], int n);
// quick sort
void quick_sort(int list[], int left, int right);
// merge sort
void merge_sort(int list[], int left, int right);
// merge
void merge(int list[], int left, int mid, int right);

void copy_list(int original[], int list[], int n);
void print_list(int list[], int left, int right);