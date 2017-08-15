#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

string mystr[100];  //initialize array for no args
string str[100];    //for have args
int pos = 0;
int open = 1;
int valueing = 0;

/*readin: read and store in array
   consumes: int
   return: void
 */
void readin(int value){
    if (value != valueing){
        valueing = value;
    }
    int index = 0;
    string str;
    while(true){
        cin >> str;
        if(cin.fail() && cin.eof()){
            cin.clear();
            cin.ignore();
            break;
        }
        mystr[index] = str;
        index++;
    }
}


/* printout: for print it
     consumes: NULL
     produces: void
*/
void printout(){
    int max = 25;
    int sum = 0;
    if (valueing == 0){    //no args
        for(int pos=0; mystr[pos] != ""; pos++){
            int len = mystr[pos].length();
            sum = sum + len;
            if (sum <= max){ //if length <= 25
                cout << mystr[pos] << " ";
                sum++;
                if (sum >= max){
                    sum = 0;
                    cout << endl;
                }
                else if((sum + mystr[pos+1].length()) > max){
                    sum = 0;
                    cout << endl;
                }
            }
            else if (sum > max){  //if length > 25
                int wid = mystr[pos].length();
                string mstr[100];
                int index = 0;
                int first = 0;
                int last = 25;
                while(wid > 0){
                    mstr[index] = mystr[pos].substr(first, last);
                    first = first + 25;
                    wid = wid - 25;
                    index++;
                }  //print it
                for(int k=0; mstr[k] != ""; k++){
                    cout << mstr[k] << endl;
                }
            }
        } //for
    }
    //for contains args
    else{
        for(int i = 0; mystr[i] != ""; i++){
            int len = mystr[i].length();
            if (len <= valueing){ //if length <= args
                if(open == 1){
                    str[pos] = mystr[i];
                }
                else if(str[pos].length() + 1 + mystr[i].length() <= valueing){
                    str[pos] = str[pos] + " " + mystr[i];
                }
                else{
                    pos++;
                    str[pos] = mystr[i];
                }
            } //if
            else if(len > valueing){ //if length > args
                pos++;
                int wid = mystr[i].length();
                int first = 0;
                while(wid > 0){ //separate them
                    if (wid < valueing){
                        str[pos] = mystr[i].substr(first, first+wid);
                    }
                    else{
                        str[pos] = mystr[i].substr(first, first+valueing);
                        pos++;
                    }
                    first = first + valueing;
                    wid = wid - valueing;
                } //while
            }
        } //print it
        for(int k = 0; str[k] != ""; k++){
            cout << str[k] << endl;
        }
    }//if
}

int main(int argc, const char * argv[]){
    int myvalue = 0;
    if (argc != 1){
        istringstream iss(argv[1]); //contains args
        iss >> myvalue;
    }
    readin(myvalue);
    printout();
    return 0;
}
