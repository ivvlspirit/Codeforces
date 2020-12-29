#include <iostream>
#include <stdio.h>
#include <io.h>

using namespace std;

int main(){
    string roundNumber;
    int numOfTasks;

    cout << "Enter the round number: ";
    cin >> roundNumber;
    cout << endl;

    cout << "Enter the number of tasks: ";
    cin >> numOfTasks;
    cout << endl;

    string mkdirCommand = "mkdir " + roundNumber;
    if(system(mkdirCommand.c_str()) != 0){
        cout << "Something went wrong while creating the folder!";
    }else{
        cout << "Folder " << roundNumber << " succesfully created!" << endl;


        for(int i=0; i<numOfTasks; i++){
            char taskLetter = 'A' + i;
            string copyCommand = "copy template.cpp " + roundNumber + "\\" + roundNumber + taskLetter + ".cpp";
            system(copyCommand.c_str());
        }

        cout << numOfTasks << " files succesfully created!" << endl;
    }
}