#ifndef _klib_addr_mgr_h_
#define _klib_addr_mgr_h_

#include <map>
#include <functional>

#include "../include/allocator.h"
#include "../include/lock.h"

#ifdef _DEBUG
#define  ADDR_DESC_LEN  (150)
#else
#define  ADDR_DESC_LEN  (50)
#endif

// stats memory info
struct addr_stats_info
{
    addr_stats_info() 
        : ncurr_size(0)
        , nmax_size(0)
        , self_size(0)
        , nalloc_count(0)
        , nfree_count(0) 
    {}

    size_t ncurr_size;           // 当前大小
    size_t nmax_size;            // 最大大小
    size_t self_size;            // 自身统计消耗的内存

    size_t nalloc_count;          // 申请的次数
    size_t nfree_count;          // 释放的次数
};

struct addr_info
{
    addr_info() 
        : nsize(0)
    { desc[0] = 0; }

    size_t nsize;
    char   desc[ADDR_DESC_LEN];
};

typedef std::function<void(addr_info*)> view_addr_callback ;

// 统计
class addr_mgr
{
public:
    addr_mgr();

    virtual void set_desc(const char* desc);
    virtual const char* get_desc();

    virtual void enable_stats(bool enable);
    virtual bool get_enable_stats();

    virtual bool add_addr_info(void* p, 
        size_t nsize,
        const char* desc = nullptr);

    virtual bool del_addr_info(void* p, 
        size_t& nsize,
        const char* desc = nullptr);

    addr_stats_info& get_stats_info() { return m_stats_info; }

public:
    void for_each(const view_addr_callback& func);

protected:
    std::map<void*, 
             addr_info, 
             std::less<void*>, 
             MemAlloc<std::pair<void*, addr_info>> >    m_addr_infos;

    bool                m_enable_stats;    // 统计
    critical_section    m_auto_cs;
    addr_stats_info     m_stats_info;      // 应用消耗的内存统计
    char                m_desc[30];
};



#endif // _klib_addr_mgr_h_