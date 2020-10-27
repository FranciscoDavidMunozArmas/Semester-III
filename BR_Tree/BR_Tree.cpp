#include <iostream>

#include "BR_Tree.h"

#include "BR_Node.cpp"

#include "Libraries/Screen.cpp"

using namespace std;

template<class T>
BR_Tree<T>::BR_Tree() {
	this->_root = NULL;
}

template<class T>
void BR_Tree<T>::_add(T _data) {
	if (this->_is_empty()) {
		this->_root = new BR_Node<T>(_data, NULL, NULL, NULL, BR_COLOR::BLACK);
	}
	else {
		_add(this->_root, _data);
	}
}

template<class T>
void BR_Tree<T>::_add(BR_Node<T>* _node, T _data) {
	if (_data < _node->get_data()) {
		if (_node->get_left_node() == NULL) {
			BR_Node<T>* _data_node = new BR_Node<T>(_data, NULL, NULL, _node, BR_COLOR::RED);
			_node->set_left_node(_data_node);
			_update_balance(_data_node, true, false);
		}
		else {
			_add(_node->get_left_node(), _data);
		}
	}
	else {
		if (_node->get_right_node() == NULL) {
			BR_Node<T>* _data_node = new BR_Node<T>(_data, NULL, NULL, _node, BR_COLOR::RED);
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
void BR_Tree<T>::_delete(R _data) {
	if (!this->_is_empty()) {
		_delete(this->_root, _data);
	}
}

template<class T>
template<typename R>
void BR_Tree<T>::_delete(BR_Node<T>* _node, R _data) {
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
void BR_Tree<T>::_remove_node(BR_Node<T>* _node) {
	if (_node->get_left_node() != NULL && _node->get_right_node() != NULL) {
		BR_Node<T>* _aux = _min_node(_node->get_left_node());
		_node->set_data(_aux->get_data());
		_remove_node(_aux);
	}
	else if (_node->get_left_node() != NULL && _node->get_right_node() == NULL) {
		BR_Node<T>* _aux = _node->get_left_node();
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
		BR_Node<T>* _aux = _node->get_right_node();
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
		BR_Node<T>* _aux = _node->get_parent_node();
		delete _node;
		_update_balance(this->_min_node(_aux), false, false);
		return;
	}
}

template<class T>
BR_Node<T>* BR_Tree<T>::_min_node(BR_Node<T>* _node) {
	if (_node == NULL) {
		return NULL;
	}
	if (_node->get_right_node() != NULL) {
		return _min_node(_node->get_right_node());
	}
	else {
		return _node;
	}
}

template<class T>
void BR_Tree<T>::_update_balance(BR_Node<T>* _node, bool _added, bool _flag) {
	if (_node == NULL) {
		return;
	}
	if (_added) {
		_add_case_1(_node);
	}
}

template<class T>
void BR_Tree<T>::_add_case_1(BR_Node<T>* _node) {
	if (_node->get_parent_node() == NULL) {
		_node->set_color(BR_COLOR::BLACK);
		return;
	}
	else {
		_add_case_2(_node);
	}
}

template<class T>
void BR_Tree<T>::_add_case_2(BR_Node<T>* _node) {
	if (_node->get_parent_node()->get_color() == BR_COLOR::BLACK) {
		return;
	}
	else {
		_add_case_3(_node);
	}
}

template<class T>
void BR_Tree<T>::_add_case_3(BR_Node<T>* _node) {
	if ((_node->get_parent_node()->get_parent_node()->get_left_node() != NULL && _node->get_parent_node()->get_parent_node()->get_right_node() != NULL) && (_node->get_parent_node()->get_parent_node()->get_left_node()->get_color() == BR_COLOR::RED && _node->get_parent_node()->get_parent_node()->get_right_node()->get_color() == BR_COLOR::RED)) {
		_node->get_parent_node()->get_parent_node()->get_left_node()->set_color(BR_COLOR::BLACK);
		_node->get_parent_node()->get_parent_node()->get_right_node()->set_color(BR_COLOR::BLACK);
		_node->get_parent_node()->get_parent_node()->set_color(BR_COLOR::RED);
		this->_add_case_1(_node->get_parent_node()->get_parent_node());
	}
	else {
		_add_case_4(_node);
	}
}

template<class T>
void BR_Tree<T>::_add_case_4(BR_Node<T>* _node) {
	if (_node->get_parent_node()->get_right_node() == _node && _node->get_parent_node()->get_parent_node()->get_left_node() == _node->get_parent_node()) {
		this->_rot_left(_node->get_parent_node());
		_node = _node->get_left_node();
	}
	else if (_node->get_parent_node()->get_left_node() == _node && _node->get_parent_node()->get_parent_node()->get_right_node() == _node->get_parent_node()) {
		this->_rot_right(_node->get_parent_node());
		_node = _node->get_right_node();
	}
	_add_case_5(_node);
}

template<class T>
void BR_Tree<T>::_add_case_5(BR_Node<T>* _node) {
	_node->get_parent_node()->set_color(BR_COLOR::BLACK);
	_node->get_parent_node()->get_parent_node()->set_color(BR_COLOR::RED);
	if (_node->get_parent_node()->get_left_node() == _node && _node->get_parent_node()->get_parent_node()->get_left_node() == _node->get_parent_node()){
		this->_rot_right(_node->get_parent_node()->get_parent_node());
	}
	else {
		this->_rot_left(_node->get_parent_node()->get_parent_node());
	}
}

template<class T>
void BR_Tree<T>::_delete_case_1(BR_Node<T>* _node) {
	if (_node->get_parent_node() != NULL) {
		_delete_case_2(_node);
	}
}

template<class T>
void BR_Tree<T>::_delete_case_2(BR_Node<T>* _node) {
	BR_Node<T>* _brother_node;
	if (_node->get_parent_node()->get_left_node() == _node) {
		_brother_node = _node->get_parent_node()->get_right_node();
	}
	else {
		_brother_node = _node->get_parent_node()->get_left_node();
	}

	if (_brother_node->get_color() == BR_COLOR::RED) {
		_node->get_parent_node()->set_color(BR_COLOR::RED);
		_brother_node->set_color(BR_COLOR::BLACK);
		if (_node->get_parent_node()->get_left_node() == _node) {
			this->_rot_left(_node->get_parent_node());
		}
		else {
			this->_rot_right(_node->get_parent_node());
		}
	}
	_delete_case_3(_node);
}


template<class T>
void BR_Tree<T>::_delete_case_3(BR_Node<T>* _node) {
	BR_Node<T>* _brother_node;
	if (_node->get_parent_node()->get_left_node() == _node) {
		_brother_node = _node->get_parent_node()->get_right_node();
	}
	else {
		_brother_node = _node->get_parent_node()->get_left_node();
	}

	if (_node->get_parent_node()->get_color() == BR_COLOR::BLACK 
		&& _brother_node->get_color() == BR_COLOR::BLACK
		&& _brother_node->get_left_node()->get_color() == BR_COLOR::BLACK
		&& _brother_node->get_right_node()->get_color() == BR_COLOR::BLACK) {
		_brother_node->set_color(BR_COLOR::RED);
		this->_delete_case_1(_node->get_parent_node());
	}
	else {
		if (_node->get_parent_node()->get_color() == BR_COLOR::RED
			&& _brother_node->get_color() == BR_COLOR::BLACK
			&& _brother_node->get_left_node()->get_color() == BR_COLOR::BLACK
			&& _brother_node->get_right_node()->get_color() == BR_COLOR::BLACK) {
			_brother_node->set_color(BR_COLOR::RED);
			_node->get_parent_node()->set_color(BR_COLOR::BLACK);
		}
		else {
			_delete_case_4(_node);
		}
	}
}

template<class T>
void BR_Tree<T>::_delete_case_4(BR_Node<T>* _node) {
	BR_Node<T>* _brother_node;
	if (_node->get_parent_node()->get_left_node() == _node) {
		_brother_node = _node->get_parent_node()->get_right_node();
	}
	else {
		_brother_node = _node->get_parent_node()->get_left_node();
	}

	if (_node->get_parent_node()->get_left_node() == _node
		&& _brother_node->get_color() == BR_COLOR::BLACK
		&& _brother_node->get_left_node()->get_color() == BR_COLOR::RED
		&& _brother_node->get_right_node()->get_color() == BR_COLOR::BLACK) {
		_brother_node->set_color(BR_COLOR::RED);
		_brother_node->get_left_node()->set_color(BR_COLOR::BLACK);
		this->_rot_right(_brother_node);
	}
	else if (_node->get_parent_node()->get_right_node() == _node
		&& _brother_node->get_color() == BR_COLOR::BLACK
		&& _brother_node->get_left_node()->get_color() == BR_COLOR::BLACK
		&& _brother_node->get_right_node()->get_color() == BR_COLOR::RED) {
		_brother_node->set_color(BR_COLOR::RED);
		_brother_node->get_right_node()->set_color(BR_COLOR::BLACK);
		this->_rot_left(_brother_node);
	}

	_delete_case_5(_node);
}

template<class T>
void BR_Tree<T>::_delete_case_5(BR_Node<T>* _node) {
	BR_Node<T>* _brother_node;
	if (_node->get_parent_node()->get_left_node() == _node) {
		_brother_node = _node->get_parent_node()->get_right_node();
	}
	else {
		_brother_node = _node->get_parent_node()->get_left_node();
	}

	_brother_node->set_color(_node->get_parent_node()->get_color());
	_node->get_parent_node()->set_color(BR_COLOR::BLACK);
	if (_node->get_parent_node()->get_left_node() == _node) {
		_node->get_parent_node()->get_right_node()->get_right_node()->set_color(BR_COLOR::BLACK);
		this->_rot_left(_node->get_parent_node());
	}
	else {
		_node->get_parent_node()->get_left_node()->get_left_node()->set_color(BR_COLOR::BLACK);
		this->_rot_right(_node->get_parent_node());
	}
}

template<class T>
int BR_Tree<T>::_height(BR_Node<T>* _node, int _right, int _left) {
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
void BR_Tree<T>::_rot_right(BR_Node<T>* _node) {

	BR_Node<T>* _new_sub_root = _node->get_left_node();
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
void BR_Tree<T>::_rot_left(BR_Node<T>* _node) {

	BR_Node<T>* _new_sub_root = _node->get_right_node();
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
T* BR_Tree<T>::_look(R _data){
    return NULL;
}

template<class T>
template<typename R>
T* BR_Tree<T>::_look(BR_Node<T>* _node, R _data){
    return NULL;
}

template<class T>
bool BR_Tree<T>::_is_empty() {
	return (this->_root == NULL)? true:false;
}

template<class T>
BR_Node<T>* BR_Tree<T>::_get_root() {
	return this->_root;
}

template<class T>
void BR_Tree<T>::_print() {
	_print(this->_root, 0);
	_screen.color_text(_screen.WHITE);
}

template<class T>
void BR_Tree<T>::_print(BR_Node<T>* _node, int _count) {
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
		switch (_node->get_color())
		{
		case BR_COLOR::BLACK:
			_screen.color_text(_screen.WHITE);
			break;
		case BR_COLOR::RED:
			_screen.color_text(_screen.RED);
			break;
		}
		cout << _node->get_data() << endl;
		_print(_node->get_left_node(), _count + 1);
	}
}

template<class T>
string BR_Tree<T>::to_string(){
    return "";
}

template<class T>
BR_Tree<T>::~BR_Tree() {}
