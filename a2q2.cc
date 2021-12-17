#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]){
    //Rigid 10 element array
    string candidates[10] = {""};
    //Rigid 10 element array
    //Keep in mind if the cols exceed 10 then we will recieve a segmentation fault 
    int vote_cols[10] = {0};
    //Counts spoilt votes
    int spoiltVoters = 0;
    //Nubm of candidates
    int countCandidates = 0;
    //Num of total voters
    int voters = 0;
    //Num of allocated votes per voter
    int X;
    string voter1;
    //Valid Votes
    int valid = 0;

int counter = 0;
//First while loop reads in all the candidates
    while (!cin.eof() || !cin.fail()){
        int n;
        string line = "";
        getline(cin, line);
        istringstream ss1 { line };
        //If first item of stream is integer
        if (ss1 >> n) {
            //Problem could be in here
            ostringstream temp;
            temp << n;
            string remainingVoter1;
            getline(ss1, remainingVoter1);
            temp << remainingVoter1;
            voter1 = temp.str();
            break;
        }else if(line==""){
            break;
        }
        //If item is not int then it is saved into a tring and saved as a candidate in the array
        else {
            ss1 >> line;
            candidates[counter] = line;
        }
        ++counter;
    }
    countCandidates = counter;
    //Determines votes alloacated per voter
    if (argc > 1){
        int n;
        string theArg = argv[1];
        istringstream ss1 { theArg };
        ss1 >> n;
        X = n;
    }
    else {
        X = countCandidates;
    }
    counter = 0;
    while (!cin.eof() || !cin.fail()) {
        int index = 0;
        int count = -1;
        //Can cause segmentation fault
        int voterDistrubution[10] = {0};
        int ballots = 0;
        //sets spoil to false
        bool spoil = false;
        if (counter == 0) {
            istringstream ss2 { voter1 };
             while ( ss2 >> count ) {
                 voterDistrubution[index] = count;
                 ballots = ballots + count;
                 if (ballots > X || index > countCandidates){
                     spoil = true;
                     break;
                 }
                 ++index;
             }
             if (index != countCandidates) {
              spoil = true;
              if (countCandidates == 0) {
                ++spoiltVoters;
            }
              
            }
            ++voters;
        }
        else {
        string line;
        getline(cin, line);
        istringstream ss3 { line };
        while ( ss3 >> count) {
                 voterDistrubution[index] = count;
                 ballots = ballots + count;
                 if (ballots > X || index > countCandidates || index >= 10){
                     spoil = true;
                     break;
                 }
                 ++index;
        }
        if (index != countCandidates){
            spoil = true;
            if (countCandidates == 0) {
                ++spoiltVoters;
            }
        }
        ++voters;
    }
    if (count = -1 && countCandidates == 0){
        valid++;
    } 
    for (int i = 0; i < countCandidates; ++i){
            if (!spoil) {
            vote_cols[i] = vote_cols[i] + voterDistrubution[i];
            }
            else {
                ++spoiltVoters;
                break;
            }
        }
        ++counter;
    }

    //Output
    if (countCandidates == 0 && voters == 0){
    cout << "Number of voters: " << 0 << endl;
    cout << "Number of valid ballots: " << 0 << endl;
    cout << "Number of spoilt ballots: " << 0 << endl;
    cout << "" <<  endl;
    cout << left << setw(15) << "Candidate"  << setw(3) << "Score" << endl;
    cout << "" <<  endl;
    }
    else if (countCandidates == 0) {
        cout << "Number of voters: " << voters - 1 << endl;
        cout << "Number of valid ballots: " << voters - spoiltVoters - 1 << endl;
        cout << "Number of spoilt ballots: " << spoiltVoters << endl;
    cout << "" <<  endl;
    cout << left << setw(15) << "Candidate"  << setw(3) << "Score" << endl;
    cout << "" <<  endl;
    }
    else if (voters == 0){
    cout << "Number of voters: " << 0 << endl;
    cout << "Number of valid ballots: " << 0 << endl;
    cout << "Number of spoilt ballots: " << 0 << endl;
    cout << "" <<  endl;
    cout << left << setw(15) << "Candidate"  << setw(3) << "Score" << endl;
    cout << "" <<  endl;
     for (int i = 0; i < countCandidates; ++i){
            cout << left << setw(15) << candidates[i] << right << setw(3) << vote_cols[i] << endl;
      
        }
    }
    else {
    cout << "Number of voters: " << voters - 1 << endl;
    cout << "Number of valid ballots: " << voters - spoiltVoters << endl;
    cout << "Number of spoilt ballots: " << spoiltVoters - 1 << endl;
    cout << "" <<  endl;
    cout << left << setw(15) << "Candidate"  << setw(3) << "Score" << endl;
    cout << "" <<  endl;
        for (int i = 0; i < countCandidates; ++i){
            cout << left << setw(15) << candidates[i] << right << setw(3) << vote_cols[i] << endl;
      
        }
    }
   
    
}

