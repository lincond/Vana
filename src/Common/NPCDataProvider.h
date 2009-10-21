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
#ifndef NPCDATAPROVIDER_H
#define NPCDATAPROVIDER_H

#include "Types.h"
#include <boost/tr1/unordered_map.hpp>

using std::tr1::unordered_map;

struct NpcData {
	NpcData() : isMapleTv(false) { }
	int32_t storageCost;
	bool isMapleTv;
};

class NpcDataProvider : boost::noncopyable {
public:
	static NpcDataProvider * Instance() {
		if (singleton == 0)
			singleton = new NpcDataProvider();
		return singleton;
	}
	void loadData();

	int32_t getStorageCost(int32_t npc) { return m_data[npc].storageCost; }
	bool isMapleTv(int32_t npc) { return m_data[npc].isMapleTv; }
private:
	NpcDataProvider() {}
	static NpcDataProvider *singleton;

	unordered_map<int32_t, NpcData> m_data;
};

#endif
