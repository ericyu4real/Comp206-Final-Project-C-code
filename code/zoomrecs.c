#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zoomrecs.h"

struct ZoomRecord * student_is_found(struct ZoomRecord *ptr, char *name){
	while(ptr!=NULL){
		if(strcmp(ptr->name,name)==0){
			return ptr;
		}
		ptr=ptr->next;
        }
	return NULL;
}

struct ZoomRecord * addZoomRecord(struct ZoomRecord *temp, struct ZoomRecord *ptr, char *email, char *name, char *lab, char *duration) {

	//********************************  get the index of lab
	char labs[9]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
	int index;
	for (int i=0;i<9;i++){
		if (labs[i]==*lab){
			index=i;
			break;
		}
	}

	struct ZoomRecord *dam=student_is_found(ptr, name);
	if(dam != NULL){  // if student is recorded, update
		int num=atoi(duration);
		dam->durations[index]+=num;
		return ptr;
	}
	else{  // if student is not recorded, initiate a new record for him/her
		//******************************** set the value for email
		sprintf(temp->email, "%s", email);
		//******************************** set the value for name
		sprintf(temp->name, "%s", name);
		//******************************** set the value for durations[]
		int num=atoi(duration);
		for (int j=0;j<9;j++){
			if (j != index){
				temp->durations[j]=0;
			}
			else{
				temp->durations[j]=num;
			}
		}
	}
	//*****************************************************************************************
	if(ptr==NULL){
		temp->next=NULL;
	}
	else{
		temp->next=ptr;
	}
	return temp;
}

void generateAttendance(struct ZoomRecord *ptr, FILE *destination) {
	while(ptr!=NULL){
		fputs(ptr->email,destination);
		fputc(',',destination);
		fputs(ptr->name,destination);
		fputc(',',destination);
		float i=0;
                for(int k=0;k<9;k++){
                        char c[15];
			sprintf(c, "%d", ptr->durations[k]);
			fputs(c,destination);
			fputc(',',destination);
			if (ptr->durations[k]>=45){
				i++;
			}
                }
		i=i/9;
		char d[15];
		sprintf(d,"%.2f",i);
		fputs(d,destination);
		fputc('\n',destination);

                ptr=ptr->next;
        }       
}
