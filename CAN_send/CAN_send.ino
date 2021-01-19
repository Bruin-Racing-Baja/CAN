#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 17;
const int canID = 0x01;

MCP_CAN CAN(SPI_CS_PIN);

void setup() {

  Serial.begin(115200);

  while (CAN_OK != CAN.begin(CAN_500KBPS))  // init can bus : baudrate = 500k
  {
    Serial.println("CAN BUS init fail");
    Serial.println(" Init CAN BUS again");
    delay(100);
  }
  Serial.println("CAN BUS init ok!");
}

byte msg[8] = {0,1,2,3,4,5,6,7};

void loop() {

  //0: standard frame, 1: data length, msg: CAN message
  CAN.sendMsgBuf(canID, 0, 8, msg); 
  Serial.println("Message Sent:");
  Serial.println(msg[0]);
}
