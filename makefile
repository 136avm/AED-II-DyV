dyv: dyv.o generador.o
	gcc -o dyv dyv.o generador.o

dyv.o: dyv.cpp generador.h
	gcc -c dyv.cpp

generador.o: generador.cpp generador.h
	gcc -c generador.cpp

clean:
	rm -f *.o