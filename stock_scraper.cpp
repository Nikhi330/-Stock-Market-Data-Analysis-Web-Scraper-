#include <iostream>
#include <curl/curl.h>
#include <rapidjson/document.h>

// Callback function to handle data received from CURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

// Function to fetch stock market data from an API
std::string fetchStockData(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return response;
}

// Function to parse JSON response and extract stock price
void parseStockData(const std::string& jsonResponse) {
    rapidjson::Document doc;
    doc.Parse(jsonResponse.c_str());
    
    if (doc.HasParseError()) {
        std::cerr << "Error parsing JSON" << std::endl;
        return;
    }
    
    if (doc.HasMember("price") && doc["price"].IsDouble()) {
        std::cout << "Stock Price: " << doc["price"].GetDouble() << std::endl;
    } else {
        std::cerr << "Invalid data received" << std::endl;
    }
}

int main() {
    std::string apiUrl = "https://query1.finance.yahoo.com/v7/finance/quote?symbols=AAPL"; // Yahoo Finance API
    std::string stockData = fetchStockData(apiUrl);
    
    if (!stockData.empty()) {
        parseStockData(stockData);
    } else {
        std::cerr << "Failed to fetch stock data." << std::endl;
    }
    
    return 0;
}
