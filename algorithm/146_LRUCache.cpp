#include <iostream>
#include <unordered_map>
#include <list>

/*
146. LRU缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。
当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

*/

using namespace std;

//自己实现的 list
class LRUCache {
	struct list_node
	{
		int m_key;
		int m_value;
		list_node* prev;
		list_node* next;
		list_node(int key, int value) : m_key(key), m_value(value), prev(nullptr), next(nullptr) {}
	};
	class LRUList
	{
	public:
		LRUList() : head(new list_node(0, 0)), tail(new list_node(0, 0))
		{
			head->next = tail;
			tail->prev = head;
		}
		void erase(list_node* node)
		{
			if (head->next == tail)
				return;
			list_node* prev_node = node->prev;
			list_node* next_node = node->next;
			prev_node->next = next_node;
			next_node->prev = prev_node;
		}
		void push_back(list_node* node)
		{
			node->prev = tail->prev;
			node->next = tail;
			tail->prev->next = node;
			tail->prev = node;
		}
		list_node* front() { return head->next; }
		void pop_front()
		{
			erase(head->next);
		}
		list_node* head;
		list_node* tail;
	};
public:
	LRUCache(int capacity) :
		m_capacity(capacity),
		m_size(0)
	{}

	int get(int key) {
		int result = -1;
		if (m_size!= 0 && m_map.find(key) != m_map.end())
		{
			list_node* node = m_map[key];
			result = node->m_value;
			m_list.erase(node);
			m_list.push_back(node);
		}

		return result;
	}

	void put(int key, int value) {
		if (m_capacity == 0)
			return;
		list_node* node;
		if (m_map.find(key) != m_map.end())
		{
			node = m_map[key];
			node->m_value = value;
			m_list.erase(node);
		}
		else
		{
			node = new list_node(key, value);
			m_map[key] = node;
			if (m_size == m_capacity)
			{
				list_node* front_node = m_list.front();
				m_list.pop_front();
				m_map.erase(front_node->m_key);
				delete front_node;
			}
			else
				m_size++;
		}
		m_list.push_back(node);
	}
private:
	LRUList m_list;
	unordered_map<int, list_node*> m_map;
	int m_capacity;
	int m_size;
};

//使用 stl 提供的list
class LRUCache1 {
public:
	typedef pair<int, int> list_node;

	LRUCache1(int capacity) :
		m_capacity(capacity),
		m_size(0)
	{}

	int get(int key) {
		int result = -1;
		if (m_size != 0 && m_map.find(key) != m_map.end())
		{
			auto i = m_map[key];
			list_node* node = *i;
			result = node->second;
			m_list.erase(i);
			m_list.push_back(node);
			i = m_list.end();
			m_map[key] = --i;
		}

		return result;
	}

	void put(int key, int value) {
		if (m_capacity == 0)
			return;
		list_node* node;
		if (m_map.find(key) != m_map.end())
		{
			auto i = m_map[key];
			node = *i;
			node->second = value;
			m_list.erase(i);
		}
		else
		{
			node = new list_node(key, value);
			if (m_size == m_capacity)
			{
				list_node* node = m_list.front();
				m_list.pop_front();
				m_map.erase(node->first);
				delete node;
			}
			else
				m_size++;
		}
		m_list.push_back(node);
		auto i = m_list.end();
		m_map[key] = --i;
	}
private:
	list<list_node*> m_list;
	unordered_map<int, list<list_node*>::iterator> m_map;
	int m_capacity;
	int m_size;
};