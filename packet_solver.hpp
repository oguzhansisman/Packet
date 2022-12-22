#include "stdint.h"

namespace com
{
    class com_channel_c
    {
    private:
        /* data */
        static uint32_t total_ch_num_u32;
        struct 
        {
            uint8_t (*m_solver_fp)(void* p_data);
            uint8_t (*m_creater_fp)(void* p_data);
        }fps;
        
    public:
        com_channel_c(uint8_t (*solver_fp)(void* p_data), uint8_t (*creater_fp)(void* p_data));
        ~com_channel_c();
        uint8_t create(void* p_data_u8, uint32_t size_u32);
        uint8_t solve(void* p_data_u8);
    };
}
