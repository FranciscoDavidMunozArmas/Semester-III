#include <iostream>

#include "AVL_Tree.h"

#include "AVL_Node.cpp"

using namespace std;

template<class T>
AVL_Tree<T>::AVL_Tree() {
	this->_root = NULL;
}

template<class T>
void AVL_Tree<T>::_add(T _data) {
	if (this->_is_empty()) {
		this->_root = new AVL_Node<T>(_data, NULL, NULL, NULL);
	}
	else {
		_add(this->_root, _data);
	}
}

template<class T>
void AVL_Tree<T>::_add(AVL_Node<T>* _node, T _data) {
	if (_data < _node->get_data()) {
		if (_node->get_left_node() == NULL) {
			AVL_Node<T>* _data_node = new AVL_Node<T>(_data, NULL, NULL, _node);
			_node->set_left_node(_data_node);
			_update_balance(_data_node, true, false);
		}
		else {
			_add(_node->get_left_node(), _data);
		}
	}
	else {
		if (_node->get_right_node() == NULL) {
			AVL_Node<T>* _data_node = new AVL_Node<T>(_data, NULL, NULL, _node);
			_node->set_right_node(_data_node);
			_update_balance(_data_node, true, false);
		}
		else {
			_add(_node->get_right_node(), _data);
		}
	}
}

template<class T>
template<typename R>
void AVL_Tree<T>::_delete(R _data) {
	if (!this->_is_empty()) {
		_delete(this->_root, _data);
	}
}

template<class T>
template<typename R>
void AVL_Tree<T>::_delete(AVL_Node<T>* _node, R _data) {
	if (_node == NULL) {
		return;
	}
	else if (_data < _node->get_data()) {
		_delete(_node->get_left_node(), _data);
	}
	else if (_data > _node->get_data()) {
		_delete(_node->get_right_node(), _data);
	}
	else {
		_remove_node(_node);
	}
}

template<class T>
void AVL_Tree<T>::_remove_node(AVL_Node<T>* _node) {
	if (_node->get_left_node() != NULL && _node->get_right_node() != NULL) {
		AVL_Node<T>* _aux = _min_node(_node->get_left_node());
		_node->set_data(_aux->get_data());
		_remove_node(_aux);
	}
	else if (_node->get_left_node() != NULL && _node->get_right_node() == NULL) {
		AVL_Node<T>* _aux = _node->get_left_node();
		_node->set_data(_aux->get_data());
		_node->set_left_node(_aux->get_left_node());
		if (_aux->get_left_node() != NULL) {
			_aux->get_left_node()->set_parent_node(_node);
		}
		_node->set_right_node(_aux->get_right_node());
		if (_aux->get_right_node() != NULL) {
			_aux->get_right_node()->set_parent_node(_node);
		}
		delete _aux;
		_update_balance(this->_min_node(_node), false, false);
		return;
	}
	else if (_node->get_left_node() == NULL && _node->get_right_node() != NULL) {
		AVL_Node<T>* _aux = _node->get_right_node();
		_node->set_data(_aux->get_data());
		_node->set_left_node(_aux->get_left_node());
		if (_aux->get_left_node() != NULL) {
			_aux->get_left_node()->set_parent_node(_node);
		}
		_node->set_right_node(_aux->get_right_node());
		if (_aux->get_right_node() != NULL) {
			_aux->get_right_node()->set_parent_node(_node);
		}
		delete _aux;
		_update_balance(this->_min_node(_node), false, false);
		return;
	}
	else {
		if (_node == this->_root) {
			this->_root = NULL;
			delete _node;
			return;
		}
		else if (_node->get_parent_node()->get_right_node() == _node) {
			_node->get_parent_node()->set_right_node(NULL);
		}
		else if (_node->get_parent_node()->get_left_node() == _node) {
			_node->get_parent_node()->set_left_node(NULL);
		}
		AVL_Node<T>* _aux = _node->get_parent_node();
		delete _node;
		_update_balance(this->_min_node(_aux), false, false);
		return;
	}
}

template<class T>
AVL_Node<T>* AVL_Tree<T>::_min_node(AVL_Node<T>* _node) {
	if (_node == NULL) {
		return NULL;
	}
	if (_node->get_right_node() != NULL) {
		return (_node->get_right_node());
	}
	else {
		return _node;
	}
}

template<class T>
void AVL_Tree<T>::_update_balance(AVL_Node<T>* _node, bool _added, bool _flag) {
	if (_node == NULL) {
		return;
	}
	if (this->_height(_node->get_right_node(), 0, 0) - this->_height(_node->get_left_node(), 0, 0) == -2) {
		//Rotate Right
		if (this->_height(_node->get_left_node()->get_right_node(), 0, 0) - this->_height(_node->get_left_node()->get_left_node(), 0, 0) == 1) {
			this->_rot_left(_node->get_left_node());
			this->_rot_right(_node);
		}
		else {
			this->_rot_right(_node);
		}
	}
	else if (this->_height(_node->get_right_node(), 0, 0) - this->_height(_node->get_left_node(), 0, 0) == 2) {
		//Rotate Left
		if (this->_height(_node->get_right_node()->get_right_node(), 0, 0) - this->_height(_node->get_right_node()->get_left_node(), 0, 0) == -1) {
			this->_rot_right(_node->get_right_node());
			this->_rot_left(_node);
		}
		else {
			this->_rot_left(_node);
		}
	}
	_update_balance(_node->get_parent_node(), _added, _flag);
}

template<class T>
int AVL_Tree<T>::_height(AVL_Node<T>* _node, int _right, int _left) {
	if (_node == NULL) {
		return 0;
	}
	_left = _height(_node->get_left_node(), 0, 0);
	_right = _height(_node->get_right_node(), 0 , 0);
	if (_left > _right) {
		return _left + 1;
	}
	else {
		return _right + 1;
	}
}

template<class T>
void AVL_Tree<T>::_rot_right(AVL_Node<T>* _node) {

	AVL_Node<T>* _new_sub_root = _node->get_left_node();
	_node->set_left_node(_new_sub_root->get_right_node());
	if (_new_sub_root->get_right_node() != NULL) {
		_new_sub_root->get_right_node()->set_parent_node(_node);
	}
	_new_sub_root->set_parent_node(_node->get_parent_node());
	if (_node == this->_root) {
		this->_root = _new_sub_root;
	}
	else {
		if (_node->get_parent_node()->get_right_node() == _node) {
			_node->get_parent_node()->set_right_node(_new_sub_root);
		}
		else {
			_node->get_parent_node()->set_left_node(_new_sub_root);
		}
	}
	_new_sub_root->set_right_node(_node);
	_node->set_parent_node(_new_sub_root);
}

template<class T>
void AVL_Tree<T>::_rot_left(AVL_Node<T>* _node) {

	AVL_Node<T>* _new_sub_root = _node->get_right_node();
	_node->set_right_node(_new_sub_root->get_left_node());
	if (_new_sub_root->get_left_node() != NULL) {
		_new_sub_root->get_left_node()->set_parent_node(_node);
	}
	_new_sub_root->set_parent_node(_node->get_parent_node());
	if (this->_root == _node) {
		this->_root = _new_sub_root;
	}
	else {
		if (_new_sub_root->get_parent_node()->get_left_node() == _node) {
			_new_sub_root->get_parent_node()->set_left_node(_new_sub_root);
		}
		else {
			_new_sub_root->get_parent_node()->set_right_node(_new_sub_root);
		}
	}
	_new_sub_root->set_left_node(_node);
	_node->set_parent_node(_new_sub_root);
}

template<class T>
template<typename R>
T* AVL_Tree<T>::_look(R _data){
    return NULL;
}

template<class T>
template<typename R>
T* AVL_Tree<T>::_look(AVL_Node<T>* _node, R _data){
    return NULL;
}

template<class T>
bool AVL_Tree<T>::_is_empty() {
	return (this->_root == NULL)? true:false;
}

template<class T>
AVL_Node<T>* AVL_Tree<T>::_get_root() {
	return this->_root;
}

template<class T>
void AVL_Tree<T>::_print() {
	_print(this->_root, 0);
}

template<class T>
void AVL_Tree<T>::_print(AVL_Node<T>* _node, int _count) {
	if (this->_is_empty()) {
		cout << "Arbol Vacio" << endl;
		return;
	}
	if (_node == NULL) {
		return;
	}
	else {
		_print(_node->get_right_node(), _count + 1);
		for (int i = 0; i < _count; i++) {
			cout << " ";
		}
		cout << _node->get_data() << endl;
		_print(_node->get_left_node(), _count + 1);
	}
}

template<class T>
string AVL_Tree<T>::to_string(){
    return "";
}

template<class T>
AVL_Tree<T>::~AVL_Tree() {}
