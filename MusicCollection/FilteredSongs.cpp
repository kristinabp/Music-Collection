#include "FilteredSongs.h"
#include <iomanip>

void FilteredSongs::printHelper(Node* node, int spaces) const
{
	if (node != nullptr) {
		if (node->right) {
			printHelper(node->right, spaces + 4);
		}
		if (spaces) {
			std::cout << std::setw(spaces) << ' ';
		}
		if (node->right) std::cout << " /\n" << std::setw(spaces) << ' ';
		std::cout << node->data->getName() << "\n ";
		if (node->left) {
			std::cout << std::setw(spaces) << ' ' << " \\\n";
			printHelper(node->left, spaces + 4);
		}
	}
}

void FilteredSongs::printtHelper(Node* root) const
{
	if (root == nullptr) return;
	printtHelper(root->left);
	std::cout << root->data->getName() << '\n';
	printtHelper(root->right);
}

bool FilteredSongs::containsHelper(Node* node, Song* element) const
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

void FilteredSongs::removeHelper(Node*& node,Song* element)
{
	if (node == nullptr)
	{
		return;
	}

	if (element < node->data)
	{
		return removeHelper(node->left, element);
	}

	if (element > node->data)
	{
		return removeHelper(node->right, element);
	}

	if (element == node->data)
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

size_t FilteredSongs::calculateHeightHelper(Node* node) const
{
	if (node == nullptr)
	{
		return 0;
	}

	return 1 + std::max(calculateHeightHelper(node->left), calculateHeightHelper(node->right));
}

Song* FilteredSongs::getMinElement(Node* node)
{
	while (node->left != nullptr)
	{
		node = node->left;
	}

	return node->data;
}

void FilteredSongs::eraseHelper(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	eraseHelper(node->left);
	eraseHelper(node->right);
	delete node;
}

int FilteredSongs::getSubtreeDifference(Node* node) const
{
	int leftHeight = calculateHeightHelper(node->left);
	int rightHeight = calculateHeightHelper(node->right);

	return leftHeight - rightHeight;
}

FilteredSongs::Node* FilteredSongs::leftRotation(Node* node)
{
	Node* temp = node->right;
	node->right = nullptr;
	temp->left = node;

	return temp;
}

FilteredSongs::Node*  FilteredSongs::rightRotation(Node* node)
{
	Node* temp = node->left;
	node->left = nullptr;
	temp->right = node;

	return temp;
}

FilteredSongs::Node* FilteredSongs::leftRightRotation(Node* node)
{
	Node* temp = node->left;
	node->left = leftRotation(temp);

	return rightRotation(node);
}

FilteredSongs::Node* FilteredSongs::rightLeftRotation(Node* node)
{
	Node* temp = node->right;
	node->right = rightRotation(temp);

	return leftRotation(node);
}

FilteredSongs::Node*& FilteredSongs::balance(Node*& node)
{
	int balanceFactor = getSubtreeDifference(node);
	if (balanceFactor > 1)
	{
		if (getSubtreeDifference(node->left) > 0)
		{
			node = rightRotation(node);
		}
		else
		{
			node = leftRightRotation(node);
		}
	}
	else if (balanceFactor < -1)
	{
		if (getSubtreeDifference(node->right) > 0)
		{
			node = rightLeftRotation(node);
		}
		else
		{
			node = leftRotation(node);
		}
	}
	return node;
}

FilteredSongs::Node* FilteredSongs::insertHelper(Node*& node, Song* element)
{
	if (node == nullptr)
	{
		return new Node{ element, nullptr, nullptr };
	}
	else if (element->getName() < node->data->getName())
	{
		node->left = insertHelper(node->left, element);
		node = balance(node);
	}
	else if (element->getName() >= node->data->getName())
	{
		node->right = insertHelper(node->right, element);
		node = balance(node);
	}

	return node;
}

FilteredSongs::FilteredSongs(): root(nullptr)
{
}

FilteredSongs& FilteredSongs::insert(Song* element)
{
	root = insertHelper(root, element);
	return *this;
}

void FilteredSongs::prettyPrint() const
{
	printHelper(root);
}

bool FilteredSongs::contains(Song* element) const
{
	return containsHelper(root, element);
}

void FilteredSongs::remove(Song* element)
{
	return removeHelper(root, element);
}

void FilteredSongs::print() const
{
	printtHelper(root);
}

FilteredSongs::~FilteredSongs()
{
	eraseHelper(root);
}
