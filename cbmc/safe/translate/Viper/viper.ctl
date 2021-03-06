#PASS: The processor freezes as soon as a value greater than 2**20 is
# stored in the program counter.
AG(reg_P[31:20]=0 + AG !reg_P[31:20]=0);

#PASS: An illegal instruction causes STOP to be aserted.
AG(cf=0 * !df[2:1]=b11 * ff[3:0]={b1101,b1110,b1111} * reg_P[31:20]=0 ->
   AX STOP=1);

#PASS: Once STOP is asserted, it remains so.
AG(STOP=1 -> AG STOP=1);
