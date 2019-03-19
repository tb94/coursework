 /***************************
  *                         *
  *  CSCI 480 Assignment 7  *
  *     File Allocation     *
  *                         *
  * Date - 12/5/17          *
  * Programmer - Tim Bretz  *
  *                         *
  ***************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>

#define BLOCK_SIZE 512
#define HOWOFTEN 1 
#define MAX_ENTRIES 12
#define PRINT_RANGE 50 

using namespace std;

struct File
{
    string      fileName;
    int         size;
    short int   startingBlock;
};

list<File>             Directory;
list<File>::iterator   it,
                       next;

void copyFile(string, string);
void deleteFile(string);
void print(list<File>);
void renameFile(string, string);
void deallocate(File);
int allocate(int);
File newFile(string, int);
list<File>::iterator findFile(string);
short int               FAT[4096];
int                     FATit;

 

int main()
{
    char        transaction;
    string      fileName1,
                fileName2;
    int         size,
                count = 0;

    ifstream    data ("data7.txt");

    cout << "\nStarting File Allocation\n";


    for (FATit = 0; FATit < 4096; FATit++)
    {
        FAT[FATit] = 0;
    }

    Directory.push_back(newFile(".", 512));

    print(Directory);

    cout << "\nBegin Simulation\n";

    while (!data.eof())
    {
        count++;

        data >> transaction;

        switch (transaction)
        {
            case 'C':
                // Copy File

                data >> fileName1 >> fileName2;
                
                cout << "\nCopy " << fileName1 << " to file " << fileName2;

                copyFile(fileName1, fileName2);
                
                break;

            case 'D':
                // Delete File
                
                data >> fileName1;

                cout << "\nDelete " << fileName1;

                deleteFile(fileName1);
                
                break;

            case 'N':
                // New File

                data >> fileName1 >> size;

                cout << "\nCreate new file " << fileName1;

                Directory.push_back(newFile(fileName1, size));
                
                break;

            case 'M':
                // Modify File

                data >> fileName1 >> size;

                cerr << "\nModify " << fileName1;

                if (findFile(fileName1) == Directory.end())
                      cout << "\nFile not found: " << fileName1;
                else
                {
                    Directory.push_back(newFile("temp", size));
                    cerr << "\nTemporary file added to directory";
                    deleteFile(fileName1);
                    cerr << "\nOld file deleted";

                    renameFile("temp", fileName1);
                    cerr << "\nRenamed to original file name";
                }

                break;

            case 'R':
                // Rename File

                data >> fileName1 >> fileName2;

                renameFile(fileName1, fileName2);
                
                print(Directory);
                
                break;

            case '?':
                // All Done!

                cout << "\nTasks Complete\n";

                break;
        }

        if (count == HOWOFTEN)
        {
            count = 0;
            print(Directory);
        }
    }

    if (count != HOWOFTEN)
        print(Directory);

    return 0;
}

void copyFile(string file1, string file2)
{   
    list<File>::iterator temp;

    if (findFile(file1) == Directory.end())
        cout << "File not found: " << file1;
    
    else if (findFile(file2) != Directory.end())
        cout << "File already exists: " << file2;
    
    else
    {
        temp = findFile(file1);

        Directory.push_back(newFile(file2, temp->size));
    }                  
}
void deleteFile(string file)
{
    list<File>::iterator temp;

    if (findFile(file) == Directory.end())
        cout << "File not found: " << file;
    
    else
    {
        temp = findFile(file);

        for (it = Directory.begin(); it != Directory.end(); it++)
        {
            if (temp->fileName == it->fileName)
            {
                it = Directory.erase(it);
                --it;
            } 
        }
        cerr << "\nCalling deallocate for " << temp->fileName;
        deallocate(*temp);
        cerr << "\nFile Deallocated successfully";
    }
}

File newFile(string file, int s)
{
    File f;

    if (findFile(file) != Directory.end())
        cout << "File already exists: " << file;

    else
    {
        f.fileName = file;
        f.size = s;
        f.startingBlock = allocate(s); 
    }

    return f;
}
 
void print(list<File> list)
{
    if (list.empty())
        cout << "(none)\n";
    else
    {
        int i = 0;

        cout << "\n\nDirectory:\n";

        for (it = list.begin(); it != list.end(); it++)
        {
            cout << it->fileName << "\t" << it->size << endl;
            i++;
        }

        cout << "\nFAT:\n";

        i = 0;

        cout << "|\t";

        for (FATit = 0; FATit < PRINT_RANGE; FATit++)
        {
            cout << FAT[FATit] << "\t|\t";
            i++;

            if (i == 7)
            {
                cout << "\n ---------------------------------------------------------------------------------------------------------------\n|\t";
                i = 0;
            }
        }
        cout << endl;
    }
}

list<File>::iterator findFile(string file)
{
    it = Directory.begin();

    while (it != Directory.end())
    {
        if (it->fileName == file)
            return it;
        else
            it++;
    }

    return Directory.end(); 
}

void renameFile(string name1, string name2)
{
    list<File>::iterator f1 = findFile(name1),
                         f2 = findFile(name2);

    if (f1 == Directory.end())
        cout << "File not found: " << name1;

    else if (f2 != Directory.end())
        cout << "File already exists: " << name2;

    else
    {
        for (it = Directory.begin(); it != Directory.end(); it++)
        {
            if (f1->fileName == it->fileName)
                it->fileName = name2;
        }
    }

}

int allocate(int s)
{
    int startingBlock,
        next;

    for (FATit = 0; FATit < 4096; FATit++)
    {
        if (FAT[FATit] == 0)
        {
            startingBlock = FATit;
            break;
        }
    }

    FATit = startingBlock;
    next = FATit;
    next++;

    while (s > BLOCK_SIZE && next < 4096)
    {
        if (FAT[next] == 0)
        {
            FAT[FATit] = next;
            s -= BLOCK_SIZE;
            FATit = next;
        }
        
        next++;
    }

    if (FATit == 4096)
    {
        cout << "Error: Not enough space available\n";
        return -1;
    }

    FAT[FATit] = -1;
    return startingBlock;  
}

void deallocate(File file)
{
    cerr << "\nI made it to deallocate\n";
    short int   thisBlock = file.startingBlock,
                nextBlock;

    cerr << "\nDeallocating file " << file.fileName << " starting at block " << thisBlock;
    do
    {
        nextBlock = FAT[thisBlock];
        FAT[thisBlock] = 0;
        thisBlock = FAT[nextBlock];
    }
    while (nextBlock != -1);
}
