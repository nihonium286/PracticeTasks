#pragma once
#include <stdexcept>

namespace ctl
{
	template<typename T>
	class Vector
	{
	public:
		Vector();
		Vector(const size_t&);
		~Vector();

		Vector& operator=(const Vector&);

		void assign(size_t, const T&);

		T& front();
		T& back();
		void push_back(const T&);
		void pop_back(); 
		size_t size() const;
		T* data() const;

		bool empty() const;

		T* begin();
		T* end();

		T& operator[](const size_t&);
		T& at(const size_t&);

	private:
		T* m_pBegin;
		T* m_pEnd;
		size_t m_size;
	};

}
