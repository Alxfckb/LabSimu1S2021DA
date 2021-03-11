#!/bin/bash
#Autor:    Alexander Alvarado
#Tipo:     Script de Bash
#Ejecutar  ./clima.sh
#Resumen   Este script muestra en terminal el clima de Guatemala el día de hoy.


archivo=temp.txt                            #Creamos un archivo temporal para guardar la información del clima.
 
while read -r line                          #Leemos las líneas del archivo del clima
do
        echo $line >> $archivo              #Trasladamos estas líneas al archivo temporal
done <<< "$(curl wttr.in/guatemala)"
head -7 $archivo                            #Mostramos las primeras 7 líneas en terminal
rm $archivo                                  #Eliminamos el archivo temporal
