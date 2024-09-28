/*  
 *  File Name: dictionaryList.cpp
 *  Assignment: Lab 2 Exercise A
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Sept 23, 2024
 */

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"

using namespace std;

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

const char* DictionaryList::operator [](int pos) {
    go_to_first();
    for (int i = 0; i < pos; i++) {
        step_fwd();
    }
    return cursor_datum().c_str();
}

ostream& operator<<(ostream& os, DictionaryList& rhs) {
    string result;
    rhs.go_to_first();
    while(rhs.cursor_ok()) {
        result += to_string(rhs.cursor_key()) + "\t" + rhs.cursor_datum().c_str() + "\n";
        rhs.step_fwd();
    }
    os << result;
    return os;
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

const Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const Mystring& datumA)
{
  // Add new node at head?                                                                                  
  if (headM == 0 || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }
	
  // Overwrite datum at head?                                                                               
  else if (keyA == headM->keyM)
    headM->datumM = datumA;
	
  // Have to search ...                                                                                     
  else {
      
    //POINT ONE
		
    // if key is found in list, just overwrite data;                                                        
    for (Node *p = headM; p !=0; p = p->nextM)
		{
			if(keyA == p->keyM)
			{
				p->datumM = datumA;
				return;
			}
		}
		
    //OK, find place to insert new node ...                                                                 
    Node *p = headM ->nextM;
    Node *prev = headM;
		
    while(p !=0 && keyA >p->keyM)
		{
			prev = p;
			p = p->nextM;
		}
		
    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
	
}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    } 
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}

// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.
void DictionaryList::find(const Key& keyA)
{
    if (headM == 0)
        return;
    
    // Traverse through the list and compare keys
    go_to_first();
    while (cursor_ok()) {
        if (cursorM->keyM == keyA) {
            return;
        }
        // Moves the cursor further up the list by 1.
        step_fwd();
    }

    return;
}


void DictionaryList::destroy()
{
    if (headM == 0) {
        return;
    }

    go_to_first();
    headM = 0;
    Node *doomed_node = cursorM;

    while(cursor_ok()) {
        doomed_node = cursorM;
        step_fwd();
        delete doomed_node;
    }

    sizeM = 0;

    return;
}


void DictionaryList::copy(const DictionaryList& source)
{
    if (source.headM == 0) {
        return;
    }
    Node *source_node = source.headM;
    Node *current_node = source.headM->nextM;;
    headM = new Node(source_node->keyM, source_node->datumM, 0);
    
    go_to_first();  
    while(current_node != 0) {
        cursorM->nextM = new Node(current_node->keyM, current_node->datumM, 0);
        current_node = current_node->nextM;
        step_fwd();
    }

    sizeM = source.size();
    if (source.cursor_ok()) {
        find(source.cursor_key());
    }

    return;
}


