#include <stdio.h>
#include <string.h>

int count_heads(char* line, char delimiter) {

	int head_count = 1;
	while (*line != '\n') {
		if (*line == delimiter){
			head_count++;
		}
		line++;

	}
	return head_count;
}
int get_index(char* string, char element){
	int length = strlen(string);
	for (int i = 0; i < length; i++){
		if(string[i] == element) {
			return i;
		}
	}
	return length;
}

void get_headers(char* line, char delimiter, int head_count, int line_length) {
	char headers[head_count][255];
	int start = 0;
	char* line_begin = line;

	int indexes[head_count]; 
	int count = 0;
	for (int j = 0; j < line_length; j++) {
		if (*line == delimiter | *line == '\n') {
			indexes[count] = j;
			count++;
		}
		line++;
	}
	line = line_begin;	

	for (int i = 0; i < head_count; i++) {
		int index = indexes[i];
		char temp_string[255];
		int skip_count = 0;

		for (int j = 0; j < index - start; j++) {
			if (*line != ' ' & *line != delimiter) {
			temp_string[j-skip_count] = *line;
			}
			else {
				skip_count++;
			}
			line++;
		}
		temp_string[index-start-skip_count] = '\0';
		strcpy(headers[i], temp_string);
		start = index;

	}

	for (int i = 0; i < head_count; i++) {
			
		printf("%s\n", headers[i]);
	}
		

	
}



int main() {
	char file_name[] = "addresses.csv";	
	FILE* fp = fopen(file_name, "r");
	char buffer[255];
	int row_count = 0;
	int head_count = 0;
	int line_count = 0;

	while (fgets(buffer, sizeof(buffer), fp)) {
		if(line_count == 0) {
			head_count = count_heads(buffer, ',');
			get_headers(buffer, ',', head_count, strlen(buffer));
		}
		 line_count++;
	}
	char headers[head_count][255];

	fclose(fp);
	return 0;
}
