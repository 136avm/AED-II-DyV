dyv: dyv.cpp generador.h
	g++ -o dyv dyv.cpp

run: dyv
	./dyv