#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

const string BASE62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

string encodeBase62(long long num) {
    if (num == 0) return string(1, BASE62[0]);

    string result;
    while (num > 0) {
        result.push_back(BASE62[num % 62]);
        num /= 62;
    }
    reverse(result.begin(), result.end());
    return result;
}


class URLShortener{
    private:
        unordered_map<string, string> shortToLong;
        int counter;
    public:
        URLShortener(){
            counter = 1;
        }
        string shortenURL(const string& longURL){
            long long id = counter++;
            string shortCode = encodeBase62(id);
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
    string s1 = service.shortenURL("https://www.google.com");
    string s2 = service.shortenURL("https://www.github.com");
    string s3 = service.shortenURL("https://www.openai.com");
    cout << s1 << "->" << service.redirectURL(s1) << endl;
    cout << s2 << "->" << service.redirectURL(s2) << endl;
    cout << s3 << "->" << service.redirectURL(s3) << endl;
}