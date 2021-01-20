# CAN
CAN bus libraries and send/receive templates.
- [Overview](#overview)
- [Hardware](#hardware)
- [Dictionary](#dictionary)

## Overview
CAN Bus is a reliable communication protocol widely used in vehicles. All microcontrollers can send messages on the bus but those with higher priorities (lower numerical ID) take precedence. Every microcontroller can read every message on the bus as well as the associated ID. Message failure is automatically handled, and nodes will try again until message is successful, or will auto shut-off if it fails too many times. RX filters (masks) can be used to accept only messages fitting certain requirements.

### Technical Details  
CAN Bus sends messages in a frame, which contains ID, delimiters, data, and checking bits. Each frame is 128 bits and frames are separated by 3 interframe spacing bits. Within the frame is a maximum of 8 bytes for data. Max baud rate is 1Mbps but decreases for long bus length. If 5 of the same bits appear in a row, the transmitter will "stuff" an extra bit of opposite polarity to help keep track of clock edges. If possible, avoid long strings of 1s or 0s as this can increase message size by 10%.

CAN IDs are an 11bit usually hexidecimal number. On the CAN bus, a state of 1 is passive and a state of 0 is passive. During the arbitration phase of a frame, all nodes attempt to send their ID at the same time. If a bit in a node's ID is 1 (passive) but the node sees a 0 (active), it means another node with higher priority is also attempting to transmit, so the lower priority node waits for the next frame. 0x00 is the highest priority ID.

## Hardware
The [Seeed CANBed](https://www.seeedstudio.com/CANBed-Arduino-CAN-BUS-Development-Kit-Atmega32U4-with-MCP2515-and-MCP2551-p-4365.html) integrates a CAN Transceiver IC with an ATMega32U4 (Arduino Leonardo). We have 3 of the units to test with.

Teensy 4.0 requires a [CAN Transceiver](https://www.amazon.com/SN65HVD230-CAN-Board-Communication-Development/dp/B00KM6XMXO/ref=pd_sbs_23_1/139-4643608-2420310?_encoding=UTF8&pd_rd_i=B00KM6XMXO&pd_rd_r=ce118a35-22cb-46f7-92e2-3216728be2cd&pd_rd_w=qILMH&pd_rd_wg=WCYt1&pf_rd_p=52b7592c-2dc9-4ac6-84d4-4bda6360045e&pf_rd_r=ZZ0ZDGD7BV6253A1JERZ&psc=1&refRID=ZZ0ZDGD7BV6253A1JERZ) and uses the [FlexCAN Library](https://github.com/teachop/FlexCAN_Library). We currently do not have any of the transceivers.

At each end of the bus, a 120 resistor must be soldered between CANH and CANL to prevent message reflection. The CANBed includes a switch for the end nodes to engage/disengage a resistor.

# Dictionary
- CAN - Controller Area Network
