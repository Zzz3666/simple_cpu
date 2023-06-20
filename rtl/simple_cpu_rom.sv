module simple_cpu_rom(clk,rst,rom_addr,rom_data);
input logic clk;
input logic rst;
input logic [31:0]rom_addr;
output logic [31:0]rom_data;

logic [31:0] logic_rom_data [1023:0];

always @ (posedge clk or negedge rst) begin
    if(!rst) begin
        rom_data <= 0;
    end
    else begin
            rom_data <= logic_rom_data[rom_addr];
    end
end


endmodule