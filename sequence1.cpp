//Lisbeth Lazala
//CSC 212

#include <iostream>
#include <cassert>
#include "sequence1.h"

namespace main_savitch_2c
{
  //CLASS CONSTRUCTOR
  sequence::sequence(size_type CAPACITY){
    capacity = CAPACITY;
		data = new value_type[capacity];
		current_index = 0;
		used = 0;
  }

  //COPY CONSTRUCTOR
  sequence::sequence(const sequence& entry)
  {
    capacity = entry.capacity;
    data = new value_type[capacity];
		used = entry.used;
		current_index = entry.current_index;
		copy(entry.data,entry.data+used,data);
  }

  //Postcondition: The first item on the sequence becomes the current item
  //     (but if the sequence is empty, then there is no current item).
  void sequence::start()
  {
    current_index=0;
  }

  //Precondition: is_item returns true.
  //Postcondition: If the current item was already the last item in the
  //sequence, then there is no longer any current item. Otherwise, the new
  //current item is the item immediately after the original current item.
  void sequence::advance()
  {
    if (is_item()){
      current_index++;
    }
  }


//Precondition: size( ) < CAPACITY.
//Postcondition: A new copy of entry has been inserted in the sequence
//before the current item. If there was no current item, then the new entry
//has been inserted at the front of the sequence. In either case, the newly
//inserted item is now the current item of the sequence.
  void sequence::insert(const value_type& entry)
  {
    if(used == CAPACITY)
    {
      CAPACITY = (CAPACITY*1.5) + 1 ; //increase capacity size
		  resize(CAPACITY);
    }
    if(!is_item())
    {
      current_index = 0; 
    }
    for(int i = used; i > CAPACITY; i--)
    {
      data[i] = data[i-1];
	    data[current_index] = entry; //inserts entry
	    used++;
    }
  }

  //  Precondition: size( ) < CAPACITY.
  //     Postcondition: A new copy of entry has been inserted in the sequence after
  //     the current item. If there was no current item, then the new entry has
  //     been attached to the end of the sequence. In either case, the newly
  //     inserted item is now the current item of the sequence.
  void sequence::attach(const value_type& entry)
  {
    if(used == CAPACITY)
    {
      CAPACITY = (CAPACITY*1.5) + 1;
      resize(CAPACITY);
      data[current_index+1] = entry;
    }
    if(!is_item())
	   {
       data[current_index]=entry;
     }
     else
     {
       for(int i = used; i > CAPACITY+1; i--)
       {
         data[i] = data[i-1];	}
		     data[current_index+1] = entry;
		     current_index++;
       }
     }
     used++;
  }

  // Precondition: is_item returns true.
  //     Postcondition: The current item has been removed from the sequence, and the
  //     item after this (if there is one) is now the new current item.
  void sequence::remove_current()
  {
    if(is_item())
    {
      for (int i = current_index; i < used; i++)
			{
        data[i] = data[i+1];
      }
			used--;
    }
  }

//CONST MEMBER FUNCTIONS
  sequence::size_type sequence::size( ) const
  {
    return used; //num of used = the size of sequence
  }

  bool sequence::is_item( ) const
  {
    return current_index < used; //if current_index < used, is_item will return true
  }

  sequence::value_type sequence::current( ) const
  {
    return data[current_index]; //returns value of current index
  }

  sequence::~sequence()
  {
    delete [] data; //deletes sequence storage
  }

  void sequence::resize(size_type new_capacity)
  {
    if(new_capacity > used)
		{
			value_type * array_block;
			capacity = new_capacity;
			array_block = new value_type[capacity];
			copy(data,data+used,array_block);
			delete [] data;
			data = array_block;
		}
  }
}
