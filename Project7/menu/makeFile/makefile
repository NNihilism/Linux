objects = main.o func.o
menu:$(objects)
	gcc $(objects) -o menu
main.o:
	gcc main.c -c
func.o:
	gcc func.c -c
clean:
	rm -f $(objects) 
