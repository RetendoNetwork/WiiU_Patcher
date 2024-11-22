#include "main.h"
#include "screen.h"

int 
main(int argc, char **argv[]) {
    nn::ac::Initialize();
    WHBProcInit();
    WHBLogConsoleInit();
    WHBLogUdpInit();

    uint32_t ip = 0;

    if (!nn::ac::GetAssignedAddress(&ip)) {
      WHBLogPrintf("GetAssignedAddress failed!");
    }

    WiiUScreen* screen = new WiiUScreen();

    screen->StartFrame();
    screen->DrawText("-- [Retendo Network Patcher] --");
    screen->DrawTextf("The console IP Address is -> %u.%u.%u.%u",
                (ip >> 24) & 0xFF,
                (ip >> 16) & 0xFF,
                (ip >>  8) & 0xFF,
                (ip >>  0) & 0xFF);
    screen->DrawText("Press [+] to swipe to Retendo Network Service.");
    screen->DrawText("Press [-] to swipe to Nintendo Network Service.");
    screen->EndFrame();

    while(WHBProcIsRunning()) {
        VPADReadError err;
		VPADStatus vpad;

		VPADRead(VPAD_CHAN_0, &vpad, 1, &err);
		uint32_t btn = vpad.hold | vpad.trigger;

        if (btn & VPAD_BUTTON_PLUS) {
            OSSleepTicks(OSMillisecondsToTicks(150));
        } else if (btn & VPAD_BUTTON_MINUS) {
            OSSleepTicks(OSMillisecondsToTicks(150));   
        } else if (btn & VPAD_BUTTON_HOME) {
            OSSleepTicks(OSMillisecondsToTicks(150));
        }
    }
    
    WHBLogConsoleFree();
    WHBProcShutdown();
    nn::ac::Finalize();
    return 0;
}