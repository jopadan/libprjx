#pragma once

#include "scalar.hpp"

namespace prjx::math::vec
{
	template<typename T, size_t N, enum align A = align::adaptive, size_t N_POW2 = std::bit_ceil<size_t>(N)>
	struct __attribute__((aligned(N==N_POW2 && A != align::scalar || A == align::vector ? alignof(T) * N_POW2 : alignof(T)))) type : std::array<T, N>
	{
		inline constexpr T& x() requires(N > 0) { return (*this)[0]; }
		inline constexpr T& y() requires(N > 1) { return (*this)[1]; }
		inline constexpr T& z() requires(N > 2) { return (*this)[2]; }
		inline constexpr T& w() requires(N > 3) { return (*this)[3]; }
	};

	template<size_t N, enum align A = align::adaptive>
	using i8  = type<i8 , N, A>;
	template<size_t N, enum align A = align::adaptive>
	using i16 = type<i16, N, A>;
	template<size_t N, enum align A = align::adaptive>
	using i32 = type<i32, N, A>;
	template<size_t N, enum align A = align::adaptive>
	using i64 = type<i64, N, A>;

	template<size_t N, enum align A = align::adaptive>
	using u8  = type<u8 , N, A>;
	template<size_t N, enum align A = align::adaptive>
	using u16 = type<u16, N, A>;
	template<size_t N, enum align A = align::adaptive>
	using u32 = type<u32, N, A>;
	template<size_t N, enum align A = align::adaptive>
	using u64 = type<u64, N, A>;

	template<size_t N, enum align A = align::adaptive>
	using f32 = type<f32, N, A>;
	template<size_t N, enum align A = align::adaptive>
	using f64 = type<f64, N, A>;
};
