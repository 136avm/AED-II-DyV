#!/bin/bash

# Variable tope para el bucle, se debe llamar tope
tope=5

# Si existe el archivo salida.txt, se borra
if [ -f salida.txt ]; then
    rm salida.txt
fi

for i in $(seq 1 1 $tope); do
    ./dyv >> salida.txt
done

# Contar si las lineas de salida.txt son igual que tope
if [ $(wc -l < salida.txt) -eq $tope ]; then
    echo "OK"
else
    echo "ERROR"
fi

# Terminar el programa
exit 0