#define MAX 100
typedef struct { 
	char name[10];
	int id;
	char grade[4];
}StudentRecord;

StudentRecord r[MAX];	 
int num_record = 0;		   
char *fname = "grade.txt"; 

void read_record(char *fname);
void print_record();
void search_record();
void change_record();
void write_record(char *fname);

void read_record(char *fname) {
	int i = 0;

	FILE *ifp;
	
	ifp = fopen(fname, "r"); 
	while (fscanf(ifp, "%s %d %s", r[i].name, &r[i].id, r[i].grade) == 3)
		++i; 

	
	num_record = i; 
	fclose(ifp);
}

void print_record() {
	printf("\n------------------------------------\n");
	for (int i = 0; i < num_record; i++) 
		printf("\t%s \t%d \t%s\n", r[i].name, r[i].id, r[i].grade);
	printf("------------------------------------\n");
}

void search_record() {
	char s_name[10]; 
	printf("\n Search name : ");
	gets(s_name); 

	for (int i = 0; i < num_record; i++) {
		if (strcmp(s_name, r[i].name) == 0) {	
			printf("   Name:  ");
			puts(r[i].name);
			printf("   ID:    %d\n", r[i].id);
			printf("   Grade: ");
			puts(r[i].grade);
			break;
		}
	}
}

void change_record() {
	char c_name[10]; 
	char c_grade[4];  
	printf("\n Name : ");
	gets(c_name);	
	printf(" Grade: ");
	for (int i = 0; i < num_record; i++) {
		if (strcmp(c_name, r[i].name) == 0) {
			gets(c_grade);
			strcpy(r[i].grade, c_grade);
			printf("\n\n Record change !\n");
			break;
		}
	}
}

void write_record(char *fname) {
	printf("\n");
	FILE *ifp;
	ifp = fopen(fname, "w"); 
	
	for (int i = 0; i < num_record; i++)
		fprintf(ifp, "%s %d %s\n", r[i].name, r[i].id, r[i].grade);
	
	fclose(ifp); 
	printf(" 6 records have written to grade.txt. \n");
}