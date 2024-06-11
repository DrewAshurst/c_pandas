#include <stdio.h>


int countHeaders(FILE* fptr, char delimiter) {
	char c;
	int field_nums = 1;
	do {
			c = fgetc(fptr);
			if (c == delimiter) {
			field_nums++;
			} else if (c == '\n') {
			
				break;
			}
		} while (c != EOF);
	return field_nums;	
}

void createHeaders(FILE* fptr, int head_count, char headers[][100], char delimiter) {
	char c;
	for (int i = 0; i < head_count; i++) {
		
		while (1) {
			c = fgetc(fptr);
			if (c == delimiter){
				break;
			}
			printf("%c\n", c);
		}
	}
	
}

void readCsv(char* file_name, char delimiter) {
	FILE* fptr = fopen(file_name, "r");
	
	char c;
	int head_count = countHeaders(fptr, delimiter);
	char headers[head_count][100];
	fclose(fptr);
	fptr = fopen("addresses.csv", "r");
	createHeaders(fptr, head_count, headers, delimiter);

	fclose(fptr);
}

