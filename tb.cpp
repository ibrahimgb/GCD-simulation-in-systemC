#include "tb.h"
void tb::do_tb(){
    cout << "do_tb is starting ..." << endl;
//cout << "@" << sc_time_stamp() << " Create VCD file" << endl;
//sc_trace_file* wf = sc_create_vcd_trace_file("vcd/gcd");
//cout << "@" << sc_time_stamp() << " Dump the desired signals" << endl;
//sc_trace(wf, clk, "Clock");
//sc_trace(wf, reset, "Reset");
//sc_trace(wf, valid, "Valid");
//sc_trace(wf, A, "A");
//sc_trace(wf, B, "B");
//sc_trace(wf, ready, "Ready");
//sc_trace(wf, GCD, "GCD");
cout << "@" << sc_time_stamp() << " Wait for 5 clock cycles" << endl;
wait(5);
cout << "@" << sc_time_stamp() << " Set the Reset signal to 1" << endl;
reset.write(1); wait(5);
cout << "@" << sc_time_stamp() << " Set the Reset signal to 0, the input A to 35 and the input B to 30" << endl;
reset.write(0); A.write(35); B.write(30); wait(1);
cout << "@" << sc_time_stamp() << " Set the Valid signal to 1" << endl;
valid.write(1); wait(1);
cout << "@" << sc_time_stamp() << " Set the Valid signal to 0" << endl;
valid.write(0); wait(1);
cout << "@" << sc_time_stamp() << " Wait a few clock cycles to see the result" << endl;
while(ready.read() != 1){
cout << "@" << sc_time_stamp() << " Ready not set. Wait for 1 clock cycle" << endl;
wait(1);
}
cout << "@" << sc_time_stamp() << " Ready signal is set. GCD is " << GCD << endl;
wait(5);
cout << "@" << sc_time_stamp() << " Set the input A to 50 and the input B to 70" << endl;
A.write(50);
B.write(70);
wait(1);
cout << "@" << sc_time_stamp() << " Set the Valid signal to 1" << endl;
valid.write(1);
wait(1);
cout << "@" << sc_time_stamp() << " Set the Valid signal to 0" << endl;
valid.write(0);
wait(1);
cout << "@" << sc_time_stamp() << " Wait a few clock cycles to see the result" << endl;
while(ready.read() != 1){
cout << "@" << sc_time_stamp() << " Ready not set. Wait for 1 clock cycle" << endl;
wait(1);
}
cout << "@" << sc_time_stamp() << " Ready signal is set. GCD is " << GCD << endl;
wait(5);
sc_stop();
}