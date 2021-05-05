#include "decryption.h"
 
/*
	Generated 05/05/2021 18:27:49 by baba08000
	Game version 1.36.4.9059384
*/
 
namespace offsets
{
	constexpr auto camera_base = 0x14023700;
	constexpr auto camera_pos = 0x1D8;
	constexpr auto game_mode = 0x169C8C08;
	constexpr auto local_index = 0x6F228;
	constexpr auto name_array = 0x16D51578;
	constexpr auto name_array_padding = 0x4C70;
	constexpr auto ref_def = 0x16D46498;
	constexpr auto weapon_definition = 0x140F1260;
 	
	namespace bones
	{
		constexpr auto bone_base = 0x5814C;
		constexpr auto distribute = 0x9CACE10;
		constexpr auto size = 0x150;
		constexpr auto visible = 0x528EA20;
		constexpr auto ENCRYPTED_PTR: Address = 0x1AE147A;
		constexpr auto BASE_POS: Address = 0x5814C;
	}
 
	namespace directx
	{
		constexpr auto command_queue = 0x18781C28;
		constexpr auto swap_chain = 0x18786FA0;
	}
 
	namespace other ans client info
	{
	
		constexpr auto recoil = 0x2980;
		pub const ENCRYPTED_PTR: Address = 0x16D43B08;
	}	
 
	namespace player
	{
		constexpr auto dead_1 = 0xA8;
		constexpr auto dead_2 = 0xBB8;
		constexpr auto pos_info = 0xCF8;
		constexpr auto size = 0x3A60;
		constexpr auto stance = 0xE14;
		constexpr auto team_id = 0x758;
		constexpr auto valid = 0x94;
		constexpr auto weapon_index = 0xB68;
	}
 
}
 
 
namespace decryption
{
	auto get_client_info() -> uint64_t
	{
		uint64_t rax, rcx, r8, r9, rdx = 0;
 
		auto rbx = *(uint64_t*)(global::module_base + 0x16D43B08);
		if (!rbx)
			return 0;
 
		rax = rbx;
		rax >>= 0x1F;
		rbx ^= rax;
		rax = (global::module_base + 0xBE1);
		rdx -= rax;
		rcx = rbx;
		rdx = 0;
		rcx >>= 0x3E;
		rdx <<= 0x10;
		rax = (global::module_base + 0x63CD);
		rdx ^= *(uint64_t*)(global::module_base + 0x622B0D1);
		rax = (~rax);
		rcx ^= rax;
		rdx = (~rdx);
		rcx ^= rbx;
		rax = 0x2099063A22C9CFF1;
		if (utils::is_bad_ptr((void*)(rdx + 0xb)))
			return 0xFFFFFFFFFFFFFFFF;
		rbx = *(uint64_t*)(rdx + 0xb);
		rbx *= rcx;
		rbx *= rax;
		rax = 0x2FD09EB3CD54624E;
		rbx -= rax;
		return rbx;
	}
 
	auto get_client_info_base(uint64_t client_info) -> uint64_t
	{
		uint64_t RAX = global::module_base, RBX = global::module_base, RCX = global::module_base, RDX = global::module_base, R8 = global::module_base, RDI = global::module_base, R9 = global::module_base, R10 = global::module_base, R11 = global::module_base, R12 = global::module_base, R13 = global::module_base, R14 = global::module_base, R15 = global::module_base, RSI = global::module_base, RSP = global::module_base, RBP = global::module_base;
		RAX = *(uint64_t*)(client_info + 0x9DBC8);
		if (!RAX)
			return 0;
		RBX = global::peb;
		RBX = (~RBX);
		// test rax,rax
		// je near ptr 00000000019A266Fh
		RCX = RBX;
		RCX = _rotr64(RCX, 0x16);
		// and ecx,0Fh
		RCX &= 0xF;
		switch (RCX)
		{
		case 0:
		{
			R11 = global::module_base;
			R15 = global::module_base + 0xEBF6;
			RDI = global::module_base + 0x77A;
			R10 = *(uint64_t*)(global::module_base + 0x622B106);
			RAX += RBX;
			RCX = R15;
			RCX = (~RCX);
			RCX += RBX;
			RAX ^= RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x7);
			RAX *= RCX;
			RCX = 0x44945786E31E1462;
			RAX -= RCX;
			RCX = 0x57E0BCA8D84EE02F;
			RAX *= RCX;
			RCX = 0x5A5F9808C67C32C9;
			RAX -= RCX;
			RCX = RAX;
			RCX >>= 0xB;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x16;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2C;
			RAX ^= RCX;
			RAX -= R11;
			return RAX;
		}
		case 1:
		{
			RDI = global::module_base + 0x77A;
			R10 = *(uint64_t*)(global::module_base + 0x622B106);
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x7);
			RCX = global::module_base + 0x555D18AA;
			RDX = RBX;
			RAX += RCX;
			RDX = (~RDX);
			RAX += RDX;
			RCX = global::module_base + 0x254C2F48;
			RCX = (~RCX);
			RCX ^= RBX;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x1F;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3E;
			RAX ^= RCX;
			RCX = 0xFA90058EFA715541;
			RAX *= RCX;
			RCX = global::module_base + 0x854F;
			RAX += RBX;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0xB;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x16;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2C;
			RAX ^= RCX;
			RCX = 0x4A826B064E56FDC5;
			RAX *= RCX;
			return RAX;
		}
		case 2:
		{
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			R10 = *(uint64_t*)(global::module_base + 0x622B106);
			R14 = 0xDA61F39F73CC03F8;
			RCX = RBX;
			RSP = global::module_base + 0x5C89F41F;
			RCX *= RSP;
			RCX += R14;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0xC;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x18;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x30;
			RCX ^= RBX;
			RAX ^= RCX;
			RAX ^= R11;
			RCX = 0x9C45F3814CCAB0C;
			RAX -= RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x7);
			RSP = 0x3AEE2B69DCEB78DF;
			RCX *= RSP;
			RAX *= RCX;
			return RAX;
		}
		case 3:
		{
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			R9 = *(uint64_t*)(global::module_base + 0x622B106);
			RAX -= R11;
			RAX ^= RBX;
			RAX -= RBX;
			RCX = global::module_base + 0x25E73C66;
			RAX += RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x7);
			RAX *= RCX;
			RCX = 0x1859E746B925D7FB;
			RAX *= RCX;
			RAX -= RBX;
			RAX += RBX;
			RCX = RAX;
			RCX >>= 0x15;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2A;
			RAX ^= RCX;
			return RAX;
		}
		case 4:
		{
			R10 = *(uint64_t*)(global::module_base + 0x622B106);
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			RCX = RAX;
			RCX >>= 0x1A;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x34;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x11;
			RAX ^= RCX;
			// mov rdx,[rbp+0F8h]
			RCX = RAX;
			RCX >>= 0x22;
			RDX -= RDI;
			RCX ^= RAX;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x7);
			RAX *= RCX;
			RCX = 0xE58A812351820045;
			RAX += RBX;
			RAX *= RCX;
			RAX ^= R11;
			RAX += RBX;
			RCX = RAX;
			RCX >>= 0x28;
			RAX ^= RCX;
			return RAX;
		}
		case 5:
		{
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			RDX = *(uint64_t*)(global::module_base + 0x622B106);
			RCX = RAX;
			RCX >>= 0x24;
			RCX ^= RAX;
			RAX = RBX;
			RAX = (~RAX);
			RCX += RAX;
			RAX = 0xD30FABB31296BB1D;
			RAX += RCX;
			RAX += R11;
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= RDX;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x7);
			RCX = 0x2A241A029847FF1D;
			RAX *= RCX;
			RAX += R11;
			RAX += RBX;
			RAX ^= RBX;
			return RAX;
		}
		case 6:
		{
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			R9 = *(uint64_t*)(global::module_base + 0x622B106);
			RAX ^= R11;
			RAX -= R11;
			RAX += 0xFFFFFFFFE5BF829B;
			RAX += RBX;
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x7);
			RCX = 0x46E0AD8AF104D757;
			RCX -= RBX;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x27;
			RAX ^= RCX;
			RCX = 0x3B5F1237A1C3F7FA;
			RAX ^= RCX;
			RCX = 0x3E7EB8A47D840D39;
			RAX *= RCX;
			return RAX;
		}
		case 7:
		{
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			R15 = global::module_base + 0x180999D9;
			RDX = *(uint64_t*)(global::module_base + 0x622B106);
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= RDX;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x7);
			RAX ^= RBX;
			RCX = 0xAAEA0A779ED96F58;
			RAX ^= RCX;
			RAX -= R11;
			RCX = 0x20E864166B9D9746;
			RAX += RCX;
			RCX = R15;
			RCX = (~RCX);
			RCX ^= RBX;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x24;
			RAX ^= RCX;
			RCX = 0x5B5A5256A3375667;
			RAX *= RCX;
			return RAX;
		}
		case 8:
		{
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			R9 = *(uint64_t*)(global::module_base + 0x622B106);
			RCX = 0xF4993DACDEBAEF7F;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1F;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3E;
			RAX ^= RCX;
			RAX ^= RBX;
			RAX ^= R11;
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x7);
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
			RCX = global::module_base + 0x4AEC90FA;
			RAX -= RBX;
			RAX += RCX;
			RCX = 0x4F5248099221225D;
			RAX *= RCX;
			return RAX;
		}
		case 9:
		{
			R10 = *(uint64_t*)(global::module_base + 0x622B106);
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			RDX = RBX;
			RDX -= R11;
			RDX -= 0x6C4EEA5A;
			RAX ^= RDX;
			RCX = global::module_base + 0x63C7A48F;
			RAX += RBX;
			RCX = (~RCX);
			RCX++;
			RAX += RCX;
			RDX = RBX;
			RDX = (~RDX);
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x7);
			RAX *= RCX;
			RCX = 0xC0B9DA6F23BF7533;
			RAX *= RCX;
			RCX = global::module_base + 0x3D14;
			RCX = (~RCX);
			RDX *= RCX;
			RAX += RDX;
			RCX = R11 + 0x7A7D113C;
			RCX += RBX;
			RAX ^= RCX;
			RCX = 0x6B11F3B77F7DCB7B;
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
			return RAX;
		}
		case 10:
		{
			R11 = *(uint64_t*)(global::module_base + 0x622B106);
			RDI = global::module_base + 0x77A;
			R15 = global::module_base + 0x15C09C43;
			RCX = RBX;
			RCX = (~RCX);
			RSP = global::module_base + 0x5332F3EC;
			RCX *= RSP;
			RAX += RCX;
			// mov rdx,[rbp+0F8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R11;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX = *(uint64_t*)(RDX + 0x7);
			RDX *= RAX;
			RAX = RBX;
			RAX ^= R15;
			RAX += RDX;
			RCX = 0xF0EE24B7B3164041;
			RAX *= RCX;
			RAX += RBX;
			RCX = RAX;
			RCX >>= 0x26;
			RAX ^= RCX;
			RCX = 0xA43145B930A54A5;
			RAX *= RCX;
			RCX = 0x3D121A44F0BAAE62;
			RAX -= RCX;
			return RAX;
		}
		case 11:
		{
			RDI = global::module_base + 0x77A;
			R15 = global::module_base + 0x641D;
			R10 = *(uint64_t*)(global::module_base + 0x622B106);
			RCX = R15;
			RCX = (~RCX);
			RCX -= RBX;
			RAX += RCX;
			RCX = global::module_base + 0x2DDB9F87;
			RDX = RBX;
			RDX *= RCX;
			RDX ^= RAX;
			RAX = global::module_base + 0x736B;
			RAX *= RBX;
			RAX += RDX;
			RCX = 0x5435BD98F78C1543;
			RAX *= RCX;
			RCX = 0x8545A0F62076C3E1;
			RAX *= RCX;
			RCX = 0xC2CE815C6A769A3D;
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
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x7);
			return RAX;
		}
		case 12:
		{
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			R9 = *(uint64_t*)(global::module_base + 0x622B106);
			RCX = 0xFFFFFFFFD2040867;
			RCX -= RBX;
			RCX -= R11;
			RAX += RCX;
			RCX = RBX;
			RCX = (~RCX);
			RCX -= R11;
			RCX += 0xFFFFFFFF8E07BA2E;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x17;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2E;
			RAX ^= RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0x7);
			RBP = 0xBD861B9C0B0AD353;
			RCX *= RBP;
			RAX *= RCX;
			RAX -= RBX;
			RCX = 0x215E811B091FEFC3;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x13;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x26;
			RAX ^= RCX;
			return RAX;
		}
		case 13:
		{
			R10 = *(uint64_t*)(global::module_base + 0x622B106);
			RDI = global::module_base + 0x77A;
			RDX = RBX;
			RDX = (~RDX);
			RCX = global::module_base + 0x400C03C3;
			RCX = (~RCX);
			RDX += RCX;
			RAX ^= RDX;
			RCX = RAX;
			RCX >>= 0x11;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x22;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x15;
			RAX ^= RCX;
			RCX = RAX;
			// mov rdx,[rbp+0F8h]
			RCX >>= 0x2A;
			RDX -= RDI;
			RCX ^= RAX;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RAX = 0x62CCB32FE7211709;
			RCX += RAX;
			RDX ^= R10;
			RCX ^= RBX;
			RAX = 0x78F9259586F4C996;
			RCX ^= RAX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x7);
			RAX *= RCX;
			RCX = 0x7056F087288C7A9F;
			RAX *= RCX;
			return RAX;
		}
		case 14:
		{
			R10 = *(uint64_t*)(global::module_base + 0x622B106);
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			R15 = global::module_base + 0x6616;
			RCX = 0x10C91274746C2E62;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1E;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3C;
			RAX ^= RCX;
			RCX = RBX;
			RCX = (~RCX);
			RCX *= R15;
			RAX += RCX;
			RCX = 0x2B36F59B3EA02675;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x6;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0xC;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x18;
			RAX ^= RCX;
			// mov rdx,[rbp+0F8h]
			RDX -= RDI;
			RDX = 0; // Special case
			RCX = RAX;
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RCX >>= 0x30;
			RCX ^= RAX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0x7);
			RAX *= RCX;
			RAX ^= R11;
			return RAX;
		}
		case 15:
		{
			R9 = *(uint64_t*)(global::module_base + 0x622B106);
			R11 = global::module_base;
			RDI = global::module_base + 0x77A;
			R15 = global::module_base + 0xB94F;
			RCX = 0x19B74345AD53C8F5;
			RAX *= RCX;
			RAX += R11;
			// mov rcx,[rbp+0F8h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0x7);
			R13 = 0xDCD52A02685A2AA3;
			RCX = RBX;
			RCX = (~RCX);
			RCX ^= R15;
			RCX += R13;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0xF;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1E;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x3C;
			RAX ^= RCX;
			RCX = R11 + 0x520A8469;
			RCX += RBX;
			RAX ^= RCX;
			RAX -= R11;
			RAX += 0xFFFFFFFFFFFF0E6F;
			RAX += RBX;
			return RAX;
		}
		default:
			return 0;
		}
	}
 
	auto get_bone() -> uint64_t
	{
		uint64_t RAX = global::module_base, RBX = global::module_base, RCX = global::module_base, RDX = global::module_base, R8 = global::module_base, RDI = global::module_base, R9 = global::module_base, R10 = global::module_base, R11 = global::module_base, R12 = global::module_base, R13 = global::module_base, R14 = global::module_base, R15 = global::module_base, RSI = global::module_base, RSP = global::module_base, RBP = global::module_base;
		R8 = *(uint64_t*)(global::module_base + 0x150F1128);
		if (!R8)
			return 0;
		RBX = global::peb;
		// test r8,r8
		// je near ptr 0000000001AE638Dh
		RAX = RBX;
		RAX = _rotl64(RAX, 0x31);
		// and eax,0Fh
		RAX &= 0xF;
		switch (RAX)
		{
		case 0:
		{
			RDI = global::module_base + 0x90B;
			R10 = *(uint64_t*)(global::module_base + 0x622B1EA);
			// mov rcx,[rbp+98h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RAX = 0xD0937D3042D2117A;
			RCX = (~RCX);
			RAX += R8;
			if (utils::is_bad_ptr((void*)(RCX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0x13);
			R8 *= RAX;
			RAX = 0xEE8CA74360DDAEB5;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x16;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x2C;
			R8 ^= RAX;
			RAX = global::module_base;
			R8 ^= RAX;
			R8 += RAX;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x1D;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3A;
			R8 ^= RAX;
			return R8;
		}
		case 1:
		{
			RDI = global::module_base + 0x90B;
			R10 = *(uint64_t*)(global::module_base + 0x622B1EA);
			R8 += RBX;
			RAX = global::module_base;
			R8 -= RAX;
			R8 += 0xFFFFFFFFFFFF45B4;
			R8 += RBX;
			RAX = R8;
			RAX >>= 0x26;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x13);
			RAX = R8;
			RAX >>= 0x1;
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
			RAX = 0x4B1ACA35AF7E3197;
			R8 += RAX;
			RAX = 0xC9AAACAC7BD1B10F;
			R8 ^= RAX;
			RAX = 0xE2DB39CAE2BE8091;
			R8 *= RAX;
			return R8;
		}
		case 2:
		{
			RDI = global::module_base + 0x90B;
			R9 = *(uint64_t*)(global::module_base + 0x622B1EA);
			RAX = R8;
			RAX >>= 0x22;
			R8 ^= RAX;
			R8 ^= RBX;
			RAX = 0x6F11685E7D783D11;
			R8 *= RAX;
			RAX = 0x4EF2CD2D54F7D444;
			R8 += RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x13);
			RSP = 0xEE5D56A35F188137;
			RAX *= RSP;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x26;
			R8 ^= RAX;
			R8 -= RBX;
			return R8;
		}
		case 3:
		{
			RDI = global::module_base + 0x90B;
			R9 = *(uint64_t*)(global::module_base + 0x622B1EA);
			R8 ^= RBX;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x12;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x24;
			R8 ^= RAX;
			RAX = 0x138B351938CAFA1B;
			R8 *= RAX;
			RAX = 0xC755F36DCAF7D95D;
			R8 ^= RAX;
			RAX = 0x15672904708A9B31;
			R8 *= RAX;
			R8 ^= RBX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x13);
			return R8;
		}
		case 4:
		{
			RDI = global::module_base + 0x90B;
			R10 = *(uint64_t*)(global::module_base + 0x622B1EA);
			RAX = R8;
			RAX >>= 0x1F;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3E;
			R8 ^= RAX;
			// mov rcx,[rbp+98h]
			RCX -= RDI;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RAX = RBX;
			RAX -= global::module_base;
			RCX = (~RCX);
			RAX += R8;
			R8 = 0xCB39FFC7CBDC43F3;
			RAX *= R8;
			R8 = 0x740E9596DCFB24E5;
			RAX -= R8;
			R8 = 0x3C6B768F97F9FCC5;
			RAX ^= R8;
			if (utils::is_bad_ptr((void*)(RCX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0x13);
			R8 *= RAX;
			RAX = global::module_base + 0x72EF9D8F;
			RAX -= RBX;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x26;
			R8 ^= RAX;
			RAX = 0x95A3ADBAEBE359;
			R8 ^= RAX;
			return R8;
		}
		case 5:
		{
			RDI = global::module_base + 0x90B;
			R9 = *(uint64_t*)(global::module_base + 0x622B1EA);
			RAX = R8;
			RAX >>= 0x21;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x21;
			R8 ^= RAX;
			R8 += RBX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x13);
			RAX = R8;
			RAX >>= 0x1E;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3C;
			R8 ^= RAX;
			RAX = 0x8CD06F1616595E27;
			R8 *= RAX;
			RAX = 0x76660623CAECB3E0;
			R8 += RAX;
			return R8;
		}
		case 6:
		{
			RDI = global::module_base + 0x90B;
			R9 = *(uint64_t*)(global::module_base + 0x622B1EA);
			RAX = R8;
			RAX >>= 0x1C;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x38;
			R8 ^= RAX;
			RAX = RBX;
			RBP = global::module_base + 0x9116;
			RAX ^= RBP;
			RAX -= RBX;
			RAX -= global::module_base;
			R8 += RAX;
			RAX = 0xD517282BA1DDB3F3;
			R8 *= RAX;
			RAX = 0x6DF0AFFC156DDA58;
			R8 += RAX;
			RAX = R8;
			RAX >>= 0x11;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x22;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x13);
			R8 *= RAX;
			RAX = 0x150BE96DBF69271D;
			R8 += RAX;
			RAX = global::module_base;
			R8 += RAX;
			return R8;
		}
		case 7:
		{
			R11 = *(uint64_t*)(global::module_base + 0x622B1EA);
			RDI = global::module_base + 0x90B;
			RAX = R8;
			RAX >>= 0x1D;
			R8 ^= RAX;
			// mov rdx,[rbp+98h]
			RCX = R8;
			RDX -= RDI;
			RCX >>= 0x3A;
			RCX ^= R8;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			R8 = global::module_base + 0x78EFFC1D;
			RDX ^= R11;
			RDX = (~RDX);
			RAX = 0x70295A6B7C75AD69;
			RCX *= RAX;
			RAX = RBX;
			RAX *= R8;
			if (utils::is_bad_ptr((void*)(RDX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RDX + 0x13);
			RCX ^= RAX;
			R8 *= RCX;
			RAX = R8;
			RAX >>= 0x1F;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3E;
			R8 ^= RAX;
			RAX = 0x1074CAB455C40DD3;
			R8 *= RAX;
			RAX = 0x21D0F63A01EF0A43;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0xF;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1E;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x3C;
			R8 ^= RAX;
			return R8;
		}
		case 8:
		{
			RDI = global::module_base + 0x90B;
			R9 = *(uint64_t*)(global::module_base + 0x622B1EA);
			RAX = R8;
			RAX >>= 0xD;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x1A;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x34;
			R8 ^= RAX;
			RAX = 0x5A47B075FC579AB9;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x8;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x10;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x13);
			return R8;
		}
		case 9:
		{
			RDI = global::module_base + 0x90B;
			R9 = *(uint64_t*)(global::module_base + 0x622B1EA);
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R9;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x13);
			RSP = 0x79604417B173B4C3;
			RAX *= RSP;
			R8 *= RAX;
			RAX = 0xD29787C0CB96202B;
			R8 *= RAX;
			RAX = global::module_base;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x20;
			R8 ^= RAX;
			RAX = global::module_base;
			R8 ^= RAX;
			RAX = 0xDE4F9494CEDED061;
			R8 *= RAX;
			RAX = global::module_base;
			R8 -= RAX;
			return R8;
		}
		case 10:
		{
			RDI = global::module_base + 0x90B;
			R10 = *(uint64_t*)(global::module_base + 0x622B1EA);
			// mov rcx,[rbp+98h]
			RCX -= RDI;
			RCX = 0; // Special case
			RAX = 0x8D01A706494EFA73;
			RAX *= R8;
			RCX = _rotl64(RCX, 0x10);
			R8 = global::module_base;
			RAX += R8;
			RCX ^= R10;
			RCX = (~RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0x13);
			R8 *= RAX;
			R8 -= RBX;
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
			RAX = global::module_base;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x14;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x28;
			R8 ^= RAX;
			RAX = 0x2B60B88CEEBE06A3;
			R8 ^= RAX;
			return R8;
		}
		case 11:
		{
			RDI = global::module_base + 0x90B;
			R10 = *(uint64_t*)(global::module_base + 0x622B1EA);
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x13);
			RAX = global::module_base;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x25;
			R8 ^= RAX;
			RAX = 0x90C83B4083DD670B;
			R8 *= RAX;
			RAX = R8;
			RAX >>= 0x14;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x28;
			RAX ^= RBX;
			R8 ^= RAX;
			return R8;
		}
		case 12:
		{
			RDI = global::module_base + 0x90B;
			R11 = *(uint64_t*)(global::module_base + 0x622B1EA);
			RAX = global::module_base;
			R8 -= RAX;
			R8 += 0xFFFFFFFFE77B19A1;
			R8 += RBX;
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
			RAX = R8;
			RAX >>= 0x1;
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
			RAX = 0xA67B8F0BA00FC2D7;
			R8 *= RAX;
			// mov rcx,[rbp+98h]
			RCX -= RDI;
			RCX = 0; // Special case
			RAX = RBX;
			RCX = _rotl64(RCX, 0x10);
			RAX = (~RAX);
			RBP = global::module_base + 0x2ABA;
			RAX *= RBP;
			RCX ^= R11;
			RAX ^= R8;
			RCX = (~RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 = *(uint64_t*)(RCX + 0x13);
			R8 *= RAX;
			R8 ^= RBX;
			RAX = global::module_base + 0x21BBFBB1;
			R8 ^= RAX;
			RAX = global::module_base;
			R8 += RAX;
			return R8;
		}
		case 13:
		{
			RDI = global::module_base + 0x90B;
			R10 = *(uint64_t*)(global::module_base + 0x622B1EA);
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
			RCX = RBX;
			RCX = (~RCX);
			RAX = global::module_base + 0x837A;
			RCX *= RAX;
			RAX = global::module_base + 0x16B2C751;
			R8 += RCX;
			RAX = (~RAX);
			RAX += RBX;
			R8 ^= RAX;
			RAX = global::module_base + 0x274787B1;
			R8 += RBX;
			R8 += RAX;
			RAX = 0xC9162F873C0F6585;
			R8 ^= RAX;
			RAX = 0xD49712B677F28D87;
			R8 *= RAX;
			RAX = 0xF9BBC609A45D28DE;
			R8 ^= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x13);
			return R8;
		}
		case 14:
		{
			R10 = *(uint64_t*)(global::module_base + 0x622B1EA);
			RDI = global::module_base + 0x90B;
			RAX = R8;
			RAX >>= 0x13;
			R8 ^= RAX;
			RAX = R8;
			RAX >>= 0x26;
			R8 ^= RAX;
			RCX = RBX;
			// mov rax,[rbp+98h]
			RCX = (~RCX);
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x13);
			R8 *= RAX;
			RAX = 0xE9B651D8B341091;
			R8 *= RAX;
			RAX = global::module_base + 0x1CCEB943;
			RAX = (~RAX);
			R8 ^= RAX;
			RAX = global::module_base + 0xA5DE;
			RAX = (~RAX);
			R8 ^= RCX;
			RAX ^= RCX;
			R8 -= RAX;
			R8 -= RBX;
			R8 ^= RBX;
			RAX = global::module_base + 0x213C;
			RAX = (~RAX);
			RAX ^= RBX;
			R8 -= RAX;
			return R8;
		}
		case 15:
		{
			RDI = global::module_base + 0x90B;
			R10 = *(uint64_t*)(global::module_base + 0x622B1EA);
			RAX = 0x3101191592EC31EB;
			R8 *= RAX;
			RAX = RBX;
			RBP = global::module_base + 0x2E1143D8;
			RAX ^= RBP;
			R8 -= RAX;
			RAX = global::module_base;
			R8 -= RAX;
			RAX = R8;
			RAX >>= 0x23;
			R8 ^= RAX;
			RAX = 0xD04FF38D82AAF02F;
			R8 *= RAX;
			RCX = RBX;
			RCX = (~RCX);
			RAX = global::module_base + 0x74C57B6B;
			R8 += RAX;
			R8 += RCX;
			RAX = 0x714D2A195510C981;
			R8 *= RAX;
			// mov rax,[rbp+98h]
			RAX -= RDI;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x13))) return 0xFFFFFFFFFFFFFFFF; R8 *= *(uint64_t*)(RAX + 0x13);
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
		RAX = 0x8B61F82C5FB08221;
		R11 = global::module_base;
		RAX = _umul128(RAX, RCX, &RDX);
		R10 = 0xFD3EF24BB8B98DF;
		RDX >>= 0xC;
		RAX = RDX * 0x1D63;
		RCX -= RAX;
		RAX = 0x1809F41F14DEA43;
		R8 = RCX * 0x1D63;
		RAX = _umul128(RAX, R8, &RDX);
		RDX >>= 0x6;
		RAX = RDX * 0x2A99;
		R8 -= RAX;
		RAX = 0xCCCCCCCCCCCCCCCD;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = 0x26E009370049B803;
		RDX >>= 0x4;
		RCX = RDX + RDX * 0x4;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = R8;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0x9;
		RAX = RAX + RCX * 0x4;
		RCX = RAX * 0x6F2;
		RAX = R8 * 0x6F4;
		RAX -= RCX;
		RAX = *(uint16_t*)(RAX + R11 + 0x6236DC0);
		R8 = RAX * 0x13C8;
		RAX = R10;
		RAX = _umul128(RAX, R8, &RDX);
		RCX = R8;
		RAX = R10;
		RCX -= RDX;
		RCX >>= 0x1;
		RCX += RDX;
		RCX >>= 0xC;
		RCX = RCX * 0x1E23;
		R8 -= RCX;
		R9 = R8 * 0x29A5;
		RAX = _umul128(RAX, R9, &RDX);
		RAX = R9;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0xC;
		RAX = RAX * 0x1E23;
		R9 -= RAX;
		RAX = 0xF1D48BCEE0D399FB;
		RAX = _umul128(RAX, R9, &RDX);
		RAX = 0xF0F0F0F0F0F0F0F1;
		RDX >>= 0x9;
		RCX = RDX * 0x21E;
		RAX = _umul128(RAX, R9, &RDX);
		RDX >>= 0x4;
		RCX += RDX;
		RAX = RCX * 0x22;
		RCX = R9 + R9 * 0x8;
		RCX <<= 0x2;
		RCX -= RAX;
		return *(uint16_t*)(RCX + R11 + 0x623F8B0);
	}
 
}
