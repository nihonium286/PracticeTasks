#include "vector.h"

using namespace ctl;

template<typename T>
Vector<T>::Vector(const size_t& size) :
	m_size(size)
{
	m_pBegin = new T[m_size];
	m_pEnd = m_pBegin + m_size;
	for (T* it = m_pBegin; it != m_pEnd; ++it) {
		*it = 0;
	}
}

template<typename T>
Vector<T>::Vector() :
	m_pBegin(0),
	m_pEnd(0),
	m_size(0) 
{
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	Vector<T> v;
	v.m_pBegin = other.m_pBegin;
	v.m_pEnd = other.m_pEnd;
	v.m_size = other.m_size;

	return v;
}

template<typename T>
void Vector<T>::assign(size_t count, const T& value) {
	m_size = count;
	m_pBegin = new T[m_size];
	m_pEnd = m_pBegin + m_size;
	for (T* it = m_pBegin; it != m_pEnd; ++it) {
		*it = value;
	}
}

template<typename T>
Vector<T>::~Vector()
{
	delete m_pBegin;
}

template<typename T>
T& Vector<T>::front() {
	return *m_pBegin;
}

template<typename T>
T& Vector<T>::back() {
	return *(m_pEnd-1);
}

template<typename T>
size_t Vector<T>::size() const {
	return m_size;
}

template<typename T>
T* Vector<T>::data() const {
	return m_pBegin;
}

template<typename T>
void Vector<T>::push_back(const T& value){
	m_size++;
	T* new_begin = new T[m_size];
	T* temp = new_begin;

	for (T* it = m_pBegin; it != m_pEnd; ++it) {
		*temp = *it;
		temp++;
	}
	*temp = value;
	m_pBegin = new_begin;
	m_pEnd = temp + 1;

}

template<typename T> 
void Vector<T>::pop_back() {
	m_size--;
	m_pEnd--;
}

template<typename T>
T* Vector<T>::begin() {
	return m_pBegin;
}

template<typename T>
T* Vector<T>::end() {
	return m_pEnd;
}

template<typename T>
T& Vector<T>::operator[](const size_t& pos) {
	if (pos > m_size - 1) {
		std::out_of_range ex("element out of range");
		throw ex;
	}
	return *(m_pBegin + pos);
}

template<typename T>
T& Vector<T>::at(const size_t& pos) {
	if (pos > m_size - 1) {
		std::out_of_range ex("element out of range");
		throw ex;
	}
	return *(m_pBegin + pos);
}

template<typename T>
bool Vector<T>::empty() const {
	return m_pBegin == m_pEnd;
}