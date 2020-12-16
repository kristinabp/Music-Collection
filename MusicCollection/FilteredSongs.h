#ifndef FILTEREDSONGS_H
#define FILTEREDSONGS_H

#include "Song.h"

class FilteredSongs
{
private:
	struct Node
	{
		Song* data;
		Node* left,* right;
	};
	Node* root;

	void printHelper(Node* node, int spaces = 0) const;
	void printtHelper(Node* root)const;
	bool containsHelper(Node* node, Song* element) const;
	void removeHelper(Node*& node,Song* element);
	size_t calculateHeightHelper(Node* node) const;
	Song* getMinElement(Node* node);
	void eraseHelper(Node* node);
	int getSubtreeDifference(Node* node) const;
	Node* leftRotation(Node* node);
	Node* rightRotation(Node* node);
	Node* leftRightRotation(Node* node);
	Node* rightLeftRotation(Node* node);
	Node*& balance(Node*& node);
	Node* insertHelper(Node*& node, Song* element);
public:
	FilteredSongs();
	FilteredSongs& insert(Song* element);
	void prettyPrint() const;
	bool contains(Song* element) const;
	void remove(Song* element);

	void print()const;
	~FilteredSongs();
};

#endif // !FILTEREDSONGS_H


