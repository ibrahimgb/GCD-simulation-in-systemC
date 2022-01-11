#include "systemc.h"
SC_MODULE(pgcd) {
// Inputs
sc_in<bool> clk;
sc_in<bool> reset;
sc_in<bool> valid;
sc_in<sc_uint<4> > A;
sc_in<sc_uint<4> > B;
// Outputs
sc_out<bool> ready;
sc_out<sc_uint<4> > GCD;
// Variables
sc_uint<4> X, Y;
sc_uint<4> gcd_tmp;
bool ready_tmp;
//Process
void do_pgcd();
SC_CTOR(pgcd) {
SC_METHOD(do_pgcd);
sensitive << clk.pos();
}
};