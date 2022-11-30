/*
 * main.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Clinton Holladay
 * The user inputs 32 bits of encoded data and the program will parse those bits according to the below scheme. 
 * Then the user inputs the non-encoded data and the program will encode it into a 32 bit packet. 
 *     --------------Packet in names-------------------
 * MSB |addrmode|shortaddr|longaddr|sensor|bat|payload|status|crc| LSB
 * =====================================================================
 *     --------------Packet in bits-------------------
 * MSB |1|11|11111111|111|111|111111111111|1|11| LSB
 *     1-2-----8------3---3------12-------1-2
 *     ------------32 bit packet---------------
 */

#include<stdio.h>
#include<stdint.h>

void wait_for_user();

typedef struct
{
	uint8_t crc; //LSB
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddr;
	uint8_t shortAddr;
	uint8_t addrMode; //MSB
}Packet_t;

int main(void)
{
	Packet_t packet;
	uint32_t Userpacket = 0;
	printf("Packet parsing time!!!\nPlease enter a 32 bit Hexadecimal# :\n");
	scanf("%x", &Userpacket);
	printf("Thank you. Parsing your Packet now.\n");

	//Packet parsing into struct
	packet.crc = Userpacket & 0x0003;
	packet.status = (Userpacket >> 2) & (0x0001);
	packet.payload = (Userpacket >> 3) & (0x0FFF);
	packet.bat = (Userpacket >> 15) & (0x0007);
	packet.sensor = (Userpacket >> 18) & (0x0007);
	packet.longAddr = (Userpacket >> 21) & (0x00FF);
	packet.shortAddr = (Userpacket >> 29) & (0x0003);
	packet.addrMode = (Userpacket >> 31) & (0x0001);

	printf("Parsing Complete!\n");
	printf("======================================\n");
	printf("crc:-------0x%x\n", packet.crc);
	printf("status:----0x%x\n", packet.status);
	printf("payload:---0x%x (%c)\n", packet.payload, packet.payload);
	printf("bat:-------0x%x\n", packet.bat);
	printf("sensor:----0x%x\n", packet.sensor);
	printf("longAddr:--0x%x\n", packet.longAddr);
	printf("shortAddr:-0x%x\n", packet.shortAddr);
	printf("addrMode:--0x%x\n", packet.addrMode);
	printf("======================================\n\n");

	printf("======================================\n");
	printf("======================================\n");
	printf("======================================\n\n");

	uint32_t GeneratedPacket = 0;
	printf("Packet parsing time!!!\nPlease fill the struct with Hexadecimal#s :\n");
	printf("======================================\n");
	printf("ENTER the crc:");
	scanf("%x", &packet.crc);
	printf("\nENTER the status:");
	scanf("%x", &packet.status);
	printf("\nENTER the payload:");
	scanf("%x", &packet.payload);
	printf("\nENTER the bat:");
	scanf("%x", &packet.bat);
	printf("\nENTER the sensor:");
	scanf("%x", &packet.sensor);
	printf("\nENTER the longAddr:");
	scanf("%x", &packet.longAddr);
	printf("\nENTER the shortAddr:");
	scanf("%x", &packet.shortAddr);
	printf("\nENTER the addrMode:");
	scanf("%x", &packet.addrMode);
	printf("\n======================================\n");

	//Parsing struct into a new packet
	GeneratedPacket = packet.crc;
	GeneratedPacket |= (packet.status << 2);
	GeneratedPacket |= (packet.payload << 3);
	GeneratedPacket |= (packet.bat << 15);
	GeneratedPacket |= (packet.sensor << 18);
	GeneratedPacket |= (packet.longAddr << 21);
	GeneratedPacket |= (packet.shortAddr << 29);
	GeneratedPacket |= (packet.addrMode << 31);

	printf("Parsing Complete!\n");
	printf("======================================\n");
	printf("Generated packet:--0x%x\n", GeneratedPacket);

	wait_for_user();
}

void wait_for_user()//hang program to wait for user input
{
	printf("Press any key to EXIT\n");
	while(getchar()!= '\n'){}
	getchar();
}
