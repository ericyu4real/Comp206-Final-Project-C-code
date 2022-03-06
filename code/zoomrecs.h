struct ZoomRecord
{
char email[60]; // email of the student 
char name[60]; // name of the student
int durations[9]; // duration for each lab. 
struct ZoomRecord *next;
};

struct ZoomRecord * addZoomRecord(struct ZoomRecord *temp, struct ZoomRecord *ptr, char *email, char *name, char *lab, char *duration);
void generateAttendance(struct ZoomRecord *ptr, FILE *destination);
