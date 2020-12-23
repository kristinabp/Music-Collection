#include "AlphabeticalSortedSongs.h"
#include <iomanip>

void AlphabeticalSortedSongs::printHelper(Node* node, int spaces) const
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

void AlphabeticalSortedSongs::printtHelper(Node* root) const
{
	if (root == nullptr) return;
	printtHelper(root->left);
	std::cout << root->data->getName() << '\n';
	printtHelper(root->right);
}

bool AlphabeticalSortedSongs::containsHelper(Node* node, Song* element) const
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

void AlphabeticalSortedSongs::removeHelper(Node*& node,Song* element)
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

size_t AlphabeticalSortedSongs::calculateHeightHelper(Node* node) const
{
	if (node == nullptr)
	{
		return 0;
	}

	return 1 + std::max(calculateHeightHelper(node->left), calculateHeightHelper(node->right));
}

Song* AlphabeticalSortedSongs::getMinElement(Node* node)
{
	while (node->left != nullptr)
	{
		node = node->left;
	}

	return node->data;
}

void AlphabeticalSortedSongs::eraseHelper(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	eraseHelper(node->left);
	eraseHelper(node->right);
	delete node;
}

int AlphabeticalSortedSongs::getSubtreeDifference(Node* node) const
{
	int leftHeight = calculateHeightHelper(node->left);
	int rightHeight = calculateHeightHelper(node->right);

	return leftHeight - rightHeight;
}

AlphabeticalSortedSongs::Node* AlphabeticalSortedSongs::leftRotation(Node* node)
{
	Node* temp = node->right;
	node->right = nullptr;
	temp->left = node;

	return temp;
}

AlphabeticalSortedSongs::Node* AlphabeticalSortedSongs::rightRotation(Node* node)
{
	Node* temp = node->left;
	node->left = nullptr;
	temp->right = node;

	return temp;
}

AlphabeticalSortedSongs::Node* AlphabeticalSortedSongs::leftRightRotation(Node* node)
{
	Node* temp = node->left;
	node->left = leftRotation(temp);

	return rightRotation(node);
}

AlphabeticalSortedSongs::Node* AlphabeticalSortedSongs::rightLeftRotation(Node* node)
{
	Node* temp = node->right;
	node->right = rightRotation(temp);

	return leftRotation(node);
}

AlphabeticalSortedSongs::Node*& AlphabeticalSortedSongs::balance(Node*& node)
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

AlphabeticalSortedSongs::Node* AlphabeticalSortedSongs::insertHelper(Node*& node, Song* element)
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

void AlphabeticalSortedSongs::songHelper(Node*& node, std::vector<Song*>& s)
{   
	if (root == nullptr) return;
	songHelper(root->left,s);
	s->push_back(root->data->clone());
	songHelper(root->right,s);
}

AlphabeticalSortedSongs::AlphabeticalSortedSongs(): root(nullptr), size(0)
{
}

AlphabeticalSortedSongs& AlphabeticalSortedSongs::insert(Song* element)
{
	root = insertHelper(root, element);
	size++;
	return *this;
}

void AlphabeticalSortedSongs::prettyPrint() const
{
	printHelper(root);
}

bool AlphabeticalSortedSongs::contains(Song* element) const
{
	return containsHelper(root, element);
}

void AlphabeticalSortedSongs::remove(Song* element)
{
	return removeHelper(root, element);
}

int AlphabeticalSortedSongs::sizee() const
{
	return size;
}

std::vector<Song*> AlphabeticalSortedSongs::getSongs() 
{
	std::vector<Song*> songs;
	songHelper(root, songs);
	return songs;
}

void AlphabeticalSortedSongs::print() const
{
	printtHelper(root);
}

AlphabeticalSortedSongs::~AlphabeticalSortedSongs()
{
	eraseHelper(root);
}
