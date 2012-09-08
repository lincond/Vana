--[[
Copyright (C) 2008-2012 Vana Development Team

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
--]]

function beginInstance()
	addInstanceMap(240050400);
	players = getAllMapPlayerIds(240050400);
	for i = 1, #players do
		addInstancePlayer(players[i]);
	end
	setInstanceMax(30);
end

function changeMap(playerId, newMap, oldMap, isPartyLeader)
	b = isInstanceMap(newMap);

	if not b then
		removeInstancePlayer(playerId);
	elseif b then
		addInstancePlayer(playerId);
	end
end

function instanceTimerEnd(fromtTimer) end
function playerDeath(playerId) end
function playerDisconnect(playerId, isPartyLeader) end
function timerEnd(name, fromtTimer) end
function mobDeath(mobId, mapMobId, mapId) end
function mobSpawn(mobId, mapMobId, mapId) end
function friendlyHit(mobId, mapMobId, mapId, hp, maxHp) end
function partyDisband(partyId) end
function partyRemoveMember(partyId, playerId) end