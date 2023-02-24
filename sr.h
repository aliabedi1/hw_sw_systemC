
struct sr : sc_module {
    sc_in<bool> clk;
    sc_in<bool> din;

	sc_out<sc_int<8> > r;

    
    void shift();
    
    
    SC_CTOR( sr ) {

	SC_THREAD( shift); 
 		sensitive_pos << clk;
    }
};
