#ifndef _klib_klib_h
#define _klib_klib_h

#include <WinSock2.h>
#include <Windows.h>

#include "macro.h"
#include "istddef.h"
#include "inttype.h"

#include "core/klib_core.h"

#include "core/console_screen.h"
#include "core/ini_file.h"
#include "core/DateTime.h"
#include "core/mini_dumper.h"
#include "core/private_heap.h"
#include "core/scope_guard.h"
#include "core/ip_seg_table.h"
#include "core/ini_file.h"
#include "core/console_screen.h"
#include "core/seqnumber.h"

#include "sys/sys.h"

#include "io/file.h"
#include "io/path.h"
#include "io/stream.h"

#include "kthread/kthreadpool.h"
#include "kthread/threadpool.h"
#include "kthread/ReadWriteSection.h"
#include "kthread/thread.h"
#include "kthread/auto_lock.h"

#include "net/winsock_init.h"
#include "net/addr_resolver.h"
#include "net/tcp_socket.h"
#include "net/udp_client.h"


#include "encrypt/MD5.h"
#include "encrypt/md5_single.h"
#include "encrypt/sha1_single.h"
#include "encrypt/crc_single.h"
#include "encrypt/des_single.h"
#include "encrypt/rc4_single.h"

#include "ui/TrayIcon.h"

#include "algo/sort.h"
#include "algo/ld.h"
#include "algo/string_hash.h"

#include "algo/search/search.h"
#include "algo/search/kmp.h"
#include "algo/search/sunday.h"
#include "algo/search/text_search.h"
#include "algo/search/wm_wrapper.h"

#include "util/strutil.h"
#include "util/convert.h"
#include "util/atom.h"
#include "util/perf_counter.h"

#include "pattern/aspect.h"
#include "pattern/factory.h"
#include "pattern/fsm.h"
#include "pattern/object_reuser.h"
#include "pattern/object_pool.h"
#include "pattern/actor.h"
#include "pattern/active_object.h"
#include "pattern/fix_circle_buff.h"

#include "aom/iframework_imp.h"

#include "debuglog.h"

#include "rdebug/ensure.h"
#include "rdebug/must_have_base.h"
#include "rdebug/logger.h"

#include "mem/share_memory.h"

namespace klib
{

using namespace klib::algo;
using namespace klib::debug;
using namespace klib::kthread;
using namespace klib::core;
using namespace klib::mem;
using namespace klib::net;
using namespace klib::util;
using namespace klib::encode;

}

#endif
