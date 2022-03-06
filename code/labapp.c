#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zoomrecs.h"

int main(int argc, char *argv[]) {

	if (argc != 3) {    //check the number of passing arguments is 2 or not
		printf("Usage ./labapp <sourcecsv> <outputcsv>\n");
		return 1;
	}

	FILE *source=fopen(argv[1],"rt");

	if ( source==NULL ){
		printf("Error! Unable to open the input file %s\n", argv[1]);
		return 1;
	}

	char c[200];
        fgets(c,200,source);
	fgets(c,200,source);

	FILE *destination=fopen(argv[2],"wt");
	if ( destination==NULL ){
		printf("Error! Unable to open the output file %s\n", argv[2]);
		return 1;
	}

	struct ZoomRecord *head = NULL;
	struct ZoomRecord *temp;
	while(!feof(source)) {

		char *email=strtok(c,",");
		char *name=strtok(NULL,",");
		char *lab=strtok(NULL,",");
		char *duration=strtok(NULL,"\n");

		temp=(struct ZoomRecord *) malloc(sizeof(struct ZoomRecord));
		if (temp==NULL){  //check whether malloc has enough memory to handle
			printf("Error! program ran out of memory");
			return 1;
		}

		head=addZoomRecord(temp, head, email, name, lab, duration);

		fgets(c,200,source);
	
	}
	fclose(source);

	//write:
	fputs("User Email,Name (Original Name),A,B,C,D,E,F,G,H,I,Attendance (Percentage)\n", destination);
	generateAttendance(head, destination);
	fclose(destination);
	
	//free the memory
	while (head!=NULL){
		struct ZoomRecord * temp=head;
		free(head);
		head=temp->next;
	}
	return 0;

}
