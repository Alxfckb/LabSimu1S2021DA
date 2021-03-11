#!/bin/bash

#Autor:    Alexander Alvarado
#Tipo:     Script de Bash
#Ejecutar  ./archivos.sh
#Resumen   Generador automático de comentario para scripts de C.

#bienvenida

echo " * * * * Generador de archivos de C * * * * "

#obtener y validar el nombre del archivo
read -p "Ingrese el nombre del archivo: " nombre
fnombre=$nombre".c"

#Cerrar el archivo si no se le asignó un nombre
if [ -z $nombre ]; then
	echo "no ingresó un nombre válido"
	exit 2
fi

#Ingresar resumen, entradas y salidas
read -p "Ingrese resumen de su código: " resumen

read -p "Ingrese entradas: " entradas

read -p "Ingrese salidas: " salidas

read -p "Ingrese las librerías que utilizará " lib

#obtener información del sistema
author=$(whoami)
fecha=$(date)
version=$(gcc --version | head -n 1)

#crear nuestro contenido
echo "/*" > $fnombre
echo "Autor: " $author >> $fnombre
echo "Complilador: " $version >> $fnombre
echo "Para comilar: gcc -o" $nombre  $fnombre >> $fnombre
echo "Fecha: " $fecha >> $fnombre 
echo "librerias: " $lib >> $fnombre
echo resumen: $resumen >> $fnombre
echo entradas: $entradas >> $fnombre
echo salidas: $salidas >> $fnombre
echo "*/" >> $fnombre
