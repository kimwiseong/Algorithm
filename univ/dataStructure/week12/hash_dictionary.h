#define TABLE_SIZE 13
#define boolean unsigned char
#define true 1
#define false 0

typedef struct {
	char key[100];
	char data[100];
} element;
element hash_table[TABLE_SIZE];

int num_comparison;
int build_dictionary(char *fname);
void hash_insert(char *key, char *data);
char * hash_search(char *key);
void hash_show();
int hash(char *key);
int transform(char *key);