/* assignGear specific macros */
//Dependencies - ACE3, RHS USAF, 3CB, CUP

class baseMan {// Weaponless baseclass
    displayName = "Unarmed";
    // All randomized.
 	uniform[] = {"CUP_U_B_BAF_dpm_S1_RolledUp"};
   	vest[] = {};
   	backpack[] = {};
   	headgear[] = {};
   	goggles[] = {"CUP_FR_NeckScarf"};
   	hmd[] = {};
    // Leave empty to remove all. "Default" > leave original item.

    // All randomized
    primaryWeapon[] = {};
    scope[] = {};
    bipod[] = {};
    attachment[] = {};
    silencer[] = {};
    // Leave empty to remove all. "Default" for primaryWeapon > leave original weapon.

    // Only *Weapons[] arrays are randomized
    secondaryWeapon[] = {};
    secondaryAttachments[] = {};
    sidearmWeapon[] = {};
    sidearmAttachments[] = {};
    // Leave empty to remove all. "Default" for secondaryWeapon or sidearmWeapon > leave original weapon.

    // These are added to the uniform or vest
    magazines[] = {};
    items[] = {};
    // These are added directly into their respective slots
    linkedItems[] = {
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
		"ACE_Flashlight_MX991"
    };

    // These are put into the backpack
    backpackItems[] = {};

    // This is executed after unit init is complete. argument: _this = _unit.
    code = "";

	// These are acre item radios that will be added during the ACRE init. ACRE radios added via any other system will be erased.
	radios[] = {};
};
class r : baseMan
{
    displayName = "Rifleman";
    headgear[] = {"CUP_H_BAF_Helmet_1_dpm"};
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
    backpack[] = {"1T_B_Para_DPM"};
    primaryWeapon[] = {"UK3CB_BAF_L85A2"};
	goggles[] = {"CUP_FR_NeckScarf"};
    scope[] = {"UK3CB_BAF_SUSAT"};
    attachment[] = {};
    magazines[] =
    {
        LIST_11("rhs_mag_30Rnd_556x45_Mk318_Stanag"),
        LIST_2("rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red"),
        LIST_2("HandGrenade"),
        LIST_2("rhs_mag_an_m8hc")
    };
	items[] =
	{
		LIST_3("ACE_fieldDressing"),
		"ACE_morphine"
	};
};
class g : r
{
    displayName = "Grenadier";
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Grenadier"};
    primaryWeapon[] = {"UK3CB_BAF_L85A2_UGL"};
	scope[] = {"UK3CB_BAF_SUSAT"};
    magazines[] +=
    {
        LIST_8("rhs_mag_M441_HE"),
        LIST_4("rhs_mag_m714_White")
    };
};
class car : r
{
    displayName = "Carabinier";
    primaryWeapon[] = {"UK3CB_BAF_L85A2"};
};
class m : car
{
    displayName = "Medic";
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Medic"};
	backpack[] = {"1T_B_Para_DPM"};
	backpackItems[] = {
		LIST_15("ACE_fieldDressing"),
		LIST_10("ACE_morphine"),
		LIST_6("ACE_epinephrine"),
		LIST_2("ACE_bloodIV"),
		LIST_2("rhs_mag_an_m8hc")
	};
};
class smg : r
{
    displayName = "Submachinegunner";
    primaryWeapon[] = {"UK3CB_BAF_L22"};
    magazines[] =
    {
        LIST_6("rhs_mag_30Rnd_556x45_Mk318_Stanag"),
        "HandGrenade",
        LIST_2("rhs_mag_an_m8hc")
    };
};
class ftl : g
{
    displayName = "Fireteam Leader";
    backpack[] = {"1T_B_Para_DPM"};
	magazines[] +=
    {
        LIST_2("rhs_mag_m715_Green"),
		LIST_2("rhs_mag_m713_Red"),
		LIST_2("rhs_mag_m18_green")
    };
    linkedItems[] += {"Rangefinder","ItemGPS"};
};
class sl : ftl
{
    displayName = "Squad Leader";
    sidearmWeapon[] = {"Pstl9x19_FNGP35"};
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Officer"};
	backpack[] = {"1T_B_Para_DPM"};
    magazines[] +=
    {
        LIST_3("13Rnd_9x19_FNGP35")
    };
	items[] += {"ACE_Maptools"};
    linkedItems[] =
    {
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "Rangefinder",
        "ItemGPS"
    };
};
class co : sl
{
    displayName = "Platoon Leader";
	backpack[] = {"1T_B_Para_DPM"};
	magazines[] = {
		LIST_3("13Rnd_9x19_FNGP35"),
		LIST_2("rhs_mag_m715_Green"),
		LIST_3("rhs_mag_m713_Red"),
		LIST_2("rhs_mag_m18_green"),
		LIST_2("SmokeShellPurple"),
		LIST_3("rhs_mag_M441_HE"),
        LIST_2("rhs_mag_m714_White"),
		LIST_7("rhs_mag_30Rnd_556x45_Mk318_Stanag"),
        LIST_2("rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red"),
        "HandGrenade",
        LIST_2("rhs_mag_an_m8hc")
	};
	backpackItems[] = {};
};
class fac : co
{
    displayName = "Forward Air Controller";
	backpack[] = {"1T_B_Para_DPM"};
	radios[] = {"ACRE_PRC117F"};
	    magazines[] +=
    {
        LIST_2("Laserbatteries")
    };
	linkedItems[] = {
		"ItemMap",
		"ItemCompass",
		"ItemWatch",
		"ItemGPS",
		"UK3CB_BAF_Soflam_Laserdesignator"
	};
	items[] = {
		LIST_3("ACE_fieldDressing"),
		"ACE_morphine",
		"ACE_Kestrel4500",
		"ACE_microDAGR",
		"ACE_Maptools"
	};
};
class ar : r
{
	displayName = "Automatic Rifleman";
	primaryWeapon[] = {"rhs_weap_m249_pip_S_para"};
	bipod[] = {};
	magazines[] =
	{
		LIST_2("UK3CB_BAF_200Rnd"),
		LIST_3("UK3CB_BAF_200Rnd_T"),
		"HandGrenade",
		"rhs_mag_an_m8hc"
	};
};
class aar : r
{
    displayName = "Assistant Automatic Rifleman";
    backpackItems[] =
    {
		LIST_2("UK3CB_BAF_200Rnd"),
		LIST_3("UK3CB_BAF_200Rnd_T"),
    };
    linkedItems[] += {"Binocular"};
};
class rat : car
{
    displayName = "Rifleman (AT)";
    secondaryWeapon[] = {"launch_NLAW_F"};
};
class mmgg : ar
{
	displayName = "MMG Gunner";
	primaryWeapon[] = {"UK3CB_BAF_L7A2"};
	backpack[] = {"1T_B_Para_DPM"};
	magazines[] =
	{
		LIST_4("UK3CB_BAF_75Rnd"),
		LIST_2("UK3CB_BAF_75Rnd_T"),
		"HandGrenade",
		"rhs_mag_an_m8hc"
	};
};
class mmgac : r
{
    displayName = "MMG Ammo Carrier";
    vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
	backpackItems[] =
    {
        LIST_3("UK3CB_BAF_75Rnd")
    };
};
class mmgag : aar
{
	displayName = "MMG Assistant Gunner";
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
	backpack[] = {"1T_B_Para_DPM"};
	linkedItems[] =
	{
		"ItemMap",
		"ItemCompass",
		"ItemWatch",
		"Rangefinder",
		"ItemGPS"
	};
	backpackItems[] =
	{
		LIST_3("UK3CB_BAF_75Rnd")
	};
};
class hmgg : car
{
    displayName = "HMG Gunner";
	secondaryWeapon[] = {"UK3CB_BAF_L111A1"};
    backpack[] = {"1T_B_Para_DPM"};
	backpackItems[] =
    {
        LIST_3("UK3CB_BAF_100Rnd_127x99_Box")
    };

};
class hmgac : r
{
    displayName = "HMG Ammo Carrier";
    backpack[] = {"1T_B_Para_DPM"};
	backpackItems[] =
    {
        LIST_3("UK3CB_BAF_100Rnd_127x99_Box")
    };
};
class hmgag : car
{
	displayName = "HMG Assistant Gunner";
	secondaryWeapon[] = {"UK3CB_BAF_Tripod"};
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
    backpack[] = {"1T_B_Para_DPM"};
	backpackItems[] =
    {
        LIST_3("UK3CB_BAF_100Rnd_127x99_Box")
    };
	linkedItems[] =
	{
		"ItemMap",
		"ItemCompass",
		"ItemWatch",
		"Rangefinder",
		"ItemGPS"
	};
};
class matg : car
{
	displayName = "MAT Gunner";
	secondaryWeapon[] = {"UK3CB_BAF_Javelin_Slung_Tube"};
	backpack[] = {"1T_B_Para_DPM"};
	linkedItems[] =
    {
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "UK3CB_BAF_Javelin_CLU"
    };
};
class matac : r
{
	displayName = "MAT Ammo Carrier";
	backpack[] = {"1T_B_Para_DPM"};
	secondaryWeapon[] = {"UK3CB_BAF_Javelin_Slung_Tube"};
};
class matag : car
{
	displayName = "MAT Assistant Gunner";
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
	backpack[] = {"1T_B_Para_DPM"};
	secondaryWeapon[] = {"UK3CB_BAF_Javelin_Slung_Tube"};
	linkedItems[] =
	{
		"ItemMap",
		"ItemCompass",
		"ItemWatch",
		"Rangefinder",
		"ItemGPS"
	};
};
class hatg : car
{
    displayName = "HAT Gunner";
	backPack[] = {"rhs_Tow_Gun_Bag"};
};
class hatac : r
{
	displayName = "HAT Ammo Carrier";
	backPack[] = {"rhs_Tow_Gun_Bag"};
};	
class hatag : car
{
	displayName = "HAT Assistant Gunner";
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
	backPack[] = {"rhs_TOW_Tripod_Bag"};
	linkedItems[] =
	{
		"ItemMap",
		"ItemCompass",
		"ItemWatch",
		"Rangefinder",
		"ItemGPS"
	};
};
class mtrg : car
{
    displayName = "Mortar Gunner";
    secondaryWeapon[] = {"UK3CB_BAF_L16"};
	backpack[] = {"1T_B_Para_DPM"};
	backpackItems[] =
	{
		LIST_2("UK3CB_BAF_1Rnd_81mm_Mo_shells");
	};
    linkedItems[] =
    {
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemGPS"
    };
};
class mtrac : r
{
    displayName = "Mortar Ammo Carrier";
    backpack[] = {"1T_B_Para_DPM"};
	backpackItems[] =
	{
		LIST_2("UK3CB_BAF_1Rnd_81mm_Mo_shells");
	};
	
};
class mtrag : car
{
    displayName = "Mortar Assistant Gunner";
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
    secondaryWeapon[] = {"UK3CB_BAF_L16_Tripod"};
	 backpack[] = {"1T_B_Para_DPM"};
	backpackItems[] =
	{
		LIST_2("UK3CB_BAF_1Rnd_81mm_Mo_shells");
	};
    linkedItems[] =
    {
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "Rangefinder",
        "ItemGPS"
    };
};
class samg : car
{
    displayName = "AA Missile Specialist";
    secondaryWeapon[] = {"rhs_weap_fim92"};
    magazines[] +=
    {
        LIST_3("rhs_fim92_mag")
    };
};
class samag : car
{
    displayName = "AA Assistant Missile Specialist";
    linkedItems[] =
    {
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "Rangefinder",
        "ItemGPS"
    };
    backpackItems[] =
    {
        LIST_2("rhs_fim92_mag")
    };
};
class sn : r
{
    displayName = "Sniper";
    uniform[] = {"CUP_U_B_BAF_dpm_S1_RolledUp"};
    vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Scout"};
    headgear[] = {"CUP_H_BAF_Helmet_1_dpm"};
    goggles[] = {"CUP_FR_NeckScarf"};
    primaryWeapon[] = {"UK3CB_BAF_L115A3_Ghillie"};
    scope[] = {"UK3CB_BAF_SB31250_Ghillie"};
    sidearmWeapon[] = {"Pstl9x19_FNGP35"};
    magazines[] =
    {
        LIST_9("UK3CB_BAF_L115A3_Mag"),
        LIST_2("HandGrenade"),
        LIST_4("13Rnd_9x19_FNGP35")
    };
	backpack[] = {};
	linkedItems[] += {"ACE_Vector","ItemGPS"};
	items[] += {"ACE_Kestrel4500", "ACE_microDAGR"};
};
class sp : sn
{
    displayName = "Spotter";
    primaryWeapon[] = {"UK3CB_BAF_L85A2_UGL"};
	scope[] = {"UK3CB_BAF_SUSAT"};
    magazines[] =
    {
		LIST_7("rhs_mag_30Rnd_556x45_Mk318_Stanag"),
        LIST_2("rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red"),
        LIST_2("HandGrenade"),
        LIST_2("rhs_mag_an_m8hc"),
        LIST_4("rhs_mag_M441_HE"),
        LIST_4("rhs_mag_m714_White"),
		LIST_4("13Rnd_9x19_FNGP35")
    };
};
class vc : smg
{
    displayName = "Vehicle Commander";
    uniform[] = {"CUP_U_B_BAF_dpm_S1_RolledUp"};
    vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
    backpack[] = {"1T_B_Para_DPM"};
	radios[] = {"ACRE_PRC117F"};
    headgear[] = {"CUP_H_BAF_Crew_Helmet_dpm"};
    linkedItems[] += {"Binocular","ItemGPS"};
	magazines[] += {
		LIST_2("rhs_mag_m715_Green")
	};
};
class vd : smg
{
    displayName = "Vehicle Driver";
    uniform[] = {"CUP_U_B_BAF_dpm_S1_RolledUp"};
    vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
    backpack[] = {"1T_B_Para_DPM"};
    headgear[] = {"CUP_H_BAF_Crew_Helmet_dpm"};
    linkedItems[] += {"ItemGPS"};
    backpackItems[] = {"ToolKit"};
};
class vg : vd
{
    displayName = "Vehicle Gunner";
    backpack[] = {};
	backpackItems[] = {};
};
class pp : smg
{
    displayName = "Helicopter Pilot";
    uniform[] = {"CUP_U_B_BAF_dpm_S1_RolledUp"};
    vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Pilot"};
    headgear[] = {"H_PilotHelmetHeli_O"};
    goggles[] = {"default"};
    linkedItems[] += {"ItemGPS"};
	magazines[] += {
		LIST_2("rhs_mag_m715_Green")
	};
	items[] += {"ACE_DAGR"};
};
class pcc : smg
{
    displayName = "Helicopter Crew Chief";
    uniform[] = {"CUP_U_B_BAF_dpm_S1_RolledUp"};
    vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Pilot"};
    headgear[] = {"H_PilotHelmetHeli_O"};
	backpack[] = {"1T_B_Para_DPM"};
    goggles[] = {"default"};
    linkedItems[] += {"ItemGPS"};
    backpackItems[] = {"ToolKit"};
	magazines[] += {
		LIST_2("rhs_mag_m715_Green")
	};
};
class pc : pcc
{
    displayName = "Helicopter Crew";
	backpack[] = {};
    backpackItems[] = {};
};
class jp : baseMan
{
    displayName = "Jet pilot";
    uniform[] = {"U_I_pilotCoveralls"};
    headgear[] = {"MNP_Helmet_Dslyecxi"};
    goggles[] = {"default"};
	sidearmWeapon[] = {"Pstl9x19_FNGP35"};
    magazines[] =
    {
        LIST_4("13Rnd_9x19_FNGP35")
    };
	items[] =
	{
		LIST_3("ACE_fieldDressing"),
		"ACE_morphine"
	};
    linkedItems[] = {"ItemMap","ItemGPS","ItemCompass","ItemWatch"};
};
class eng : car
{
    displayName = "Combat Engineer (Explosives)";
    vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
    magazines[] +=
    {
        LIST_4("ClaymoreDirectionalMine_Remote_Mag")
    };
    backpackItems[] = {
        "MineDetector",
        "ToolKit",
        LIST_2("DemoCharge_Remote_Mag"),
        LIST_2("SLAMDirectionalMine_Wire_Mag")
    };
	items[] += {"ACE_M26_Clacker","ACE_DefusalKit"};
};
class engm : car
{
    displayName = "Combat Engineer (AP Mines)";
    vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
    items[] +=
    {
        LIST_2("APERSBoundingMine_Range_Mag"),
        LIST_2("APERSTripMine_Wire_Mag"),
		"ACE_M26_Clacker",
		"ACE_DefusalKit"
    };
    backpackItems[] = {
        "MineDetector",
        "ToolKit",
        "ATMine_Range_Mag"
    };
};
class UAV : car
{
    displayName = "UAV Operator";
    backpack[] = {"B_rhsusf_B_BACKPACK"};
	vest[] = {"CUP_V_BAF_Osprey_Mk2_dpm_Soldier2","CUP_V_BAF_Osprey_Mk2_dpm_Soldier1"};
    linkedItems[] += {"B_UavTerminal"};
};