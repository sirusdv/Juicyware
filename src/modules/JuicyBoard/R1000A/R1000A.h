#ifndef R1000A_H
#define R1000A_H

#include "modules/JuicyBoard/R1000A_I2C/R1000A_I2C.h"

#include "I2C.h"            // mbed.h lib
#include "Module.h"         // for registering events
#include <string>
using std::string;

#define R1000_I2C_BASE      0x10        // I2C address base for R1000A module
#define REG_TEMP            0x10        // I2C register address of temperature readback

class StreamOutput;

// R1000A class declaration goes here
class R1000A : public Module {
    public:
        // Default Constructor
        R1000A();

        // Destructor
        ~R1000A();

        // Smoothie main module loading function
        void on_module_loaded();

        // console line received
        void on_console_line_received(void *);

        // Scan I2C bus for modules
        void ScanI2CBus();

        // Report populated slot ID's
        void ReportI2CID();
    
        // reports temperature of card on slot
        int getTemp(int Slot);

        // Accessor functions
        int getSlotDevID(int) const;

        static bool parse_command(const char *cmd, string args, StreamOutput *stream);

    private:
        // Member variables
        R1000A_I2C i2c;

        int SlotPlatID[16];             // module platform ID
        int SlotDevID[16];              // module device ID
        int SlotDevFW[16];              // module firmware version

        // console commands
        void getTemp(string);
};

#endif
