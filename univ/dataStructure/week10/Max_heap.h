#define MAX_SIZE 100
#define boolean unsigned char
#define true 1
#define false 0

typedef struct {
	int key;
	char data;
}Element;


Element heap[MAX_SIZE];
int heap_size = 0;


void insert_max_heap(Element item);
Element delete_max_heap();
void max_heap_show();
boolean is_heap_empty();

void insert_max_heap(Element item) {
	int i = ++heap_size;
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

Element delete_max_heap() {
	if (is_heap_empty()) {
		printf("\n Heap is empty !!! \n");
		exit(1);
	}
	Element max = heap[1];
	Element temp = heap[heap_size--]; int c = 2, p = 1;
	while (c <= heap_size) {
		if ((c < heap_size) && (heap[c].key < heap[c + 1].key)) c++;
		if (temp.key >= heap[c].key) break;
		heap[p] = heap[c];
		p = c;
		c *= 2;
	}
	heap[p] = temp;
	return max;
}

void max_heap_show() {
	for (int i = 1; i <= heap_size; i++)
		printf(" %d %c \n", heap[i].key, heap[i].data);
}

boolean is_heap_empty() {
	if (heap_size == 0) return true;
	return false;
}

