#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class URLShortener{
    private:
        unordered_map<string, string> shortToLong;
        int counter;
    public:
        URLShortener(){
            counter = 1;
        }
        string shortenURL(const string& longURL){
            string shortCode = "url" + to_string(counter++);
            shortToLong[shortCode] = longURL;
            return shortCode;
        }
        string redirectURL(const string& shortCode){
            if(shortToLong.find(shortCode)==shortToLong.end())
                return "404 Not Found!";
            return shortToLong[shortCode];
        }
};

int main(){
    URLShortener service;
    string short1 = service.shortenURL("https://www.google.com");
    string short2 = service.shortenURL("https://www.github.com");
    cout << short1 << "->" << service.redirectURL(short1) << endl;
    cout << short2 << "->" << service.redirectURL(short2) << endl;
}