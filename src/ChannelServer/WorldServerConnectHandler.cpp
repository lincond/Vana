/*
Copyright (C) 2008-2009 Vana Development Team

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
#include "WorldServerConnectHandler.h"
#include "BeautyDataProvider.h"
#include "ChannelServer.h"
#include "Configuration.h"
#include "ConfigurationPacket.h"
#include "Connectable.h"
#include "DropDataProvider.h"
#include "GuildPacket.h"
#include "ItemDataProvider.h"
#include "MapDataProvider.h"
#include "MapleSession.h"
#include "MiscUtilities.h"
#include "MobDataProvider.h"
#include "PacketCreator.h"
#include "PacketReader.h"
#include "Player.h"
#include "PlayerDataProvider.h"
#include "PlayerPacket.h"
#include "PlayersPacket.h"
#include "QuestDataProvider.h"
#include "Quests.h"
#include "Rates.h"
#include "ReactorDataProvider.h"
#include "ScriptDataProvider.h"
#include "ShopDataProvider.h"
#include "SkillDataProvider.h"
#include "WorldServerConnection.h"
#include <iostream>
#include <limits>

void WorldServerConnectHandler::connectLogin(WorldServerConnection *player, PacketReader &packet) {
	int8_t worldid = packet.get<int8_t>();
	if (worldid != -1) {
		ChannelServer::Instance()->setWorld(worldid);
		ChannelServer::Instance()->setWorldIp(packet.get<uint32_t>());
		ChannelServer::Instance()->setWorldPort(packet.get<int16_t>());
		std::cout << "Connecting to world " << (int16_t) worldid << std::endl;
		ChannelServer::Instance()->connectWorld();
	}
	else {
		std::cout << "Error: No world server to connect" << std::endl;
		ChannelServer::Instance()->shutdown();
	}
}

void WorldServerConnectHandler::connect(WorldServerConnection *player, PacketReader &packet) {
	int16_t channel = packet.get<int16_t>();
	if (channel != -1) {
		int8_t chid = channel + 1;
		uint16_t port = packet.get<uint16_t>();
		ChannelServer::Instance()->setChannel(channel);
		ChannelServer::Instance()->setPort(port);

		Configuration conf = ConfigurationPacket::getConfig(packet);

		ChannelServer::Instance()->setConfig(conf);
		ChannelServer::Instance()->setPianusChannel(MiscUtilities::isBossChannel(conf.pianusChannels, chid));
		ChannelServer::Instance()->setPapChannel(MiscUtilities::isBossChannel(conf.papChannels, chid));
		ChannelServer::Instance()->setZakumChannel(MiscUtilities::isBossChannel(conf.zakumChannels, chid));
		ChannelServer::Instance()->setHorntailChannel(MiscUtilities::isBossChannel(conf.horntailChannels, chid));
		ChannelServer::Instance()->setPinkBeanChannel(MiscUtilities::isBossChannel(conf.pinkbeanChannels, chid));

		ChannelServer::Instance()->listen();
		std::cout << "Handling channel " << channel << " on port " << port << std::endl;

		ChannelServer::Instance()->displayLaunchTime();
	}
	else {
		std::cout << "Error: No channel to handle" << std::endl;
		ChannelServer::Instance()->shutdown();
	}
}

void WorldServerConnectHandler::playerChangeChannel(WorldServerConnection *player, PacketReader &packet) {
	int32_t playerid = packet.get<int32_t>();
	uint32_t ip = packet.get<uint32_t>();
	int16_t port = packet.get<int16_t>();

	Player *ccPlayer = PlayerDataProvider::Instance()->getPlayer(playerid);
	if (!ccPlayer) {
		return;
	}
	if (ip == 0) {
		PlayerPacket::sendBlockedMessage(ccPlayer, 0x01);
	}
	else {
		ccPlayer->setOnline(0); // Set online to 0 BEFORE CC packet is sent to player
		PlayerPacket::changeChannel(ccPlayer, ip, port);
		ccPlayer->saveAll(true);
		ccPlayer->setSaveOnDc(false);
	}
}

void WorldServerConnectHandler::findPlayer(PacketReader &packet) {
	int32_t finder = packet.get<int32_t>();
	int16_t channel = packet.get<int16_t>();
	string name = packet.getString();
	int8_t is = packet.get<int8_t>();
	if (channel == -1) {
		PlayersPacket::findPlayer(PlayerDataProvider::Instance()->getPlayer(finder), name, -1, is);
	}
	else {
		PlayersPacket::findPlayer(PlayerDataProvider::Instance()->getPlayer(finder), name, channel, is, 1);
	}
}

void WorldServerConnectHandler::whisperPlayer(PacketReader &packet) {
	int32_t whisperee = packet.get<int32_t>();
	string whisperer = packet.getString();
	uint16_t channel = packet.get<int16_t>();
	string message = packet.getString();

	PlayersPacket::whisperPlayer(PlayerDataProvider::Instance()->getPlayer(whisperee), whisperer, channel, message);
}

void WorldServerConnectHandler::scrollingHeader(PacketReader &packet) {
	string message = packet.getString();
	ChannelServer::Instance()->setScrollingHeader(message);
}

void WorldServerConnectHandler::newConnectable(PacketReader &packet) {
	Connectable::Instance()->newPlayer(packet.get<int32_t>());
}

void WorldServerConnectHandler::forwardPacket(PacketReader &packet) {
	PacketCreator ppacket;
	int32_t playerid = packet.get<int32_t>();
	ppacket.addBuffer(packet);

	Player *player = PlayerDataProvider::Instance()->getPlayer(playerid);
	if (player != 0)
		player->getSession()->send(ppacket);
}

void WorldServerConnectHandler::guildPacketHandlerWorld(PacketReader &packet) {
	switch (packet.get<int8_t>()) {
		case 0x01: PlayerDataProvider::Instance()->unloadGuild(packet.get<int32_t>()); break;
		case 0x02: GuildPacket::handleEmblemChange(packet); break;
		case 0x03: { // Remove player guild info
			Player *player = PlayerDataProvider::Instance()->getPlayer(packet.get<int32_t>());
			if (player == 0) 
				return;

			player->setGuildId(0);
			player->setGuildRank(5);
			break;
		}
		case 0x04: { // Add guild to player
			Player *player = PlayerDataProvider::Instance()->getPlayer(packet.get<int32_t>());
			if (player == 0) 
				return;

			player->setGuildId(packet.get<int32_t>());
			player->setGuildRank(packet.get<uint8_t>());
			player->setAllianceId(packet.get<int32_t>());
			player->setAllianceRank(packet.get<uint8_t>());
			break;
		}
		case 0x05: { // Update player guild and alliance rank
			Player *player = PlayerDataProvider::Instance()->getPlayer(packet.get<int32_t>());
			if (player == 0) 
				return;

			player->setGuildRank(packet.get<uint8_t>());
			player->setAllianceRank(packet.get<uint8_t>());
			break;
		}
		case 0x06: { // Remove/add money from/to the player
			Player *player = PlayerDataProvider::Instance()->getPlayer(packet.get<int32_t>());
			if (player == 0) 
				return;

			Quests::giveMesos(player, packet.get<int32_t>());
			break;
		}
		case 0x07: { // Change guild capacity
			Guild *gi = PlayerDataProvider::Instance()->getGuild(packet.get<int32_t>());
			if (gi == 0) 
				return;
			gi->capacity = packet.get<int32_t>();
			break;
		}
		case 0x08: GuildPacket::handleNameChange(packet); break;
		case 0x09: PlayerDataProvider::Instance()->loadGuild(packet.get<int32_t>()); break;
		case 0x0a: {
			int32_t guilds = packet.get<int32_t>();
			int32_t id, capacity, alliance;
			string name;
			GuildLogo logo;
			for (int32_t i = 0; i < guilds; i++) {
				id = packet.get<int32_t>();
				name = packet.getString();
				logo.logo = packet.get<int16_t>();
				logo.color = packet.get<uint8_t>();
				logo.background = packet.get<int16_t>();
				logo.backgroundColor = packet.get<uint8_t>();
				capacity = packet.get<int32_t>();
				alliance = packet.get<int32_t>();

				PlayerDataProvider::Instance()->addGuild(id, name, logo, capacity, alliance);
				break;
			}
		}
	}
}

void WorldServerConnectHandler::alliancePacketHandlerWorld(PacketReader &packet) {
	switch (packet.get<int8_t>()) {
		case 0x01: { // (un)Load Alliance and set the allianceids and ranks
			uint8_t option = packet.get<uint8_t>();
			int32_t allianceid = packet.get<int32_t>();
			if (option == 0)
				PlayerDataProvider::Instance()->unloadAlliance(allianceid);
			else
				PlayerDataProvider::Instance()->loadAlliance(allianceid);
			uint8_t guilds = packet.get<uint8_t>();
			for (uint8_t i = 0; i < guilds; i++) {
				Guild *guild = PlayerDataProvider::Instance()->getGuild(packet.get<int32_t>());
				guild->allianceid = allianceid;

				int32_t players = packet.get<int32_t>();
				for (int32_t j = 0; j < players; j++) {
					int32_t playerid = packet.get<int32_t>();
					uint8_t rank = packet.get<uint8_t>();
					if (Player *player = PlayerDataProvider::Instance()->getPlayer(playerid)) {
						player->setAllianceId(allianceid);
						player->setAllianceRank(rank);
					}
				}
			}
			break;
		}
		case 0x02: { // Changing the Alliance Leader
			int32_t allianceid = packet.get<int32_t>();
			Player *to = PlayerDataProvider::Instance()->getPlayer(packet.get<int32_t>());
			Player *from = PlayerDataProvider::Instance()->getPlayer(packet.get<int32_t>());
			if ((to != 0 && to->getAllianceId() != allianceid) || (from != 0 && from->getAllianceId() != allianceid)) 
				return;
			if (to != 0) 
				to->setAllianceRank(2);
			if (from != 0) 
				from->setAllianceRank(1);
			break;
		}
		case 0x03: { // Changing the Alliance Capacity
			if (Alliance *alliance = PlayerDataProvider::Instance()->getAlliance(packet.get<int32_t>())) 
				alliance->capacity = packet.get<int32_t>();
			break;
		}
		case 0x04: { // Changing the alliance id and rank
			int32_t allianceid = packet.get<int32_t>();
			Guild *guild = PlayerDataProvider::Instance()->getGuild(packet.get<int32_t>());
			guild->allianceid = allianceid;
			int32_t players = packet.get<int32_t>();
			for (int32_t i_2 = 0; i_2 < players; i_2++) {
				if (Player *player = PlayerDataProvider::Instance()->getPlayer(packet.get<int32_t>())) {
					player->setAllianceId(allianceid);
					player->setAllianceRank(packet.get<uint8_t>());
				}
			}
			break;
		}
		case 0x05: { // Changing the rank of someone
			int32_t allianceid = packet.get<int32_t>();
			Player *victim = PlayerDataProvider::Instance()->getPlayer(packet.get<int32_t>());
			if (victim != 0 || victim->getAllianceId() != allianceid || victim->getGuildId() == 0) 
				return;
			victim->setAllianceRank(packet.get<uint8_t>());
			break;
		}
		case 0x06: { // Channel Server Alliance Data Packet
			int32_t alliances = packet.get<int32_t>();
			int32_t id, capacity;
			string name;
			for (int32_t i = 0; i < alliances; i++) {
				id = packet.get<int32_t>();
				name = packet.getString();
				capacity = packet.get<int32_t>();
				PlayerDataProvider::Instance()->addAlliance(id, name, capacity);
			}
			break;
		}
	}
}

void WorldServerConnectHandler::setRates(PacketReader &packet) {
	int32_t ratesSetBit = packet.get<int32_t>();
	if (ratesSetBit & Rates::SetBits::exp) {
		ChannelServer::Instance()->setExpRate(packet.get<int32_t>());
	}
	if (ratesSetBit & Rates::SetBits::questExp) {
		ChannelServer::Instance()->setQuestExpRate(packet.get<int32_t>());
	}
	if (ratesSetBit & Rates::SetBits::meso) {
		ChannelServer::Instance()->setMesoRate(packet.get<int32_t>());
	}
	if (ratesSetBit & Rates::SetBits::drop) {
		ChannelServer::Instance()->setDropRate(packet.get<int32_t>());
	}
}

void WorldServerConnectHandler::reloadMcdb(PacketReader &packet) {
	string args = packet.getString();
	if (args == "all") {
		ItemDataProvider::Instance()->loadData();
		DropDataProvider::Instance()->loadData();
		ShopDataProvider::Instance()->loadData();
		MobDataProvider::Instance()->loadData();
		BeautyDataProvider::Instance()->loadData();
		ScriptDataProvider::Instance()->loadData();
		SkillDataProvider::Instance()->loadData();
		ReactorDataProvider::Instance()->loadData();
		QuestDataProvider::Instance()->loadData();
	}
	else if (args == "items") ItemDataProvider::Instance()->loadData();
	else if (args == "drops") DropDataProvider::Instance()->loadData();
	else if (args == "shops") ShopDataProvider::Instance()->loadData();
	else if (args == "mobs") MobDataProvider::Instance()->loadData();
	else if (args == "beauty") BeautyDataProvider::Instance()->loadData();
	else if (args == "scripts") ScriptDataProvider::Instance()->loadData();
	else if (args == "skills") SkillDataProvider::Instance()->loadData();
	else if (args == "reactors") ReactorDataProvider::Instance()->loadData();
	else if (args == "quest") QuestDataProvider::Instance()->loadData();
}