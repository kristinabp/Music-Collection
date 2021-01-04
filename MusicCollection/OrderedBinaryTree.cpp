#include "OrderedBinaryTree.h"

OrderedBinaryTree:: Node* OrderedBinaryTree::insertHelper(Node*& node, Song* element)
{
	if (node == nullptr)
	{
		return new Node{ element, nullptr, nullptr };
	}
	else if (element->getName() < node->data->getName())
	{
		node->left = insertHelper(node->left, element);
	}
	else if (element->getName() >= node->data->getName())
	{
		node->right = insertHelper(node->right, element);
	}

	return node;
}

bool OrderedBinaryTree::containsHelper(Node* node, Song* element) const
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->data == element)
	{
		return true;
	}
	return containsHelper(node->left, element) || containsHelper(node->right, element);
}

void OrderedBinaryTree::removeHelper(Node*& node, Song* element)
{
	if (node == nullptr)
	{
		return;
	}

	if (element->getName() < node->data->getName())
	{
		return removeHelper(node->left, element);
	}

	if (element->getName() > node->data->getName())
	{
		return removeHelper(node->right, element);
	}

	if (element->getName() == node->data->getName())
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			Node* save = node;
			node = nullptr;
			delete save;
			return;
		}

		if (node->left == nullptr)
		{
			Node* save = node;
			node = node->left;
			delete save;
			return;
		}

		if (node->right == nullptr)
		{
			Node* save = node;
			node = node->right;
			delete save;
			return;
		}

		Song* minElement = getMinElement(node->right);
		node->data = minElement;

		removeHelper(node->right, minElement);
	}
}

Song* OrderedBinaryTree::getMinElement(Node* node)
{
	while (node->left != nullptr)
	{
		node = node->left;
	}

	return node->data;
}

void OrderedBinaryTree::eraseHelper(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	eraseHelper(node->left);
	eraseHelper(node->right);
	delete node;
}

void OrderedBinaryTree::printHelper(Node* root) const
{
	if (root == nullptr) return;
	printHelper(root->left);
	root->data->print();
	printHelper(root->right);
}

OrderedBinaryTree::OrderedBinaryTree() : root(nullptr), size(0)
{
}

OrderedBinaryTree& OrderedBinaryTree::insert(Song* element)
{
	if (contains(element))
		return *this;
	root = insertHelper(root, element);
	size++;
	return *this;
}

bool OrderedBinaryTree::contains(Song* element) const
{
	return containsHelper(root, element);
}

void OrderedBinaryTree::remove(Song* element)
{
	return removeHelper(root, element);
}

int OrderedBinaryTree::sizee() const
{
	return size;
}

void OrderedBinaryTree::print() const
{
	printHelper(root);
}

OrderedBinaryTree::~OrderedBinaryTree()
{
	eraseHelper(root);
}
