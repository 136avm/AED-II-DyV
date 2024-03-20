all: clean dyv run

dyv: dyv.cpp generador.h
	g++ -o dyv dyv.cpp

clean:
	rm -f dyv

run: dyv
	./dyv