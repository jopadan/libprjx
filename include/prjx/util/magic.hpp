#pragma once

#include <prjx/math/scalar.hpp>

#define EXTERNALFORCES_VERSION_NUMBER 2
#define        RESTART_VERSION_NUMBER 1
#define       LOADSAVE_VERSION_NUMBER 5
#define           GOAL_VERSION_NUMBER 1
#define     BSP_PORTAL_VERSION_NUMBER 1
#define      TELEPORTS_VERSION_NUMBER 2

namespace prjx
{
	static const enum class version
	{
		NONE              = 000,
		REMASTERED        = 200,
		N64               = 110,
		PSX               = 120,
		PSP               = 130,
		FULL_RETAIL_PATCH = 102,
		GATEWAY           = 101,
		FULL_RETAIL       = 100,
	};
	static const std::vector<const std::string> fingerprint = "Full Retail Patch Version (" MARKET_NAME ") 8 July 1998";
}
namespace prjx::file
{
	static const u32 magic = 0x584A5250; // MAGIC_NUMBER 
	struct bgo
	{
		static const version = 3; // BGO_VERSION_NUMBER
	};
	struct msg
	{
		static const version = 1; // MSG_VERSION_NUMBER
	};
	struct cam
	{
		static const version = 1; // CAM_VERSION_NUMBER
	};
	struct mxv
	{
		static const version = 3; // MXV_VERSION_NUMBER
	};
	struct mx
	{
		static const version = 2; // MX_VERSION_NUMBER
	};
	struct cob
	{
		static const version = 2; // COB_VERSION_NUMBER
	};
	struct nme
	{
		static const version = 3; // NME_VERSION_NUMBER
	};
	struct nod
	{
		static const version = 1; // NOD_VERSION_NUMBER
	};
	struct zon
	{
		static const version = 2; // ZON_VERSION_NUMBER
	};
	struct pic
	{
		static const version = 1; // PIC_VERSION_NUMBER
	};
	struct wat
	{
		static const version = 1; // WAT_VERSION_NUMBER
	};
	struct bsp
	{
		static const version = 1; // BSP_VERSION_NUMBER
	};
	struct trg
	{
		static const version = 1; // TRG_VERSION_NUMBER
	};
	struct fx
	{
		static const version = 4; // FX_VERSION_NUMBER
	};
	struct mxa
	{
		static const version = 2; // MXA_VERSION_NUMBER
	};
	struct mc
	{
		static const version = 1; // MC_VERSION_NUMBER
	};
	/* Real-Time Lights (.RTL) file format */
	struct rtl
	{
		static const version = 2; // RTL_VERSION_NUMBER
		struct header
		{
			union magic
			{
				c8<4> string;
				u32   number;
			};
			u32 version;
			u16 rt_lights;
		};
	};
};

