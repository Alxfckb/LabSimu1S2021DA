unset label
clear
set terminal pdf
set output "xt.pdf"
set xlabel "t[s]"
set ylabel "y[m]"
set xrange[0:4182.93]
set yrange[0:2E19]
set grid
set datafile separator " "
set style data points
plot "xt.txt" using 2:1 title "x t"
