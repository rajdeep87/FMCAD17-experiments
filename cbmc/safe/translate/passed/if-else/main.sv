module main (clk, a, b, c, d);
   input clk;
   input [7:0] a;
   input [7:0] b;
   output [8:0] c;
   output d;
   reg d;
 always @(posedge clk) begin
   if(b) begin
    d = 1'b0;
   end
  else begin
    d = 1'b1;
  end
 assert property1: !b || !d; 
 assert property (b |-> !d); 
 assert property3: b || d;
 assert property (!b |-> d); 
 end
endmodule 
