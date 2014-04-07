/*!
 \file      Example1.cpp

 \brief     Example code source for class serialib.
            This example open the device on ttyACM0.
            (USB to RS232 converter under linux).
            If the opening is successful, it sends the AT command
            and waits for a string being received from the device.
            After 5 seconds, if no valid data are received from the
            device, reception is giving up.

 \author    Philippe Lucidarme (University of Angers) <serialib@googlegroups.com>
 \version   1.2
 \date      05/01/2011
 */

#include <stdio.h>
#include "serialib.h"


#if defined (_WIN32) || defined( _WIN64)
#define         DEVICE_PORT             "COM1"                               // COM1 for windows
#endif

#ifdef __linux__
//#define         DEVICE_PORT             "/dev/ttyS0"                         // ttyS0 for linux
#define         DEVICE_PORT             "/dev/ttyS2"                         // ttyS0 for linux
#endif


int main()
{
    serialib LS;                                                            // Object of the serialib class
    int Ret;                                                                // Used for return values
    // Open serial port

    Ret=LS.Open(DEVICE_PORT,9600);                                        // Open serial link at 115200 bauds
    if (Ret!=1) {                                                           // If an error occured...
        printf ("Error while opening port. Permission problem ?\n");        // ... display a message ...
        return Ret;                                                         // ... quit the application
    }
    printf ("Serial port opened successfully !\n");

    while(1){


    // Write the AT command on the serial port

    Ret=LS.WriteString("AT\n");                                             // Send the command on the serial port
    if (Ret!=1) {                                                           // If the writting operation failed ...
        printf ("Error while writing data\n");                              // ... display a message ...
        return Ret;                                                         // ... quit the application.
    }
    printf ("Write operation is successful \n");



    LS.Close();
    sleep(1);
    }
    return 0;

}


