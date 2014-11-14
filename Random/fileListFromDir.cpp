/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/***************************************************************
 * fileListFromDir.cpp
 * 
 * Platform:	 Windows, Microsoft Visual Studio
 *
 * Dependencies: Add dirent.h to include library of VC
 *
 * Description:  The program reads all the file names from a
 *				 directory and writes them to a text file.
 *				 The user can choose to write only some part of 
 *				 filename to output list. By default extensions
 *				 are not written in output file because the 
 *				 default delimiter is "." (dot)
 *
 * Inputs:		 Set values of the three macros:
 *				 1. LIST_PATH
 *				 2. DIR_PATH
 *				 3. DELIMITER
 *
 * December 23, 2013, Pulkit Verma
 * First version.
 ***************************************************************/

#include <fstream>
#include <string>
#include <dirent.h>

#define LIST_PATH "D:/List.txt"
#define DIR_PATH "D:/TestDir"
#define DELIMITER "."

using namespace std;

/*************************************************************
 * This method will break the inputString depending on the 
 * delimiter and return the left part. inputString will be
 * updated to the right part.
 *************************************************************/
char* stringSeperator(char** inputString, const char* delimiter);

int main()
{
	char *token,*tempString;
	ifstream fin;
	string dir, filepath;
	DIR *dp;
	struct dirent *dirp;
	struct stat filestat;
	FILE *fp;

	dir=DIR_PATH;
	dp = opendir( dir.c_str() );

	if (dp == NULL)
	{
		perror("Error while opening the input directory.\n");
		return errno;
	}

	if( (fp = fopen(LIST_PATH,"w")) == NULL ) //open the file
	{
		perror("Error while opening the list file.\n");
		return errno;
	}

	while ((dirp = readdir( dp )))
	{
		filepath = dir + "/" + dirp->d_name;

		// If the file is a directory or invalid it will be skipped 
		if (stat( filepath.c_str(), &filestat )) 
			continue;
		if (S_ISDIR( filestat.st_mode ))  
			continue;   

		tempString = strdup(dirp->d_name);
		if (tempString != NULL)
			while ((token = stringSeperator(&tempString,DELIMITER)) != NULL)
			{
				fprintf(fp,"%s\n",token);
				break;
				// By using break here, we have ensured to take only
				// part of the file name which lie on left hand side 
				// of first delimiter encountered
			}
	}

	fclose(fp);
	closedir( dp );
	return 0;
}

char* stringSeperator(char** inputString, const char* delimiter)
{
	char* startString = *inputString;
	char* tempString;
	tempString = (startString != NULL) ? strpbrk(startString, delimiter) : NULL;

	if (tempString == NULL)
		*inputString = NULL;
	else
	{
		*tempString = '\0';
		*inputString = tempString + 1;
	}

	return startString;
}
