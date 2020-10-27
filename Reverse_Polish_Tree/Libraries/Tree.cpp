#include "Tree.h"

/**
 * @brief Tree
 * @tparam T 
*/
template<typename T>
Tree<T>::Tree() {
	this->_root = NULL;
}

/**
 * @brief _is_empty
 * @tparam T 
 * @return bool
*/
template<typename T>
bool Tree<T>::_is_empty() {
	return (this->_root == NULL) ? true : false;
}

/**
 * @brief ~Tree
 * @tparam T 
*/
template<typename T>
Tree<T>::~Tree() {
	this->_root = NULL;
}
