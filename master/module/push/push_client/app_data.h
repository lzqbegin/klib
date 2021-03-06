#pragma once

#include <macro.h>
#include "../../include/push_interface.h"


#define  CURRENT_CLIENT_VERSION_STRING "1.1.1.0"
#define  CURRENT_CLIENT_VERSION_VALUE  inet_addr(CURRENT_CLIENT_VERSION_STRING)

class app_data : public singleton<app_data>
{
    DECLARE_SINGLETON_CLASS(app_data)

public:
    DEFINE_ACCESS_FUN_REF_CONST(std::string, channel, channel_)
    DEFINE_ACCESS_FUN_REF_CONST(std::string, mac, mac_)
    DEFINE_ACCESS_FUN_REF_CONST(std::string, user, user_)
    DEFINE_ACCESS_FUN_REF_CONST(std::string, pass, pass_)
    DEFINE_ACCESS_FUN_REF_CONST(std::string, appid, appid_)
    DEFINE_ACCESS_FUN_REF_CONST(UINT64,      last_msg_id, last_msg_id_)

    DEFINE_ACCESS_FUN_REF_CONST(std::string, svr_domain, svr_domain_);
    DEFINE_ACCESS_FUN_REF_CONST(USHORT,      svr_port,   svr_port_);
    DEFINE_ACCESS_FUN_REF_CONST(handle_data_callback, data_callback, data_callback_);
    DEFINE_ACCESS_FUN_REF_CONST(handle_msg_callback, msg_callback, msg_callback_);

    DEFINE_ACCESS_FUN_REF_CONST(UINT32,      logic_addr,   logic_addr_);
    DEFINE_ACCESS_FUN_REF_CONST(USHORT,      logic_port,   logic_port_);

    void save(){}
protected:
    std::string channel_;
    std::string mac_;
    std::string user_;
    std::string pass_;
    std::string appid_;
    UINT64 last_msg_id_;

    std::string svr_domain_;
    USHORT      svr_port_;

    UINT32      logic_addr_;
    USHORT      logic_port_;

    handle_data_callback data_callback_;
    handle_msg_callback msg_callback_;
};

