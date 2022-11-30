/*
 * main.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Clinton Holladay
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

typedef union
{
	uint32_t packetValue;
	struct
	{
		uint32_t crc       :2; //LSB
		uint32_t status    :1;
		uint32_t payload   :12;
		uint32_t bat       :3;
		uint32_t sensor    :3;
		uint32_t longAddr  :8;
		uint32_t shortAddr :2;
		uint32_t addrMode  :1; //MSB
	}Packet_t;
}Packet_u;

int main(void)
{
	Packet_u packet;
	printf("Packet parsing time!!!\nPlease enter a 32 bit Hexadecimal# :\n");
	scanf("%x", &packet.packetValue);
	printf("Thank you. Parsing your Packet now.\n");

	printf("Parsing Complete!\n");
	printf("======================================\n");
	printf("crc:-------0x%x\n", packet.Packet_t.crc);
	printf("status:----0x%x\n", packet.Packet_t.status);
	printf("payload:---0x%x (%c)\n", packet.Packet_t.payload, packet.Packet_t.payload);
	printf("bat:-------0x%x\n", packet.Packet_t.bat);
	printf("sensor:----0x%x\n", packet.Packet_t.sensor);
	printf("longAddr:--0x%x\n", packet.Packet_t.longAddr);
	printf("shortAddr:-0x%x\n", packet.Packet_t.shortAddr);
	printf("addrMode:--0x%x\n", packet.Packet_t.addrMode);
	printf("======================================\n\n");

	printf("======================================\n");
	printf("======================================\n");
	printf("======================================\n\n");

	uint32_t tmp = 0;
	printf("Packet parsing time!!!\nPlease fill the struct with Hexadecimal#s :\n");
	printf("======================================\n");
	printf("ENTER the crc:");
	scanf("%x", &tmp);
	packet.Packet_t.crc = tmp;
	printf("\nENTER the status:");
	scanf("%x", &tmp);
	packet.Packet_t.status = tmp;
	printf("\nENTER the payload:");
	scanf("%x", &tmp);
	packet.Packet_t.payload = tmp;
	printf("\nENTER the bat:");
	scanf("%x", &tmp);
	packet.Packet_t.bat = tmp;
	printf("\nENTER the sensor:");
	scanf("%x", &tmp);
	packet.Packet_t.sensor = tmp;
	printf("\nENTER the longAddr:");
	scanf("%x", &tmp);
	packet.Packet_t.longAddr = tmp;
	printf("\nENTER the shortAddr:");
	scanf("%x", &tmp);
	packet.Packet_t.shortAddr = tmp;
	printf("\nENTER the addrMode:");
	scanf("%x", &tmp);
	packet.Packet_t.addrMode = tmp;
	printf("\n======================================\n");

	printf("Parsing Complete!\n");
	printf("======================================\n");
	printf("Generated packet is: 0x%x\n", packet.packetValue);

	wait_for_user();
}

void wait_for_user()//hang program to wait for user input
{
	printf("Press any key to EXIT\n");
	while(getchar()!= '\n'){}
	getchar();
}
