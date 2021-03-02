#!/bin/bash

#Autor:    Alexander Alvarado
#Tipo:     Script de Bash
#Ejecutar  ./generadorarchivo.sh
#Resumen   Generador automático de comentario para scripts de C.

#bienvenida

echo " * * * * Generador de archivos de C * * * * "
#obtener y validar el nombre del archivo
read -p "Ingrese el nombre del archivo: " nombre
fnombre=$nombre".c"
if [ -z $nombre ]; then
	echo "no ingresó un nombre válido"
	exit 2
fi
#obtener informacióndel sistema
author=$(whoami)
fecha=$(date)
version=$(gcc --version | head -n 1)

#crear nuestro contenido
echo "/*" > $fnombre
echo "Autor: " $author >> $fnombre
echo "Complilador: " $version >> $fnombre
echo "Para comilar: gcc -o" $nombre  $fnombre >> $fnombre
echo "Fecha: " $fecha >> $fnombre 
echo "librerias: stdio (u otras)" >> $fnombre
echo "Resumen, Entradas, Salidas" >> $fnombre
echo "*/" >> $fnombre 
