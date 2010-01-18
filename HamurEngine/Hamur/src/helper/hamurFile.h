#ifndef HAMUR_FILE_H
#define HAMUR_FILE_H

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::ios;
using std::endl;


namespace hamur
{
    /**
     * Handles file operations.
     * File writing and reading.
     */
    class HamurFile
	{
		public:
			 HamurFile();
			~HamurFile();

			void write(const string &input);
            void write(int input);
            void write(float input);
            void write(double input);

            void openFile();
            void closeFile();

		protected:
			
		private:
           
            string fileName;
			ofstream file; 
	};
    
}

#endif // HAMUR_FILE_H 