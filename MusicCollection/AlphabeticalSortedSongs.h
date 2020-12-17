#ifndef ALPHABETICALSORTEDSONGS_H
#define ALPHABETIVALSORTEDSONGS_H

#include "Song.h"
#include<vector>
class AlphabeticalSortedSongs
{
private:
	struct Node
	{
		Song* data;
		Node* left,* right;
	};
	Node* root;
	int size;

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
	std::vector<Song*> songHelper(Node*& node);

public:
	AlphabeticalSortedSongs();
	AlphabeticalSortedSongs& insert(Song* element);
	void prettyPrint() const;
	bool contains(Song* element) const;
	void remove(Song* element);
	int sizee()const;
	std::vector<Song*> getSongs();

	void print()const;
	~AlphabeticalSortedSongs();
};

#endif // !FILTEREDSONGS_H


