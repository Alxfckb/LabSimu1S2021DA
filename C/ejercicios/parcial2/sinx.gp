unset label
clear
set terminal pdf
set output "sin.pdf"
set xlabel "x"
set xrange[-10:10]
set yrange[-0.5:1.5]
set grid

set arrow from pi,-0.5 to pi,1.5 nohead dt 2 lc -1
plot sin(x)/x
