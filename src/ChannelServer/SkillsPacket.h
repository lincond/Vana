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
#ifndef SKILLSPACK_H
#define SKILLSPACK_H

#include "Types.h"
#include <vector>

using std::vector;

class Player;
struct PlayerSkillInfo;
struct SkillActiveInfo;
struct SpecialSkillInfo;

namespace SkillsPacket {
	void addSkill(Player *player, int32_t skillid, PlayerSkillInfo skillinfo);
	void showSkill(Player *player, int32_t skillid, unsigned char level);
	void useSkill(Player *player, int32_t skillid, int32_t time, SkillActiveInfo pskill, SkillActiveInfo mskill, int16_t addedinfo, int32_t mountid = 0);
	void endSkill(Player *player, SkillActiveInfo pskill, SkillActiveInfo mskill);
	void healHP(Player *player, int16_t hp);
	void showSkillEffect(Player *player, int32_t skillid, unsigned char level = 0);
	void showSpecialSkill(Player *player, SpecialSkillInfo info); // Hurricane/Pierce/Big Bang/Monster Magnet
	void endSpecialSkill(Player *player, SpecialSkillInfo info);
	void showMagnetSuccess(Player *player, int32_t mapmobid, unsigned char success); // New packet in .56
	void sendCooldown(Player *player, int32_t skillid, int16_t time);
	void showBerserk(Player *player, unsigned char level, bool on);
};

#endif
