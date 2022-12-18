#include "packet_solver.hpp"
#include "stddef.h"

com_channel_c::com_channel_c(uint8_t (*solver_fp)(void* p_data), uint8_t (*creater_fp)(void* p_data))
{
    this->fps.m_solver_fp = creater_fp;
    this->fps.m_solver_fp = solver_fp;

    this->total_ch_num_u32++;
}

com_channel_c::~com_channel_c()
{
    this->fps.m_creater_fp = NULL;
    this->fps.m_solver_fp = NULL;
}

uint8_t com_channel_c::create(void* p_data_u8, uint32_t size_u32)
{
    if (NULL != this->fps.m_creater_fp)
    {
        this->fps.m_creater_fp(p_data_u8);
        return 1;
    }
    else
    {
        return 0;
    }



}

uint8_t com_channel_c::solve(void* p_data_u8) 
{

    if (NULL != this->fps.m_solver_fp)
    {
        this->fps.m_solver_fp(p_data_u8);
        return 1;
    }
    else
    {
        return 0;
    }
}
