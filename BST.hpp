/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 08 PokeTree
Date Last Modified: 4/3/2017
------------------------------------------*/

//*********************************************
//
//     CONSTRUCTOR
//
//*********************************************
template <typename T, typename S>
BST<T,S>::BST()
{

}

//*********************************************
//
//     COPY CONSTRUCTOR
//
//*********************************************
template <typename T, typename S>
BST<T,S>::BST(BST<T,S>& tree)
{
  m_root = copyTree(tree.m_root);
}

template <typename T, typename S>
Node<T>* BST<T,S>::copyTree(Node<T>* subtree)
{
  Node<T>* tree = nullptr;

  if(subtree != nullptr)
  {
    tree = new Node<T>(subtree->getValue());
    tree->setLHS(copyTree(subtree->getLHS()));
    tree->setRHS(copyTree(subtree->getRHS()));
  }

  return(tree);

}

//*********************************************
//
//      DECONSTRUCTOR
//
//*********************************************
template <typename T, typename S>
BST<T,S>::~BST()
{
  deleteTree(m_root);
}

template <typename T, typename S>
void BST<T,S>::deleteTree(Node<T>* jumper)
{
  if(!jumper)
  {
    return;
  }
  deleteTree(jumper->getLHS());
  deleteTree(jumper->getRHS());
  delete jumper;
}

//*********************************************
//
//      IN SAVE
//
//*********************************************
template <typename T, typename S>
void BST<T,S>::INsave(std::string filename)
{
  m_outfile.open(filename);
  INrec(m_root);
  m_outfile.close();
}

//IN SAVE recursive method
template <typename T, typename S>
void BST<T, S>::INrec(Node<T>* subtree)
{
  if(subtree == nullptr)
  {
    return;
  }
  else
  {
    INrec(subtree->getLHS());
    m_outfile << subtree->getValue().getANAME() << "," << subtree->getValue().getID() << "," << subtree->getValue().getJNAME() << std::endl;
    INrec(subtree->getRHS());
  }
}

//*********************************************
//
//      PRE SAVE
//
//*********************************************
template <typename T, typename S>
void BST<T,S>::PREsave(std::string filename)
{
  m_outfile.open(filename);
  PRErec(m_root);
  m_outfile.close();
  }

  //PRE SAVE recursive method
  template <typename T, typename S>
  void BST<T,S>::PRErec(Node<T>* subtree)
  {
  if(subtree == nullptr)
  {
    return;
  }
  else
  {
    m_outfile << subtree->getValue().getANAME() << "," << subtree->getValue().getID() << "," << subtree->getValue().getJNAME() << std::endl;
    PRErec(subtree->getLHS());
    PRErec(subtree->getRHS());
  }
}

//*********************************************
//
//      POST SAVE
//
//*********************************************
template <typename T, typename S>
void BST<T,S>::POSTsave(std::string filename)
{
  m_outfile.open(filename);
  POSTrec(m_root);
  m_outfile.close();
  }

  //POST SAVE recursive method
  template <typename T, typename S>
  void BST<T, S>::POSTrec(Node<T>* subtree)
  {
  if(subtree == nullptr)
  {
    return;
  }
  else
  {
    POSTrec(subtree->getLHS());
    POSTrec(subtree->getRHS());
    m_outfile << subtree->getValue().getANAME() << "," << subtree->getValue().getID() << "," << subtree->getValue().getJNAME() << std::endl;
  }
}

//*********************************************
//
//     SEARCH
//
//*********************************************
template <typename T, typename S>
T BST<T,S>::search(S key) throw(std::runtime_error)
{
  Node<T>* jumper = m_root;
  bool found = false;

  while(!found)
  {
    found = true;

    if(jumper == nullptr)
    {
      throw(std::runtime_error("Pokemon not found!\n"));
    }
    else if((jumper->getValue()) == key)
    {
      return(jumper->getValue());
    }
    else if(jumper->getValue() < key)
    {
      jumper = jumper->getRHS();
      found = false;
    }
    else
    {
      jumper = jumper->getLHS();
      found = false;
    }
  }

  return(jumper->getValue());
}

//Overloaded Search
template <typename T, typename S>
bool BST<T,S>::search(T value) throw(std::runtime_error)
{
  Node<T>* jumper = m_root;
  bool found = false;

  while(!found)
  {
    found = true;

    if(jumper == nullptr)
    {
      return(false);
    }
    else if((jumper->getValue()) == value)
    {
      return(true);
    }
    else if(jumper->getValue() < value)
    {
      jumper = jumper->getRHS();
      found = false;
    }
    else
    {
      jumper = jumper->getLHS();
      found = false;
    }
  }

  return(true);

}
//*********************************************
//
//     ADD
//
//*********************************************
template <typename T, typename S>
void BST<T,S>::add(T value) throw(std::runtime_error)
{
  if(search(value))
  {
    throw(std::runtime_error("Pokemon is already in Tree!\n"));
  }

  if(m_root == nullptr)
  {
    Node<T>* temp = new Node<T>(value);
    m_root = temp;
  }
  else
  {
    recAdd(value, m_root);
  }
}

//*********************************************
//
//     RED ADD
//
//*********************************************
template <typename T, typename S>
void BST<T,S>::recAdd(T value, Node<T>* subtree)
{
  if(value > subtree->getValue())
  {
    if(subtree->getRHS() == nullptr)
    {
      Node<T>* temp = new Node<T>(value);
      subtree->setRHS(temp);
    }
    else
    {
      recAdd(value, subtree->getRHS());
    }
  }
  if(value < subtree->getValue())
  {
    if(subtree->getLHS() == nullptr)
    {
      Node<T>* temp = new Node<T>(value);
      subtree->setLHS(temp);
    }
    else
    {
      recAdd(value, subtree->getLHS());
    }
  }
}

//*********************************************
//
//     REMOVE
//
//*********************************************
/*template <typename T, typename S>
void BST<T,S>::removeEntry(S avlue)
{

}*/













//Free Space
