#include "httplib.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<string, string> urlStore;
int counter = 1;

const string BASE62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

string encodeBase62(int num) {
    string res;
    while (num > 0) {
        res.push_back(BASE62[num % 62]);
        num /= 62;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    httplib::Server server;

    // Create short URL
    server.Post("/shorten", [](const httplib::Request& req, httplib::Response& res) {
        if (req.body.find("\"url\"") == string::npos) {
            res.status = 400;
            res.set_content("Invalid JSON", "text/plain");
            return;
        }

        auto start = req.body.find(":\"") + 2;
        auto end = req.body.rfind("\"");
        string longUrl = req.body.substr(start, end - start);

        string shortCode = encodeBase62(counter++);
        urlStore[shortCode] = longUrl;

        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content(
            "{\"shortUrl\":\"http://localhost:8080/" + shortCode + "\"}",
            "application/json"
        );
    });

    // Redirect
    server.Get(R"(/(\w+))", [](const httplib::Request& req, httplib::Response& res) {
        string code = req.matches[1];

        if (urlStore.find(code) == urlStore.end()) {
            res.status = 404;
            res.set_content("Not Found", "text/plain");
            return;
        }

        res.status = 302;
        res.set_header("Location", urlStore[code]);
    });

    cout << "Server running on http://localhost:8080\n";
    server.listen("localhost", 8080);
}
