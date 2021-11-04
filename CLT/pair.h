#pragma once

namespace ctl
{
	template<typename T1, typename T2>
	struct Pair {
		Pair();

		Pair(const T1& x, const T2& y);

		template<class U1, class U2>
		Pair(U1&& x, U2&& y);

		template<class U1, class U2>
		Pair(Pair<U1, U2>&& p);


		T1 first;
		T2 second;
	};

	template<typename T1, typename T2>
	Pair<T1, T2>::Pair() :
		first(),
		second() {
	}

	template<typename T1, typename T2>
	Pair<T1, T2>::Pair(const T1& x, const T2& y) :
		first(x),
		second(y) {
	}

	template<typename T1, typename T2>
	template<class U1, class U2>
	Pair<T1, T2>::Pair(U1&& x, U2&& y) :
		first(x),
		second(y) {
	}

	template<typename T1, typename T2>
	template<class U1, class U2 >
	Pair<T1, T2>::Pair(Pair<U1, U2>&& p) :
		first(p.first),
		second(p.second) {
	}


}