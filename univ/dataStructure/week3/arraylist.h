#define MaxSize 3
#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;

Element List[MaxSize];
int size = 0;

void list_insert(Element e);
void list_delete(Element e);
boolean list_empty();
boolean list_full();
void list_show();

void list_insert(Element e) {
	if (list_full()) {
		printf("\nList is full !!!\n");
		return;
	}
	List[size++] = e;
}

void list_delete(Element e) {
	if (list_empty()) {
		printf("\nList is Empty !!!\n");
		return;
	}
	
	int i = 0;
	while (List[i] != e) {
		if (i == 3) {
			printf("\nData does not exist !!!\n");
			return;
		}
		i++;
	}

	while (i < size-1) {
		List[i] = List[i + 1]; 
		List[i + 1] = NULL;		
		i++;	
	}
	size--;
}

boolean list_empty() {
	if (size == 0) return true;
	else return false;
}

boolean list_full() {
	if (size > MaxSize - 1) return true;
	else return false;
}

void list_show() {
	printf("\n");
	if (list_empty()) {
		printf("List is Empty !!!\n");
		return;
	}

	for (int i = 0; i < size; i++)
		printf("%c ", List[i]);

	printf("\n");
}