using namespace std;
class Solution {
public:
    int maximum69Number (int num) {   //converting int to string
        string s = to_string(num);
        for( char& c : s ){
            if( c == '6'){            // checking only the first string
                c = '9';
                break;
            }
        }return stoi(s);              // converting string to int
    }
};