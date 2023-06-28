#include "PacketHandler.h"



void PacketHandler::Serialize(Packet* packet, BYTE* buffer)
{
    int offset = 0;

    memcpy(buffer + offset, &packet->size, sizeof(packet->size));
    offset += sizeof(packet->size);

    memcpy(buffer + offset, &packet->id, sizeof(packet->id));
    offset += sizeof(packet->id);

    memcpy(buffer + offset, packet->data, packet->size);
}

void PacketHandler::Deserialize(BYTE* buffer, Packet* packet)
{
    int offset = 0;

    memcpy(&packet->size, buffer + offset, sizeof(packet->size));
    offset += sizeof(packet->size);

    memcpy(&packet->id, buffer + offset, sizeof(packet->id));
    offset += sizeof(packet->id);

    memcpy(packet->data, buffer + offset, packet->size);
}

void PacketHandler::MakeSignUpPacket(Packet* packet, const char* id, const char* pw)
{
    int offset = 0;

    packet->id = C2S_LOGIN_REQUEST;

    memcpy(packet->data + offset, id, strlen(id));
    offset += strlen(id);

    memcpy(packet->data + offset, pw, strlen(pw));
    offset += strlen(pw);

    packet->size = offset;
}

void PacketHandler::MakeLoginPacket(Packet* packet, const char* id, const char* pw)
{
    int offset = 0;

    packet->id = C2S_SIGNUP_REQUEST;

    memcpy(packet->data + offset, id, strlen(id));
    offset += strlen(id);

    memcpy(packet->data + offset, pw, strlen(pw));
    offset += strlen(pw);

    packet->size = offset;
}

void PacketHandler::MakeLogoutPacket(Packet* packet, const char* id)
{
    int offset = 0;

    packet->id = C2S_LOGOUT;

    memcpy(packet->data + offset, id, strlen(id));
    offset += strlen(id);

    packet->size = offset;
}


