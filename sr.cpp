#include "systemc.h"
#include "sr.h"

void sr::shift()
{
	sc_int<8> t_r;

	r.write(0);
	while (1) {
		wait();
		t_r = r;

		t_r[7] = t_r[6];
		t_r[6] = t_r[5];
		t_r[5] = t_r[4];
		t_r[4] = t_r[3];
		t_r[3] = t_r[2];
		t_r[2] = t_r[1];
		t_r[1] = t_r[0];
		t_r[0] = din;
		wait(2, SC_NS);
		r.write(t_r);
	}
}
