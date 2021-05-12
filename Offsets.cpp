#include "decryption.h"
 
/*
	Generated 11/05/2021 21:35:49 by baba08000
	Game version 1.36.6.9114006
*/
 
namespace offsets
{
	constexpr auto camera_base = 0x146F4700;
	constexpr auto camera_pos = 0x1D8;
	constexpr auto game_mode = 0x17099C08;
	constexpr auto local_index = 0x6B240;
	constexpr auto name_array = 0x17422678;
	constexpr auto name_array_padding = 0x4C70;
	constexpr auto ref_def = 0x17417598;
	constexpr auto weapon_definition = 0x147C2260;
 
	namespace bones
	{
		constexpr auto bone_base = 0xF45C;
		constexpr auto distribute = 0xA37D9B0;
		constexpr auto size = 0x150;
		constexpr auto visible = 0x5954D50;
	}
 
	namespace directx
	{
		constexpr auto command_queue = 0x18E52C28;
		constexpr auto swap_chain = 0x18E57FA0;
	}
 
	namespace other
	{
		constexpr auto recoil = 0x4688C;
	}
 
	namespace player
	{
		constexpr auto dead_1 = 0x10;
		constexpr auto dead_2 = 0x34;
		constexpr auto pos_info = 0x26D8;
		constexpr auto size = 0x3A88;
		constexpr auto stance = 0x2C84;
		constexpr auto team_id = 0x262C;
		constexpr auto valid = 0x26D4;
		constexpr auto weapon_index = 0x3708;
	}
 
}
 
namespace decryption
{
	auto get_client_info() -> uint64_t
	{
		uint64_t RAX = 0, RBX = 0, RCX = 0, RDX = 0, R8 = 0, RDI = 0, R9 = 0, R10 = 0, R11 = 0, R12 = 0, R13 = 0, R14 = 0, RSI = 0, RSP = 0, RBP = 0;
		RBX = *(uint64_t*)(global::module_base + 0x17414C08);
		if (!RBX)
			return 0;
 
		R8 = global::module_base;
		RCX = global::peb;
		RCX = (~RCX);
		// test rbx,rbx
		// je short 000000000205FC31h
		RAX = global::module_base;
		RDX = global::module_base + 0xE9D;
		RAX -= RDX;
		RCX += RBX;
		RAX = 0; // Special case
		RCX += R8;
		RAX = _rotl64(RAX, 0x10);
		RDX = 0xD0FDC0E5AC56A3F1;
		RAX ^= *(uint64_t*)(global::module_base + 0x68FE0DC);
		RCX *= RDX;
		RAX = _byteswap_uint64(RAX);
		RDX = 0x7C09AF42D8BF321D;
		RCX += RDX;
		if (utils::is_bad_ptr((void*)(RAX + 0x17))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x17);
		RAX *= RCX;
		RBX = RAX;
		RBX >>= 0x27;
		RBX ^= RAX;
		RBX += R8;
		return RBX;
	}
 
	auto get_client_info_base(uint64_t client_info) -> uint64_t
	{
		uint64_t RAX = global::module_base, RBX = global::module_base, RCX = global::module_base, RDX = global::module_base, R8 = global::module_base, RDI = global::module_base, R9 = global::module_base, R10 = global::module_base, R11 = global::module_base, R12 = global::module_base, R13 = global::module_base, R14 = global::module_base, R15 = global::module_base, RSI = global::module_base, RSP = global::module_base, RBP = global::module_base;
		RAX = *(uint64_t*)(client_info + 0x9DC08);
		if (!RAX)
			return 0;
		RDI = global::peb;
		// test rax,rax
		// je near ptr 00000000020648E4h
		RCX = RDI;
		RCX >>= 0x17;
		// and ecx,0Fh
		RCX &= 0xF;
		switch (RCX)
		{
		case 0:
		{
			R9 = *(uint64_t*)(global::module_base + 0x68FE117);
			RSI = global::module_base + 0x6AC;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x11);
			RCX = global::module_base;
			RAX += RCX;
			RCX = 0x5CD525BAF45D4153;
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
			RCX = 0x3E9F9DBB6E66EB1A;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX -= RCX;
			RAX += 0xFFFFFFFF856D9D0D;
			RAX += RDI;
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
			RCX = RAX;
			RCX >>= 0xE;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x38;
			RAX ^= RCX;
			return RAX;
		}
		case 1:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE117);
			RSI = global::module_base + 0x6AC;
			R15 = global::module_base + 0x64C85167;
			RDX = RDI;
			RDX = (~RDX);
			RCX = global::module_base + 0x4224;
			RCX = (~RCX);
			RDX *= RCX;
			RCX = 0xACCE08093FB3EFFD;
			RAX ^= RDX;
			RAX *= RCX;
			RCX = 0x5FB21A878C77BA33;
			RAX += RCX;
			RCX = R15;
			RCX = (~RCX);
			RCX += RDI;
			RAX ^= RCX;
			RCX = 0x22C2431C8FB82D9B;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x1C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x38;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x14;
			RAX ^= RCX;
			RCX = RAX;
			// mov rdx,[rbp+0E8h]
			RDX -= RSI;
			RCX >>= 0x28;
			RDX = 0; // Special case
			RCX ^= RAX;
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x11);
			RAX *= RCX;
			return RAX;
		}
		case 2:
		{
			RBX = *(uint64_t*)(global::module_base + 0x68FE117);
			RSI = global::module_base + 0x6AC;
			RCX = 0xD6D9DEEDA5248D76;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x11;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x22;
			RAX ^= RCX;
			R8 = RDI;
			R8 = (~R8);
			// mov r9,[rbp+0E8h]
			R9 -= RSI;
			R9 = 0; // Special case
			R9 = _rotl64(R9, 0x10);
			RCX = global::module_base + 0x2EC9;
			R9 ^= RBX;
			RDX = 0xDDE2E61B691384A0;
			RDX += RAX;
			RCX = (~RCX);
			RDX ^= R8;
			RAX = global::module_base + 0x20F5092D;
			RAX ^= RDX;
			RAX += R8;
			RCX += RAX;
			R9 = _byteswap_uint64(R9);
			if (utils::is_bad_ptr((void*)(R9 + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(R9 + 0x11);
			RAX *= RCX;
			RAX ^= RDI;
			RCX = 0x565E27B475312525;
			RAX *= RCX;
			return RAX;
		}
		case 3:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE117);
			RSI = global::module_base + 0x6AC;
			R11 = global::module_base + 0x7D269E03;
			RCX = 0xB179BC20C4853E9B;
			RAX *= RCX;
			RCX = global::module_base;
			RAX -= RCX;
			RCX = 0x4A9F7DDA7B6600D7;
			RAX -= RCX;
			RCX = RAX;
			RCX >>= 0x22;
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
			// mov rdx,[rbp+0E8h]
			RCX = 0x67EE65DA588AACB0;
			RCX += RAX;
			RDX -= RSI;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x11);
			RAX *= RCX;
			RCX = RDI;
			RCX ^= R11;
			RAX -= RCX;
			return RAX;
		}
		case 4:
		{
			RSI = global::module_base + 0x6AC;
			R11 = global::module_base + 0x379408E5;
			R9 = *(uint64_t*)(global::module_base + 0x68FE117);
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x11);
			RSP = 0x62E007A4AB5B56AB;
			RCX *= RSP;
			RAX *= RCX;
			RCX = RDI;
			RCX = (~RCX);
			RCX ^= R11;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x15;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2A;
			RAX ^= RCX;
			RAX ^= RDI;
			RCX = 0xC1E61306CF319D97;
			RAX *= RCX;
			RCX = 0xF6A67E73491A1EFB;
			RCX -= global::module_base;
			RAX += RCX;
			return RAX;
		}
		case 5:
		{
			RSI = global::module_base + 0x6AC;
			R10 = *(uint64_t*)(global::module_base + 0x68FE117);
			RCX = global::module_base;
			RAX = RAX + RCX * 0x2;
			RAX ^= RCX;
			RCX = 0x76E88693C2A89DC9;
			RAX *= RCX;
			RCX = global::module_base;
			RAX ^= RCX;
			// mov rdx,[rbp+0E8h]
			RDX -= RSI;
			RDX = 0; // Special case
			RCX = RDI + RAX;
			RDX = _rotl64(RDX, 0x10);
			RAX = global::module_base + 0x2D9B;
			RCX += RAX;
			RDX ^= R10;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x11);
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x26;
			RAX ^= RCX;
			return RAX;
		}
		case 6:
		{
			RSI = global::module_base + 0x6AC;
			R15 = global::module_base + 0x25792B82;
			R10 = *(uint64_t*)(global::module_base + 0x68FE117);
			RCX = global::module_base;
			RDX = RCX + 0x44E66251;
			RCX += RAX;
			RDX += RDI;
			RDX ^= RCX;
			RCX = RDX;
			RAX = RDX;
			RCX >>= 0xE;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1C;
			RAX ^= RCX;
			RDX = global::module_base + 0x3ED51D49;
			RCX = RAX;
			RCX >>= 0x38;
			RAX ^= RCX;
			RCX = RDI;
			RCX ^= RDX;
			RAX -= RCX;
			RCX = RDI;
			RCX *= R15;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX += RCX;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x11);
			RCX = 0xD821E1F8F10CC0E5;
			RAX *= RCX;
			return RAX;
		}
		case 7:
		{
			RSI = global::module_base + 0x6AC;
			R9 = *(uint64_t*)(global::module_base + 0x68FE117);
			RCX = global::module_base;
			RAX += RCX;
			RCX = 0xCDD63885C351FBB5;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x28;
			RAX ^= RCX;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x11);
			RBP = 0xD86054F77497C21F;
			RCX *= RBP;
			RAX *= RCX;
			RCX = 0xE9FBCF5BFD0D9235;
			RAX *= RCX;
			RCX = global::module_base + 0x2B58;
			RCX -= RDI;
			RAX += RCX;
			RAX += RDI;
			return RAX;
		}
		case 8:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE117);
			RSI = global::module_base + 0x6AC;
			R15 = global::module_base + 0x261CDD99;
			RBX = global::module_base + 0x6877DAE4;
			RCX = 0x74F032451C0F3AAB;
			RAX += RCX;
			RCX = 0x91AAF2F4B147480D;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x28;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xD;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1A;
			RAX ^= RCX;
			RDX = RAX;
			RDX >>= 0x34;
			RDX ^= RAX;
			RAX = RDI;
			RAX ^= RBX;
			RCX = 0xAE4F1D68CD4FA409;
			RAX += RDX;
			RAX *= RCX;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x11);
			RCX = R15;
			RCX = (~RCX);
			RCX += RDI;
			RAX ^= RCX;
			return RAX;
		}
		case 9:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE117);
			RSI = global::module_base + 0x6AC;
			R15 = global::module_base + 0x19301967;
			RCX = 0xA03A5CAEA4279C49;
			RAX *= RCX;
			RCX = 0x71C02514CF8A9DA8;
			RAX += RCX;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x11);
			RCX = 0x9EDB961AC1CA708C;
			RAX ^= RCX;
			RAX += R15;
			RDX = RDI;
			RDX = (~RDX);
			RAX += RDX;
			RCX = RAX;
			RCX >>= 0x10;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX ^= RCX;
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
			return RAX;
		}
		case 10:
		{
			RSI = global::module_base + 0x6AC;
			RBX = global::module_base + 0x1A015076;
			R9 = *(uint64_t*)(global::module_base + 0x68FE117);
			RCX = RAX;
			RCX >>= 0x1C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x38;
			RAX ^= RCX;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x11);
			RCX = RAX;
			RCX >>= 0x15;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2A;
			RAX ^= RCX;
			RCX = RDI;
			RCX ^= RBX;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0xC;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x18;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x30;
			RAX ^= RCX;
			RCX = 0x11B19D41A5FE8AE1;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x26;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX ^= RCX;
			return RAX;
		}
		case 11:
		{
			RSI = global::module_base + 0x6AC;
			R15 = global::module_base + 0x78378FCB;
			RBX = global::module_base + 0x7998;
			R9 = *(uint64_t*)(global::module_base + 0x68FE117);
			RCX = global::module_base;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x1F;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3E;
			RAX ^= RCX;
			RCX = 0x41CF04660260443;
			RAX += RCX;
			RCX = 0x740D13B79DE35AE6;
			RAX += RCX;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x11);
			RAX *= RCX;
			RAX ^= RDI;
			RAX ^= RBX;
			RCX = 0x7712A4C8F3E6DF2D;
			RAX *= RCX;
			RCX = RDI;
			RCX = (~RCX);
			RAX += RCX;
			RAX += R15;
			return RAX;
		}
		case 12:
		{
			RSI = global::module_base + 0x6AC;
			R9 = *(uint64_t*)(global::module_base + 0x68FE117);
			RAX -= RDI;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x11);
			RSP = 0xDCBB02268230C67;
			RCX *= RSP;
			RAX *= RCX;
			RCX = RDI + RDI;
			RCX -= global::module_base;
			RCX += 0xFFFFFFFFFFFF5629;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x12;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x24;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xD;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1A;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x34;
			RAX ^= RCX;
			RAX += RDI;
			return RAX;
		}
		case 13:
		{
			RSI = global::module_base + 0x6AC;
			R15 = global::module_base + 0x22DB7F31;
			R10 = *(uint64_t*)(global::module_base + 0x68FE117);
			RDX = RAX;
			RDX >>= 0x21;
			RDX ^= RAX;
			RAX = RDI;
			RAX = (~RAX);
			RAX *= R15;
			RAX += RDX;
			RAX += RDI;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x11);
			RAX *= RCX;
			RCX = 0x8DDCF2B3E1571114;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX -= RCX;
			RCX = 0x6010B0A9C3D8407D;
			RAX ^= RCX;
			RCX = 0x4B13677AC2BC8B55;
			RAX *= RCX;
			return RAX;
		}
		case 14:
		{
			RSI = global::module_base + 0x6AC;
			RBX = global::module_base + 0x7B82;
			R10 = *(uint64_t*)(global::module_base + 0x68FE117);
			RCX = RAX;
			RCX >>= 0xD;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1A;
			RAX ^= RCX;
			// mov rdx,[rbp+0E8h]
			RDX -= RSI;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RCX = RAX;
			RDX ^= R10;
			RCX >>= 0x34;
			RCX ^= RAX;
			RAX = global::module_base;
			RDX = _byteswap_uint64(RDX);
			RCX ^= RAX;
			if (utils::is_bad_ptr((void*)(RDX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x11);
			RAX *= RCX;
			RCX = 0x294BF04F8056DBA0;
			RAX += RCX;
			RCX = RDI;
			RCX ^= RBX;
			RAX -= RCX;
			RAX += RDI;
			RCX = global::module_base + 0x22D3C70A;
			RAX += RCX;
			RCX = 0xF4E5078B5230FB51;
			RAX *= RCX;
			RCX = 0x5B401C942FFFFB4D;
			RAX += RCX;
			return RAX;
		}
		case 15:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE117);
			RSI = global::module_base + 0x6AC;
			RAX -= RDI;
			RCX = 0x867F13D085A61055;
			RAX *= RCX;
			// mov rcx,[rbp+0E8h]
			RCX -= RSI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x11))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x11);
			RSP = 0x341894F65D84D9E7;
			RCX *= RSP;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x1A;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x34;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX -= RCX;
			RCX = 0x5AB80474995D546;
			RAX += RCX;
			RAX += RDI;
			RCX = global::module_base;
			RAX += RCX;
			return RAX;
		}
		default:
			return 0;
		}
	}
 
	auto get_bone() -> uint64_t
	{
		uint64_t RAX = global::module_base, RBX = global::module_base, RCX = global::module_base, RDX = global::module_base, R8 = global::module_base, RDI = global::module_base, R9 = global::module_base, R10 = global::module_base, R11 = global::module_base, R12 = global::module_base, R13 = global::module_base, R14 = global::module_base, R15 = global::module_base, RSI = global::module_base, RSP = global::module_base, RBP = global::module_base;
		R8 = *(uint64_t*)(global::module_base + 0x157C2128);
		if (!R8)
			return 0;
		RBX = global::peb;
		// test r8,r8
		// je near ptr 00000000021ABF19h
		RAX = RBX;
		RAX = _rotr64(RAX, 0x19);
		// and eax,0Fh
		RAX &= 0xF;
		switch (RAX)
		{
		case 0:
		{
			RDI = global::module_base + 0x587;
			R11 = global::module_base + 0x48269EDE;
			R9 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RAX = R11;
			RAX = (~RAX);
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
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
			RAX = R8;
			RAX >>= 0x17;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x2E;
			R8 ^= RAX;
			RAX = 0xED7410F992E48EB4;
			R8 ^= RAX;
			RAX = 0xCA1E81C2A154401F;
			R8 *= RAX;
			RAX = 0xF546F8F2621774B8;
			R8 ^= RAX;
			return R8;
		}
		case 1:
		{
			RDI = global::module_base + 0x587;
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RAX = global::module_base;
			R8 -= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
			RAX = RBX;
			RAX = (~RAX);
			RAX -= global::module_base;
			RAX += 0xFFFFFFFF9ED9FE0C;
			R8 += RAX;
			RAX = 0xCA90CB0068439DA1;
			R8 *= RAX;
			RAX = global::module_base;
			R8 -= RAX;
			R8 += 0xFFFFFFFFFFFF087B;
			R8 += RBX;
			RAX = R8;
			RAX >>= 0x12;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x24;
			R8 ^= RAX;
			RAX = RBX;
			RAX = (~RAX);
			RBP = global::module_base + 0xD8CE;
			RAX ^= RBP;
			R8 -= RAX;
			R8 ^= RBX;
			return R8;
		}
		case 2:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RDI = global::module_base + 0x587;
			RAX = 0x957AAF972E96A661;
			R8 *= RAX;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = 0x5D0581BB99708655;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x14;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x28;
			R8 ^= RAX;
			// mov rcx,[rbp+98h]
			RCX -= RDI;
			RCX = 0; // Special case
			RAX = RBX;
			RAX = (~RAX);
			RCX = _rotl64(RCX, 0x10);
			RBP = global::module_base + 0x6359D526;
			RAX += RBP;
			RCX ^= R10;
			RAX ^= R8;
			RCX = (~RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0x19);
			R8 *= RAX;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = 0x4DDB70F59F05E4D;
			R8 *= RAX;
			return R8;
		}
		case 3:
		{
			RDI = global::module_base + 0x587;
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RAX = global::module_base;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x26;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1C;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x38;
			R8 ^= RAX;
			RAX = 0x83389ED83A901B2B;
			R8 *= RAX;
			RAX = 0x365CC06F7F0DE72E;
			R8 -= RAX;
			RAX = global::module_base;
			R8 ^= RAX;
			// mov rcx,[rbp+98h]
			RAX = 0xE0B7F19A32E2AA20;
			RAX += R8;
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = (~RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0x19);
			R8 *= RAX;
			return R8;
		}
		case 4:
		{
			RDI = global::module_base + 0x587;
			R9 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RAX = global::module_base;
			R8 ^= RAX;
			RAX = 0x8AC3EFA9DA0A8D8B;
			R8 *= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
			R8 += RBX;
			RAX = 0xF973860AC466360A;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1B;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x36;
			R8 ^= RAX;
			RAX = global::module_base;
			R8 += RAX;
			RAX = 0x1AC7A93E5D43FE37;
			R8 *= RAX;
			return R8;
		}
		case 5:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RDI = global::module_base + 0x587;
			RAX = 0x653A5498063B8DEC;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
			RAX = RBX;
			RAX = (~RAX);
			RBP = global::module_base + 0x50E3D590;
			RAX ^= RBP;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x1E;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3C;
			R8 ^= RAX;
			RAX = 0xE84C88441CE825B5;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x12;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x24;
			R8 ^= RAX;
			RAX = 0xCDD67953BE2BB4F;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x9;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x12;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x24;
			R8 ^= RAX;
			return R8;
		}
		case 6:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RDI = global::module_base + 0x587;
			RAX = 0x5153ABB8593DDADB;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x21;
			R8 ^= RAX;
			RAX = 0xEDBC195CD9B262AD;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x19);
			R8 *= RAX;
			RAX = 0x3E354FBC80E0F82;
			R8 -= RAX;
			RCX = RBX;
			RAX = global::module_base + 0x14723642;
			RCX ^= RAX;
			RAX = global::module_base;
			R8 += RAX;
			R8 += RCX;
			RAX = RBX;
			RAX = (~RAX);
			RBP = global::module_base + 0xB464;
			RAX ^= RBP;
			R8 -= RAX;
			return R8;
		}
		case 7:
		{
			RDI = global::module_base + 0x587;
			R9 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
			RAX = R8;
			RAX >>= 0xF;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1E;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3C;
			R8 ^= RAX;
			RAX = global::module_base + 0x774B;
			R8 += RBX;
			R8 += RAX;
			RAX = 0x349052E6B405CC69;
			R8 ^= RAX;
			RAX = 0xB94ABC745524D4BF;
			R8 *= RAX;
			RAX = global::module_base;
			R8 ^= RAX;
			R8 ^= RBX;
			RAX = 0x6A26AC931BA2F076;
			R8 -= RAX;
			return R8;
		}
		case 8:
		{
			RDI = global::module_base + 0x587;
			RDX = global::module_base + 0x5CC41DE8;
			R11 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RAX = RBX;
			RBP = global::module_base + 0x347CCC0D;
			RAX *= RBP;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x1A;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x34;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R11;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
			RAX = RBX;
			RBP = global::module_base + 0xD85B;
			RAX ^= RBP;
			R8 += RAX;
			RAX = RDX;
			RAX = (~RAX);
			RAX ^= RBX;
			RAX += RBX;
			R8 += RAX;
			RBP = 0x99E674537B740E3F;
			R8 *= RBP;
			RAX = RBX;
			RBP = global::module_base + 0x12212BBC;
			RAX ^= RBP;
			R8 -= RAX;
			return R8;
		}
		case 9:
		{
			RDI = global::module_base + 0x587;
			R9 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RAX = R8;
			RAX >>= 0xB;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x16;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x2C;
			R8 ^= RAX;
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
			R8 += RBX;
			RAX = R8;
			RAX >>= 0x19;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x32;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
			RAX = R8;
			RAX >>= 0x1F;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3E;
			R8 ^= RAX;
			RAX = 0x38A1EF881F5EE677;
			R8 *= RAX;
			RAX = 0x5BE9C9F250F9B96;
			R8 ^= RAX;
			return R8;
		}
		case 10:
		{
			RDI = global::module_base + 0x587;
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RAX = global::module_base + 0x507A4A5B;
			RAX = (~RAX);
			RAX += RBX;
			R8 += RAX;
			RAX = 0x328F559E57A8C447;
			R8 *= RAX;
			RAX = 0x176756A1C915F2C0;
			R8 += RAX;
			RAX = 0x38412B5A11B1767F;
			R8 ^= RBX;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x19;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x32;
			R8 ^= RAX;
			R8 ^= RBX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
			return R8;
		}
		case 11:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RDI = global::module_base + 0x587;
			RCX = global::module_base + 0x5BBB1F90;
			RAX = R8;
			RAX >>= 0x1B;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x36;
			R8 ^= RAX;
			R8 -= RBX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x19);
			R8 *= RAX;
			RAX = RBX;
			R8 ^= RBX;
			RAX = (~RAX);
			RBP = global::module_base + 0x3F50;
			RAX ^= RBP;
			R8 ^= RCX;
			R8 -= RAX;
			RAX = 0x3F6202625888A061;
			R8 *= RAX;
			R8 ^= RBX;
			return R8;
		}
		case 12:
		{
			RDI = global::module_base + 0x587;
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			R8 ^= RBX;
			RAX = 0x65933DB287FFAA52;
			R8 += RAX;
			R8 += RBX;
			RAX = R8;
			RAX >>= 0x1A;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x34;
			R8 ^= RAX;
			RAX = global::module_base + 0x39E3EC62;
			RAX = (~RAX);
			R8 -= RBX;
			R8 += RAX;
			RAX = 0x20077BDA408A67F3;
			R8 *= RAX;
			RAX = 0xD595C092B1477BB3;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
			return R8;
		}
		case 13:
		{
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RDI = global::module_base + 0x587;
			R11 = global::module_base + 0x11C3272B;
			RAX = 0x27D454B7C2F2C25D;
			R8 *= RAX;
			RAX = RBX;
			RAX *= R11;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x27;
			R8 ^= RAX;
			RCX = RBX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x19);
			RAX *= R8;
			R8 = global::module_base + 0x6E55;
			RCX ^= R8;
			R8 = 0x5DAA4C8200B6165C;
			R8 += RAX;
			R8 += RCX;
			RAX = 0xAABCDD711970C5D5;
			R8 ^= RAX;
			RAX = global::module_base + 0x31437F76;
			R8 += RBX;
			R8 += RAX;
			return R8;
		}
		case 14:
		{
			RDI = global::module_base + 0x587;
			R11 = global::module_base + 0x3FDC3D43;
			R10 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			RAX = global::module_base;
			R8 ^= RAX;
			// mov rcx,[rbp+98h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RAX = RBX;
			RCX = (~RCX);
			RAX *= R11;
			if (utils::is_bad_ptr((void*)(RCX + 0x19))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x19);
			R8 *= RCX;
			R8 ^= RAX;
			R8 += RBX;
			RAX = 0xCE7636A94BBDC685;
			R8 *= RAX;
			RAX = 0x3CE3DF87DAAD6EE0;
			R8 += RAX;
			RAX = R8;
			RAX >>= 0x10;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			return R8;
		}
		case 15:
		{
			RDI = global::module_base + 0x587;
			R13 = global::module_base + 0x3E217CBF;
			R9 = *(uint64_t*)(global::module_base + 0x68FE1ED);
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x19))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x19);
			RAX = global::module_base;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x1B;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x36;
			R8 ^= RAX;
			RAX = RBX;
			RAX ^= R13;
			R8 -= RAX;
			RAX = 0x6307730E3950FD29;
			R8 *= RAX;
			RAX = 0x9922C716FA77D39;
			R8 -= RAX;
			RAX = RBX;
			RBP = global::module_base + 0x230E;
			RAX *= RBP;
			R8 ^= RAX;
			RAX = 0x3F05ADF6A1933CCD;
			R8 -= RAX;
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
		RAX = 0x2618C71D80B03299;
		R11 = global::module_base;
		RAX = _umul128(RAX, RCX, &RDX);
		R10 = 0x505A001505A00151;
		RDX >>= 0xA;
		RAX = RDX * 0x1AE1;
		RCX -= RAX;
		RAX = 0x8FEA21322F416A6D;
		R8 = RCX * 0x1AE1;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = R8;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0xD;
		RAX = RAX * 0x28F8;
		R8 -= RAX;
		RAX = 0x8618618618618619;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = R8;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0x4;
		RCX = RAX * 0x15;
		RAX = 0x91CC2C6C3588F85;
		RAX = _umul128(RAX, R8, &RDX);
		RDX >>= 0x5;
		RCX += RDX;
		RAX = RCX * 0x706;
		RCX = R8 * 0x708;
		RCX -= RAX;
		RAX = *(uint16_t*)(RCX + R11 + 0x6908250);
		R8 = RAX * 0x13C8;
		RAX = R10;
		RAX = _umul128(RAX, R8, &RDX);
		RCX = R8;
		RAX = R10;
		RCX -= RDX;
		RCX >>= 0x1;
		RCX += RDX;
		RCX >>= 0xC;
		RCX = RCX * 0x185B;
		R8 -= RCX;
		R9 = R8 * 0x20A5;
		RAX = _umul128(RAX, R9, &RDX);
		RAX = R9;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0xC;
		RAX = RAX * 0x185B;
		R9 -= RAX;
		RAX = 0x4E5E0A72F0539783;
		RAX = _umul128(RAX, R9, &RDX);
		RAX = R9;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0x6;
		RCX = RAX * 0x62;
		RAX = 0xCD85689039B0AD13;
		RAX = _umul128(RAX, R9, &RDX);
		RAX = R9;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0x6;
		RCX += RAX;
		RAX = RCX * 0x8E;
		RCX = R9 + R9 * 0x8;
		RCX <<= 0x4;
		RCX -= RAX;
		RSI = *(uint16_t*)(RCX + R11 + 0x69115D0);
		return RSI;
	}
 
}
