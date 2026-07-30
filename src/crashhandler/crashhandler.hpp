//
// Created by meowy on 7/30/26.
//

#ifndef NEKOCRAFT_CRASHHANDLER_HPP
#define NEKOCRAFT_CRASHHANDLER_HPP

namespace nekocraft {
    class crashhandler {
    public:
        static void Crash(int type,const char *msg);

        //static void type
        static void Fatal(const char* msg);
    };
} // nekocraft

#endif //NEKOCRAFT_CRASHHANDLER_HPP
