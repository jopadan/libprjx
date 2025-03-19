#pragma once

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <bit>
#include <array>

namespace prjx::math
{

using b8  = bool;
using c8  = char;
using c32 = char32_t;

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using f32 = float;
using f64 = double;

enum class align
{
	none     = 0 << 0,
	scalar   = 1 << 0,
	vector   = 1 << 1,
	matrix   = 1 << 2,
	adaptive = 1 << 3,
};

};
