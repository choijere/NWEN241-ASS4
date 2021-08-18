#ifndef __ABSTRACT_DB_HPP__
#define __ABSTRACT_DB_HPP__

/**
 * You will need to add the necessary class declaration for Task 4 in this
 * file.
 */

namespace nwen 
{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };
    
    class AbstractDbTable {
		public:
		virtual int rows() = 0;
		virtual bool show(unsigned int row) = 0;
		virtual movie* get(unsigned int row) = 0;
		virtual bool add(movie &entry) = 0;
		virtual bool update(unsigned int row, movie &entry) = 0;
		virtual bool remove(unsigned int row) = 0;
		bool loadCSV(const char* fileLocation);
	};
}

#endif /* __ABSTRACT_DB_HPP__ */
