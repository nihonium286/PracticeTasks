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
Vector<T>::Vector():
	m_pBegin(0),
	m_pEnd(0)
{
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
T* Vector<T>::begin() {
	return m_pBegin;
}

template<typename T>
T* Vector<T>::end() {
	return m_pEnd;
}

template<typename T>
T& Vector<T>::operator[](const size_t& pos) {
	return *(m_pBegin + pos);
}