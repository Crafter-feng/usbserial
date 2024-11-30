namespace usbserial {

    //% shim=usbserial::writeString
    function writeString(text: string): void{

    }

    /**
     * Print a line of text to the serial port
     * @param value to send over serial
     */
    //% weight=90
    //% help=serial/write-line blockGap=8
    //% blockId=usb_serial_writeline block="usb serial|write line %text"
    //% text.shadowOptions.toString=true
    export function writeLine(text: string): void{
        if (!text) text = "";
        writeString(text);
        writeString("\r\n");
    }
}