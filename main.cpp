#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<string>
#include<ctime>
#include<windows.h>

using namespace std;

const string BASE62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

struct URLRecord{
    string longURL;
    time_t createdAt;
    time_t expiryTime;
};

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

const int DEFAULT_EXPIRY_SECONDS = 60 * 60 * 24 ; 

class URLShortener{
    private:
        unordered_map<string, URLRecord> urlStore;
        int counter;
    public:
        URLShortener(){
            counter = 1;
        }
        string shortenURL(const string& longURL,int expirySeconds=DEFAULT_EXPIRY_SECONDS){
            long long id = counter++;
            string shortCode = encodeBase62(id);
            time_t now = time(nullptr);
            URLRecord record;
            record.longURL = longURL;
            record.createdAt = now;
            record.expiryTime = now+expirySeconds;
            urlStore[shortCode] = record;
            return shortCode;
        }
        string redirectURL(const string& shortCode){
            if(urlStore.find(shortCode)==urlStore.end())
                return "404 Not Found!";
            time_t now = time(nullptr);
            if(now>urlStore[shortCode].expiryTime)
                return "404 Link Expired!";
            
            return urlStore[shortCode].longURL;
        }
};

int main(){
    URLShortener service;
    string s1 = service.shortenURL("https://www.google.com",5);
    cout << "Short URL: " << s1 << endl;
    cout << "Redirect: " << service.redirectURL(s1)<< endl;
    cout<<"Waiting for expiry..."<<endl;
    Sleep(6000);
    cout<< "Redirect after expiry: " << service.redirectURL(s1)<< endl;
    return 0;
}