#include "Vtest_beach.h"
#include <verilated_vcd_c.h>
#define GEN_WAVE 0
#define MAX_SIM_TIME 20540
#define MAX_ROM_ADDR 1023
vluint64_t sim_time = 0;
vluint64_t init_rom = 0;
int main(int argc, char **argv, char **env)
{
    Vtest_beach *dut = new Vtest_beach;
#if (GEN_WAVE)
    Verilated::traceEverOn(true);

    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");
#endif
    while (init_rom < MAX_ROM_ADDR)
    {
        dut->test_beach__DOT__simple_cpu_inst__DOT__simple_cpu_rom_inst__DOT__logic_rom_data[init_rom] = init_rom;
        init_rom++;
    }
    while (sim_time < MAX_SIM_TIME)
    {
        dut->clk = (sim_time % 10) ? dut->clk : dut->clk ^ 1;
        dut->rst = (sim_time < 50) ? 0 : 1;
        if (sim_time % 20 == 0)
        {
            printf("PC:%08X", dut->test_beach__DOT__simple_cpu_inst__DOT__pc);
            printf("\tINST:%08X", dut->test_beach__DOT__simple_cpu_inst__DOT__rom_data);
            printf("\n");
        }
        dut->eval();
#if (GEN_WAVE)
        m_trace->dump(sim_time);
#endif
        sim_time++;
    }
#if (GEN_WAVE)
    m_trace->close();
#endif
    delete dut;
    exit(EXIT_SUCCESS);
}