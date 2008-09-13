/*
Copyright (C) 2008 Vana Development Team

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#include "LoginServerAcceptPlayerPacket.h"
#include "InterHeader.h"
#include "LoginServerAcceptPlayer.h"
#include "MapleSession.h"
#include "PacketCreator.h"
#include "Rates.h"
#include "Worlds.h"

void LoginServerAcceptPlayerPacket::connect(LoginServerAcceptPlayer *player, World *world) {
	PacketCreator packet;
	packet.addShort(INTER_WORLD_CONNECT);
	packet.addByte(world->id);
	packet.addShort(world->port);
	packet.addInt(world->maxChannels);
	packet.addByte(world->maxMultiLevel);
	
	packet.addInt(Rates::SetBits::all);
	packet.addInt(world->exprate);
	packet.addInt(world->questexprate);
	packet.addInt(world->mesorate);
	packet.addInt(world->droprate);
	player->getSession()->send(packet);
}

void LoginServerAcceptPlayerPacket::connectChannel(LoginServerAcceptPlayer *player, char worldid, const string &ip, int16_t port) {
	PacketCreator packet;
	packet.addShort(INTER_LOGIN_CHANNEL_CONNECT);
	packet.addByte(worldid);
	packet.addString(ip);
	packet.addShort(port);
	player->getSession()->send(packet);
}

void LoginServerAcceptPlayerPacket::newPlayer(LoginServerAcceptPlayer *player, uint16_t channel, int32_t charid) {
	PacketCreator packet;
	packet.addShort(INTER_NEW_PLAYER);
	packet.addShort(channel);
	packet.addInt(charid);
	player->getSession()->send(packet);
}
