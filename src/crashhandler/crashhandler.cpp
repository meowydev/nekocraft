//
// Created by meowy on 7/30/26.
//

#include "crashhandler.hpp"
#include <format>
#include <tinyfiledialogs.h>

namespace nekocraft {

    void crashhandler::Crash(int type,const char* msg) {
        if (type == 1) {
            tinyfd_messageBox(
                "NekoCraft crashed",
                msg,
                "okcancel",
                "error",
                1
            );
        }
    }

    void crashhandler::Fatal(const char *msg) {
        crashhandler::Crash(1, msg);
    }
} // nekocraft


// TABLE
// 1 - FATAL