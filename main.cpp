#include "tb.h"
#include "pgcd.h"
int sc_main(int argc, char *argv[]) {
pgcd pgcd("PGCD_Module");
tb tb("TB");
sc_clock clk("Clock", 10, SC_NS);
sc_signal<bool> reset; 
sc_signal<bool> valid; 
sc_signal<sc_uint<4> > A;
sc_signal<sc_uint<4> > B;
sc_signal<bool> ready; 
sc_signal<sc_uint<4> > GCD;

pgcd.clk(clk);
pgcd.reset(reset); 
pgcd.valid(valid); 
pgcd.A(A); 
pgcd.B(B); 
pgcd.ready(ready); 
pgcd.GCD(GCD);

tb.clk(clk);
tb.reset(reset);
tb.valid(valid); 
tb.A(A); 
tb.B(B); 
tb.ready(ready); 
tb.GCD(GCD);
sc_start();
return 0;
}

