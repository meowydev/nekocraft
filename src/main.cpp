#include <iostream>
#include <SFML/Graphics.hpp>
#include <tinyfiledialogs.h>

int main() {
    int result = tinyfd_messageBox(
        "NekoCraft crashed",
        "Core.d failed unexpectedly.\n\nSTOP CODE: CORE.D 0000\n\nTo continue execution press OK otherwise Cancel",
        "okcancel",
        "error",
        0
    );

    if (result == 1) {
        printf("Continuing execution");
    }
    else if (result == 0) {
        printf("stopped");
    }

    return 100;
}
