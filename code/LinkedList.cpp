// LinkedList.cpp

//Hayden Moritz
//COSC 2030 - Lab02

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}


const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}

//Size method to return size of a LLList
double List::size()
{
	Node *temp;
	temp = first_;
	int length=0;
	while (temp!=NULL) {
		length++;
		temp = temp->next_;
	}
	return length;
}

//A sum method to report the sum of a LLList
double List::sum()
{
	Node *temp;
	double sum = 0;
	temp = first_;
	while (temp != NULL) {
		sum += temp->entry_;
		temp = temp->next_;
	}
	return sum;
}

//An insertAsLast method to insert a new Node object as the last Node in the linked list
void List::insertAsLast(double x)
{
	Node *last = first_;
	last->entry_ = x;
	last->next_ = NULL;
	if (first_ == NULL) {
		first_ = last;
	}
	else {
		Node *temp = first_;
		while (temp->next_!=NULL) {
			temp = temp->next_;
		}
		temp->next_ = last;
	}
}

// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}


