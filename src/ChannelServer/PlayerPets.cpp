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
#include "Pets.h"
#include "MySQLM.h"
#include "PlayerPets.h"

void PlayerPets::addPet(Pet *pet) {
	playerpets[pet->getId()] = pet;

	if (pet->getIndex() != -1) {
		setSummoned(pet->getId(), pet->getIndex());
	}
}

Pet * PlayerPets::getPet(int32_t petid) {
	return playerpets.find(petid) != playerpets.end() ? playerpets[petid] : 0;
}

void PlayerPets::setSummoned(int32_t petid, char index) {
	summoned[index] = petid;
}

int32_t PlayerPets::getSummoned(char index) {
	return summoned[index] > 0 ? summoned[index] : 0;
}

void PlayerPets::save() {
	mysqlpp::Query query = Database::getCharDB().query();
	for (unordered_map<int32_t, Pet *>::iterator iter = playerpets.begin(); iter != playerpets.end(); iter++) {
		query << "UPDATE pets SET "
			<< "`index` = " << mysqlpp::quote << (int16_t) iter->second->getIndex() << ","
			<< "name = " << mysqlpp::quote << iter->second->getName() << ","
			<< "level = " << mysqlpp::quote << (int16_t) iter->second->getLevel() << ","
			<< "closeness = " << mysqlpp::quote << iter->second->getCloseness() << ","
			<< "fullness = " << mysqlpp::quote << (int16_t) iter->second->getFullness()
			<< " WHERE id = " << mysqlpp::quote << iter->second->getId();
		query.exec();
	}
}
