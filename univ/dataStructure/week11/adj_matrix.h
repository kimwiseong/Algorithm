#define MAX_VERTICES 100
#define boolean unsigned char
#define true 1
#define false 0

// Adjacency matrix for a graph
int adj[MAX_VERTICES][MAX_VERTICES];
// Array for search
int visited[MAX_VERTICES];
void build_simple_graph();
void insert_edge(int v, int w);
void dfs(int v);
void bfs(int v);

typedef int Element;
// Global queue
typedef struct queue *queue_pointer;
typedef struct queue {
	Element item;
	queue_pointer link;
} queue;
queue_pointer front, rear;
void addq(Element e);
Element deleteq();
boolean is_queue_empty();
int countE = 0;
void build_simple_graph() {
	for (int i = 0; i < MAX_VERTICES; i++)
		for (int j = 0; j < MAX_VERTICES; j++)
			adj[i][j] = 0;

	insert_edge(1, 2);
	insert_edge(2, 1);
	insert_edge(1, 3);
	insert_edge(3, 1);
	insert_edge(1, 4);
	insert_edge(4, 1);
	insert_edge(2, 5);
	insert_edge(5, 2);
	insert_edge(3, 5);
	insert_edge(5, 3);
	insert_edge(4, 5);
	insert_edge(5, 4);

	int count = 0; int index1 = 0, index2 = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
		for (int j = 0; j < MAX_VERTICES; j++)
			if (adj[i][j] > 0) {
				if (i != index1 && j != index2)
					count++;
				index1 = i; index2 = j;
			}
	printf(" Graph is built. v = %d, E = %d. \n\n", count, countE/2);
}

void insert_edge(int v, int w) {
	adj[v][w] = 1;
	countE++;
}

void dfs(int v) {
	int w;
	printf(" %d ", v);
	visited[v] = true;
	for (w = 0; w < MAX_VERTICES; w++)
		if (!visited[w] && adj[v][w])
			dfs(w);
}

void bfs(int v) {
	int w;
	printf(" %d ", v);
	visited[v] = true;
	addq(v);
	while (!is_queue_empty()) {
		v = deleteq();
		for (w = 0; w < MAX_VERTICES; w++)
			if (!visited[w] && adj[v][w]) {
				printf(" %d ", w);
				visited[w] = true;
				addq(w);
			}
	}
}

void addq(Element e) {
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

boolean is_queue_empty() {
	if (front == NULL) return true;
	return false;
}
