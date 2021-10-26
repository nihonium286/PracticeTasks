#pragma once
namespace ctl
{
	template<typename T>
	class Vector
	{
	public:
		Vector();
		Vector(const size_t&);
		~Vector();

		T& front();
		T& back();
		void push_back(const T&);
		size_t size() const;

		T* begin();
		T* end();

		T& operator[](const size_t&);

	private:
		T* m_pBegin;
		T* m_pEnd;
		size_t m_size;
	};

}
