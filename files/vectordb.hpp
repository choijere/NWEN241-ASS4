#ifndef __VECTOR_DB_HPP__
#define __VECTOR_DB_HPP__

#include "abstractdb.hpp"
#include <vector>

using namespace nwen;
using namespace std;

class VectorDbTable : public AbstractDbTable
{
	public:
	//[CORE] functions
	//return number of rows present
	int rows();
	//print the row, return true on success
	bool show(unsigned int row);
	//select a movie from the db and retreive the actual struct itself
	struct movie* get(unsigned int row);
	//add a movie into the db.
	bool add(movie &entry);
	
	//[COMPLETION] functions
	//Replace the row with the new entry. Return true upon success
	bool update(unsigned int row, movie &entry);
	//Remove the entry located at the row. Return true upon success
	bool remove(unsigned int row);
	
	//HELPER functions
	//see vectordb.cpp for more details.
	bool contains(movie &entry);
	
	vector<movie> database;
};


#endif /* __VECTOR_DB_HPP__ */
