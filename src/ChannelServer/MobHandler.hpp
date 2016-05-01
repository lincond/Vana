/*
Copyright (C) 2008-2016 Vana Development Team

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
#pragma once

#include "Common/Types.hpp"

namespace Vana {
	class PacketReader;
	struct MobSkillLevelInfo;

	namespace ChannelServer {
		class Mob;
		class Player;
		namespace MobHandler {
			auto handleMobStatus(player_id_t playerId, ref_ptr_t<Mob> mob, skill_id_t skillId, skill_level_t level, item_id_t weapon, int8_t hits, damage_t damage = 0) -> int32_t;
			auto handleBomb(ref_ptr_t<Player> player, PacketReader &reader) -> void;
			auto monsterControl(ref_ptr_t<Player> player, PacketReader &reader) -> void;
			auto friendlyDamaged(ref_ptr_t<Player> player, PacketReader &reader) -> void;
			auto handleTurncoats(ref_ptr_t<Player> player, PacketReader &reader) -> void;
		}
	}
}