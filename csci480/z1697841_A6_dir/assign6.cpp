
/*       CSCI 480                   *
 *                                  *
 * Programmer: Tim Bretz            *
 * Assignment 6 - Memory Management *
 * Date = 11/15/17                  *
 *                                  */

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <stdlib.h>

#define KB 1024
#define MB 1024*1024

using namespace std;

struct Block
{
    int startingAddress;
    int blockSize;
    string processID;
    string blockID;
};

list<Block> Avail,
             InUse;  
list<Block>::iterator it,
                    next;


int main()
{
    Block newBlock(int, int, string, string);
    void print(list<Block>);
    void allocateFF(string, int, string);
    void deallocate(string);
    void deallocate(string, string);

    Block block;

    bool bFit = false,
         fFit = false;

    char transaction;
    string pID, bID, fit;
    int s;
    
    cout << "\nThis is a memory-management simulation.\n";
    cout << "\nInserting new blocks to Avail\n";

    Avail.push_back(newBlock(3*MB, MB, "", ""));
    Avail.push_back(newBlock(4*MB, 2*MB, "", ""));
    Avail.push_back(newBlock(6*MB, 2*MB, "", ""));
    Avail.push_back(newBlock(8*MB, 4*MB, "", ""));
    Avail.push_back(newBlock(12*MB, 4*MB, "", ""));
    
    cout << "\nAvail:\n";
    print(Avail);

    cout << "\nInUse:\n";
    print(InUse);

   
    // open and read input file data6.txt
    
    ifstream data ("data6.txt");

    while (!data.eof())
    {
        data >> transaction;
    
        cout << "\nTransaction: ";

        switch(transaction)
        {
            case 'L':
                data >> pID >> s >> bID;
                
                cout << "Request to load process " << pID 
                     << ", Block ID " << bID 
                     << " using " << s << " bytes of memory.\n\n";

                allocateFF(pID, s, bID);
                break;

            case 'A':
                data >> pID >> s >> bID;

                cout << "Request to Allocate additional " << s 
                     << " bytes for process " << pID
                     << ", Block ID: " << bID << endl << endl;

                allocateFF(pID, s, bID);
                break;

            case 'D':
                data >> pID >> bID;

                cout << "Request to Deallocate Block ID: " << bID
                     << " for process " << pID << ".\n";

                deallocate(pID, bID);
                break;

            case 'T':
                data >> pID;

                cout << "Request to Terminate process " << pID << endl;

                deallocate(pID);
                break;

            case '?':
                goto theEnd;
                break;
        }

        cout << "\nList of available blocks\n";
        print(Avail);
        cout << "\nList of blocks currently in use\n";
        print(InUse);
    }

theEnd:
    //  after all transactions print both lists

    cout << "\nEnd of File\n";
    cout << "\nAvail:\n";
    print(Avail);
    cout << "\nInUse:\n";
    print(InUse);

    //  close input file
    data.close();

    return 0;
}
void print(list<Block> list)
{
    int sum = 0;

    if (list.empty())
        cout << "(NONE)" << endl;
    else
    {
        cout << "Start Address\t\t\tSize\n";

        for (it = list.begin(); it != list.end(); it++)
        {
            cout << "\t" << it->startingAddress << "\t\t" << it->blockSize << endl;
            sum += it->blockSize;
        }
        cout << "Total size of the list = " << sum << endl;
    }
}

Block newBlock(int start, int size, string pid, string bid)
{
    Block b;
    b.startingAddress = start;
    b.blockSize = size;
    b.processID = pid;
    b.blockID = bid;

    return b;
}

// load or allocate space in Avail
void allocateFF(string pid, int size, string bid)
{
    bool found = false;
   
    it = Avail.begin();
    
    // first fit
    
    do
    {
        // if there is room for new block

        if (it->blockSize >= size)
        {
            cout << "Sufficient Memory Block found. Size: " << it->blockSize << endl;
            
            // move to InUse

            it->blockSize -= size;
            InUse.push_front(newBlock(it->startingAddress, size, pid, bid));
            it->startingAddress += size;

            cout << "Allocated Successfully.\n";

            // if there is no more room
            if (it->blockSize <= 0)
            {
                Avail.erase(it);
            }
            
            found = true;
            break;
        }
        else
            it++;
 
        if (it == Avail.end())
        {
            cout << "\nError: Attempt to allocate memory failed.\nNo block of sufficient memory available.\n\n";
            found = true;
        }
    }
    while (!found);
}

// deallocate all blocks in process
void deallocate(string pid)
{
    list<Block>::iterator temp;
    
    it = InUse.begin();

    while (it != InUse.end())
    {
        next = it;
        next++;
        
        if (it->processID == pid)
        {
            for (temp = Avail.begin(); temp != Avail.end(); temp++)
            {
                // search by starting address
                if (temp->startingAddress < it->startingAddress)
                    continue;
                else
                {
                    // move block to Avail
                    Avail.insert(temp, newBlock(it->startingAddress, it->blockSize,
                                                it->processID, it->blockID));
                    cout << "Memory Block Found.\n";
                    
                    break;
                }
            }

            cout << "removing block at " << it->startingAddress << endl;

            // remove from InUse
            it = InUse.erase(it);
            continue;
        }
        else
        {
            it++;
        }

        if (next == InUse.end())
        {
            cout << "Error: Attempt to deallocate memory failed. Block not found.\n";
            return;
        }
    }

    it = Avail.begin();
    next = it; 
    next++;

    while (next != Avail.end())
    {
        int nextSA = next->startingAddress,
            itSA = it->startingAddress,
            nextBS = next->blockSize,
            itBS = it->blockSize;

        if ((nextSA == (itSA + itBS)) && ((nextBS + itBS) <= (4 * MB)))
        {
            cout << "Merging free memory block at address " << it->startingAddress
                 << " with free memory block at address " << next->startingAddress << endl;
            
            // it absorbs next
            
            it->blockSize += next->blockSize;
            
            next = Avail.erase(next);
        }

        else
        {
            it++;
            next = it;
            next++;
        }
    }

   cout << "Termination of process successful.\n";

}

// deallocate specific block
void deallocate(string pid, string bid)
{
    list<Block>::iterator temp;
    
    for (it = InUse.begin(); it != InUse.end(); it++)
    {
        next = it;
        next++;

        if (it->processID == pid && it->blockID == bid)
        {
            for (temp = Avail.begin(); temp != Avail.end(); temp++)
            {
                // search by starting address
                if (temp->startingAddress > it->startingAddress)
                {
                    // add to Avail
                    Avail.insert(temp, newBlock(it->startingAddress, it->blockSize,
                                                it->processID, it->blockID));
                    cout << "Memory Block Found.\n";
                    break;
                }
            }

            // remove from InUse
            InUse.erase(it);
            break;
        }
        else if (next == InUse.end())
        {
            cout << "Error: Attempt to deallocate memory failed. Block not found.\n";
            return;
        }
    }

    it = Avail.begin();
    next = it; 
    next++;

    while (next != Avail.end())
    {
        if ((next->startingAddress == (it->startingAddress + it->blockSize))
                && ((next->blockSize + it->blockSize) <= (4 * MB)))
        {
            cout << "Merging free memory block at address " << it->startingAddress
                 << " with free memory block at address " << next->startingAddress << endl;

            // it absorbs next
            it->blockSize += next->blockSize;
            next = Avail.erase(next);
        }

        else
        {
            it++;
            next = it;
            next++;
        }
    }

    cout << "Deallocation of block successful.\n";
}
