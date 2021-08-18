#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <sstream>
#include "abstractdb.hpp"

using namespace nwen;
using namespace std;

bool AbstractDbTable::loadCSV(const char* fileLocation)
{
	//FIRST: open file
	fstream fsIn(fileLocation, ios::in);
	if(!fsIn.is_open())
	{
		return false; //failure to open
	}
	
	//SECOND: read all lines
	vector<string> row;
	string line, data;
	while(getline(fsIn, line))
	{
		row.clear();
		
		// use this to split the row
		stringstream s(line);
		
		//read all columns, but it
		while (getline(s, data, ','))
		{
			//add all the column data into row vector
			row.push_back(data);
		}
		
		//Now check for any invalid formatting
		if(row.size() != 4)
		{
			return false;
		}
		//Create movie struct, put it into appendThis vector
		struct movie temp;
		
		//conversion
		unsigned long id = (unsigned) stoi(row[0]);
		temp.id = id;
		
		char title[50];
		for(int i = 0; (unsigned)i < sizeof(title); i++) {temp.title[i] = row[1][i];}
		
		unsigned short year = (short) stoul(row[2]);
		temp.year = year;
		
		char director[50];
		for(int i = 0; (unsigned)i < sizeof(director); i++) {temp.director[i] = row[3][i];}
		
		add(temp);
	}
	
	//THIRD: close
	fsIn.close();
	return true;
};
