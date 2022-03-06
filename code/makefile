labapp: labapp.o zoomrecs.o
	gcc labapp.o zoomrecs.o -o labapp
labapp.o: labapp.c zoomrecs.h zoomrecs.c
	gcc -c labapp.c
zoomrecs.o: zoomrecs.c zoomrecs.h
	gcc -c zoomrecs.c
clean:
	rm *.o labapp
