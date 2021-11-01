#pragma once

#ifdef min
	#undef min
#endif
#ifdef max
	#undef max
#endif

namespace ctl
{
	template <typename T>
	void swap(T& first, T& second) {
		T temp = first;
		first = second;
		second = temp;
	}

	template <typename It>
	It min(It first, It last) {
		It min_v = first;
		for (It it = first; it != last; ++it) {
			min_v = *min_v < *it ? min_v : it;
		}
		return min_v;
	}

	template <typename It>
	It max(It first, It last) {
		It max_v = first;
		for (It it = first; it != last; ++it) {
			max_v = *max_v >= *it ? max_v : it;
		}
		return max_v;
	}


	template <typename It>
	pair<It,It> minmax(It first, It last) { // TODO: pair type template
		It min_v = first;
		It max_v = first;
		for (It it = first; it != last; ++it) {
			min_v = *min_v < *it ? min_v : it;
			max_v = *max_v >= *it ? max_v : it;
		}
		return make_pair(min_v, max_v);
	}

	template <typename It>
	void selectionSort(It first, It last) {
		for (It it = first; it != last; ++it) {
			auto min_el = min(it, last);
			swap(*it, *min_el);
		}
	}
}
