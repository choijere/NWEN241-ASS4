#include <iostream>
#include <vector>
#include <algorithm>
#include "vectordb.hpp"
#include "abstractdb.hpp"

using namespace nwen;
using namespace std;

//return number of rows
int VectorDbTable::rows() 
{
	return database.size();
}

//print out the row, including all its fields, and then return true to indicate success.
bool VectorDbTable::show(unsigned int row)
{
	if(row > database.size())
	{
		return false;
	}
	else
	{
		cout << "Showing entry in row: " << row << endl;
		cout << "ID:       " << database[row].id << endl;
		cout << "Title:    " << database[row].title << endl;
		cout << "Year:     " << database[row].year << endl;
		cout << "Director: " << database[row].director << endl;
		return true;
	}
}

//return a pointer to the movie structure at the selected row.
struct movie* VectorDbTable::get(unsigned int row)
{
	if(row > database.size())
	{
		return NULL;
	}
	else
	{
		struct movie* ptr = &database[row];
		return ptr;
	}
}

//Add a movie struct into the database array.
bool VectorDbTable::add(movie &entry)
{
	if(VectorDbTable::contains(entry))
	{
		return false;
	}
	else
	{
		database.push_back(entry);
		return true;
	}
}

//Replace the row with the new entry. Return true upon success
bool VectorDbTable::update(unsigned int row, movie &entry)
{
	if(row > database.size())
	{
		return false;
	}
	else
	{
		database[row] = entry;
		return true;
	}
}

//Remove the entry located at the row. Return true upon success
bool VectorDbTable::remove(unsigned int id)
{
	//FIRST, look for the id
	int detectedRow = -1;
	for(unsigned long i = 0; i<database.size(); i++)
	{
		if(database[i].id == id)
		{
			detectedRow = i;
			break;
		}
	}
	
	//THEN, remove
	if(detectedRow == -1)
	{
		return false;
	}
	else
	{
		database.erase(database.begin() + detectedRow);
		return true;
	}
}

/*iterates through the database looking for entry.
doing this instead of that terrible "std::find()" function because it results in an unsolvable, and incomprehensible error message
that no one else on the entire planet is getting.*/
bool VectorDbTable::contains(movie &entry)
{
	for(unsigned long i = 0; i<database.size(); i++)
	{
		if(database[i].id == entry.id)
		{
			return true;
		}
	}
	return false;
}


