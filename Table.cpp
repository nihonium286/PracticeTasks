#include "test_runner.h"
#include <iostream>
#include <vector>
#include <map>

template<typename T>
class Table {
public:
	Table(size_t rows, size_t columns) {
		m_rows = rows;
		m_columns = columns;
		if (m_rows == 0 or m_columns == 0) {
			m_rows = m_columns = 0;
		}
		std::vector<std::vector<T>> table(m_rows, std::vector<T>(m_columns));
		m_table = table;
	}
	void Resize(size_t new_rows, size_t new_columns) {
		m_rows = new_rows;
		m_columns = new_columns;
		if (m_rows == 0 or m_columns == 0) {
			m_rows = m_columns = 0;
		}
		m_table.resize(m_rows);
		for (int i{}; i < m_rows; ++i) {
			m_table[i].resize(m_columns);
		}
	}
	std::pair<size_t, size_t> Size() const{
		return { m_rows, m_columns };
	}
	std::vector<T> operator [] (size_t i) const {
		return m_table[i];
	}
	std::vector<T>& operator [] (size_t i) {
		return m_table[i];
	}
private:
	size_t m_rows, m_columns;
	std::vector<std::vector<T>> m_table;
};

void TestTable() {
	Table<int> t(1, 1);
	ASSERT_EQUAL(t.Size().first, 1u);
	ASSERT_EQUAL(t.Size().second, 1u);
	t[0][0] = 42;
	ASSERT_EQUAL(t[0][0], 42);
	t.Resize(3, 4);
	ASSERT_EQUAL(t.Size().first, 3u);
	ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestTable);
	return 0;
}