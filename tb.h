#include "systemc.h"
SC_MODULE(tb) {
// Inputs
sc_in<bool> clk;
sc_in<bool> ready;
sc_in<sc_uint<4> > GCD;
// Outputs
sc_out<bool> reset;
sc_out<bool> valid;
sc_out<sc_uint<4> > A;
sc_out<sc_uint<4> > B;
//Process
void do_tb();
SC_CTOR(tb) {
SC_THREAD(do_tb);
sensitive << ready << clk.pos();
}
};