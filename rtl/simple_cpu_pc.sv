module simple_cpu_pc(clk,rst,pc);
input logic clk;
input logic rst;
output logic [31:0]pc;

always_ff @ (posedge clk or negedge rst) begin
    if(~rst) begin
        pc <= 32'b0;
    end
    else begin
        pc <= pc + 1'b1;
    end
end
endmodule