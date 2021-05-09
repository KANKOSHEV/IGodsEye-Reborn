#include "decryption.h"
 
/*
	Generated 08/05/2021 20:29:51 by baba08000
	Game version 1.36.5.9086423
*/
 
namespace offsets
{
	constexpr auto camera_base = 0x14739700;
	constexpr auto camera_pos = 0x1D8;
	constexpr auto game_mode = 0x170DEC08;
	constexpr auto local_index = 0x73C70;
	constexpr auto name_array = 0x174675F8;
	constexpr auto name_array_padding = 0x4C70;
	constexpr auto ref_def = 0x1745C518;
	constexpr auto weapon_definition = 0x14807260;
 
	namespace bones
	{
		constexpr auto bone_base = 0x22C;
		constexpr auto distribute = 0xA3C2E90;
		constexpr auto size = 0x150;
		constexpr auto visible = 0x599EF20;
	}
 
	namespace directx
	{
		constexpr auto command_queue = 0x18E97C28;
		constexpr auto swap_chain = 0x18E9CFA0;
	}
 
	namespace other
	{
		constexpr auto recoil = 0x3F080;
	}
 
	namespace player
	{
		constexpr auto dead_1 = 0x3390;
		constexpr auto dead_2 = 0x164;
		constexpr auto pos_info = 0x3840;
		constexpr auto size = 0x3A68;
		constexpr auto stance = 0x678;
		constexpr auto team_id = 0x5E8;
		constexpr auto valid = 0xE50;
		constexpr auto weapon_index = 0x3708;
	}
 
}
 
namespace decryption
{
	auto get_client_info() -> uint64_t
	{
		uint64_t RAX = 0, RBX = 0, RCX = 0, RDX = 0, R8 = 0, RDI = 0, R9 = 0, R10 = 0, R11 = 0, R12 = 0, R13 = 0, R14 = 0, RSI = 0, RSP = 0, RBP = 0;
		RBX = *(uint64_t*)(global::module_base + 0x17459B88);
		if (!RBX)
			return 0;
 
		R8 = global::module_base;
		RCX = global::peb;
		RCX = (~RCX);
		// test rbx,rbx
		// je short 0000000002070951h
		RCX += R8;
		RAX = global::module_base + 0xC12;
		RDX = 0x6004E7164BC967D8;
		RDX += RBX;
		RDX += RCX;
		RCX = global::module_base;
		RCX -= RAX;
		RAX = RDX;
		RCX = 0; // Special case
		RAX >>= 0x21;
		RCX = _rotl64(RCX, 0x10);
		RAX ^= RDX;
		RCX ^= *(uint64_t*)(global::module_base + 0x69440C1);
		RCX = _byteswap_uint64(RCX);
		if (utils::is_bad_ptr((void*)(RCX + 0x13))) return 0xFFFFFFFFFFFFFFFF; RBX = *(uint64_t*)(RCX + 0x13);
		RBX *= RAX;
		RAX = 0x4C8E566FE07B7D45;
		RBX ^= R8;
		RBX *= RAX;
		return RBX;
	}
 
	auto get_client_info_base(uint64_t client_info) -> uint64_t
	{
		uint64_t RAX = global::module_base, RBX = global::module_base, RCX = global::module_base, RDX = global::module_base, R8 = global::module_base, RDI = global::module_base, R9 = global::module_base, R10 = global::module_base, R11 = global::module_base, R12 = global::module_base, R13 = global::module_base, R14 = global::module_base, R15 = global::module_base, RSI = global::module_base, RSP = global::module_base, RBP = global::module_base;
		RAX = *(uint64_t*)(client_info + 0x9DBD8);
		if (!RAX)
			return 0;
		R11 = global::peb;
		// test rax,rax
		// je near ptr 0000000002070670h
		RCX = R11;
		RCX = _rotl64(RCX, 0x2E);
		// and ecx,0Fh
		RCX &= 0xF;
		switch (RCX)
		{
		case 0:
		{
			RBX = global::module_base + 0xA4B;
			R9 = *(uint64_t*)(global::module_base + 0x6944106);
			RCX = RAX;
			RCX >>= 0x16;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2C;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX += RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0xB);
			RBP = 0x72EA232B1F86ABA1;
			RCX *= RBP;
			RAX *= RCX;
			RAX ^= R11;
			RCX = 0x3EA89E23A6EFD9AC;
			RAX ^= RCX;
			RCX = 0x4F7E844D5CF0236D;
			RAX += RCX;
			RAX += R11;
			return RAX;
		}
		case 1:
		{
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RBX = global::module_base + 0xA4B;
			R15 = global::module_base + 0x114A;
			// mov rdx,[rbp+0F8h]
			RDX -= RBX;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RDX = *(uint64_t*)(RDX + 0xB);
			RDX *= RAX;
			RAX = R11 + 0x1;
			RAX *= R15;
			RAX += RDX;
			RCX = RAX;
			RCX >>= 0x22;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX ^= RCX;
			RCX = 0x519D3B9E5A4C9636;
			RAX -= RCX;
			RCX = 0xF6DEDC00D566887;
			RAX ^= RCX;
			RAX -= R11;
			RCX = 0x957AB25E0A038BB9;
			RAX *= RCX;
			return RAX;
		}
		case 2:
		{
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RBX = global::module_base + 0xA4B;
			R15 = global::module_base + 0x7D19D6C1;
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
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = 0x70FA72240EE5B485;
			RAX ^= RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0xB);
			RDX = R11;
			RCX = R15;
			RCX = (~RCX);
			RDX = (~RDX);
			RCX *= RDX;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x11;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x22;
			RAX ^= RCX;
			RCX = 0x3089F4D3EE7BA0E3;
			RAX *= RCX;
			RCX = R11;
			RBP = global::module_base + 0x6C09571B;
			RCX ^= RBP;
			RAX -= RCX;
			RCX = global::module_base + 0x226F2AFC;
			RDX ^= RCX;
			RAX -= RDX;
			return RAX;
		}
		case 3:
		{
			RBX = global::module_base + 0xA4B;
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			// mov rdx,[rbp+0F8h]
			RDX -= RBX;
			RCX = R11;
			RDX = 0; // Special case
			RCX ^= RAX;
			RDX = _rotl64(RDX, 0x10);
			RDX ^= R10;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0xB);
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x9;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x12;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x24;
			RAX ^= RCX;
			RCX = 0x716311AC0FC1D513;
			RAX ^= RCX;
			RCX = global::module_base;
			RCX += 0x136E;
			RCX += R11;
			RAX += RCX;
			RCX = 0xBA23CCA0EAD73757;
			RAX *= RCX;
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
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = 0xDE79B01CB4BE241D;
			RAX ^= RCX;
			return RAX;
		}
		case 4:
		{
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RBX = global::module_base + 0xA4B;
			R15 = global::module_base + 0x402A097D;
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
			RCX >>= 0x8;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x10;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = 0xFFFFFFFFFFFF96CC;
			RCX -= R11;
			RCX -= global::module_base;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x13;
			RAX ^= RCX;
			// mov rdx,[rbp+0F8h]
			RDX -= RBX;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RCX = RAX;
			RDX ^= R10;
			RCX >>= 0x26;
			RCX ^= RAX;
			RAX = 0x8BBEFE768B80CC09;
			RCX ^= RAX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0xB);
			RAX *= RCX;
			RCX = 0x27DB0445DB3EF495;
			RAX *= RCX;
			RDX = R11;
			RDX = (~RDX);
			RCX = R15;
			RCX = (~RCX);
			RDX += RCX;
			RAX ^= RDX;
			return RAX;
		}
		case 5:
		{
			RBX = global::module_base + 0xA4B;
			R9 = *(uint64_t*)(global::module_base + 0x6944106);
			RAX ^= R11;
			RCX = RAX;
			RCX >>= 0x1A;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x34;
			RAX ^= RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0xB);
			RCX = 0x2420B462D593767;
			RAX *= RCX;
			RCX = global::module_base;
			RAX += RCX;
			RCX = 0xF367C92A70C7E00D;
			RAX *= RCX;
			RCX = 0x8576546C1993E69;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x11;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x22;
			RAX ^= RCX;
			return RAX;
		}
		case 6:
		{
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RBX = global::module_base + 0xA4B;
			RDX = R11;
			RDX = (~RDX);
			RCX = global::module_base + 0x1214CF8E;
			RAX += RCX;
			RAX += RDX;
			RCX = RAX;
			RCX >>= 0x14;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x28;
			RAX ^= RCX;
			RCX = global::module_base;
			RCX += 0x53BA611D;
			RCX += R11;
			RAX += RCX;
			RCX = global::module_base;
			RCX += 0x9655;
			RCX += R11;
			RAX ^= RCX;
			RCX = 0x4C03B8A114FFD96F;
			RAX *= RCX;
			RCX = 0x623FF8752111244F;
			RAX += RCX;
			RCX = 0x2F5E6C9B57AB1147;
			RAX ^= RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0xB);
			return RAX;
		}
		case 7:
		{
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RBX = global::module_base + 0xA4B;
			RAX ^= R11;
			RCX = 0xFE5F1185DCA3ACBD;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x10;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = global::module_base + 0x1776BB17;
			RAX -= R11;
			RAX += RCX;
			// mov rdx,[rbp+0F8h]
			RDX -= RBX;
			RDX = 0; // Special case
			RCX = R11;
			RCX = (~RCX);
			RDX = _rotl64(RDX, 0x10);
			RBP = global::module_base + 0x9298;
			RCX *= RBP;
			RDX ^= R10;
			RCX += RAX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0xB);
			RAX *= RCX;
			RAX -= R11;
			RCX = global::module_base;
			RAX += RCX;
			return RAX;
		}
		case 8:
		{
			RBX = global::module_base + 0xA4B;
			R9 = *(uint64_t*)(global::module_base + 0x6944106);
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0xB);
			RCX = 0xD733975F3FE2F95C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x27;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX += R11;
			RAX ^= RCX;
			RAX += R11;
			RCX = 0xA03C76E143332EA9;
			RAX *= RCX;
			RCX = 0x19E5143505A7D0CA;
			RAX ^= RCX;
			return RAX;
		}
		case 9:
		{
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RBX = global::module_base + 0xA4B;
			RCX = global::module_base;
			RAX -= RCX;
			RCX = RAX;
			RCX >>= 0xE;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1C;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x38;
			RAX ^= RCX;
			RCX = R11;
			RCX -= global::module_base;
			RAX += RCX;
			RCX = 0xF30BDE82131A7B77;
			RAX ^= RCX;
			// mov rdx,[rbp+0F8h]
			RDX -= RBX;
			RDX = 0; // Special case
			RCX = RAX;
			RDX = _rotl64(RDX, 0x10);
			RAX = 0xEE27EBC14C4C1E13;
			RCX ^= RAX;
			RDX ^= R10;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0xB);
			RAX *= RCX;
			RCX = 0x751D586D3BDEA5D9;
			RAX *= RCX;
			return RAX;
		}
		case 10:
		{
			RBX = global::module_base + 0xA4B;
			R15 = global::module_base + 0x5CB5CB34;
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RCX = 0x2CC9097E0D2DE324;
			RAX ^= RCX;
			RCX = 0x2F0ED6302D81AC5B;
			RAX *= RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0xB);
			RCX = RAX;
			RCX >>= 0x13;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x26;
			RAX ^= RCX;
			RCX = R11;
			RCX = (~RCX);
			RCX ^= R15;
			RCX -= global::module_base;
			RAX += RCX;
			RCX = 0x375A6E201DA6C6C6;
			RAX ^= RCX;
			RAX ^= R11;
			return RAX;
		}
		case 11:
		{
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RBX = global::module_base + 0xA4B;
			R15 = global::module_base + 0x3C11D3D5;
			RCX = RAX;
			RCX >>= 0xD;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x1A;
			RAX ^= RCX;
			RDX = RAX;
			RDX >>= 0x34;
			RAX ^= RDX;
			RCX = R11;
			RCX *= R15;
			RAX -= RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0xB);
			RCX = RAX;
			RCX >>= 0x17;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x2E;
			RAX ^= RCX;
			RCX = global::module_base + 0x11212265;
			RCX = (~RCX);
			RCX ^= R11;
			RAX += RCX;
			RCX = 0x88DAEA5F43B83F17;
			RAX *= RCX;
			RCX = 0xE90BC04083304DCC;
			RAX ^= R11;
			RAX ^= RCX;
			return RAX;
		}
		case 12:
		{
			RBX = global::module_base + 0xA4B;
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RCX = global::module_base;
			RAX -= RCX;
			RCX = 0x81241A07DEE2CE8;
			RAX += RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0xB);
			RAX += R11;
			RCX = RAX;
			RCX >>= 0xC;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x18;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x30;
			RAX ^= RCX;
			RCX = 0x85ABE4B0F8B57445;
			RAX *= RCX;
			RCX = R11;
			RCX -= global::module_base;
			RCX -= 0x5D8D;
			RAX ^= RCX;
			return RAX;
		}
		case 13:
		{
			RBX = global::module_base + 0xA4B;
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RAX -= R11;
			RCX = 0x4446086A6F163874;
			RAX += RCX;
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
			RCX = 0x35B940C7DD545954;
			RAX ^= RCX;
			RCX = global::module_base;
			RAX -= RCX;
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R10;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RCX = *(uint64_t*)(RCX + 0xB);
			RSP = 0xCB066093B8976631;
			RCX *= RSP;
			RAX *= RCX;
			RCX = global::module_base;
			RAX ^= RCX;
			return RAX;
		}
		case 14:
		{
			RBX = global::module_base + 0xA4B;
			R9 = *(uint64_t*)(global::module_base + 0x6944106);
			RAX += R11;
			RCX = 0x65EEF3032E9EFB39;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0x8;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x10;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RAX += R11;
			// mov rcx,[rbp+0F8h]
			RCX -= RBX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= R9;
			RCX = _byteswap_uint64(RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX *= *(uint64_t*)(RCX + 0xB);
			RCX = RAX;
			RCX >>= 0x1;
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
			RCX = RAX;
			RCX >>= 0x20;
			RAX ^= RCX;
			RCX = 0x1412150B3221919;
			RAX += RCX;
			RCX = RAX;
			RCX >>= 0x21;
			RAX ^= RCX;
			return RAX;
		}
		case 15:
		{
			R10 = *(uint64_t*)(global::module_base + 0x6944106);
			RBX = global::module_base + 0xA4B;
			RCX = 0x372F150F7FB6466B;
			RAX *= RCX;
			RCX = RAX;
			RCX >>= 0xA;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x14;
			RAX ^= RCX;
			RCX = RAX;
			RCX >>= 0x28;
			RAX ^= RCX;
			// mov rdx,[rbp+0F8h]
			RDX -= RBX;
			RDX = 0; // Special case
			RDX = _rotl64(RDX, 0x10);
			RCX = 0x2BC12DFA41B0D49D;
			RDX ^= R10;
			RCX += RAX;
			RDX = _byteswap_uint64(RDX);
			if (utils::is_bad_ptr((void*)(RDX + 0xB))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RDX + 0xB);
			RAX *= RCX;
			RCX = global::module_base;
			RAX += RCX;
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
			RCX = global::module_base;
			RCX += 0x595;
			RCX += R11;
			RAX ^= RCX;
			RCX = 0x16FC158D12EC2B1B;
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
		RDX = *(uint64_t*)(global::module_base + 0x15807128);
		if (!RDX)
			return 0;
		R8 = global::peb;
		R8 = (~R8);
		// test rdx,rdx
		// je near ptr 000000000234FBB3h
		RAX = R8;
		RAX = _rotl64(RAX, 0x2E);
		// and eax,0Fh
		RAX &= 0xF;
		switch (RAX)
		{
		case 0:
		{
			R11 = global::module_base + 0x2B9;
			R10 = *(uint64_t*)(global::module_base + 0x69441E0);
			RAX = RDX;
			RAX >>= 0x16;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x2C;
			RDX ^= RAX;
			RDX += R8;
			RAX = 0x1B280B6201F600C0;
			RAX -= global::module_base;
			RDX += RAX;
			RAX = 0xEC07D89853EE66C1;
			RDX *= RAX;
			RAX = 0xAEA449FEE6BB8A13;
			RDX ^= RAX;
			RDX -= R8;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			return RDX;
		}
		case 1:
		{
			R11 = global::module_base + 0x2B9;
			R10 = *(uint64_t*)(global::module_base + 0x69441E0);
			RDX ^= R8;
			RAX = global::module_base;
			RDX -= RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= R10;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			RAX = RDX;
			RAX >>= 0x1A;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x34;
			RDX ^= RAX;
			RDX -= R8;
			RAX = 0x368E91171976A6ED;
			RDX *= RAX;
			RDX -= R8;
			RAX = 0xB28D87393BDCD977;
			RDX *= RAX;
			return RDX;
		}
		case 2:
		{
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			R11 = global::module_base + 0x2B9;
			R15 = global::module_base + 0x4C7AE15A;
			// mov rcx,[rbp+548h]
			RCX -= R11;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RAX = RDX;
			RCX ^= RBX;
			RAX >>= 0x25;
			RCX = (~RCX);
			RAX ^= RDX;
			RAX += R8;
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX = *(uint64_t*)(RCX + 0x7);
			RDX *= RAX;
			RCX = RDX;
			RCX >>= 0x26;
			RDX ^= RCX;
			RAX = R15;
			RAX ^= R8;
			RDX -= RAX;
			RAX = 0x57DD9BA705F5507C;
			RDX ^= RAX;
			RAX = 0xE89F9CDA727BDCD5;
			RDX *= RAX;
			RAX = 0x62CC68D2A033F7A3;
			RDX += RAX;
			return RDX;
		}
		case 3:
		{
			R11 = global::module_base + 0x2B9;
			R12 = global::module_base + 0xFB3A;
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			RDX ^= R8;
			RAX = 0xCF3D44918484956B;
			RDX *= RAX;
			RAX = RDX;
			RAX >>= 0x15;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x2A;
			RDX ^= RAX;
			RDX += R8;
			RDX ^= R12;
			RDX ^= R8;
			RAX = 0x38FE7B7574CC98E;
			RDX -= RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			RAX = 0x3DBAF7BF27079236;
			RDX += RAX;
			return RDX;
		}
		case 4:
		{
			R11 = global::module_base + 0x2B9;
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			RAX = RDX;
			RAX >>= 0x1C;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x38;
			RDX ^= RAX;
			RAX = 0xE82F5E7A28AEF0BB;
			RDX ^= RAX;
			RAX = global::module_base;
			RDX ^= RAX;
			RDX -= R8;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			RAX = RDX;
			RAX >>= 0x6;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0xC;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x18;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x30;
			RDX ^= RAX;
			RCX = global::module_base + 0x126DB83D;
			RCX = (~RCX);
			RAX = R8;
			RAX = (~RAX);
			RCX += RAX;
			RAX = 0x14E0CC5097010F5B;
			RDX ^= RCX;
			RDX *= RAX;
			return RDX;
		}
		case 5:
		{
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			R11 = global::module_base + 0x2B9;
			RAX = 0xBA59E69C455478D;
			RDX *= RAX;
			RDX ^= R8;
			RAX = global::module_base + 0x6339;
			RAX += R8;
			RDX ^= RAX;
			RAX = 0x7AEBD6E95A4AB045;
			RDX *= RAX;
			RAX = RDX;
			RAX >>= 0x1C;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x38;
			RDX ^= RAX;
			RAX = 0x99E0521D43D2AFE1;
			RDX ^= RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x7);
			RDX *= RAX;
			RDX ^= R8;
			return RDX;
		}
		case 6:
		{
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			R11 = global::module_base + 0x2B9;
			R14 = global::module_base + 0x17063546;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x7);
			RDX *= RAX;
			RDX -= R8;
			RAX = 0x9D04BED544FD0625;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x12;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x24;
			RDX ^= RAX;
			RAX = 0x3E99509E5A2A10C1;
			RDX *= RAX;
			RAX = global::module_base + 0x1D0491B8;
			RAX += R8;
			RDX ^= RAX;
			RAX = 0x57A2BBF6BCD7F1B6;
			RDX ^= RAX;
			RAX = R14;
			RAX = (~RAX);
			RDX += RAX;
			RAX = R8;
			RAX = (~RAX);
			RDX += RAX;
			return RDX;
		}
		case 7:
		{
			R11 = global::module_base + 0x2B9;
			R12 = global::module_base + 0x7278;
			R13 = global::module_base + 0x1B9E9DB9;
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			RAX = R12;
			RAX -= R8;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0xA;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x14;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x28;
			RDX ^= RAX;
			RAX = R8;
			RAX = (~RAX);
			RAX *= R13;
			RDX += RAX;
			RDX ^= R8;
			RAX = 0xC2C227307B7A4CB1;
			RDX *= RAX;
			RAX = 0xFE7BE1CAE4B4DAF4;
			RDX ^= RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			RAX = 0x28ACE7E4796D14D5;
			RDX *= RAX;
			return RDX;
		}
		case 8:
		{
			R11 = global::module_base + 0x2B9;
			R13 = global::module_base + 0xFF61;
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			RAX = global::module_base;
			RDX += RAX;
			// mov rcx,[rbp+548h]
			RCX -= R11;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RAX = RDX;
			RCX ^= RBX;
			RAX ^= R8;
			RCX = (~RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX = *(uint64_t*)(RCX + 0x7);
			RDX *= RAX;
			RAX = 0x7CD90884C05B3A7B;
			RDX *= RAX;
			RAX = 0x1E15C180745D3753;
			RDX *= RAX;
			RAX = R13;
			RAX -= R8;
			RDX += RAX;
			RAX = RDX;
			RAX >>= 0x1B;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x36;
			RDX ^= RAX;
			RAX = 0xC7A5CD3C58C762B5;
			RDX *= RAX;
			return RDX;
		}
		case 9:
		{
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			R11 = global::module_base + 0x2B9;
			RDX ^= R8;
			RAX = RDX;
			RAX >>= 0x3;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x6;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0xC;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x18;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x30;
			RDX ^= RAX;
			RDX += R8;
			RAX = 0x608C28154B5BDBB4;
			RDX ^= RAX;
			RAX = 0x4D7232849DDBE54F;
			RDX *= RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			RAX = RDX;
			RAX >>= 0x13;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x26;
			RDX ^= RAX;
			RAX = 0xD0A9E64B4A0BD5A7;
			RDX *= RAX;
			return RDX;
		}
		case 10:
		{
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			R11 = global::module_base + 0x2B9;
			RAX = 0x9439BFF15DB5ECBF;
			RDX ^= RAX;
			RAX = 0x9BA4690F5CA4B09D;
			RDX *= RAX;
			RAX = R8;
			RAX -= global::module_base;
			RAX += 0xFFFFFFFFFFFFFE89;
			RDX += RAX;
			RAX = RDX;
			RAX >>= 0x1B;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x36;
			RDX ^= RAX;
			RDX += R8;
			RAX = global::module_base + 0x5A886C79;
			// mov rcx,[rbp+548h]
			RAX -= R8;
			RCX -= R11;
			RAX += RDX;
			RCX = 0; // Special case
			RCX = _rotl64(RCX, 0x10);
			RCX ^= RBX;
			RCX = (~RCX);
			if (utils::is_bad_ptr((void*)(RCX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX = *(uint64_t*)(RCX + 0x7);
			RDX *= RAX;
			RAX = RDX;
			RAX >>= 0x7;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0xE;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x1C;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x38;
			RDX ^= RAX;
			return RDX;
		}
		case 11:
		{
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			R11 = global::module_base + 0x2B9;
			R12 = global::module_base + 0x3B31916F;
			RAX = RDX;
			RAX >>= 0x6;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0xC;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x18;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x30;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x1D;
			RDX ^= RAX;
			RCX = RDX;
			RCX >>= 0x3A;
			RCX ^= RDX;
			RAX = R8;
			RAX = (~RAX);
			RDX = R12;
			RDX = (~RDX);
			RDX += RCX;
			RDX += RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			RAX = RDX;
			RAX >>= 0x4;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x8;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x10;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x20;
			RDX ^= RAX;
			RAX = global::module_base + 0x47B76D4B;
			RAX = (~RAX);
			RAX *= R8;
			RDX ^= RAX;
			RAX = 0xC81349E4E181F269;
			RDX *= RAX;
			RAX = 0x66BD3D54575F1E64;
			RDX += RAX;
			return RDX;
		}
		case 12:
		{
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			R11 = global::module_base + 0x2B9;
			R12 = global::module_base + 0x50385D23;
			RAX = global::module_base;
			RDX += RAX;
			RDX -= R8;
			RAX = RDX;
			RAX >>= 0x1E;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x3C;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x11;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x22;
			RDX ^= RAX;
			RAX = R8 + R12;
			RDX ^= RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			RAX = 0x4C49005C62001245;
			RDX *= RAX;
			RAX = 0x53D4AD4A23C57E63;
			RDX += RAX;
			return RDX;
		}
		case 13:
		{
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			R11 = global::module_base + 0x2B9;
			R15 = global::module_base + 0x2EBD8CFC;
			RAX = global::module_base + 0x726AB89A;
			RAX = (~RAX);
			RAX += RDX;
			RDX = R8 + 0x1;
			RDX += RAX;
			RBP = 0xCB38AED737843133;
			RDX *= RBP;
			R12 = global::module_base;
			RAX = R8;
			RAX -= R12;
			R12 = 0x36B9215895D33A9B;
			RBP = 0x4C33E11D7C5955C5;
			RAX *= RBP;
			RAX += R12;
			RDX += RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			RAX = RDX;
			RAX >>= 0x26;
			RDX ^= RAX;
			RAX = 0xBC6395D51DD4F950;
			RDX ^= RAX;
			RAX = R15;
			RAX ^= R8;
			RDX += RAX;
			return RDX;
		}
		case 14:
		{
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			R11 = global::module_base + 0x2B9;
			RAX = 0xD792E0C7C2A74F40;
			RDX += RAX;
			RAX = 0x6CD799A349C26C89;
			RDX ^= RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RDX *= *(uint64_t*)(RAX + 0x7);
			RAX = RDX;
			RAX >>= 0x1A;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x34;
			RDX ^= RAX;
			RAX = global::module_base + 0x1A38;
			RAX += R8;
			RDX += RAX;
			RAX = RDX;
			RAX >>= 0xF;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x1E;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x3C;
			RDX ^= RAX;
			RAX = 0xEB3EF391E493A40B;
			RDX *= RAX;
			RAX = global::module_base;
			RDX -= RAX;
			RDX += 0xFFFFFFFFFFFFEA20;
			RDX += R8;
			return RDX;
		}
		case 15:
		{
			R11 = global::module_base + 0x2B9;
			RDI = global::module_base + 0xCBDA;
			R13 = global::module_base + 0x3A62AD1B;
			RBX = *(uint64_t*)(global::module_base + 0x69441E0);
			RAX = global::module_base;
			RDX ^= RAX;
			RAX = R8;
			RAX = (~RAX);
			RAX += R13;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x4;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x8;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x10;
			RDX ^= RAX;
			RAX = RDX;
			RAX >>= 0x20;
			RDX ^= RAX;
			// mov rax,[rbp+548h]
			RAX -= R11;
			RAX = 0; // Special case
			RAX = _rotl64(RAX, 0x10);
			RAX ^= RBX;
			RAX = (~RAX);
			if (utils::is_bad_ptr((void*)(RAX + 0x7))) return 0xFFFFFFFFFFFFFFFF; RAX = *(uint64_t*)(RAX + 0x7);
			RBP = 0xF576785D800788E7;
			RAX *= RBP;
			RDX *= RAX;
			RAX = 0x8F4398D915A97A5B;
			RDX ^= RAX;
			RCX = R8;
			RCX = (~RCX);
			RCX += RDI;
			RAX = RDX;
			RDX = 0x7C9C5BC8A93F8CFD;
			RAX *= RDX;
			RDX = RCX;
			RDX ^= RAX;
			return RDX;
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
		RAX = 0x406BA42925D2B4C9;
		R11 = global::module_base;
		RAX = _umul128(RAX, RCX, &RDX);
		RAX = RCX;
		R10 = 0xBCF77712AF37F609;
		RAX -= RDX;
		RAX >>= 0x1;
		RAX += RDX;
		RAX >>= 0xC;
		RAX = RAX * 0x1991;
		RCX -= RAX;
		RAX = 0xAC064CBB0F59AFE9;
		R8 = RCX * 0x1991;
		RAX = _umul128(RAX, R8, &RDX);
		RDX >>= 0xD;
		RAX = RDX * 0x2F9F;
		R8 -= RAX;
		RAX = 0x2D82D82D82D82D83;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = 0xE2C4A6886A4C2E1;
		RDX >>= 0x3;
		RCX = RDX * 0x2D;
		RAX = _umul128(RAX, R8, &RDX);
		RDX >>= 0x4;
		RCX += RDX;
		RAX = RCX * 0x242;
		RCX = R8 * 0x244;
		RCX -= RAX;
		RAX = *(uint16_t*)(RCX + R11 + 0x694FEE0);
		R8 = RAX * 0x13C8;
		RAX = R10;
		RAX = _umul128(RAX, R8, &RDX);
		RAX = R10;
		RDX >>= 0xC;
		RCX = RDX * 0x15AD;
		R8 -= RCX;
		R9 = R8 * 0x24D8;
		RAX = _umul128(RAX, R9, &RDX);
		RDX >>= 0xC;
		RAX = RDX * 0x15AD;
		R9 -= RAX;
		RAX = 0x1B7D6C3DDA338B2B;
		RAX = _umul128(RAX, R9, &RDX);
		RAX = 0x4EC4EC4EC4EC4EC5;
		RDX >>= 0x6;
		RCX = RDX * 0x254;
		RAX = _umul128(RAX, R9, &RDX);
		RDX >>= 0x2;
		RCX += RDX;
		RAX = RCX * 0x1A;
		RCX = R9 * 0x1C;
		RCX -= RAX;
		RSI = *(uint16_t*)(RCX + R11 + 0x6956480);
		return RSI;
	}
 
}
