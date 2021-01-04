#ifndef ORDEREDBINARYTREE_H
#define ORDEREDBINARYTREE_H

#include "Song.h"

class OrderedBinaryTree
{
private:
	struct Node
	{
		Song* data;
		Node* left, * right;
	};
	Node* root;
	int size;

	Node* insertHelper(Node*& node, Song* element);
	bool containsHelper(Node* node, Song* element) const;
	void removeHelper(Node*& node, Song* element);
	Song* getMinElement(Node* node);
	void eraseHelper(Node* node);
	void printHelper(Node* root)const;

public:
		OrderedBinaryTree();
		OrderedBinaryTree& insert(Song* element);
		bool contains(Song* element) const;
		void remove(Song* element);
		int sizee()const;

		void print()const;
		~OrderedBinaryTree();

};

#endif // !ORDEREDBINARYTREE_H