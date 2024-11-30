#include "pxt.h"


namespace usbserial{
      MicroBitSerial *_serial = nullptr;

    /**
     * Send a piece of text through the serial connection.
     */
    //% help=serial/write-string
    //% weight=87 blockGap=8
    //% blockId=usb_serial_writestring block="usb serial|write string %text"
    //% text.shadowOptions.toString=true
    void writeString(String text) {
      if (!text) return;

      if(_serial == nullptr)
      {
#if MICROBIT_CODAL
      _serial = new MicroBitSerial(uBit.io.usbTx, uBit.io.usbRx, 64, 64);
      _serial->setBaud(115200);
#else
      _serial = new MicroBitSerial(USBTX, USBRX, 64, 64);
      _serial->baud(115200);
#endif
      }
      _serial->send(MSTR(text));
    }   

    void sendString(const char *c, int len) {
        if(_serial != nullptr)
        {
            while (len--)
                _serial->putc(*c++);
        }
    } 
}

void sendString(const char *c, int len) {
    usbserial::sendString(c, len);
} 