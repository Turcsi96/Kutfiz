a=384400000
b=383820466
f(x)=sqrt(b*b*(1-((x*x)/(a*a))))+21100000
g(x)=-f(x)+2*21100000

set xlabel "A rendszer x koordinárái"
set ylabel "A rendszer y koordinátái"
set title "A Hold Föld körüli keringése, mint egytest probléma"
set grid

set sample 3000
set term png
set output "res.png"
plot "adat.dat" u 1:2 w l , f(x), g(x)
set output
set term x11
