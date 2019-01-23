/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 08 PokeTree
Date Last Modified: 4/3/2017
------------------------------------------*/
#ifndef BST_H
#define BST_H
#include "Node.h"
#include <stdexcept>

template <typename T, typename S>
class BST
{
private:
  Node<T>* m_root;
  std::ofstream m_outfile;
  void INrec(Node<T>* subtree);
  void PRErec(Node<T>* subtree);
  void POSTrec(Node<T>* subtree);

public:
  BST();
  BST(BST<T,S>& tree);
  ~BST();
  void deleteTree(Node<T>* jumper);
  void add(T value) throw (std::runtime_error);
  void recAdd(T value, Node<T>* subtree);
  void INsave(std::string filename);
  void PREsave(std::string filename);
  void POSTsave(std::string filename);
  T search(S key) throw(std::runtime_error);
  bool search(T value) throw(std::runtime_error);
  Node<T>* copyTree(Node<T>* subtree);
    //void removeEntry(S value);
    //Tests
};
#include "BST.hpp"
#endif
