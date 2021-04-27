#include "decryption.h"
 
/*
	Generated 27/04/2021 22:02:08
	Game version 1.36.2.9024516
*/
 
namespace offsets
{
	constexpr auto camera_base = 0x14106700;
	constexpr auto camera_pos = 0x1D8;
	constexpr auto game_mode = 0x16AABC08;
	constexpr auto local_index = 0x5748;
	constexpr auto name_array = 0x16E34578;
	constexpr auto name_array_padding = 0x4C70;
	constexpr auto ref_def = 0x16E29498;
	constexpr auto weapon_definition = 0x141D4260;
 
	namespace bones
	{
		constexpr auto bone_base = 0x22EC;
		constexpr auto distribute = 0x9D8FA00;
		constexpr auto size = 0x150;
		constexpr auto visible = 0x5363AB0;
	}
 
	namespace directx
	{
		constexpr auto command_queue = 0x18864C28;
		constexpr auto swap_chain = 0x18869FA0;
	}
 
	namespace other
	{
		constexpr auto recoil = 0x864B4;
	}
 
	namespace player
	{
		constexpr auto dead_1 = 0x3A0C;
		constexpr auto dead_2 = 0x6B0;
		constexpr auto pos_info = 0x20;
		constexpr auto size = 0x3A50;
		constexpr auto stance = 0x914;
		constexpr auto team_id = 0x644;
		constexpr auto valid = 0x770;
		constexpr auto weapon_index = 0x1310;
	}
 
}
 
namespace decryption
{
	auto get_client_info() -> uint64_t
	{
		uint64_t RAX = 0, RBX = 0, RCX = 0, RDX = 0, R8 = 0, RDI = 0, R9 = 0, R10 = 0, R11 = 0, R12 = 0, R13 = 0, R14 = 0, RSI = 0, RSP = 0, RBP = 0;
		RBX = *(uint64_t*)(global::module_base + 0x16E26B08);
		if (!RBX)
			return 0;
 
		RDX = global::peb;
		RDX = (~RDX);
		// test rbx,rbx
		// je short 0000000001A02E08h
		// mov rcx,[rbp+0D8h]
		RAX = global::module_base + 0x8FF;
		RCX -= RAX;
		R8 = 0xA780C0337FBF4B71;
		RBX *= R8;
		RCX = 0; // Special case
		RAX = global::module_base + 0x34E461A2;
		RAX = (~RAX);
		RCX = _rotl64(RCX, 0x10);
		RCX ^= *(uint64_t*)(global::module_base + 0x630C0EE);
		RAX *= RDX;
		RCX = (~RCX);
		RAX ^= RBX;
		RBX = global::module_base + 0xF4CB;
		RBX = (~RBX);
		RBX += RDX;
		if (utils::is_bad_ptr((void*)(RCX + 0x15))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x15);
		RCX *= RAX;
		RAX = RCX;
		RAX >>= 0x1F;
		RCX ^= RAX;
		RAX = RCX;
		RAX >>= 0x3E;
		RBX ^= RAX;
		RAX = 0x333FEADE56B4F4B7;
		RBX ^= RCX;
		RBX -= RAX;
		return RBX;
	}
 
	auto get_client_info_base(uint64_t client_info) -> uint64_t
	{
		uint64_t RAX = global::module_base, RBX = global::module_base, RCX = global::module_base, RDX = global::module_base, R8 = global::module_base, RDI = global::module_base, R9 = global::module_base, R10 = global::module_base, R11 = global::module_base, R12 = global::module_base, R13 = global::module_base, R14 = global::module_base, R15 = global::module_base, RSI = global::module_base, RSP = global::module_base, RBP = global::module_base;
		RAX = *(uint64_t*)(client_info + 0x9DBA8);
		if (!RAX)
			return 0;
		RBX = global::peb;
		// test rax,rax
		// je near ptr 0000000001A080E1h
		RCX = RBX;
		RCX = _rotl64(RCX, 0x27);
		// and ecx,0Fh
		RCX &= 0xF;
		switch (RCX)
		{
		case 0:
		{
			RDI = global::module_base + 0xD55;
			R9 = *(uint64_t*)(global::module_base + 0x630C137);
			RCX = global::module_base + 0x29946B0F;
			RCX = (~RCX);
			RCX += RBX;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x16;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x38;
			RAX ^= RCX;
			// mov rcx,[rbp+0D8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x9);
			RAX *= RCX;
			RCX = 0xB2DBFA9D557FF695;
			RAX ^= RCX;
			RCX = 0x51BE1F1F657D0857;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x4;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x8;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x10;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = 0x235CE195A7526153;
			RAX ^= RCX;
			return RAX;
		}
		case 1:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			RCX = R11 + 0xB640;
			RCX += RBX;
			RAX += RCX;
			RCX = 0x34479E473C0C6463;
			RAX -= RCX;
			RCX = RAX;
			RCX >>= 0x3;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x6;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xC;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x18;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x30;
			RAX ^= RCX;
			RCX = 0x9151C6D1E7695D4B;
			RAX *= RCX;
			// mov rcx,[rbp+0D8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x9);
			RCX = RAX;
			RCX >>= 0xF;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1E;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = 0x2108702042F432C8;
			RAX ^= RCX;
			return RAX;
		}
		case 2:
		{
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RCX = RAX;
			RCX >>= 0x15;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2A;
			RAX ^= RCX;
			RCX = 0x304B041E8A9186FF;
			RAX *= RCX;
			RAX ^= RBX;
			RCX = 0xD16196D3AC8FF3EF;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x16;
			RAX ^= RCX;
			RDX = RAX;
			RDX >>= 0x2C;
			RDX ^= RAX;
			RAX = RBX;
			RAX = (~RAX);
			RAX += RDX;
			RAX -= R11;
			RAX -= 0xEFD3;
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RCX = global::module_base + 0x1F7B4152;
			RCX = (~RCX);
			RCX++;
			RCX += RAX;
			RDX = _byteswap_uint64(RDX);
			RCX += RBX;
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x9);
			RAX *= RCX;
			return RAX;
		}
		case 3:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			RAX -= R11;
			RAX += RBX;
			RCX = 0xCC4FB62C055EDFA7;
			RAX *= RCX;
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RCX = RAX + R11;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x9);
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x7;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xE;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x38;
			RAX ^= RCX;
			RCX = 0x1B63E4964B2B042B;
			RAX ^= RCX;
			RCX = RBX;
			RCX = (~RCX);
			RAX += RCX;
			RCX = global::module_base + 0x34EE;
			RAX += RCX;
			return RAX;
		}
		case 4:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RDI = global::module_base + 0xD55;
			R14 = global::module_base + 0x1383EAB7;
			R15 = global::module_base + 0x6872A4F6;
			RCX = RAX;
			RCX >>= 0x14;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x28;
			RAX ^= RCX;
			RCX = 0x4F6620132952C33F;
			RAX ^= RCX;
			RAX ^= RBX;
			RDX = RBX;
			RDX = (~RDX);
			RCX = RAX;
			RAX = 0x72BCDF61F2FA0529;
			RAX *= RCX;
			RDX *= R14;
			RAX += RDX;
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RCX = RBX;
			RDX = _rotl64(RDX, 0x10);
			RCX ^= R15;
			RDX ^= R10;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RDX = *(uint64_t*)(RDX + 0x9);
			RAX *= RDX;
			RAX -= RCX;
			RCX = 0xD5CE0E362DD829BD;
			RAX *= RCX;
			return RAX;
		}
		case 5:
		{
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			R9 = *(uint64_t*)(global::module_base + 0x630C137);
			RAX += R11;
			RCX = RAX;
			RCX >>= 0x4;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x8;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x10;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = 0x2832AB91DEAE07F5;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x1E;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3C;
			RAX ^= RCX;
			// mov rcx,[rbp+0D8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x9);
			RCX = 0xA0E6520EC18C3E4B;
			RAX *= RCX;
			RCX = 0x1F2820D5D7967B35;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x16;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2C;
			RAX ^= RCX;
			return RAX;
		}
		case 6:
		{
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			RDX = global::module_base + 0xCEEF;
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RCX = 0x6E66A4467F07BE17;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x16;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x4;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x8;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x10;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = RDX;
			RCX = (~RCX);
			RCX ^= RBX;
			RAX -= RCX;
			RCX = 0xE387B9AFA7515070;
			RAX ^= RCX;
			// mov rcx,[rbp+0D8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x9);
			RAX *= RCX;
			RAX -= R11;
			RAX += RBX;
			return RAX;
		}
		case 7:
		{
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RAX -= R11;
			RAX ^= RBX;
			RAX ^= R11;
			RCX = RAX;
			RCX >>= 0x6;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xC;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x18;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x30;
			RAX ^= RCX;
			RAX -= RBX;
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RCX = RAX;
			RDX = _byteswap_uint64(RDX);
			RCX ^= R11;
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x9);
			RAX *= RCX;
			RCX = 0xF40B34B7ADBC1B17;
			RAX *= RCX;
			return RAX;
		}
		case 8:
		{
			RDI = global::module_base + 0xD55;
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RCX = RAX;
			RCX >>= 0x5;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xA;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x14;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x28;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xB;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x16;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2C;
			RAX ^= RCX;
			RCX = global::module_base + 0x62856E71;
			RCX = (~RCX);
			RCX -= RBX;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x5;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xA;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x14;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x28;
			RAX ^= RCX;
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RCX = RAX;
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RAX = 0x9CDA8E7E239479A8;
			RCX ^= RAX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x9);
			RAX *= RCX;
			RCX = 0xD65A11C14E032EC3;
			RAX *= RCX;
			return RAX;
		}
		case 9:
		{
			RDI = global::module_base + 0xD55;
			R15 = global::module_base + 0x6A585F51;
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			// mov rcx,[rbp+0D8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x9);
			RAX *= RCX;
			RCX = 0xB3A3A7120450E98E;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x4;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x8;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x10;
			RAX ^= RCX;
			RDX = RAX;
			RDX >>= 0x20;
			RCX = R15;
			RAX ^= RDX;
			RCX = (~RCX);
			RCX ^= RBX;
			RAX -= RCX;
			RCX = 0x27DC1D9CA610D47B;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x14;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x28;
			RAX ^= RCX;
			RAX ^= RBX;
			RCX = 0x4697E4A3AAEA7A4D;
			RAX += RCX;
			return RAX;
		}
		case 10:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			RCX = 0x33E7DC6E4C664B7E;
			RAX -= RCX;
			RCX = global::module_base + 0x4DFA;
			RCX = (~RCX);
			RCX ^= RBX;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x8;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x10;
			RAX ^= RCX;
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RCX = RAX;
			RDX ^= R10;
			RCX >>= 0x20;
			RCX ^= RAX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x9);
			RAX *= RCX;
			RDX = global::module_base + 0x9814;
			RAX ^= R11;
			RCX = RBX;
			RCX ^= RDX;
			RAX += RCX;
			RCX = 0x2089D20A3F5782EB;
			RAX *= RCX;
			RCX = 0xFFFFFFFF93B46D7C;
			RCX -= RBX;
			RCX -= R11;
			RAX += RCX;
			return RAX;
		}
		case 11:
		{
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RCX = 0x17B5F720083C793E;
			RDX = 0; // Special case
			RCX += RAX;
			RDX = _rotl64(RDX, 0x10);
			RAX = 0x2F04E2D6339DD9F0;
			RDX ^= R10;
			RCX ^= RAX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x9);
			RAX *= RCX;
			RCX = 0x353291FDD0AB3C41;
			RAX *= RCX;
			RAX ^= R11;
			RAX -= R11;
			RAX ^= RBX;
			RCX = RAX;
			RCX >>= 0x9;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x12;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x24;
			RAX ^= RCX;
			return RAX;
		}
		case 12:
		{
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			R9 = *(uint64_t*)(global::module_base + 0x630C137);
			// mov rcx,[rbp+0D8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x9);
			RCX = 0x6B3EB95206C97305;
			RAX *= RCX;
			RCX = 0xCC5310CF8CE673F5;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x21;
			RAX ^= RCX;
			RAX ^= RBX;
			RCX = 0xB69BD2957FB2A8AF;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x6;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xC;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x18;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x30;
			RAX ^= RCX;
			RAX += R11;
			return RAX;
		}
		case 13:
		{
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			RDX = global::module_base + 0x1D040C7D;
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RAX ^= RBX;
			RCX = RBX;
			RCX *= RDX;
			RAX ^= RCX;
			RAX -= RBX;
			RAX ^= R11;
			RCX = RAX;
			RCX >>= 0x9;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x12;
			RAX ^= RCX;
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RCX = RAX;
			RDX = _rotl64(RDX, 0x10);
			RCX >>= 0x24;
			RDX ^= R10;
			RCX ^= RAX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x9);
			RAX *= RCX;
			RCX = 0x1EE7DFA9154EA3A7;
			RAX *= RCX;
			RAX -= RBX;
			return RAX;
		}
		case 14:
		{
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RCX = RAX;
			RCX >>= 0x1D;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3A;
			RAX ^= RCX;
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RCX = R11 + 0x7111;
			RCX += RBX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RDX = *(uint64_t*)(RDX + 0x9);
			RAX *= RDX;
			RAX ^= RCX;
			RCX = 0xB8F0246E12ADCE49;
			RAX *= RCX;
			RCX = 0x7B161C06ECA147BF;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x1E;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3C;
			RAX ^= RCX;
			RCX = 0x3BF141D150A4F3BA;
			RAX -= RCX;
			RCX = 0xFFFFFFFFFFFF552C;
			RCX -= RBX;
			RCX -= R11;
			RAX += RCX;
			return RAX;
		}
		case 15:
		{
			RDI = global::module_base + 0xD55;
			R11 = global::module_base;
			R10 = *(uint64_t*)(global::module_base + 0x630C137);
			RCX = global::module_base + 0x53CD45F7;
			RCX = (~RCX);
			RCX += RBX;
			RAX ^= RCX;
			RAX += RBX;
			RCX = 0x519083637DB886FB;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0xF;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1E;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3C;
			RAX ^= RCX;
			RAX ^= R11;
			// mov rdx,[rbp+0D8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RCX = 0x13757197FDD883C0;
			RDX = _byteswap_uint64(RDX);
			RCX += RAX;
			if (utils::is_bad_ptr((void*)(RDX + 0x9))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x9);
			RAX *= RCX;
			RCX = 0x1F8BAAF13EA2024A;
			RAX -= RCX;
			return RAX;
		}
		default:
			return 0;
		}
	}
 
	auto get_bone() -> uint64_t
	{
		uint64_t RAX = global::module_base, RBX = global::module_base, RCX = global::module_base, RDX = global::module_base, R8 = global::module_base, RDI = global::module_base, R9 = global::module_base, R10 = global::module_base, R11 = global::module_base, R12 = global::module_base, R13 = global::module_base, R14 = global::module_base, R15 = global::module_base, RSI = global::module_base, RSP = global::module_base, RBP = global::module_base;
		R8 = *(uint64_t*)(global::module_base + 0x151D4128);
		if (!R8)
			return 0;
		RBX = global::peb;
		// test r8,r8
		// je near ptr 0000000001B56308h
		RAX = RBX;
		RAX <<= 0x1B;
		RAX = _byteswap_uint64(RAX);
		// and eax,0Fh
		RAX &= 0xF;
		switch (RAX)
		{
		case 0:
		{
			RDI = global::module_base + 0x351;
			R9 = *(uint64_t*)(global::module_base + 0x630C20D);
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0xF);
			RAX = R8;
			RAX >>= 0x26;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1E;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3C;
			R8 ^= RAX;
			RAX = 0xC2457C1269807078;
			R8 ^= RAX;
			RAX = 0x7862B42AE56EE8BA;
			R8 ^= RAX;
			RAX = 0x1D20BAEEF3B20BEB;
			R8 *= RAX;
			RAX = global::module_base;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x6;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0xC;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x18;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x30;
			R8 ^= RAX;
			return R8;
		}
		case 1:
		{
			RDI = global::module_base + 0x351;
			R11 = global::module_base + 0x9CAD;
			RCX = *(uint64_t*)(global::module_base + 0x630C20D);
			RAX = 0xC7A6CF51910A1A6D;
			R8 *= RAX;
			RAX = 0x91F00B852B85E8B4;
			RAX += R8;
			R8 = RAX + RBX * 0x2;
			RAX = R8;
			RAX >>= 0x17;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x2E;
			R8 ^= RAX;
			RAX = 0x5846414CC20D807B;
			R8 ^= RAX;
			RAX = RBX;
			RAX *= R11;
			R8 += RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RCX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0xF);
			return R8;
		}
		case 2:
		{
			R11 = *(uint64_t*)(global::module_base + 0x630C20D);
			RDI = global::module_base + 0x351;
			RAX = global::module_base + 0xBAE0;
			RAX = (~RAX);
			RAX += RBX;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x14;
			R8 ^= RAX;
			RDX = R8;
			RAX = 0xB45F8ACCAE45ADDF;
			// mov rcx,[rbp+98h]
			RCX -= RDI;
			RDX >>= 0x28;
			RDX ^= R8;
			RCX = 0; // Special case
			RDX *= RAX;
			RCX = _rotl64(RCX, 0x10);
			RAX = RDX;
			RCX ^= R11;
			RAX >>= 0x16;
			RCX = (~RCX);
			RDX ^= RAX;
			RAX = RDX;
			if (utils::is_bad_ptr((void*)(RCX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0xF);
			RAX >>= 0x2C;
			RAX ^= RDX;
			R8 *= RAX;
			RDX = global::module_base + 0x1899CFD5;
			RAX = RDX;
			RAX = (~RAX);
			RAX += RBX;
			R8 ^= RAX;
			RAX = 0x5658F69EC880208C;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x7;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0xE;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1C;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x38;
			R8 ^= RAX;
			return R8;
		}
		case 3:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			RDI = global::module_base + 0x351;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0xF);
			R8 *= RAX;
			RAX = global::module_base + 0x69012403;
			R8 += RBX;
			R8 += RAX;
			RAX = R8;
			RAX >>= 0x1A;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x34;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x2;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x4;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x8;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x10;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			RAX = 0xA847BAEE66D3CF9;
			R8 *= RAX;
			RCX = RBX;
			RAX = global::module_base + 0x10937881;
			RCX *= RAX;
			RAX = R8;
			R8 = 0xB14E3B2108D79D5E;
			R8 ^= RAX;
			R8 += RCX;
			RAX = 0x596CA791BF8A9741;
			R8 *= RAX;
			return R8;
		}
		case 4:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			RDI = global::module_base + 0x351;
			RCX = global::module_base + 0x1C69;
			RAX = global::module_base;
			R8 += RAX;
			RAX = global::module_base;
			RAX += 0x3F48A962;
			RAX += RBX;
			R8 += RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0xF);
			RAX = 0x8C54DB2BE00B8075;
			R8 ^= RAX;
			RAX = 0x8AF6FBBB1F521D51;
			R8 *= RAX;
			R8 ^= RCX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			return R8;
		}
		case 5:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			RDI = global::module_base + 0x351;
			R8 += RBX;
			R8 += RBX;
			RAX = global::module_base + 0x1EE276B5;
			R8 += RAX;
			RAX = 0xB5D50A3BDCF019B4;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1C;
			R8 ^= RAX;
			// mov rcx,[rbp+98h]
			RAX = R8;
			RAX >>= 0x38;
			RCX -= RDI;
			RAX ^= R8;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = (~RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0xF);
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x23;
			R8 ^= RAX;
			RAX = 0x47FBFD1C41FA23DB;
			R8 *= RAX;
			RAX = 0x1981088A78BC9A5C;
			R8 ^= RAX;
			return R8;
		}
		case 6:
		{
			RDI = global::module_base + 0x351;
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0xF);
			RAX = R8;
			RAX >>= 0x2;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x4;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x8;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x10;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			RAX = 0x7F0720F476B9D451;
			R8 *= RAX;
			RAX = global::module_base;
			R8 += RAX;
			RAX = global::module_base + 0x10FA;
			RAX = (~RAX);
			RAX += RBX;
			R8 ^= RAX;
			RAX = 0xE55732EF4F99E783;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0xF;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1E;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3C;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x17;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x2E;
			R8 ^= RAX;
			return R8;
		}
		case 7:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			RDI = global::module_base + 0x351;
			// mov rcx,[rbp+98h]
			RAX = R8;
			RAX >>= 0x1F;
			RCX -= RDI;
			R8 ^= RAX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = (~RCX);
			RAX = R8;
			RAX >>= 0x3E;
			RAX ^= R8;
			if (utils::is_bad_ptr((void*)(RCX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0xF);
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x17;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x2E;
			R8 ^= RAX;
			RAX = 0x5C5B65954F48BD01;
			R8 *= RAX;
			RAX = 0x4A3392E5D264B28B;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x19;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x32;
			R8 ^= RAX;
			RAX = global::module_base + 0xC12D;
			RAX = (~RAX);
			RAX *= RBX;
			R8 += RAX;
			RAX = 0x7AC8A55D02831EE3;
			R8 *= RAX;
			return R8;
		}
		case 8:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			RDI = global::module_base + 0x351;
			RAX = 0xD75389DAE9057A59;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x19;
			R8 ^= RAX;
			RAX = R8;
			// mov rcx,[rbp+98h]
			RCX -= RDI;
			RAX >>= 0x32;
			RCX = 0; // Special case
			RAX ^= R8;
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = (~RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0xF);
			R8 *= RAX;
			RAX = global::module_base;
			R8 ^= RAX;
			R8 += RBX;
			RAX = 0xB78EEE9C9478F4F4;
			R8 ^= RAX;
			R8 += RBX;
			RAX = global::module_base + 0x245D36BE;
			RAX = (~RAX);
			RAX += R8;
			R8 = RBX + 0x1;
			R8 += RAX;
			return R8;
		}
		case 9:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			RDI = global::module_base + 0x351;
			R11 = global::module_base + 0x37B6;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0xF);
			R8 ^= RBX;
			RAX = 0x6D5E85C25A05F45D;
			R8 *= RAX;
			RAX = R11;
			RAX = (~RAX);
			RAX ^= RBX;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x17;
			R8 ^= RAX;
			RCX = R8;
			RCX >>= 0x2E;
			RCX ^= R8;
			R8 = global::module_base + 0x3F72;
			R8 = (~R8);
			R8 ^= RBX;
			R8 += RCX;
			RAX = R8;
			RAX >>= 0x14;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x28;
			R8 ^= RAX;
			RAX = 0xFD247B1999A9A4AB;
			R8 *= RAX;
			return R8;
		}
		case 10:
		{
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			RDI = global::module_base + 0x351;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = 0x894274C036B0AB33;
			R8 *= RAX;
			RCX = RBX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0xF);
			RAX *= R8;
			R8 = global::module_base + 0x532D;
			RCX ^= R8;
			R8 = 0xB992690AC04C0B29;
			R8 += RAX;
			RAX = 0x66C1C6B8F03B535F;
			R8 += RCX;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x10;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0xC;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x18;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x30;
			R8 ^= RAX;
			return R8;
		}
		case 11:
		{
			RDI = global::module_base + 0x351;
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			RAX = R8;
			RAX >>= 0xD;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1A;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x34;
			R8 ^= RAX;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = 0x5ABF231307F1150B;
			R8 += RBX;
			R8 *= RAX;
			// mov rcx,[rbp+98h]
			RCX -= RDI;
			RAX = 0x94D6FA4A0CEF5B1E;
			RCX = 0; // Special case
			RAX += R8;
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = (~RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0xF);
			R8 *= RAX;
			RAX = RBX;
			RBP = global::module_base + 0x7880AF26;
			RAX *= RBP;
			R8 ^= RAX;
			return R8;
		}
		case 12:
		{
			RDI = global::module_base + 0x351;
			R10 = *(uint64_t*)(global::module_base + 0x630C20D);
			RAX = RBX;
			RSP = global::module_base + 0x4CBA;
			RAX *= RSP;
			R8 ^= RAX;
			R8 ^= RBX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0xF);
			RAX = 0xF8EC73C70C09B981;
			R8 *= RAX;
			RAX = global::module_base + 0xF86D;
			RAX -= RBX;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x23;
			R8 ^= RAX;
			RAX = 0x5335BBEAFA19ACF7;
			R8 ^= RAX;
			RAX = 0xBB94D92420914993;
			R8 *= RAX;
			return R8;
		}
		case 13:
		{
			RDI = global::module_base + 0x351;
			R9 = *(uint64_t*)(global::module_base + 0x630C20D);
			RAX = R8;
			RAX >>= 0x8;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x10;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0xE;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1C;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x38;
			R8 ^= RAX;
			R8 ^= RBX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0xF);
			R8 *= RAX;
			RAX = 0x840A60DB2E3F0D7;
			R8 *= RAX;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = 0x811CFA22FAAF7A4D;
			R8 *= RAX;
			return R8;
		}
		case 14:
		{
			RDI = global::module_base + 0x351;
			R9 = *(uint64_t*)(global::module_base + 0x630C20D);
			RAX = R8;
			RAX >>= 0x5;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0xA;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x14;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x28;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1E;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3C;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0xF);
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			RAX = 0xB9A169A75EDD2C33;
			R8 *= RAX;
			RAX = 0x8979226E69FF9F39;
			R8 ^= RAX;
			RAX = global::module_base;
			R8 -= RAX;
			R8 += 0xFFFFFFFFE85FA2E2;
			R8 += RBX;
			RAX = 0x74C1BE144DF01AE6;
			R8 ^= RAX;
			return R8;
		}
		case 15:
		{
			RDI = global::module_base + 0x351;
			R9 = *(uint64_t*)(global::module_base + 0x630C20D);
			RAX = R8;
			RAX >>= 0x4;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x8;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x10;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x8;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x10;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			R8 -= RBX;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = 0xE6B6130EA1F06FFF;
			R8 *= RAX;
			RAX = 0x712433D6EBFA44A0;
			R8 += RAX;
			RAX = 0x27A7BA9ACAC5ED93;
			R8 *= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0xF))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0xF);
			RAX = 0x18101EAAF8D9D40C;
			R8 += RAX;
			return R8;
		}
		default:
			return 0;
		}
	}
 
	auto get_bone_index(uint32_t index) -> uint64_t
	{
		uint64_t RAX = 0, RBX = 0, RCX = 0, RDX = 0, R8 = 0, RDI = 0, R9 = 0, R10 = 0, R11 = 0, R12 = 0, R13 = 0, R14 = 0, RSI = 0, RSP = 0, RBP = 0;
		RBX = index;
		RCX = RBX * 0x13C8;
		RAX = 0xE322F699C59B92FB;
		R11 = global::module_base;
		RAX = _umul128(RAX, RCX, &RDX);
		R10 = 0xF3C514BD9CABC1FD;
		RDX >>= 0xD;
		RAX = RDX * 0x2411;
		RCX -= RAX;
		RAX = 0x109666FC52B8A461;
		R8 = RCX * 0x2411;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = R8;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0xD;
		RAX = RAX * 0x3C1B;
		R8 -= RAX;
		RAX = 0x670B453B92840671;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = 0x47AE147AE147AE15;
		RDX >>= 0x6;
		RCX = RDX * 0x9F;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = R8;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0x6;
		RCX += RAX;
		RAX = RCX * 0xC8;
		RCX = R8 * 0xCA;
		RCX -= RAX;
		RAX = *(uint16_t*)(RCX + R11 + 0x63189F0);
		R8 = RAX * 0x13C8;
		RAX = R10;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = R10;
		RDX >>= 0xD;
		RCX = RDX * 0x219B;
		R8 -= RCX;
		R9 = R8 * 0x2538;
		RAX = _umul128(RAX, R9, &RDX);
		RDX >>= 0xD;
		RAX = RDX * 0x219B;
		R9 -= RAX;
		RAX = 0x35DCE5F9F2AF821F;
		RAX = _umul128(RAX, R9, &RDX);
		RAX = R9;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0x8;
		RCX = RAX * 0x1A7;
		RAX = 0x842108421084211;
		RAX = _umul128(RAX, R9, &RDX);
		RAX = R9;
		R9 <<= 0x6;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0x4;
		RCX += RAX;
		RAX = RCX * 0x3E;
		R9 -= RAX;
		RSI = *(uint16_t*)(R9 + R11 + 0x6320630);
		return RSI;
	}
}
