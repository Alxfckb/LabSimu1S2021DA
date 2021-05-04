unset label
clear
set terminal pdf
set output "parcial.pdf"
set xlabel "Ln(V)"
set ylabel "Ln(P)"
set xrange[3.9:5.5]
set yrange[2:5]
set grid
set datafile separator " "
set style data points
plot "data.txt" skip 1 using 1:2 title "Datos",-1.395324*x+9.639354 title "Mejor aproximación"
