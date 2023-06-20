typedef logic [31:0] pc_addr;
module simple_cpu
(clk,rst);

input logic clk;
input logic rst;

logic [31:0] pc;

logic [31:0]rom_addr;
logic [31:0]rom_data;

always_comb rom_addr = pc;



simple_cpu_rom simple_cpu_rom_inst(.*);
simple_cpu_pc simple_cpu_pc_inst(.*);
endmodule

