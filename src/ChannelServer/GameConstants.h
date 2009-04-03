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
#ifndef GAMECONSTANTS_H
#define GAMECONSTANTS_H

#include "Types.h"

// Enumerations
enum WeaponTypes {
	WEAPON_1H_SWORD = 130,
	WEAPON_1H_AXE = 131,
	WEAPON_1H_MACE = 132,
	WEAPON_DAGGER = 133,
	WEAPON_WAND = 137,
	WEAPON_STAFF = 138,
	WEAPON_2H_SWORD = 140,
	WEAPON_2H_AXE = 141,
	WEAPON_2H_MACE = 142,
	WEAPON_SPEAR = 143,
	WEAPON_POLEARM = 144,
	WEAPON_BOW = 145,
	WEAPON_CROSSBOW = 146,
	WEAPON_CLAW = 147,
	WEAPON_KNUCKLE = 148,
	WEAPON_GUN = 149
};

enum ItemFlags {
	FLAG_LOCK = 0x01,
	FLAG_SPIKES = 0x02,
	FLAG_COLD = 0x04
};

enum Act {
	ACT_HEAL,
	ACT_HURT
};

enum SkillValues {
	SKILL_X,
	SKILL_Y,
	SKILL_SPEED,
	SKILL_JUMP,
	SKILL_WATK,
	SKILL_WDEF,
	SKILL_MATK,
	SKILL_MDEF,
	SKILL_ACC,
	SKILL_AVO,
	SKILL_PROP,
	SKILL_MORPH,
	SKILL_LV
};

enum ByteTypes {
	TYPE_5,
	TYPE_6,
	TYPE_7,
	TYPE_8,
	TYPE_1,
	TYPE_2,
	TYPE_3,
	TYPE_4
};

enum MobStatus {
	WATK = 0x1,
	WDEF = 0x2,
	MATK = 0x4,
	MDEF = 0x8,
	ACC = 0x10,
	AVOID = 0x20,
	SPEED = 0x40,
	STUN = 0x80,
	FREEZE = 0x100,
	POISON = 0x200,
	SEAL = 0x400,
	WEAPON_ATTACK_UP = 0x1000,
	WEAPON_DEFENSE_UP = 0x2000,
	MAGIC_ATTACK_UP = 0x4000,
	MAGIC_DEFENSE_UP = 0x8000,
	DOOM = 0x10000,
	SHADOW_WEB = 0x20000,
	WEAPON_IMMUNITY = 0x40000,
	MAGIC_IMMUNITY = 0x80000
};

// Skills so there are fewer magic numbers
namespace Beginner {
	enum {
		ECHOOFHERO = 1005,
		FOLLOWTHELEAD = 8,
		MONSTERRIDER = 1004,
		NIMBLEFEET = 1002,
		RECOVERY = 1001
	};
};

namespace Swordsman {
	enum {
		IMPROVEDMAXHPINCREASE = 1000001,
		IRONBODY = 1000003,
	};
};

namespace Fighter {
	enum {
		AXEBOOSTER = 1101005,
		AXEMASTERY = 1100001,
		POWERGUARD = 1101007,
		RAGE = 1101006,
		SWORDBOOSTER = 1101004,
		SWORDMASTERY = 1100000
	};
};

namespace Crusader {
	enum {
		ARMORCRASH = 1111007,
		AXECOMA = 1111006,
		AXEPANIC = 1111004,
		COMBOATTACK = 1111002,
		SHOUT = 1111008,
		SWORDCOMA = 1111005,
		SWORDPANIC = 1111003
	};
};

namespace Hero {
	enum {
		ACHILLES = 1120004,
		ADVANCEDCOMBOATTACK = 1120003,
		ENRAGE = 1121010,
		GUARDIAN = 1120005,
		HEROSWILL = 1121011,
		MAPLEWARRIOR = 1121000,
		MONSTERMAGNET = 1121001,
		POWERSTANCE = 1121002
	};
};

namespace Page {
	enum {
		BWBOOSTER = 1201005,
		BWMASTERY = 1200001,
		POWERGUARD = 1201007,
		SWORDBOOSTER = 1201004,
		SWORDMASTERY = 1200000,
		THREATEN = 1201006
	};
};

namespace WhiteKnight {
	enum {
		BWFIRECHARGE = 1211004,
		BWICECHARGE = 1211006,
		BWLITCHARGE = 1211008,
		CHARGEBLOW = 1211002,
		MAGICCRASH = 1211009,
		SWORDFIRECHARGE = 1211003,
		SWORDICECHARGE = 1211005,
		SWORDLITCHARGE = 1211007
	};
};

namespace Paladin {
	enum {
		ACHILLES = 1220005,
		ADVANCEDCHARGE = 1220010,
		BWHOLYCHARGE = 1221004,
		GUARDIAN = 1220006,
		HEAVENSHAMMER = 1221011,
		HEROSWILL = 1221012,
		MAPLEWARRIOR = 1221000,
		MONSTERMAGNET = 1221001,
		POWERSTANCE = 1221002,
		SWORDHOLYCHARGE = 1221003
	};
};

namespace Spearman {
	enum {
		HYPERBODY = 1301007,
		IRONWILL = 1301006,
		POLEARMBOOSTER = 1301005,
		POLEARMMASTERY = 1300001,
		SPEARBOOSTER = 1301004,
		SPEARMASTERY = 1300000
	};
};

namespace DragonKnight {
	enum {
		DRAGONBLOOD = 1311008,
		DRAGONROAR = 1311006,
		POWERCRASH = 1311007,
		SACRIFICE = 1311005
	};
};

namespace DarkKnight {
	enum {
		ACHILLES = 1320005,
		AURAOFBEHOLDER = 1320008,
		BEHOLDER = 1321007,
		BERSERK = 1320006,
		HEROSWILL = 1321010,
		HEXOFBEHOLDER = 1320009,
		MAPLEWARRIOR = 1321000,
		MONSTERMAGNET = 1321001,
		POWERSTANCE = 1321002
	};
};

namespace Magician {
	enum {
		IMPROVEDMAXMPINCREASE = 2000001,
		MAGICARMOR = 2001003,
		MAGICGUARD = 2001002
	};
};

namespace FPWizard {
	enum {
		MEDITATION = 2101001,
		MPEATER = 2100000,
		POISONBREATH = 2101005,
		SLOW = 2101003
	};
};

namespace FPMage {
	enum {
		ELEMENTAMPLIFICATION = 2110001,
		ELEMENTCOMPOSITION = 2111006,
		POISONMIST = 2111003,
		SEAL = 2111004,
		SPELLBOOSTER = 2111005
	};
};

namespace FPArchMage {
	enum {
		BIGBANG = 2121001,
		ELQUINES = 2121005,
		FIREDEMON = 2121003,
		HEROSWILL = 2121008,
		INFINITY = 2121004,
		MANAREFLECTION = 2121002,
		MAPLEWARRIOR = 2121000,
		PARALYZE = 2121006
	};
};

namespace ILWizard {
	enum {
		COLDBEAM = 2201004,
		MEDITATION = 2201001,
		MPEATER = 2200000,
		SLOW = 2201003
	};
};

namespace ILMage {
	enum {
		ELEMENTAMPLIFICATION = 2210001,
		ELEMENTCOMPOSITION = 2211006,
		ICESTRIKE = 2211002,
		SEAL = 2211004,
		SPELLBOOSTER = 2211005
	};
};

namespace ILArchMage {
	enum {
		BIGBANG = 22210001,
		BLIZZARD = 2221007,
		HEROSWILL = 2221008,
		ICEDEMON = 2221003,
		IFRIT = 2221005,
		INFINITY = 2221004,
		MANAREFLECTION = 2221002,
		MAPLEWARRIOR = 2221000
	};
};

namespace Cleric {
	enum {
		BLESS = 2301004,
		HEAL = 2301002,
		INVINCIBLE = 2301003,
		MPEATER = 2300000
	};
};

namespace Priest {
	enum {
		DISPEL = 2311001,
		DOOM = 2311005,
		HOLYSYMBOL = 2311003,
		MYSTICDOOR = 2311002,
		SUMMONDRAGON = 2311006
	};
};

namespace Bishop {
	enum {
		BAHAMUT = 2321003,
		BIGBANG = 2321001,
		HEROSWILL = 2321009,
		HOLYSHIELD = 2321005,
		INFINITY = 2321004,
		MANAREFLECTION = 2321002,
		MAPLEWARRIOR = 2321000,
		RESURRECTION = 2321006
	};
};

namespace Archer {
	enum {
		CRITICALSHOT = 3000001,
		FOCUS = 3001003
	};
};

namespace Hunter {
	enum {
		ARROWBOMB = 3101005,
		BOWBOOSTER = 3101002,
		BOWMASTERY = 3100000,
		SOULARROW = 3101004
	};
};

namespace Ranger {
	enum {
		MORTALBLOW = 3110001,
		PUPPET = 3111002,
		SILVERHAWK = 3111005
	};
};

namespace Bowmaster {
	enum {
		CONCENTRATE = 3121008,
		HAMSTRING = 3121007,
		HEROSWILL = 3121009,
		HURRICANE = 3121004,
		MAPLEWARRIOR = 3121000,
		PHOENIX = 3121006,
		SHARPEYES = 3121002
	};
};

namespace Crossbowman {
	enum {
		CROSSBOWBOOSTER = 3201002,
		CROSSBOWMASTERY = 3200000,
		SOULARROW = 3201004
	};
};

namespace Sniper {
	enum {
		BLIZZARD = 3211003,
		GOLDENEAGLE = 3211005,
		MORTALBLOW = 3210001,
		PUPPET = 3211002
	};
};

namespace Marksman {
	enum {
		BLIND = 3221006,
		FROSTPREY = 3221005,
		HEROSWILL = 3221008,
		MAPLEWARRIOR = 3221000,
		PIERCINGARROW = 3221001,
		SHARPEYES = 3221002,
		SNIPE = 3221007
	};
};

namespace Rogue {
	enum {
		DARKSIGHT = 4001003,
		DISORDER = 4001002
	};
};

namespace Assassin {
	enum {
		CLAWBOOSTER = 4101003,
		CLAWMASTERY = 4100000,
		CRITICALTHROW = 4100001,
		DRAIN = 4101005,
		HASTE = 4101004
	};
};

namespace Hermit {
	enum {
		ALCHEMIST = 4110000,
		MESOUP = 4111001,
		SHADOWMESO = 4111004,
		SHADOWPARTER = 4111002,
		SHADOWWEB = 4111003
	};
};

namespace NightLord {
	enum {
		HEROSWILL = 4121009,
		MAPLEWARRIOR = 4121000,
		NINJAAMBUSH = 4121004,
		NINJASTORM = 4121008,
		SHADOWCLAW = 4121006,
		SHADOWSHIFTER = 4120002,
		TAUNT = 4121003,
		VENOMOUSSTAR = 4120005,
	};
};

namespace Bandit {
	enum {
		DAGGERBOOSTER = 4201002,
		DAGGERMASTERY = 4200000,
		HASTE = 4201003,
		STEAL = 4201004
	};
};

namespace ChiefBandit {
	enum {
		ASSAULTER = 4211002,
		CHAKRA = 4211001,
		MESOEXPLOSION = 4211006,
		MESOGUARD = 4211005,
		PICKPOCKET = 4211003
	};
};

namespace Shadower {
	enum {
		BOOMERANGSTEP = 4221007,
		HEROSWILL = 4221008,
		MAPLEWARRIOR = 4221000,
		NINJAAMBUSH = 4221004,
		SHADOWSHIFTER = 4220002,
		SMOKESCREEN = 4221006,
		TAUNT = 4221003,
		VENOMOUSSTAB = 4220005
	};
};

namespace Pirate {
	enum {
		DASH = 5001005
	};
};

namespace Infighter {
	enum {
		BACKSPINBLOW = 5101002,
		CORKSCREWBLOW = 5101004,
		DOUBLEUPPERCUT = 5101003,
		IMPROVEMAXHP = 5100000,
		KNUCKLERBOOSTER = 5101006,
		KNUCKLERMASTERY = 5100001,
		MPRECOVERY = 5101005,
		OAKBARREL = 5101007
	};
};

namespace Marauder {
	enum {
		ENERGYCHARGE = 5110001,
		STUNMASTERY = 5110000,
		TRANSFORMATION = 5111005
	};
};

namespace Buccaneer {
	enum {
		DEMOLITION = 5121004,
		MAPLEWARRIOR = 5121000,
		PIRATESRAGE = 5121008, // Hero's Will
		SNATCH = 5121005,
		SPEEDINFUSION = 5121009,
		SUPERTRANSFORMATION = 5121003,
		TIMELEAP = 5121010
	};
};

namespace Gunslinger {
	enum {
		BLANKSHOT = 5201004,
		GRENADE = 5201002,
		GUNBOOSTER = 5201003,
		GUNMASTERY = 5200000
	};
};

namespace Outlaw {
	enum {
		FLAMETHROWER = 5211004,
		GAVIOTA = 5211002,
		HOMINGBEACON = 5211006,
		ICESPLITTER = 5211005,
		OCTOPUS = 5211001
	};
};

namespace Corsair {
	enum {
		AERIALSTRIKE = 5221003,
		BATTLESHIP = 5221006,
		BULLSEYE = 5220011,
		ELEMENTALBOOST = 5220001,
		HYPNOTIZE = 5221009,
		MAPLEWARRIOR = 5221000,
		RAPIDFIRE = 5221004,
		SPEEDINFUSION = 5221010 // Technically Hero's Will
	};
};

namespace GM {
	enum {
		HASTE = 9001000,
		SUPERDRAGONROAR = 9001001,
		TELEPORT = 9001002,
	};
};

namespace SuperGM {
	enum {
		HEALPLUSDISPEL = 9101000,
		HASTE = 9101001,
		HOLYSYMBOL = 9101002,
		BLESS = 9101003,
		HIDE = 9101004,
		RESURRECTION = 9101005,
		SUPERDRAGONROAR = 9101006,
		TELEPORT = 9101007,
		HYPERBODY = 9101008
	};
};

namespace GMSuit {
	enum {
		HAT = 1002140,
		TOP = 1042003,
		BOTTOM = 1062007,
		WEAPON = 1322013
	};
};

namespace HelperFunctions {
	inline uint8_t getInventory(int32_t itemid) { return static_cast<uint8_t>(itemid / 1000000); }
	inline int32_t getItemType(int32_t itemid) { return (itemid / 10000); }
	inline bool isArrow(int32_t itemid) { return (getItemType(itemid) == 206); }
	inline bool isStar(int32_t itemid) { return (getItemType(itemid) == 207); }
	inline bool isBullet(int32_t itemid) { return (getItemType(itemid) == 233); }
	inline bool isRechargeable(int32_t itemid) { return (isBullet(itemid) || isStar(itemid)); }
	inline bool isEquip(int32_t itemid) { return (getInventory(itemid) == 1); }
	inline bool isPet(int32_t itemid) { return (itemid >= 5000000 && itemid <= 5000053); }
	inline bool isOverall(int32_t itemid) { return (getItemType(itemid) == 105); }
	inline bool is2hWeapon(int32_t itemid) { return (getItemType(itemid) / 10 == 14); }

	inline bool isBeginnerSkill(int32_t skillid) { return (skillid / 1000000 == 0); }
	inline bool isFourthJobSkill(int32_t skillid) { return ((skillid / 10000) % 10 == 2); }
	inline bool isSummon(int32_t skillid) { return (skillid == Sniper::PUPPET  || skillid == Ranger::PUPPET || skillid == Priest::SUMMONDRAGON || skillid == Ranger::SILVERHAWK || skillid == Sniper::GOLDENEAGLE || skillid == DarkKnight::BEHOLDER || skillid == FPArchMage::ELQUINES || skillid == ILArchMage::IFRIT || skillid == Bishop::BAHAMUT || skillid == Bowmaster::PHOENIX || skillid == Marksman::FROSTPREY || skillid == Outlaw::OCTOPUS || skillid == Outlaw::GAVIOTA); }
	inline bool isPuppet(int32_t skillid) { return (skillid == Sniper::PUPPET || skillid == Ranger::PUPPET); }
};

#endif