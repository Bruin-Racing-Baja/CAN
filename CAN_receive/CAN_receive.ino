
#include <SPI.h>
#include <mcp_can.h>


const int SPI_CS_PIN = 17;

MCP_CAN CAN(SPI_CS_PIN);

void setup() {

    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_500KBPS)) // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS init fail");
        Serial.println(" Init CAN BUS again");
        delay(100);
    }
    Serial.println("CAN BUS init ok!");

}

void loop() {

    byte len = 0;
    byte buf[1];

    if(CAN_MSGAVAIL == CAN.checkReceive()) // check if data is available
    {
         // read data, len: get data length, buf: data buffer
        CAN.readMsgBuf(&len, buf);    
        // ID of sender
        unsigned long canId = CAN.getCanId();
    } 

}
