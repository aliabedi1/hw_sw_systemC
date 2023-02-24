
#include "systemc.h"
#include "sr.h"
#include "driver.h"

int sc_main(int ac, char *av[])
{
	sc_signal<bool> din;
	sc_signal<sc_int<8> > r;

	sc_trace_file *tf;

	sc_clock clk ("ID", 10, SC_NS, 0.5, 10, SC_NS, true);

	driver dr("generateInputs");
	dr.din(din);

	sr shr("shift_reg");
	shr.din(din);
	shr.clk(clk);
	shr.r(r);

	
	tf = sc_create_vcd_trace_file("waves");
	sc_trace(tf, clk, "clk");
	sc_trace(tf, din, "din");
	sc_trace(tf, r, "r");

	sc_start(-1);

	sc_close_vcd_trace_file(tf);

	return 0;
}
